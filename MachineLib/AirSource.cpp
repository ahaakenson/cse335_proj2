/**
 * \file AirSource.cpp
 *
 * \author Andrew Haakenson
 */

#include "pch.h"
#include "AirSource.h"
#include "AirSink.h"

using namespace Gdiplus;

/// How much the tubing stiffens when pressure passes through it in pixels
const double TubingStiffness = 5;

/**
 * Constructor
 */
CAirSource::CAirSource()
{

}

/**
 * Sets air source pressure.
 * \param pressure current pressure
 */
void CAirSource::SetPressure(double pressure)
{
	// Calculate new speed based on tubing stiffness
	long speed = GetSpeed() + TubingStiffness * pressure;
	SetCurrentSpeed(speed);
	// Pass along pressure if connected to a sink
	if (mAirSink != nullptr)
	{
		mAirSink->SetPressure(pressure);
		mAirSink->SetCurrentSpeed(speed);
	}
}

/**
 * Sets component pointer
 * \param component component which this air source belongs to
 */
void CAirSource::SetComponent(CComponent* component)
{
	mComponent = component;
}

/**
 * Sets air sink pointer
 * \param airSink air sink pointer
 */
void CAirSource::SetSink(CAirSink* airSink)
{
	mAirSink = airSink;

	// Air source dictates position of connection
	if (GetPositionOwner())
	{
		Point position = GetPosition();
		mAirSink->SetPosition(position.X, position.Y);
	}
	// Air sink dictates position of connection
	else
	{
		Point position = airSink->GetPosition();
		SetPosition(position.X, position.Y);
	}
	
}

/**
 * Sets position
 * \param x x coordinate
 * \param y y coordinate
 */
void CAirSource::SetPosition(long x, long y)
{
	CTubingPoint::SetPosition(x, y);

	// Makes associated sink match position if it exists
	if (mAirSink != nullptr)
	{
		mAirSink->SetPosition(x, y);
	}
}