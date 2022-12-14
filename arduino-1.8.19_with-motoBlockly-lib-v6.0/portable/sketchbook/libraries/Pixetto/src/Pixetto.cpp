/*
 * Copyright 2020 VIA Technologies, Inc. All Rights Reserved.
 *
 * This PROPRIETARY SOFTWARE is the property of VIA Technologies, Inc.
 * and may contain trade secrets and/or other confidential information of
 * VIA Technologies, Inc. This file shall not be disclosed to any third
 * party, in whole or in part, without prior written consent of VIA.
 *
 * THIS PROPRIETARY SOFTWARE AND ANY RELATED DOCUMENTATION ARE PROVIDED AS IS,
 * WITH ALL FAULTS, AND WITHOUT WARRANTY OF ANY KIND EITHER EXPRESS OR IMPLIED,
 * AND VIA TECHNOLOGIES, INC. DISCLAIMS ALL EXPRESS OR IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET
 * ENJOYMENT OR NON-INFRINGEMENT.
*/

#include <Arduino.h>
#include "InnerSensor.h"

#if ESP32
#define SS_FUNC(f, func, ...) \
	if (f == true) \
		return ss_hw->func(__VA_ARGS__);
#else
#define SS_FUNC(f, func, ...) \
	if (f == true) \
		return ss_hw->func(__VA_ARGS__); \
	else \
		return ss_sw->func(__VA_ARGS__);
#endif

Pixetto::Pixetto(int rx, int tx)
	: ss_hw(0), m_flag(false), m_rx(rx), m_tx(tx)
{
#if ESP32
	// C:\Users\xxx\AppData\Local\Arduino15\packages\esp32\hardware\esp32\1.0.6\cores\esp32\HardwareSerial.cpp
	if (rx == 3 && tx == 1)
	{
		m_flag = true;
		ss_hw = new InnerSensor<HardwareSerial>(&Serial);
		return;
	}
	if (rx == 9 && tx == 10)
	{
		m_flag = true;
		ss_hw = new InnerSensor<HardwareSerial>(&Serial1);
		return;
	}
	if (rx == 16 && tx == 17)
	{
		m_flag = true;
		ss_hw = new InnerSensor<HardwareSerial>(&Serial2);
		return;
	}
	return;
	
#else
	swSer = 0;
	ss_sw = 0;

	// https://www.arduino.cc/reference/en/language/functions/communication/serial/
#if defined(HAVE_HWSERIAL0) && defined(HAVE_HWSERIAL1) && defined(HAVE_HWSERIAL2) && defined(HAVE_HWSERIAL3)
	// Mega, Due
	if (rx == 0 && tx == 1)
	{
		m_flag = true;
		ss_hw = new InnerSensor<HardwareSerial>(&Serial);
		return;
	}
	if (rx == 19 && tx == 18)
	{
		m_flag = true;
		ss_hw = new InnerSensor<HardwareSerial>(&Serial1);
		return;
	}
	if (rx == 17 && tx == 16)
	{
		m_flag = true;
		ss_hw = new InnerSensor<HardwareSerial>(&Serial2);
		return;
	}
	if (rx == 15 && tx == 14)
	{
		m_flag = true;
		ss_hw = new InnerSensor<HardwareSerial>(&Serial3);
		return;
	}
#elif defined(HAVE_HWSERIAL1)
	// Leonardo, Microm Yun, MKR, Zero, 101
	if (rx == 0 && tx == 1)
	{
		m_flag = true;
		ss_hw = new InnerSensor<HardwareSerial>(&Serial1);
		return;
	}
	if (rx == 13 && tx == 14)
	{
		m_flag = true;
		ss_hw = new InnerSensor<HardwareSerial>(&Serial1);
		return;
	}
#elif defined(HAVE_HWSERIAL0)
	// Uno, Nano, Mini
	if (rx == 0 && tx == 1)
	{
		m_flag = true;
		ss_hw = new InnerSensor<HardwareSerial>(&Serial);
		return;
	}
#endif

	m_flag = false;
	swSer = new SoftwareSerial(rx,tx);
	ss_sw = new InnerSensor<SoftwareSerial>(swSer);
#endif
}

void Pixetto::enableUVC(bool uvc)
{
	SS_FUNC(m_flag, enableUVC, uvc)
}

void Pixetto::begin()
{
	SS_FUNC(m_flag, begin)
}

void Pixetto::end()
{
	SS_FUNC(m_flag, end)
}

void Pixetto::flush()
{
	SS_FUNC(m_flag, flush)
}

void Pixetto::setDetectMode(bool mode)
{
	SS_FUNC(m_flag, setDetectMode, mode)
}

void Pixetto::enableFunc(Pixetto::EFunc fid)
{
	SS_FUNC(m_flag, enableFunc, fid)
}

bool Pixetto::isDetected()
{
	pinMode(m_rx, INPUT);
  	pinMode(m_tx, OUTPUT);
  
	SS_FUNC(m_flag, isDetected)
	return false;
}

int Pixetto::getFuncID()
{
	SS_FUNC(m_flag, getFuncID)
	return 0;
}

int Pixetto::getTypeID()
{
	SS_FUNC(m_flag, getTypeID)
	return 0;
}

int Pixetto::getPosX()
{
	SS_FUNC(m_flag, getPosX)
	return 0;
}

int Pixetto::getPosY()
{
	SS_FUNC(m_flag, getPosY)
	return 0;
}

int Pixetto::getH()
{
	SS_FUNC(m_flag, getH)
	return 0;
}

int Pixetto::getW()
{
	SS_FUNC(m_flag, getW)
	return 0;
}

int Pixetto::getHeight()
{
	SS_FUNC(m_flag, getH)
	return 0;
}

int Pixetto::getWidth()
{
	SS_FUNC(m_flag, getW)
	return 0;
}

int Pixetto::numObjects()
{
	SS_FUNC(m_flag, numObjects)
	return 0;
}

void Pixetto::getLanePoints(int* lx1, int* ly1, int* lx2, int* ly2, int* rx1, int* ry1, int* rx2, int* ry2)
{
	SS_FUNC(m_flag, getLanePoints, lx1, ly1, lx2, ly2, rx1, ry1, rx2, ry2)
}

void Pixetto::getEquationExpr(char *buf, int len)
{
	SS_FUNC(m_flag, getEquationExpr, buf, len)
}

float Pixetto::getEquationAnswer()
{
	SS_FUNC(m_flag, getEquationAnswer)
	return 0;
}


void Pixetto::getApriltagInfo(float* px, float* py, float* pz, int* rx, int* ry, int* rz, int* cx, int* cy)
{
	SS_FUNC(m_flag, getApriltagInfo, px, py, pz, rx, ry, rz, cx, cy)
}


float Pixetto::getApriltagField(Pixetto::EApriltagField field)
{
	SS_FUNC(m_flag, getApriltagField, field)
	return 0;
}

float Pixetto::getLanesField(Pixetto::ELanesField field)
{
	SS_FUNC(m_flag, getLanesField, field)
	return 0;
}
