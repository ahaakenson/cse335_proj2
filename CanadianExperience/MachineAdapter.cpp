/**
 * \file MachineAdapter.cpp
 *
 * \author Andrew Haakenson
 */


#include "pch.h"
#include "MachineAdapter.h"
#include "MachineFactory.h"
#include "Timeline.h"
#include "MachineDlg.h"
#include <memory>
#include <string>

using namespace std;

/**
 * Constructor
 * \param name machine drawable name
 */
CMachineAdapter::CMachineAdapter(wstring name) : CDrawable(name)
{
	CMachineFactory factory;
	mMachine = factory.CreateMachine();
}

/**
 * Draws machine in the graphics context
 * \param graphics graphics context
 */
void CMachineAdapter::Draw(Gdiplus::Graphics* graphics)
{
	// Amount to scale machine by in drawing
	float Scale = 0.5f;

	// Convert time to frames in 30fps to maintain the song speed
	double time = (double)mTimeline->GetCurrentFrame() / (double)mTimeline->GetFrameRate();
	int frame = int(time * 30.0);
	frame = frame - mStartFrame; // Offset current frame by start frame
	mMachine->SetMachineFrame(frame);

	auto save = graphics->Save();
	// Translate graphics to machine location and shrink the machine by half
	graphics->TranslateTransform((float)mPlacedPosition.X,
		(float)mPlacedPosition.Y);
	graphics->ScaleTransform(Scale, Scale);

	mMachine->DrawMachine(graphics);

	graphics->Restore(save);
}

/**
 * Sets associated timeline
 * \param timeline timeline which controls machine
 */
void CMachineAdapter::SetTimeline(CTimeline* timeline)
{
	CDrawable::SetTimeline(timeline);

	mTimeline = timeline;
}

/**
 * Shows dialogue box for changing machine number
 */
void CMachineAdapter::ShowMachineDialogue()
{
	CMachineDlg dlg(mMachine);
	if (dlg.DoModal() == IDOK)
	{
	}
}

/**
 * Saves machine to xml
 * \param root xml root node
 * \param machineNum position of machine in drawable vector
 */
void CMachineAdapter::SaveMachines(std::shared_ptr<xmlnode::CXmlNode> root, int machineNum)
{
	wstring attribute = L"machine" + to_wstring(machineNum) + L"num";
	// Set machine number as machine(insert machinenumber in actor)num attribute
	root->SetAttribute(attribute, mMachine->GetMachineNumber());
}

/**
 * Loads machine to xml
 * \param root xml root node
 * \param machineNum position of machine in drawable vector
 */
void CMachineAdapter::LoadMachines(std::shared_ptr<xmlnode::CXmlNode> root, int machineNum)
{
	wstring attribute = L"machine" + to_wstring(machineNum) + L"num";
	// Get the machine number from the xml file and set the machine to it
	mMachine->SetMachineNumber(root->GetAttributeIntValue(attribute, 0));
}