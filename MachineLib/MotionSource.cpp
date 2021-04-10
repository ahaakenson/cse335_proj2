/**
 * \file MotionSource.cpp
 *
 * \author Andrew Haakenson
 */

#include "pch.h"
#include "MotionSource.h"
#include "Cylinder.h"


/**
 * Constructor
 * \param cylinder cylinder to which this motion source belongs
 */
CMotionSource::CMotionSource(CCylinder* cylinder)
{
	mCylinder = cylinder;
}

/**
 * Sets motion sink
 * \param motionSink new motion sink
 */
void CMotionSource::SetSink(CMotionSink* motionSink)
{
	mMotionSink = motionSink;
}

/**
 * Moves the ram and hits associated motion sink
 */
void CMotionSource::DislodgeRam()
{
	if (mMotionSink != nullptr)
	{
		// TODO: Have motion sink do something
	}
}