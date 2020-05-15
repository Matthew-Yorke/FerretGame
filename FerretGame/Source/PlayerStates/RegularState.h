//*********************************************************************************************************************
//
// File: RegularState.h
//
// Description:
//    The standard state of the player, allowing basic movement and directional change.
//
//*********************************************************************************************************************

#ifndef RegularState_H
#define RegularState_H

#include "PlayerState.h"
#include "../Objects/Ferret.h"

namespace FerretGame
{
   class RegularState : public PlayerState
   {
      //***************************************************************************************************************
      // Methods - Start
      //***************************************************************************************************************

      public:

         //************************************************************************************************************
         //
         // Method: RegularState
         //
         // Description:
         //    Constructor that sets member variables to default states.
         //
         // Arguments:
         //    apPlayer - Pointer to reference the player.
         //    apEngine - Pointer to refrence the game engine for the game.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         RegularState(Ferret* apPlayer, Bebop::Bebop* apEngine);

         //************************************************************************************************************
         //
         // Method: ~PlayState
         //
         // Description:
         //    Destructor the cleans up any used memory this class handles upon the destruction of an object of this
         //    class.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         ~RegularState();

         //************************************************************************************************************
         //
         // Method: Update
         //
         // Description:
         //    Overrides the parent class of this method to implement the functionality for this required method. This
         //    method updates the player based on the key presses. In this state the player can move and chane
         //    direction.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void Update() override;

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
         
         // Pointer to a reference of the game engine.
         Bebop::Bebop* mpEngine;

         // Pointer to a reference to the player.
         Ferret* mpPlayer;

         // TODO: Remove and add to appropriate const file
         float mSprint;

      //***************************************************************************************************************
      // Member Variables - End
      //***************************************************************************************************************
   };
}

#endif // PlayState_H