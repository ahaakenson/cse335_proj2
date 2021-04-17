/**
 * \file Chime.h
 *
 * \author Andrew Haakenson
 * 
 * Class that represents a chime
 */


#pragma once
#include "Component.h"
#include "MotionSinkDestination.h"
#include "Polygon.h"
#include "MotionSink.h"
#include <memory>

 /**
  * Class that represents a chime
  */
class CChime : public CComponent, public CMotionSinkDestination
{
public:
	CChime(int length);
	void ReceiveMotion() override;
	void Draw(Gdiplus::Graphics* graphics, long machineX, long machineY) override;

	/**
	 * Gets the motion sink
	 * \return motion sink
	 */
	CMotionSink* GetSink() { return mSink.get(); }

	void SetAudioChannel(std::shared_ptr<CWavChannel> channel) override;

	void CalculateHammerRotation();
	void IncrementFramesSinceNote();

private:
	/// chime mount
	CPolygon mMount;
	/// chime hammer
	CPolygon mHammer;
	/// chime tube
	CPolygon mChime;
	/// Associated motion sink
	std::shared_ptr<CMotionSink> mSink;
	/// Rotation of the hammer
	double mRotation;
	/// Frames since chime was struck
	int mFramesSinceNote = 60;
};

