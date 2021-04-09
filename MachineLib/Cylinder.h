/**
 * \file Cylinder.h
 *
 * \author Andrew Haakenson
 * 
 * Class that represents a cylinder to hit instruments.
 */


#pragma once
#include "Component.h"
#include "Polygon.h"

 /**
  * Class that represents a cylinder to hit instruments.
  */
class CCylinder : public CComponent
{
public:
	CCylinder();
	void Draw(Gdiplus::Graphics* graphics, long machineX, long machineY) override;
	void SetRotation(double rotation);

private:
	/// Polygon for cylinder mount
	CPolygon mMount;
	/// Polygon for cylinder ram
	CPolygon mRam;
	/// Polygon for cylinder
	CPolygon mCylinder;
	/// How extended ram currently is
	double mRamPosition = 0.0;
	/// Rotation of cylinder
	double mRotation = 0.0;
};

