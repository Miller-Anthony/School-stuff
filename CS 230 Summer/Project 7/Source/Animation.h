//------------------------------------------------------------------------------
//
// File Name:	Animation.h
// Author(s):	Doug Schilling (dschilling)
// Project:		Project 3
// Course:		CS230S19
//
// Copyright � 2019 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "Component.h"

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward References:
//------------------------------------------------------------------------------

typedef class GameObject *GameObjectPtr;
typedef class Animation *AnimationPtr;
typedef class Sprite *SpritePtr;
typedef FILE* Stream;

//------------------------------------------------------------------------------
// Public Consts:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

// An example of the structure to be defined in Animation.c.
// You are free to change the contents of this structure as long as you do not
//   change the public interface declared in the header.
typedef class Animation : public Component
{
public:

	Animation(void);

	// Dynamically allocate a clone of an existing animation.
// (Hint: Perform a shallow copy of the member variables.)
// Params:
//	 other = Pointer to the component to be cloned.
// Returns:
//	 If 'other' is valid and the memory allocation was successful,
//	   then return a pointer to the cloned component,
//	   else return NULL.
	ComponentPtr Clone(void) const;

	// Read the properties of an Animation component from a file.
// [NOTE: Read the integer values for frameIndex and frameCount.]
// [NOTE: Read the float values for frameDelay and frameDuration.]
// [NOTE: Read the boolean values for isRunning and isLooping.]
// Params:
//	 animation = Pointer to the Animation component.
//	 stream = Pointer to the data stream used for reading.
	void Read(Stream stream);


	// Set the parent game object for an animation component.
	// Params:
	//	 animation = Pointer to the animation component.
	//	 parent = Pointer to the parent game object.
	void SetParent(GameObjectPtr parent);

	// Play a simple animation sequence (0 .. frameCount).
	// (Hint: Make sure to initialize all variables, except for "sprite".)
	// Params:
	//	 animation = Pointer to the animation object.
	//	 frameCount = The number of frames in the sequence.
	//	 frameDuration = The amount of time to wait between frames (in seconds).
	//	 isLooping = True if the animation loops, false otherwise.
	void Play(int frameCount, float frameDuration, bool isLooping);

	// Play a complex animation sequence (any frame/any delay).
	// (Hint: Make sure to initialize all variables, except for "sprite".)
	// Params:
	//	 animation = Pointer to the animation object.
	//	 sequence = Pointer to the animation sequence to be played.
	//void AnimationPlaySequence(AnimationPtr animation, AnimationSequencePtr sequence);

	// Update the animation.
	// Params:
	//	 animation = Pointer to the animation object.
	//	 dt = Change in time (in seconds) since the last game loop.
	void Update(float dt);

	// Determine if the animation has reached the end of its sequence.
	// Params:
	//	 animation = Pointer to the animation object.
	// Returns:
	//	 If the animation pointer is valid,
	//		then return the value in isDone,
	//		else return false.
	bool IsDone(void);

private:
	// Pointer to the parent game object associated with the animation.
	GameObjectPtr parent;

	// The current frame being displayed.
	unsigned int frameIndex;

	// The maximum number of frames in the sequence.
	unsigned int frameCount;

	// The time remaining for the current frame.
	float frameDelay;

	// The amount of time to display each successive frame.
	float frameDuration;

	// True if the animation is running; false if the animation has stopped.
	bool isRunning;

	// True if the animation loops back to the beginning.
	bool isLooping;

	// True if the end of the animation has been reached, false otherwise.
	// (Hint: This should be true for only one game loop.)
	bool isDone;

	// The animation sequence currently being played, if any.
	//AnimationSequencePtr	sequence;

	void FrameAdvance(void);
} Animation;

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------



/*----------------------------------------------------------------------------*/
