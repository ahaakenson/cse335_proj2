/**
 * \file AirSink.h
 *
 * \author Andrew Haakenson
 * 
 * Class that represents an air sink
 */

#pragma once
#include "TubingPoint.h"

class CCylinder;

 /**
  * Class that represents an air sink
  */
class CAirSink : public CTubingPoint
{
public:
    CAirSink(CCylinder* component);
    /// Copy constructor (disabled)
    CAirSink(const CAirSink&) = delete;

    /// Assignment operator (disabled)
    void operator=(const CAirSink&) = delete;

	void SetPressure(int pressure);

private:
    CCylinder* mCylinder = nullptr;
};

