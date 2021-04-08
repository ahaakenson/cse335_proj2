/**
 * \file MachineActual2Factory.h
 *
 * \author Andrew Haakenson
 *
 * Factory which produces a MachineActual with components
 */

#pragma once
#include "MachineFactory.h"

class CMachineActual;

 /**
  * Factory which produces a MachineActual with components
  */
class CMachineActual2Factory : public CMachineFactory
{
public:
	/**
	* Constructor
	*/
	CMachineActual2Factory() {}

	std::shared_ptr<CMachineActual> CreateMachine();
};

