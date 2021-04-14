/**
 * \file Gauge.h
 *
 * \author Andrew Haakenson
 * 
 * Class that represents an air gauge
 */

#pragma once
#include "Component.h"
#include "AirSinkDestination.h"
#include "Polygon.h"

 /**
  * Class that represents an air gauge
  */
class CGauge : public CComponent, public CAirSinkDestination
{
public:
	CGauge();
	void Draw(Gdiplus::Graphics* graphics, long machineX, long machineY) override;
	void SetPressure(double pressure) override;
private:
	/// Image of the gauge
	CPolygon mGauge;
};

