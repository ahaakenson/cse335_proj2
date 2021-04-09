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

class CMachineInterpreter;

 /**
  * Class that represents the machine.
  */
class CMachineActual
{
public:
	CMachineActual();
	void DrawMachineActual(Gdiplus::Graphics* graphics);
	void SetMachineActualLocation(int x, int y);

	/**
	 * Setter for interpreter pointer
	 * \param interpreter pointer to associated interpreter
	 */
	void SetInterpreter(CMachineInterpreter* interpreter) { mInterpreter = interpreter; }
	double ComputeTime(int frame);
	void AddComponent(std::shared_ptr<CComponent> component);

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
	/// Interpreter which this machine is a part of
	CMachineInterpreter* mInterpreter = nullptr;
};

