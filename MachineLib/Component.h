/**
 * \file Component.h
 *
 * \author Andrew Haakenson
 *
 * Class that represents a component in a machine.
 */

#pragma once

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
	void SetTime(double time) { mTime = time; }
	void Draw(Gdiplus::Graphics* graphics, int x, int y, int machineX, int machineY);
private:
	/// X coordinate of component
	int mXPos = 0;
	/// Y coordinate of component
	int mYPos = 0;
	/// Current time
	double mTime = 0;
};

