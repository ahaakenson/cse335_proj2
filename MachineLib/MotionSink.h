/**
 * \file MotionSink.h
 *
 * \author Andrew Haakenson
 * 
 * Class that represents a motion sink
 */

#pragma once

class CWavChannel;
class CMotionSinkDestination;

 /**
  * Class that represents a motion sink
  */
class CMotionSink
{
public:
	void SetDestination(CMotionSinkDestination* destination);
	void SetChannel(CWavChannel* channel);
	void MakeSound();

private:
	/// Associated WAV channel to play sound
	CWavChannel* mWavChannel = nullptr;
	CMotionSinkDestination* mDestination = nullptr;
};

