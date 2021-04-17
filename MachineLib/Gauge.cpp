/**
 * \file Gauge.cpp
 *
 * \author Andrew Haakenson
 */

#include "pch.h"
#include "Gauge.h"
#include "AirSink.h"
#include "AirSource.h"
#include <string>
#include <memory>

using namespace std;
using namespace Gdiplus;

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

/// Width of needle pen in pixels
const int NeedleWidth = 2;

/// Minimum rotation angle for the gauge needle in radians
const double MinAngle = 40.0 / 180.0 * M_PI;

/// Maximum rotation angle for the gauge needle in radians
const double MaxRotation = 320.0 / 180.0 * M_PI;


/**
 * Constructor
 */
CGauge::CGauge()
{
	// Set up the polygon to draw the gauge image
	mGauge.SetImage(GaugeImageFile);
	mGauge.Rectangle(-mGauge.GetImageWidth() / 2, 0);

	// Set up air source and sink
	mSink = make_shared<CAirSink>(this);
	mSource = make_shared<CAirSource>();
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
	
	double theta = MaxRotation - (MaxRotation - MinAngle) * mRotation; // rotation of needle in radians
	// Needle length in x direction
	double xOffset = sin(theta) * NeedleLength;
	// Needle length in y direction
	double yOffset = cos(theta) * NeedleLength;

	// Center of the gauge
	Point needleOrigin = Point(GetX() + machineX + CenterX, GetY() + machineY + CenterY);
	// End of the needle
	Point needleEnd = Point(GetX() + machineX + CenterX + (int)xOffset, GetY() + machineY + CenterY + (int)yOffset);

	Pen pen(Color::Red, NeedleWidth);
	graphics->DrawLine(&pen, needleOrigin, needleEnd);
}

/**
 * Receives pressure and passes it along
 * \param pressure incoming pressure
 */
void CGauge::SetPressure(double pressure)
{
	mRotation = pressure;
	mSource->SetPressure(pressure);
}

/**
 * Sets position of gauge and its source and sink
 * \param x x coordinate
 * \param y y coordinate
 */
void CGauge::SetPosition(long x, long y)
{
	CComponent::SetPosition(x, y);

	mSink->SetPosition(x - OffsetInputX, y + OffsetInputY);
	mSource->SetPosition(x + OffsetInputX, y + OffsetInputY);
}