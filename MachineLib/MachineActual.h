/**
 * \file MachineActual.h
 *
 * \author Andrew Haakenson
 *
 * Class that represents the machine.
 */

#pragma once
#include "Component.h"
#include <vector>
#include <memory>

 /**
  * Class that represents the machine.
  */
class CMachineActual
{
public:
	void DrawMachineActual(Gdiplus::Graphics* graphics, int x, int y);
	void SetMachineActualLocation(int x, int y);
private:
	/// X coordinate of machine
	int mXPos = 0;
	/// Y coordinate of machine
	int mYPos = 0;
	/// Current frame of animation
	int mCurrFrame = 0;
	/// Current time
	double mTime = 0;
	/// Components in this machine
	std::vector<std::shared_ptr<CComponent> > mComponents;
};

