/**
 * \file TubingPoint.h
 *
 * \author Andrew Haakenson
 * 
 * Class that represents a point holding up the tube
 */

#pragma once

 /**
  * Class that represents a point holding up the tube
  */
class CTubingPoint
{
public:


private:
	/// Position in the machine
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);
	/// Rotation of the point
	double mRotation = 0.0;
	/// Speed of curvature
	double mSpeed = 100;
};

