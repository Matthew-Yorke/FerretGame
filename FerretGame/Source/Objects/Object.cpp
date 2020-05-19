//*********************************************************************************************************************
//
// File: Object.cpp
//
// Description:
//    TODO: Add description.
//
//*********************************************************************************************************************

#include "Object.h"

namespace FerretGame
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
   //
   // Method: Object
   //
   // Description:
   //    TODO: Add Description.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   Object::Object()
   {
   }
   
   //******************************************************************************************************************
   //
   // Method: ~Object
   //
   // Description:
   //    TODO: Add description.
   //    
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   Object::~Object()
   {
      for (auto circleHitIter = mCircleHitboxes.begin(); circleHitIter != mCircleHitboxes.end(); ++circleHitIter)
      {
         delete circleHitIter->second;
      }

      for (auto rectangleHitIter = mRectangleHitboxes.begin(); rectangleHitIter != mRectangleHitboxes.end(); ++rectangleHitIter)
      {
         delete rectangleHitIter->second;
      }
   }

//*********************************************************************************************************************
// Public Methods - End
//*********************************************************************************************************************

//*********************************************************************************************************************
// Protected Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
   //
   // Method: GetCircleHitbox
   //
   // Description:
   //    Returns a circle hitbox if the passed in ID matches
   //
   // Arguments:
   //    aHitboxID - The ID of the hitbox.
   //
   // Return:
   //    Returns the circle hitbox that matches the passed in ID.
   //
   //******************************************************************************************************************
   Bebop::Objects::CircleObject* Object::GetCircleHitbox(const int aHitboxID)
   {
      if (mCircleHitboxes.find(aHitboxID) != mCircleHitboxes.end())
      {
         return mCircleHitboxes[aHitboxID];
      }

      return nullptr;
   }

   //******************************************************************************************************************
   //
   // Method: AddCircleHitbox
   //
   // Description:
   //    Adds a circle hitbox with the associated ID if the ID doesn't already exist.
   //
   // Arguments:
   //    aHitboxID      - The ID of the hitbox.
   //    apCircleHitbox - Pointer to the circle object being used as a circle hitbox.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Object::AddCircleHitbox(const int aHitboxID, Bebop::Objects::CircleObject* const apCircleHitbox)
   {
      if (mCircleHitboxes.find(aHitboxID) == mCircleHitboxes.end())
      {
         mCircleHitboxes.insert(std::pair<int, Bebop::Objects::CircleObject*>(aHitboxID, apCircleHitbox));
      }
   }
   
   //******************************************************************************************************************
   //
   // Method: GetRectangleHitbox
   //
   // Description:
   //    Returns a rectangle hitbox if the passed in ID matches
   //
   // Arguments:
   //    aHitboxID - The ID of the hitbox.
   //
   // Return:
   //    Returns the rectangle hitbox that matches the passed in ID.
   //
   //******************************************************************************************************************
   Bebop::Objects::RectangleObject* Object::GetRectangleHitbox(const int aHitboxID)
   {
         if (mRectangleHitboxes.find(aHitboxID) != mRectangleHitboxes.end())
      {
         return mRectangleHitboxes[aHitboxID];
      }

      return nullptr;
   }

   //******************************************************************************************************************
   //
   // Method: AddRectangleHitbox
   //
   // Description:
   //    Adds a rectangle hitbox with the associated ID if the ID doesn't already exist.
   //
   // Arguments:
   //    aHitboxID        - The ID of the hitbox.
   //    apRectangleitbox - Pointer to the rectangle object being used as a circle hitbox.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Object::AddRectangleHitbox(const int aHitboxID, Bebop::Objects::RectangleObject* const apRectangleitbox)
   {
      if (mRectangleHitboxes.find(aHitboxID) == mRectangleHitboxes.end())
      {
         mRectangleHitboxes.insert(std::pair<int, Bebop::Objects::RectangleObject*>(aHitboxID, apRectangleitbox));
      }
   }

//*********************************************************************************************************************
// Protected Methods - End
//*********************************************************************************************************************

//*********************************************************************************************************************
// Private Methods - Start
//*********************************************************************************************************************

   // There are currently no private methods for this class.

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
}