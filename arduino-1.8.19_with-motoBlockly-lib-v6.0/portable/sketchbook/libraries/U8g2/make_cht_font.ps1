$src = Get-Content "str.txt" -Encoding UTF8 -Raw
$uniEnc = [System.Text.Encoding]::Unicode
$uniChars = [System.Text.RegularExpressions.Regex]::Matches($src, '[^\x0a-\x7f]') | 
    ForEach-Object { $_.Value } | Get-Unique
Write-Host "發現中文字元: "
$uniChars -join ', ' 
(@("32-128") + ($uniChars | ForEach-Object { '$' + ([Uint32]([char]$_)).ToString('X4') })) -join ",`n" | 
    Out-File ".\tool\build\chinese1.map" -Encoding utf8
# 依列舉字元表，製作 u8g2_font_unifont_t_chinese1 陣列宣告
& .\tool\bdfconv\bdfconv.exe -v ./tool/bdf/unifont.bdf -b 0 -f 1 -M ./tool/build/chinese1.map -d ./tool/bdf/7x13.bdf -n u8g2_font_unifont_t_chinese1 -o u8g2_font_unifont.c
# 找到 .pio 下的 u8g2_fonts.c，將 u8g2_font_unifont_t_chinese1 內容換掉
$regexPattern = '(?ms)u8g2_font_unifont_t_chinese1\[\d+\] U8G2_FONT_SECTION.+?";'
$fontData = [System.Text.RegularExpressions.Regex]::Match((Get-Content "u8g2_font_unifont.c" -Encoding utf8 -Raw), $regexPattern).Value
Get-ChildItem -Path .\src\clib -Recurse -Filter u8g2_fonts.c | ForEach-Object {
    # 將 u8g2_font_unifont_t_chinese1 內容換掉
    $code = Get-Content $_.FullName -Encoding utf8 -Raw
    $code.Replace([System.Text.RegularExpressions.Regex]::Match($code, $regexPattern).Value, $fontData) |
        Out-File $_.FullName -Encoding ascii
}