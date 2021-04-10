/**
 * \file MotionSink.h
 *
 * \author Andrew Haakenson
 * 
 * Class that represents a motion sink
 */

#pragma once

class CWavChannel;

 /**
  * Class that represents a motion sink
  */
class CMotionSink
{
public:

	void SetChannel(CWavChannel* channel);
	void MakeSound();

private:
	/// Associated WAV channel to play sound
	CWavChannel* mWavChannel = nullptr;
};

