/**
 * \file TubingPoint.h
 *
 * \author Andrew Haakenson
 * 
 * Class that represents a point holding up the tube
 */

#pragma once

 /**
  * Class that represents a point holding up the tube
  */
class CTubingPoint
{
public:
	CTubingPoint(long x, long y, double rotation, long speed);
	CTubingPoint();
	virtual void SetPosition(long x, long y);

	/**
	 * Sets speed
	 * \param speed new speed
	 */
	void SetSpeed(long speed) { mSpeed = speed; }

	/**
	 * Sets position owner
	 * \param owner whether tubing point owns that position
	 */
	void SetPositionOwner(bool owner) { mPositionOwner = owner; }

	/**
	 * Sets rotation
	 * \param rotation new rotation
	 */
	void SetRotation(double rotation) { mRotation = rotation; }

	/**
	 * Gets position owner boolean
	 * \return position owner boolean
	 */
	bool GetPositionOwner() { return mPositionOwner; }

	/**
	 * Gets point speed
	 * \return speed
	 */
	long GetSpeed() { return mSpeed; }

	/**
	 * Gets point rotation
	 * \return rotation
	 */
	double GetRotation() { return mRotation; }

	/**
	 * Gets position of tubing point
	 * \return position
	 */
	Gdiplus::Point GetPosition() { return mPosition; }

private:
	/// Position in the machine
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);
	/// Rotation of the point
	double mRotation = 0.0;
	/// Speed of curvature
	long mSpeed = 50;
	/// Whether this point dictates the position of associated source/sink
	/// Tubing sources/sinks will never be position owners- they follow other components
	bool mPositionOwner = true;
};

