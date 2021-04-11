/**
 * \file AirSinkDestination.h
 *
 * \author Andrew Haakenson
 * 
 * Interface class representing destination of air sink
 */

#pragma once

 /**
  * Interface class representing destination of air sink
  */
class CAirSinkDestination
{
public:
	/**
	 * Pure virtual function for setting pressure at destination
	 * \param pressure pressure going to the air sink
	 */
	virtual void SetPressure(double pressure) = 0;
};

