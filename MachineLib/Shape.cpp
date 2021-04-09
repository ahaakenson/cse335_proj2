/**
 * \file Shape.cpp
 *
 * \author Andrew Haakenson
 */

#include "pch.h"
#include "Shape.h"

/**
 * Draw this shape.
 * \param machineX x coordinate of machine
 * \param machineY y coordinate of machine
 */
void CShape::Draw(Gdiplus::Graphics* graphics, long machineX, long machineY)
{
	mPolygon.DrawPolygon(graphics, GetX() + machineX, GetY() + machineY);
}