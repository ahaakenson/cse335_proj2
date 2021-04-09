/**
 * \file CardReader.cpp
 *
 * \author Andrew Haakenson
 * 
 * Class that represents the card reader.
 */

#pragma once
#include "Component.h"
#include "Polygon.h"
#include <string>

 /**
  * Class that represents the card reader.
  */
class CCardReader : public CComponent
{
public:
	CCardReader();
	void Draw(Gdiplus::Graphics* graphics, long machineX, long machineY) override;

	/**
	 * Setter for card in the card reader
	 * \param filename file where the card image is
	 */
	void SetCard(std::wstring filename) { mCard.SetImage(filename); }

private:
	/// Polygon representing the back of the card reader
	CPolygon mBack;
	/// Polygon reprsenting the front of the card reader
	CPolygon mFront;
	/// Polygon representing the card
	CPolygon mCard;
	/// Beats per minute of the song
	long mBeatsPerMinute = 1;

};

