/**
 * \file AirSink.cpp
 *
 * \author Andrew Haakenson
 */

#include "pch.h"
#include "AirSink.h"
#include "Cylinder.h"


/**
 * Constructor
 * \param component component which this air sink will be associated with
 */
CAirSink::CAirSink(CCylinder* component)
{
	mCylinder = component;
}

 /**
  * Sets air source pressure.
  * \param pressure current pressure
  */
void CAirSink::SetPressure(int pressure)
{
	if (mCylinder != nullptr)
	{
		mCylinder->SetPressure(pressure);
	}
}
