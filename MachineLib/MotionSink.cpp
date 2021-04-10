/**
 * \file MotionSink.cpp
 *
 * \author Andrew Haakenson
 */

#include "pch.h"
#include "MotionSink.h"
#include "WavChannel.h"


/**
 * Sets WAV channel
 * \param channel new channel
 */
void CMotionSink::SetChannel(CWavChannel* channel)
{
	mWavChannel = channel;
}

/**
 * Plays a sound if it has a channel
 */
void CMotionSink::MakeSound()
{
	if (mWavChannel != nullptr)
	{
		mWavChannel->Play();
	}
}