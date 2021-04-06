/**
 * \file MachineInterpreter.h
 *
 * \author Andrew Haakenson
 *
 * Class that holds the machine object.
 */

#pragma once

#include "Machine.h"
#include "MachineActual.h"

 /**
  * Class that holds the machine object.
  */
class CMachineInterpreter : public CMachine
{
public:
    virtual void DrawMachine(Gdiplus::Graphics* graphics) override;
    virtual void SetLocation(int x, int y) override;
private:
    /// Actual machine with components
    CMachineActual mMachineActual;
};


