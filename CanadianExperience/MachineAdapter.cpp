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
	float Scale = 0.5f;
	auto frame = mTimeline->GetCurrentFrame();
	mMachine->SetMachineFrame(mTimeline->GetCurrentFrame());

	auto save = graphics->Save();
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