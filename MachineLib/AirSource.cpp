/**
 * \file AirSource.cpp
 *
 * \author Andrew Haakenson
 */

#include "pch.h"
#include "AirSource.h"
#include "AirSink.h"

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
void CAirSource::SetPressure(int pressure)
{
	// Pass along pressure if connected to a sink
	if (mAirSink != nullptr)
	{
		mAirSink->SetPressure(pressure);
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
}