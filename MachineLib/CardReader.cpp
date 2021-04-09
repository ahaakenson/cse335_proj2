/**
 * \file CardReader.cpp
 *
 * \author Andrew Haakenson
 */

#include "pch.h"
#include "CardReader.h"
#include <string>

using namespace std;

/// Image for the back of the card reader
const std::wstring CardReaderBackImage = L"images/card-reader-back.png";

/// Image for the front of the card reader
const std::wstring CardReaderFrontImage = L"images/card-reader-front.png";


// The card actual dimensions are 847 by 379 pixels,
// a size choosen to make the column spacing exactly
// 10 pixels. We draw it much smaller than that on the screen

/// Width to draw the card on the screen in pixels
const int CardWidth = 132;

/// Height to draw the card on the screen in pixels
const int CardLength = 297;

/// Amount of offset the center of the card so it will
/// appear at the right place relative to the card reader.
const int CardOffsetX = 126;

/// Y dimension of the offset
const int CardOffsetY = 65;

// These values are all for the underlying image. They
// can be used for find the punches.

/// Width of a card column in pixels
const int CardColumnWidth = 10;

/// Height of a card row in pixels
const int CardRowHeight = 29;

/// X offset for the first column (left side)
const int CardColumn0X = 24;

/// Y offset to the first row (0's)
/// There are actually two rows above this that can be used
const int CardRow0Y = 78;

/// Width of a punched hole
const int CardPunchWidth = 8;

/// Height of a punched hole
const int CardPunchHit = 20;

/// Any average luminance below this level is considered a punched hole
const double CardPunchLuminance = 0.1;

//
// These values are for the outputs of the card reader,
// where the tubing attaches.
//

/// Y offset to the first card reader output in pixels
const int OutputOffsetY = -92;

/// X offset to the first card reader output in pixels
const int OutputOffsetX = -35;

/// X spacing for the outputs
const double OutputSpacingX = 10.7;

/**
 * Constructor
 */
CCardReader::CCardReader()
{
    mBack.SetImage(CardReaderBackImage);
    mBack.Rectangle(-mBack.GetImageWidth() / 2, 0);

    mFront.SetImage(CardReaderFrontImage);
    mFront.Rectangle(-mFront.GetImageWidth() / 2, 0);

    mCard.Rectangle(CardOffsetX, CardOffsetY, CardLength, CardWidth);
    mCard.SetRotation(-0.25);
}


/**
 * Draws the card reader
 * \param graphics graphics context
 * \param machineX x coordinate of machine
 * \param machineY y coordinate of machine
 */
void CCardReader::Draw(Gdiplus::Graphics* graphics, long machineX, long machineY)
{
    mBack.DrawPolygon(graphics, double(machineX + GetX()), double(machineY + GetY()));
    mCard.DrawPolygon(graphics, double(machineX + GetX()), double(machineY + GetY()));
    mFront.DrawPolygon(graphics, double(machineX + GetX()), double(machineY + GetY()));
}