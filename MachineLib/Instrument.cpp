/**
 * \file Instrument.cpp
 *
 * \author Andrew Haakenson
 */

#include "pch.h"
#include "Instrument.h"
#include "MotionSink.h"
#include <memory>

using namespace std;

/**
 * Constructor
 */
CInstrument::CInstrument()
{
	mSink = make_shared<CMotionSink>();
	mSink->SetDestination(this);
}

/**
 * Receives motion from motion sink
 */
void CInstrument::ReceiveMotion()
{

}

/**
 * Sets associated Wav channel with motion sink
 * \param channel Wav channel
 */
void CInstrument::SetAudioChannel(std::shared_ptr<CWavChannel> channel)
{
	mSink->SetChannel(channel.get());
}