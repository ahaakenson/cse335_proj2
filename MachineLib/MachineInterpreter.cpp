/**
 * \file MachineInterpreter.cpp
 *
 * \author Andrew Haakenson
 */

#include "pch.h"
#include "MachineInterpreter.h"
#include "MachineActual1Factory.h"
#include "MachineActual2Factory.h"

using namespace Gdiplus;

/**
 * Constructor
 */
CMachineInterpreter::CMachineInterpreter()
{
	SetMachineNumber(1);
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

/**
 * Setter for machine number
 * \param machineNumber number to set machine to
 */
void CMachineInterpreter::SetMachineNumber(int machineNumber)
{
	// Make sure number is only 1 or 2
	if (machineNumber > 0 && machineNumber < 3)
	{
		CMachine::SetMachineNumber(machineNumber);
		switch (machineNumber)
		{
			case 1:
			{
				CMachineActual1Factory factory;
				mMachineActual = factory.CreateMachine();
				break;
			}

			case 2:
			{
				CMachineActual2Factory factory;
				mMachineActual = factory.CreateMachine();
				break;
			}
		}

		mMachineActual->SetInterpreter(this);
	}
}