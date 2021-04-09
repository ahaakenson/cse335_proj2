/**
 * \file MachineActual.cpp
 *
 * \author Andrew Haakenson
 */

#include "pch.h"
#include "MachineActual.h"

using namespace Gdiplus;

/// Frame rate for the machine.
const double FrameRate = 30.0;

/**
 * Constructor
 */
CMachineActual::CMachineActual()
{
}

/** 
 * Draws the machine by drawing all of its components
 * \param graphics graphics context to draw machine in
 */
void CMachineActual::DrawMachineActual(Graphics* graphics, int x, int y)
{

	for (auto& component : mComponents)
	{
		// TODO: FIX THESE PARAMETERS
		component->Draw(graphics, mXPos, mYPos);
	}
}

/**
 * Setter for position of the machine
 * \param x x coordinate
 * /param y y coordinate
 */
void CMachineActual::SetMachineActualLocation(int x, int y)
{
	mXPos = x;
	mYPos = y;
}

/**
 * Computes the time for a frame
 * \param frame frame to compute the current time for
 * \return current time at that frame
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