/**
 * \file Gauge.cpp
 *
 * \author Andrew Haakenson
 */

#include "pch.h"
#include "Gauge.h"
#include <string>


 /// Filename for the gauge image
const std::wstring GaugeImageFile = L"images/gauge.png";

/// X Offset of the input from the bottom center of the gauge in pixels
const int OffsetInputY = -6;

/// Y Offset of the input from the bottom center of the gauge in pixels
const int OffsetInputX = 13;

/// X position of the center of the gauge in pixels
const int CenterX = 0;

/// Y position of the center of the gauge in pixels
const int CenterY = -36;

/// How long the needle should be drawn
const int NeedleLength = 10;

/// Minimum rotation angle for the gauge needle in radians
const double MinAngle = 130.0 / 180.0 * M_PI;

/// Maximum rotation angle for the gauge needle in radians
const double MaxRotation = 275.0 / 180.0 * M_PI;


/**
 * Constructor
 */
CGauge::CGauge()
{
	mGauge.SetImage(GaugeImageFile);
	mGauge.Rectangle(mGauge.GetImageWidth() / 2, 0);
}

/**
 * Draws the gauge in the graphics context
 * \param graphics graphics context
 * \param machineX x coordinate of machine
 * \param machineY y coordinate of machine
 */
void CGauge::Draw(Gdiplus::Graphics* graphics, long machineX, long machineY)
{
	mGauge.DrawPolygon(graphics, machineX + GetX(), machineY + GetY());
	// TODO: Draw needle
}

/**
 * Receives pressure and passes it along
 */
void CGauge::SetPressure(double pressure)
{
	// TODO: pass along pressure
}