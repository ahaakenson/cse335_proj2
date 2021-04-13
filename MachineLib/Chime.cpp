/**
 * \file Chime.cpp
 *
 * \author Andrew Haakenson
 */

#include "pch.h"
#include "Chime.h"
#include "MotionSink.h"
#include "Polygon.h"
#include "WavChannel.h"
#include <memory>

using namespace std;

 /// The chime hammer mount image
const std::wstring ChimeMountImage = L"images/hammer-mount.png";

/// The chime hammer image
const std::wstring ChimeHammerImage = L"images/hammer.png";

/// The chime itself
const std::wstring ChimeImage = L"images/chime.png";

/// Width to draw the actual chime
const int ChimeWidth = 15;

/// Offset of the Chime relative to the origin
/// of this component X value
const double ChimeOffsetX = -18.0;

/// Offset of the Chime Y value
const double ChimeOffsetY = 5.0;

/// The location in the hammer image for the pivot point X
const double HammerPivotX = 33;

/// The location in the hammer image for the pivot point X
const double HammerPivotY = 10;

/// Amount to rotate hammer away from chime in unit rotations
const double HammerRotation = 0.08;

/// Amount to rotate hammer between frames if it's not in resting position
const double HammerRotationDelta = 0.01;

/// Offset of chime hammer in Y direction
const int HammerOffsetY = 65;

/**
 * Constructor
 * \param length length of chime
 */
CChime::CChime(int length)
{
    mMount.SetImage(ChimeMountImage);
    mMount.Rectangle(-mMount.GetImageWidth() / 2, mMount.GetImageHeight());

    mHammer.SetImage(ChimeHammerImage);
    mHammer.Rectangle(-HammerPivotX, HammerPivotY);
    mHammer.SetRotation(HammerRotation);

    mChime.SetImage(ChimeImage);
    mChime.Rectangle(-ChimeWidth / 2, 0, ChimeWidth, -length);

    mSink = make_shared<CMotionSink>();
    mSink->SetDestination(this);

    mRotation = HammerRotation;
}

/**
 * Receives motion from motion source
 */
void CChime::ReceiveMotion()
{
    mRotation = 0;
    mHammer.SetRotation(mRotation);
}

/**
 * Draws the chime in the graphics context
 * \param graphics graphics context
 * \param machineX x coordinate of machine
 * \param machineY y coordinate of machine
 */
void CChime::Draw(Gdiplus::Graphics* graphics, long machineX, long machineY)
{
    mMount.DrawPolygon(graphics, double(machineX + GetX()), double(machineY + GetY()));
    mHammer.DrawPolygon(graphics, double(machineX + GetX()), double(machineY + GetY() + HammerOffsetY));
    mChime.DrawPolygon(graphics, double(machineX + GetX()) + ChimeOffsetX, double(machineY + GetY()) + ChimeOffsetY);
    
    CalculateHammerRotation();
}

/**
 * Sets channel for motion sink to play sounds
 * \param channel Wav channel
 */
void CChime::SetAudioChannel(std::shared_ptr<CWavChannel> channel)
{
    mSink->SetChannel(channel.get());
}

/**
 * Animates hammer between hits if it is not in resting position by incrementing rotation
 */
void CChime::CalculateHammerRotation()
{
    // Slightly rotate hammer towards resting position
    mRotation = mRotation + HammerRotationDelta;

    // Resting position reached, can't rotate anymore
    if (mRotation >= HammerRotation)
    {
        mRotation = HammerRotation;
    }

    mHammer.SetRotation(mRotation);
}