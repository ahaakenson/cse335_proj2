/**
 * \file MachineAdapter.cpp
 *
 * \author Andrew Haakenson
 * 
 * Class that adapts Machine class to Canadian Experience
 */

#pragma once
#include "Drawable.h"
#include "Machine.h"
#include <memory>
#include <string>

class CTimeline;

 /**
  * Class that adapts Machine class to Canadian Experience
  */
class CMachineAdapter : public CDrawable
{
public:
	CMachineAdapter(std::wstring name);
	void Draw(Gdiplus::Graphics* graphics) override;

	/**
	 * Hit test for whether machine was clicked. Always returns false
	 * \param pos position of mouse click
	 * \return false (machine cannot be clicked)
	 */
	bool HitTest(Gdiplus::Point pos) override { return false; }
	void SetTimeline(CTimeline* timeline) override;

private:
	std::shared_ptr<CMachine> mMachine;
	CTimeline* mTimeline = nullptr;
};

