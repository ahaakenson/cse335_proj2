/**
 * \file MachineActual.h
 *
 * \author Andrew Haakenson
 *
 * Class that represents the machine.
 */

#pragma once
#include "Component.h"
#include <vector>
#include <memory>
#include "WavPlayer.h"

class CMachineInterpreter;

 /**
  * Class that represents the machine.
  */
class CMachineActual
{
public:
	CMachineActual();
	void DrawMachineActual(Gdiplus::Graphics* graphics);
	void SetMachineActualLocation(int x, int y);
	void SetMachineActualFrame(int frame);

	/**
	 * Setter for interpreter pointer
	 * \param interpreter pointer to associated interpreter
	 */
	void SetInterpreter(CMachineInterpreter* interpreter) { mInterpreter = interpreter; }
	double ComputeTime(int frame);
	void AddComponent(std::shared_ptr<CComponent> component);

	/**
	 * Gets WAV player
	 * \return WAV player
	 */
	CWavPlayer* GetWavPlayer() { return mWavPlayer.get(); }

private:
	/// X coordinate of machine
	int mXPos = 0;
	/// Y coordinate of machine
	int mYPos = 0;
	/// Current frame of animation
	int mCurrFrame = 0;
	/// Current time
	double mTime = 0;

	/// Components in this machine
	std::vector<std::shared_ptr<CComponent> > mComponents;
	/// Interpreter which this machine is a part of
	CMachineInterpreter* mInterpreter = nullptr;

	/// WAV player for playing sounds
	std::shared_ptr<CWavPlayer> mWavPlayer;
};

