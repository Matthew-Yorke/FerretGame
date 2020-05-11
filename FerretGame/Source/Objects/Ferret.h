//*********************************************************************************************************************
//
// File: Ferret.h
//
// Description:
//    TODO: Add description.
//
//*********************************************************************************************************************

#ifndef Ferret_H
#define Ferret_H

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
         //    TODO: Add description.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         Ferret();

         //************************************************************************************************************
         //
         // Method: ~Ferret
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
         //    TODO: Add description.
         //
         // Arguments:
         //    aMovement - TODO: Add description.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void Move(Bebop::Math::Vector2D<float> aMovement);

         //************************************************************************************************************
         //
         // Method: Rotate
         //
         // Description:
         //    TODO: Add description.
         //
         // Arguments:
         //    aRotationChange - TODO: Add description.
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
         //    TODO: Add description.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    TODO: Add description.
         //
         //************************************************************************************************************
         float GetAngleRadians();

         Bebop::Objects::CircleObject* GetBackHitbox();
         Bebop::Objects::CircleObject* GetMiddleHitbox();
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

         Bebop::Objects::CircleObject* mBackHitBox;
         Bebop::Objects::CircleObject* mMiddleHitBox;
         Bebop::Objects::CircleObject* mFrontHitBox;

      //***************************************************************************************************************
      // Member Variables - End
      //***************************************************************************************************************
   };
}

#endif // Definition_H TODO: Don't forget to update this.