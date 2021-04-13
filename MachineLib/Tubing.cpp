/**
 * \file Tubing.cpp
 *
 * \author Andrew Haakenson
 */

#include "pch.h"
#include "Tubing.h"
#include "AirSource.h"
#include "AirSink.h"
#include "TubingPoint.h"
#include <vector>
#include <memory>

using namespace Gdiplus;
using namespace std;

/// Width of the pen drawing tubes
const REAL PenWidth = 3;

/**
 * Constructor
 */
CTubing::CTubing()
{
	mSource = make_shared<CAirSource>();
	mSink = make_shared<CAirSink>(this);

	// Set position owner to false
	// Causes tubing to follow the components it's attached to
	mSource->SetPositionOwner(false);
	mSink->SetPositionOwner(false);

	mClamps.push_back(mSink);
	mClamps.push_back(mSource);
}

/**
 * Draws the tubing in the graphics context
 * \param graphics graphics context
 * \param machineX x coordinate of the machine
 * \param machineY y coordinate of the machine
 */
void CTubing::Draw(Gdiplus::Graphics* graphics, long machineX, long machineY)
{
	Point machinePoint = Point(machineX, machineY);

	Pen pen(Color::Black, PenWidth);
	// Go through each point and draw the curve between them
	for (unsigned int i = 1; i < mClamps.size(); i++)
	{
		auto startClamp = mClamps[i - 1];
		auto endClamp = mClamps[i];

		Point p1 = startClamp->GetPosition();
		Point p4 = endClamp->GetPosition();

		Point p2, p3;

		p2.X = p1.X - int(sin(startClamp->GetRotation() * M_PI * 2) * startClamp->GetSpeed());
		p2.Y = p1.Y + int(cos(startClamp->GetRotation() * M_PI * 2) * startClamp->GetSpeed());
		
		p3.X = p4.X - int(-1 * sin(endClamp->GetRotation() * M_PI * 2) * endClamp->GetSpeed());
		p3.Y = p4.Y + int(-1 * cos(endClamp->GetRotation() * M_PI * 2) * endClamp->GetSpeed());

		auto state = graphics->Save();
		// Transform graphics context to offset everything by machine position
		graphics->TranslateTransform((REAL)machinePoint.X, (REAL)machinePoint.Y);
		graphics->SetSmoothingMode(SmoothingMode::SmoothingModeHighQuality);

		graphics->DrawBezier(&pen, p1, p2, p3, p4);

		graphics->Restore(state);
	}
}

/**
 * Adds a clamp to the tube between the ends
 * \param x x coordinate
 * \param y y coordinate
 * \param rotation rotation of the clamp
 * \param speed speed of the clamp
 */
void CTubing::AddClamp(long x, long y, double rotation, long speed)
{
	auto clamp = make_shared<CTubingPoint>(x, y, rotation, speed);
	auto insertIterator = mClamps.end() - 1;
	// Insert the clamp just before the air source
	mClamps.insert(insertIterator, clamp);
}

/**
 * Receives pressure and passes it along to air source
 * \param pressure incoming pressure from 0-1
 */
void CTubing::SetPressure(double pressure)
{
	mSource->SetPressure(pressure);
}