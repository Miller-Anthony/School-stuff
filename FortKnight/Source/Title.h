//------------------------------------------------------------------------------
//
// File Name:	Title.h
// Author(s):	Akshat Madan
// Project:		Knightmare
// Course:		GAM150
//
// Copyright � 2019 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "Objects.h"

//------------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
	/* Assume C declarations for C++ */
#endif

//------------------------------------------------------------------------------
// Forward References:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Consts:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Load the resources associated with the Level1 game state.
void TitleLoad();

// Initialize the memory associated with the Level1 game state.
void TitleInit();

// Update the Level1 game state.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
void TitleUpdate(float dt);

// Shutdown any memory associated with the Level1 game state.
void TitleShutdown();

// Unload the resources associated with the Level1 game state.
void TitleUnload();

/*----------------------------------------------------------------------------*/

#ifdef __cplusplus
}                       /* End of extern "C" { */
#endif

