/**
 * \file AirSource.h
 *
 * \author Andrew Haakenson
 * 
 * Class that represents an air source
 */

#pragma once
#include "TubingPoint.h"

class CComponent;
class CAirSink;

/**
 * Class that represents an air source
 */
class CAirSource : public CTubingPoint
{
public:
    CAirSource();
    /// Copy constructor (disabled)
    CAirSource(const CAirSource&) = delete;

    /// Assignment operator (disabled)
    void operator=(const CAirSource&) = delete;
	
    void SetPressure(double pressure);
    void SetComponent(CComponent* component);
    void SetSink(CAirSink* airSink);
    void SetPosition(long x, long y) override;
private:
    /// The component which this belongs to
    CComponent* mComponent = nullptr;
    /// Associated air sink
    CAirSink* mAirSink = nullptr;
};

