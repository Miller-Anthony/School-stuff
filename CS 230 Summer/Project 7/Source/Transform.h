//------------------------------------------------------------------------------
//
// File Name:	Transform.h
// Author(s):	Doug Schilling (dschilling)
// Project:		Project 2
// Course:		CS230S19
//
// Copyright � 2019 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "Matrix2D.h"
#include "Component.h"

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward References:
//------------------------------------------------------------------------------

//typedef struct Matrix2D Matrix2D;
typedef class Transform * TransformPtr;
typedef struct Vector2D Vector2D;
typedef FILE* Stream;

//------------------------------------------------------------------------------
// Public Constants:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

// You are free to change the contents of this structure as long as you do not
//   change the public interface declared in the header.
typedef class Transform : public Component
{
public:

	// Dynamically allocate a new transform object.
// (Hint: Use calloc() to ensure that all member variables are initialized to 0.)
// (Hint: Make sure to initialize all member variables properly.)
// (Hint: Failing to initialize the scale values to non-zero values will result in invisible sprites.)
// Returns:
//	 If the memory allocation was successful,
//	   then return a pointer to the allocated memory,
//	   else return NULL.
	Transform(void);

	// Free the memory associated with a transform object.
// (Also, set the transform pointer to NULL.)
// Params:
//	 transform = Pointer to the transform pointer.
	~Transform(void);

	// Dynamically allocate a clone of an existing transform.
// (Hint: Make sure to perform a shallow copy or deep copy, as appropriate.)
// Params:
//	 other = Pointer to the component to be cloned.
// Returns:
//	 If 'other' is valid and the memory allocation was successful,
//	   then return a pointer to the cloned component,
//	   else return NULL.
	ComponentPtr Clone(void) const;

	// Read the properties of a Transform component from a file.
	// [NOTE: Read the translation value using StreamReadVector2D.]
	// [NOTE: Read the rotation value using StreamReadFloat.]
	// [NOTE: Read the scale value using StreamReadVector2D.]
	// Params:
	//	 physics = Pointer to the Transform component.
	//	 stream = Pointer to the data stream used for reading.
	void Read(Stream stream);

	// Get the transform matrix, based upon translation, rotation and scale settings.
	// (HINT: If the isDirty flag is true, then recalculate the transform matrix.)
	// Params:
	//	 transform = Pointer to the transform object.
	// Returns:
	//	 If the transform pointer is valid,
	//		then return a pointer to the component's matrix structure,
	//		else return a NULL pointer.
	Matrix2D * GetMatrix(void);

	// Get the translation of a transform component.
	// Params:
	//	 transform = Pointer to the transform object.
	// Returns:
	//	 If the transform pointer is valid,
	//		then return a pointer to the component's translation structure,
	//		else return a NULL pointer.
	const Vector2D * GetTranslation(void);

	// Get the rotation value of a transform component.
	// Params:
	//	 transform = Pointer to the transform object.
	// Returns:
	//	 If the transform pointer is valid,
	//		then return the component's rotation value (in radians),
	//		else return 0.0f.
	float GetRotation(void);

	// Get the scale of a transform component.
	// Params:
	//	 transform = Pointer to the transform object.
	// Returns:
	//	 If the transform pointer is valid,
	//		then return a pointer to the component's scale structure,
	//		else return a NULL pointer.
	const Vector2D * GetScale(void);

	// Set the translation of a transform component.
	// Params:
	//	 transform = Pointer to the transform component.
	//	 translation = Pointer to a translation vector.
	void SetTranslation(const Vector2D * translation);

	// Set the rotation of a transform component.
	// Params:
	//	 transform = Pointer to the transform component.
	//	 rotation = The rotation value (in radians).
	void SetRotation(float rotation);

	// Set the scale of a transform component.
	// Params:
	//	 transform = Pointer to the transform component.
	//	 translation = Pointer to a scale vector.
	void SetScale(const Vector2D * scale);
private:

	// The translation (or world position) of a game object.
	Vector2D	translation;

	// The rotation (or orientation) of a game object (in radians).
	float	rotation;

	// The scale (or size) of a game object.
	// (Hint: This should be initialized to (1, 1).)
	Vector2D	scale;

	// The transformation matrix resulting from concatenating the 
	//	 matrix = Translation*Rotation*Scale matrices.
	Matrix2D	matrix;

	// True if the transformation matrix needs to be recalculated.
	// (Hint: this should be initialized to true.)
	bool	isDirty;

} Transform;

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------