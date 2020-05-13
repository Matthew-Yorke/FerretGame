//*********************************************************************************************************************
//
// File: Ferret.h
//
// Description:
//    This class handles the creation and changes of a ferret object within the game. A ferret is able to turn and move
//    throughout a game scene.
//
//*********************************************************************************************************************

#ifndef Ferret_H
#define Ferret_H

#include "FerretConstants.h"
#include "BebopCore/Graphics/AnimatedSprite.h"
#include "BebopCore/Math/Vector2D.h"
#include "BebopCore/Objects/CircleObject.h"

namespace FerretGame
{
   class Ferret
   {
      //***************************************************************************************************************
      // Methods - Start
      //***************************************************************************************************************

      public:

         //************************************************************************************************************
         //
         // Method: Ferret
         //
         // Description:
         //    Constructor the sets member variables to default values.
         //
         // Arguments:
         //    aLocation - the X/Y-Coordinate of thwere the object is created on the scene.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         Ferret(const Bebop::Math::Vector2D<float> aLocation);

         //************************************************************************************************************
         //
         // Method: ~Ferret
         //
         // Description:
         //    Destructor that cleans up any allocated memory before the object is destroyed.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         ~Ferret();

         //************************************************************************************************************
         //
         // Method: GetSprite
         //
         // Description:
         //    Returns the sprite information for the ferret. 
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Return the current sprite information for the ferret.
         //
         //************************************************************************************************************
         Bebop::Graphics::AnimatedSprite* GetSprite();

         //************************************************************************************************************
         //
         // Method: Move
         //
         // Description:
         //    Updates the forward movement of the ferret by the passed in x/y change.
         //
         // Arguments:
         //    aMovement - The X/Y-Coordinate position change.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void Move(Bebop::Math::Vector2D<float> aMovement);

         //************************************************************************************************************
         //
         // Method: ChangeHeight
         //
         // Description:
         //    Updates the height of the ferret by the passed in height change.
         //
         // Arguments:
         //    aHeightChange - The height change.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void ChangeHeight(int aHeightChange);

         //************************************************************************************************************
         //
         // Method: GetHeight
         //
         // Description:
         //    Returns the current height of the ferret.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns the current height.
         //
         //************************************************************************************************************
         int GetHeight();

         //************************************************************************************************************
         //
         // Method: SetVerticalMovement
         //
         // Description:
         //    Updates the vertical movement of the ferret witht he passed in value.
         //
         // Arguments:
         //    aVerticalMovement - The vertical movement to set the ferret to.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void SetVerticalMovement(VerticalMovement aVerticalMovement);

         //************************************************************************************************************
         //
         // Method: SetVerticalMovement
         //
         // Description:
         //    Returns the current vertical movement of the ferret.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns the current vertical movement.
         //
         //************************************************************************************************************
         VerticalMovement SetVerticalMovement();

         //************************************************************************************************************
         //
         // Method: Rotate
         //
         // Description:
         //    Rotate the ferret angle using the passed in rotational change.
         //
         // Arguments:
         //    aRotationChange - The rotational change.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void Rotate(float aRotationChange);

         //************************************************************************************************************
         //
         // Method: GetAngleRadians
         //
         // Description:
         //    Returns the angle in radians of the current rotation of the ferret.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns the current rotation in radians.
         //
         //************************************************************************************************************
         float GetAngleRadians();

         //************************************************************************************************************
         //
         // Method: GetBackHitbox
         //
         // Description:
         //    Retrieveal the back hitbox of the ferret.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns a pointer to reference the back hitbox of the ferret.
         //
         //************************************************************************************************************
         Bebop::Objects::CircleObject* GetBackHitbox();

         //************************************************************************************************************
         //
         // Method: GetMiddleHitbox
         //
         // Description:
         //    Retrieveal the middle hitbox of the ferret.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns a pointer to reference the middle hitbox of the ferret.
         //
         //************************************************************************************************************
         Bebop::Objects::CircleObject* GetMiddleHitbox();

         //************************************************************************************************************
         //
         // Method: GetFrontHitbox
         //
         // Description:
         //    Retrieveal the frontal hitbox of the ferret.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns a pointer to reference the frontal hitbox of the ferret.
         //
         //************************************************************************************************************
         Bebop::Objects::CircleObject* GetFrontHitbox();

      protected:

         // There are currently no protected methods for this class.

      private:

         // There are currently no private methods for this class.

      //***************************************************************************************************************
      // Methods - End
      //***************************************************************************************************************

      //***************************************************************************************************************
      // Member Variables - Start
      //***************************************************************************************************************

      public:

         // There are currently no public member variables for this class.

      protected:

         // There are currently no protected member variables for this class.

      private:

         // The X-Coordinate and Y-Coordinate of the object's location.
         Bebop::Math::Vector2D<float> mLocation;

         // The rotation of the object in degrees.
         float mRotation;

         // The animated sprite for the ferret to be drawn.
         Bebop::Graphics::AnimatedSprite* mSprite;

         // The hitbox(circles) for the ferret to check for collisions.
         Bebop::Objects::CircleObject* mBackHitBox;
         Bebop::Objects::CircleObject* mMiddleHitBox;
         Bebop::Objects::CircleObject* mFrontHitBox;

         // The height the ferret is currently at.
         int mHeight;

         // Tracks the current vertical movement of the ferret.
         VerticalMovement mVerticalMovement;

      //***************************************************************************************************************
      // Member Variables - End
      //***************************************************************************************************************
   };
}

#endif // Definition_H TODO: Don't forget to update this.