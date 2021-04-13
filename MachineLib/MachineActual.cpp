/**
 * \file MachineActual.cpp
 *
 * \author Andrew Haakenson
 */

#include "pch.h"
#include "MachineActual.h"
#include "WavPlayer.h"
#include <memory>

using namespace Gdiplus;
using namespace std;

/// Frame rate for the machine.
const double FrameRate = 30.0;

/**
 * Constructor
 */
CMachineActual::CMachineActual()
{
	mWavPlayer = make_shared<CWavPlayer>();
}

/** 
 * Draws the machine by drawing all of its components
 * \param graphics graphics context to draw machine in
 */
void CMachineActual::DrawMachineActual(Graphics* graphics)
{

	for (auto& component : mComponents)
	{
		component->Draw(graphics, mXPos, mYPos);
	}
}

/**
 * Setter for position of the machine
 * \param x x coordinate
 * \param y y coordinate
 */
void CMachineActual::SetMachineActualLocation(int x, int y)
{
	mXPos = x;
	mYPos = y;
}

/**
 * Computes the time for a frame
 * \param frame frame to compute the current time for
 * \return current time at that frame in seconds
 */
double CMachineActual::ComputeTime(int frame)
{
	return frame / FrameRate;
}

/**
 * Adds a component to the machine
 * \param component Component to add to the machine
 */
void CMachineActual::AddComponent(std::shared_ptr<CComponent> component)
{
	// Set both ends of the composition
	component->SetMachine(this);
	mComponents.push_back(component);
}

/**
 * Setter for current frame
 * \param frame current frame
 */
void CMachineActual::SetMachineActualFrame(int frame)
{
	mCurrFrame = frame;
	mTime = ComputeTime(frame);
	// Update the time for all of the components
	for (auto& component : mComponents)
	{
		component->SetTime(mTime);
	}
}