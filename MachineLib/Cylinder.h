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
#include "AirSinkDestination.h"
#include <memory>

class CAirSink;
class CMotionSource;
class CMotionSink;

 /**
  * Class that represents a cylinder to hit instruments.
  */
class CCylinder : public CComponent, public CAirSinkDestination
{
public:
	CCylinder();
	void Draw(Gdiplus::Graphics* graphics, long machineX, long machineY) override;
	void SetRotation(double rotation);
	virtual void SetPressure(double pressure) override;
	/**
	 * Gets associated air sink
	 * \return air sink
	 */
	CAirSink* GetSink() { return mAirSink.get(); }

	void SetMotionSink(CMotionSink* sink);

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
	/// Maximum extension compared to cylinder's max
	double mMaxExtension = 1.0;

	/// Whether cylinder is vertical
	bool mVertical = true;
	/// Associated air sink
	std::shared_ptr<CAirSink> mAirSink;
	/// Associated motion source
	std::shared_ptr<CMotionSource> mMotionSource;
};

