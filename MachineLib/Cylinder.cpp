/**
 * \file Cylinder.cpp
 *
 * \author Andrew Haakenson
 */

#include "pch.h"
#include "Cylinder.h"
#include "AirSink.h"
#include "MotionSource.h"
#include "MotionSink.h"
#include <memory>

using namespace std;

 /// Cylinder base image
const std::wstring CylinderBaseImage = L"images/cylinder-base.png";

/// Cylinder body image
const std::wstring CylinderBodyImage = L"images/cylinder.png";

/// Cylinder ram image
const std::wstring CylinderRamImage = L"images/cylinder-ram.png";

/// The maximum pixels to move the cylinder ram when enabled
const int CylinderMaxExtent = 44;

/// Angle from bottom center of the cylinder
/// to the tubing connector in rotations
const double ConnectorAngle = -0.17;

/// Distance from bottom center of the cylinder to the tubing connector
const double ConnectorDistance = 24.5;

/**
 * Constructor
 */
CCylinder::CCylinder()
{
    mMount.SetImage(CylinderBaseImage);
    mMount.Rectangle(-mMount.GetImageWidth() / 2, 0);

    mCylinder.SetImage(CylinderBodyImage);
    mCylinder.Rectangle(-mCylinder.GetImageWidth() / 2, 0);

    mRam.SetImage(CylinderRamImage);
    mRam.Rectangle(-mCylinder.GetImageWidth() / 2, 0);

    mAirSink = make_shared<CAirSink>(this);
    mMotionSource = make_shared<CMotionSource>(this);
}


/**
 * Draws the cylinder in graphics context
 * \param graphics graphics context
 * \param machineX x coordinate of machine
 * \param machineY y coordinate of machine
 */
void CCylinder::Draw(Gdiplus::Graphics* graphics, long machineX, long machineY)
{
    mMount.DrawPolygon(graphics, double(machineX + GetX()), double(machineY + GetY()));

    double theta = 2 * M_PI * (mRotation); // rotation in radians
    // How extended ram is in x direction
    double xOffset = sin(theta) * (double)CylinderMaxExtent * mMaxExtension *  mRamPosition;
    // How extended ram is in y direction
    double yOffset = cos(theta) * (double)CylinderMaxExtent * mMaxExtension * mRamPosition;
    // Switch signs since lower pixel number mean higher on screen
    yOffset = yOffset * -1;
    mRam.DrawPolygon(graphics, double(machineX + GetX()) + xOffset, double(machineY + GetY()) + yOffset);

    mCylinder.DrawPolygon(graphics, double(machineX + GetX()), double(machineY + GetY()));
}

/**
 * Sets rotation of the cylinder
 * \param rotation Rotation of the cylinder between 0-1
 */
void CCylinder::SetRotation(double rotation)
{
    mMount.SetRotation(rotation);
    mRam.SetRotation(rotation);
    mCylinder.SetRotation(rotation);
    mRotation = rotation;
}

/**
 * Sets pressure of cylinder and moves ram
 * \param pressure pressure from air source
 */
void CCylinder::SetPressure(double pressure)
{
    mRamPosition = pressure;

    // Max pressure, strike the motion sink
    if (pressure == 1.0)
    {
        mMotionSource->DislodgeRam();
    }
}

/**
 * Associates connected motion source with new motion sink
 * \param sink motion sink
 */
void CCylinder::SetMotionSink(CMotionSink* sink)
{
    mMotionSource->SetSink(sink);
}