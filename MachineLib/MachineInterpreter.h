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
#include <memory>

 /**
  * Class that holds the machine object.
  */
class CMachineInterpreter : public CMachine
{
public:
    CMachineInterpreter();
    virtual void DrawMachine(Gdiplus::Graphics* graphics) override;
    virtual void SetLocation(int x, int y) override;
private:
    /// Actual machine with components
    std::shared_ptr<CMachineActual> mMachineActual;
};


