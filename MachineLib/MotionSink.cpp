/**
 * \file MotionSink.cpp
 *
 * \author Andrew Haakenson
 */

#include "pch.h"
#include "MotionSink.h"
#include "WavChannel.h"
#include "MotionSinkDestination.h"

/**
 * Sets WAV channel
 * \param channel new channel
 */
void CMotionSink::SetChannel(CWavChannel* channel)
{
	mWavChannel = channel;
}

/**
 * Sets associated component pointer
 * \param destination new component
 */
void CMotionSink::SetDestination(CMotionSinkDestination* destination)
{
	mDestination = destination;
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
	if (mDestination != nullptr)
	{
		mDestination->ReceiveMotion();
	}
}