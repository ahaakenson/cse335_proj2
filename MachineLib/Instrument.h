/**
 * \file Instrument.h
 *
 * \author Andrew Haakenson
 * 
 * Class that represents a noise making instrument
 */

#pragma once
#include "Shape.h"
#include "MotionSinkDestination.h"
#include <memory>

class CMotionSink;

 /**
  * Class that represents a noise making instrument
  */
class CInstrument : public CShape, public CMotionSinkDestination
{
public:
	CInstrument();
	void ReceiveMotion() override;
	void SetAudioChannel(std::shared_ptr<CWavChannel> channel) override;

	/**
	 * Gets the motion sink
	 * \return motion sink
	 */
	CMotionSink* GetSink() { return mSink.get(); }


private:
	/// Associated motion sink
	std::shared_ptr<CMotionSink> mSink;
};

