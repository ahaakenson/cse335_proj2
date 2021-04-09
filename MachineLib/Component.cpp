/**
 * \file Component.cpp
 *
 * \author Andrew Haakenson
 */


#include "pch.h"
#include "Component.h"

/**
 * Setter for component position
 * \param x new x coordinate of component
 * \param y new y coordinate of component
 */
void CComponent::SetPosition(long x, long y)
{
	mXPos = x;
	mYPos = y;
}
