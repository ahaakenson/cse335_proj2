/**
 * \file TubingPoint.cpp
 *
 * \author Andrew Haakenson
 */

#include "pch.h"
#include "TubingPoint.h"

using namespace Gdiplus;

/**
 * Default constructor
 */
CTubingPoint::CTubingPoint()
{

}

/**
 * Constructor
 * \param x x coordinate
 * \param y y coordinate
 * \param rotation clamp rotation
 * \param speed clamp speed
 */
CTubingPoint::CTubingPoint(long x, long y, double rotation, long speed) :
	mRotation(rotation), mSpeed(speed)
{
	mPosition = Point(x, y);
}

/**
 * Sets position
 * \param x x coordinate
 * \param y y coordinate
 */
void CTubingPoint::SetPosition(long x, long y)
{
	mPosition = Point(x, y);
}

/**
 * Sets speed
 * \param speed new speed
 */
void CTubingPoint::SetSpeed(long speed)
{
	mSpeed = speed;
}