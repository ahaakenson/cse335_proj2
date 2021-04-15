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
#include <memory>

class CAirSink;
class CAirSource;

 /**
  * Class that represents an air gauge
  */
class CGauge : public CComponent, public CAirSinkDestination
{
public:
	CGauge();
	void Draw(Gdiplus::Graphics* graphics, long machineX, long machineY) override;
	void SetPressure(double pressure) override;
	void SetPosition(long x, long y) override;

	/**
	 * Gets associated air sink
	 * \return air sink
	 */
	CAirSink* GetSink() { return mSink.get(); }

	/**
	 * Gets associated air source
	 * \return air source
	 */
	CAirSource* GetSource() { return mSource.get(); }
private:
	/// Image of the gauge
	CPolygon mGauge;
	/// Associated air sink
	std::shared_ptr<CAirSink> mSink;
	/// Associated air source
	std::shared_ptr<CAirSource> mSource;
	/// Current needle rotation
	double mRotation = 0.0;
};

