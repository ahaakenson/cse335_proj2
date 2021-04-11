/**
 * \file MotionSinkDestination.h
 *
 * \author Andrew Haakenson
 * 
 * Interface class for motion sink destinations
 */

#pragma once
#include <memory>

class CWavChannel;

 /**
  * Interface class for motion sink destinations
  */
class CMotionSinkDestination
{
public:
	/**
	 * Pure virtual function for receiving motion from the motion sink
	 */
	virtual void ReceiveMotion() = 0;
	
	/**
	 * Pure virtual function for setting Wav channel
	 * \param channel Wav channel
	 */
	virtual void SetAudioChannel(std::shared_ptr<CWavChannel> channel) = 0;
};

