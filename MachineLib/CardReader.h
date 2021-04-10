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
#include "AirSource.h"
#include <string>
#include <vector>

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

	void SetTime(double time) override;
	void UpdateColumn(double time);
	bool CCardReader::IsPunched(int column, int row);
	
	/**
	 * Get an air source.
	 * @param i Source index 0-9
	 * @return Pointer to CAirSource object.
     */
	std::shared_ptr<CAirSource> GetSource(int i) { return mSources[i]; }

private:
	/// Polygon representing the back of the card reader
	CPolygon mBack;
	/// Polygon reprsenting the front of the card reader
	CPolygon mFront;
	/// Polygon representing the card
	CPolygon mCard;
	/// Beats per minute of the song
	long mBeatsPerMinute = 180;
	/// Current card column
	long mColumn = 0;
	/// Air sources originating at card reader slots
	std::vector<std::shared_ptr<CAirSource>> mSources;
};

