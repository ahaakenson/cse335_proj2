/**
 * \file MachineFactory.cpp
 *
 * \author Andrew Haakenson
 *
 * You are allowed to change this file.
 */

#include "pch.h"
#include "MachineFactory.h"
#include "MachineInterpreter.h"


using namespace std;


/**
 * Create a machine object
 * \returns Object of type CMachine
 */
std::shared_ptr<CMachine> CMachineFactory::CreateMachine()
{
    return make_shared<CMachineInterpreter>();
    //return make_shared<CMachine>();
}

