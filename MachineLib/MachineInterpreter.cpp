/**
 * \file MachineInterpreter.cpp
 *
 * \author Andrew Haakenson
 */

#include "pch.h"
#include "MachineInterpreter.h"
#include "MachineActual1Factory.h"

using namespace Gdiplus;

/**
 * Constructor
 */
CMachineInterpreter::CMachineInterpreter()
{
	CMachineActual1Factory factory;
	mMachineActual = factory.CreateMachine();
}

/**
* Draw the machine at the currently specified location
* \param graphics GDI+ Graphics object
*/
void CMachineInterpreter::DrawMachine(Graphics* graphics)
{
	// TODO: CHANGE PARAMETERS OF DRAW COORDINATES
	mMachineActual->DrawMachineActual(graphics, 0, 0);
}

/**
* Sets location of the machine
* \param x x coordinate
* \param y y coordinate
*/
void CMachineInterpreter::SetLocation(int x, int y)
{
	mMachineActual->SetMachineActualLocation(x, y);
}