/**
 * \file MachineAdapter.cpp
 *
 * \author Andrew Haakenson
 */


#include "pch.h"
#include "MachineAdapter.h"
#include "MachineFactory.h"
#include "Timeline.h"
#include <memory>
#include <string>

using namespace std;

/**
 * Constructor
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
	mMachine->SetMachineFrame(frame);

	auto save = graphics->Save();
	// Translate graphics to machine location and shrink the machine by half
	graphics->TranslateTransform((float)mPlacedPosition.X,
		(float)mPlacedPosition.Y);
	graphics->ScaleTransform(Scale, Scale);

	mMachine->DrawMachine(graphics);

	graphics->Restore(save);
}

void CMachineAdapter::SetTimeline(CTimeline* timeline)
{
	CDrawable::SetTimeline(timeline);

	mTimeline = timeline;
}