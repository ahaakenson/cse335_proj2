/**
 * \file Tubing.h
 *
 * \author Andrew Haakenson
 * 
 * Class that describes the tubing.
 */

#pragma once
#include "Component.h"
#include "AirSinkDestination.h"
#include <memory>
#include <vector>

class CAirSource;
class CAirSink;
class CTubingPoint;

 /**
  * Class that describes the tubing.
  */
class CTubing : public CComponent, public CAirSinkDestination
{
public:
	CTubing();
	void Draw(Gdiplus::Graphics* graphics, long machineX, long machineY) override;
	void AddClamp(long x, long y, double rotation, long speed);
	
	/**
	 * Gets air source at the sending end of tube
	 * \return air source
	 */
	CAirSource* GetSource() { return mSource.get(); }

	/**
	 * Gets air sink at receiving end of tube
	 * \return air sink
	 */
	CAirSink* GetSink() { return mSink.get(); }

	void SetPressure(double pressure) override;

private:
	/// Air source on the sending end of the tube
	std::shared_ptr<CAirSource> mSource;
	/// Air sink on the receiving end of the tube
	std::shared_ptr<CAirSink> mSink;
	/// Vector of all clamps on the tube
	std::vector<std::shared_ptr<CTubingPoint>> mClamps;

};

