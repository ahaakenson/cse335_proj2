/**
 * \file Component.h
 *
 * \author Andrew Haakenson
 *
 * Class that represents a component in a machine.
 */

#pragma once

class CMachineActual;

 /**
  * Class that represents a component in a machine.
  */
class CComponent
{
public:
	/**
	 * Setter for current time
	 * \param time Current time
	 */
	virtual void SetTime(double time) { mTime = time; }

	/**
	 * Draw function for component.  Pure virtual
	 * \param graphics graphics context to draw in
	 * \param machineX x coordinate of machine
	 * \param machineY y coordinate of machine
	 */
	virtual void Draw(Gdiplus::Graphics* graphics, long machineX, long machineY) = 0;

	/**
	 * Setter for machine pointer
	 * \param machine pointer to machine this component belongs to
	 */
	void SetMachine(CMachineActual* machine) { mMachineActual = machine; }

	void SetPosition(long x, long y);

	/**
	 * Getter for x position of component
	 * \return x position
	 */
	long GetX() { return mXPos; }

	/**
	 * Getter for y position of component
	 * \return y position
	 */
	long GetY() { return mYPos; }

private:
	/// X coordinate of component
	long mXPos = 0;
	/// Y coordinate of component
	long mYPos = 0;
	/// Current time
	double mTime = 0;
	/// Machine which this component is a part of
	CMachineActual* mMachineActual = nullptr;

};

