/**
 * \file MachineActual.cpp
 *
 * \author Andrew Haakenson
 */

#include "pch.h"
#include "MachineActual.h"

using namespace Gdiplus;

/**
 * Constructor
 * \param machineNumber number of this machine
 */
CMachineActual::CMachineActual(int machineNumber)
{
	mMachineNumber = machineNumber;
}

/** 
 * Draws the machine by drawing all of its components
 */
void CMachineActual::DrawMachineActual(Graphics* graphics, int x, int y)
{

	for (auto& component : mComponents)
	{
		// TODO: FIX THESE PARAMETERS
		component->Draw(graphics, 0, 0, mXPos, mYPos);
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