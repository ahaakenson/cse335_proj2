/**
 * \file Instrument.h
 *
 * \author Andrew Haakenson
 * 
 * Class that represents a noise making instrument
 */

#pragma once
#include "Component.h"
#include "MotionSinkDestination.h"

 /**
  * Class that represents a noise making instrument
  */
class CInstrument : public CComponent, public CMotionSinkDestination
{
};

