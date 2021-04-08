/**
 * \file MachineActualFactory.h
 *
 * \author Andrew Haakenson
 *
 * Factory which produces a MachineActual with components
 */

#pragma once

#include "MachineFactory.h"
#include <memory>

class CMachineActual;

/**
 * Factory which produces a MachineActual with components
 */
class CMachineActual1Factory : public CMachineFactory
{
public:
	/**
	* Constructor
	*/
	CMachineActual1Factory() {}

	std::shared_ptr<CMachineActual> CreateMachine();
};

