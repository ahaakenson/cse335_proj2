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
#include "XmlNode.h"
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
	/**
	 * Sets machine number in machine
	 * \param machine machine number
	 */
	void SetMachineNumber(int machine) { mMachine->SetMachineNumber(machine); }
	void ShowMachineDialogue() override;
	void SetStartFrame(int startFrame) { mStartFrame = startFrame; }
	void SaveMachines(std::shared_ptr<xmlnode::CXmlNode> root, int machineNum) override;
	void LoadMachines(std::shared_ptr<xmlnode::CXmlNode> root, int machineNum) override;

private:
	/// Associated machine
	std::shared_ptr<CMachine> mMachine;
	/// Timeline which controls machine
	CTimeline* mTimeline = nullptr;
	///  Which frame to start playing at
	int mStartFrame = 0;
};

