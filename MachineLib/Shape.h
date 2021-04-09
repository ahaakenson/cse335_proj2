/**
 * \file Shape.h
 *
 * \author Andrew Haakenson
 *
 * Class that represents a shape.
 */

#pragma once
#include "Component.h"
#include "Polygon.h"
#include <string>

 /**
  * Class that represents a shape.
  */
class CShape : public CComponent
{
public:
	/**
	 * Create a rectangle
	 * \param x Left side X
	 * \param y Bottom left Y
	 * \param wid Width of the rectangle. If not supplied, use an image width
	 * \param hit Height of the rectangle. If not supplied, use an image height
	 */
	void Rectangle(int x, int y, int wid = 0, int hit = 0) { mPolygon.Rectangle(x, y, wid, hit); }

	/**
	 * Set an image we will use as a texture for the polygon
	 * \param filename Image filename
	 */
	void SetImage(std::wstring filename) { mPolygon.SetImage(filename); }

	/**
	 * Get the width of any set image for this polygon. This may not be
	 * the width we actually draw, but is the size of the polygon itself.
	 * @return Width in pixels
	*/
	int GetImageWidth() { return mPolygon.GetImageWidth(); }

	/**
	 * Setter for polygon color
	 * \param color color for polygon
	 */
	void SetColor(Gdiplus::Color color) { mPolygon.SetColor(color); }

	void Draw(Gdiplus::Graphics* graphics, long machineX, long machineY) override;

private:
	CPolygon mPolygon;
};

