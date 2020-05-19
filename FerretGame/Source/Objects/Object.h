//*********************************************************************************************************************
//
// File: Object.h
//
// Description:
//    TODO: Add description.
//
//*********************************************************************************************************************

#ifndef Object_H
#define Object_H

#include <map>
#include "../../../Bebop/Includes/BebopCore/Objects/CircleObject.h"
#include "../../../Bebop/Includes/BebopCore/Objects/RectangleObject.h"

namespace FerretGame
{
   // TODO: Change class name.
   class Object
   {
      //***************************************************************************************************************
      // Methods - Start
      //***************************************************************************************************************

      public:

         //************************************************************************************************************
         //
         // Method: Object
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
         Object();

         //************************************************************************************************************
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
         //************************************************************************************************************
         virtual ~Object();

      protected:

         //************************************************************************************************************
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
         //************************************************************************************************************
         Bebop::Objects::CircleObject* GetCircleHitbox(const int aHitboxID);

         //************************************************************************************************************
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
         //************************************************************************************************************
         void AddCircleHitbox(const int aHitboxID, Bebop::Objects::CircleObject* const apCircleHitbox);

         //************************************************************************************************************
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
         //************************************************************************************************************
         Bebop::Objects::RectangleObject* GetRectangleHitbox(const int aHitboxID);

         //************************************************************************************************************
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
         //************************************************************************************************************
         void AddRectangleHitbox(const int aHitboxID, Bebop::Objects::RectangleObject* const apRectangleitbox);

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

         // Vector of circular hitboxes.
         std::map<int, Bebop::Objects::CircleObject*> mCircleHitboxes;

         // Vector of rectangular hitboxes.
         std::map<int, Bebop::Objects::RectangleObject*> mRectangleHitboxes;

      private:

         // There are currently no private member variables for this class.

      //***************************************************************************************************************
      // Member Variables - End
      //***************************************************************************************************************
   };
}

#endif // Object_H TODO: Don't forget to update this.