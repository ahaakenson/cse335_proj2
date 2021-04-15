/**
 * \file MachineAdapter.cpp
 *
 * \author Andrew Haakenson
 */


#include "pch.h"
#include "MachineAdapter.h"
#include "MachineFactory.h"
#include <memory>
#include <string>

using namespace std;

/**
 * Constructor
 */
CMachineAdapter::CMachineAdapter(wstring name) : CDrawable(name)
{
	CMachineFactory factory;
	mMachine = factory.CreateMachine();
}

/**
 * Draws machine in the graphics context
 * \param graphics graphics context
 */
void CMachineAdapter::Draw(Gdiplus::Graphics* graphics)
{
	mMachine->SetLocation(mPlacedPosition.X, mPlacedPosition.Y);
	mMachine->DrawMachine(graphics);
}