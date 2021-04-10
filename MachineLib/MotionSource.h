/**
 * \file MotionSource.h
 *
 * \author Andrew Haakenson
 * 
 * Class that represents a motion source
 */

#pragma once

class CCylinder;
class CMotionSink;

 /**
  * Class that represents a motion source
  */
class CMotionSource
{
public:
	CMotionSource(CCylinder* cylinder);
	/// Default constructor (disabled)
	CMotionSource() = delete;
	
	void SetSink(CMotionSink* motionSink);
	void DislodgeRam();

private:
	/// Cylinder to which this belongs
	CCylinder* mCylinder;
	/// Associated motion sink
	CMotionSink* mMotionSink = nullptr;
};

