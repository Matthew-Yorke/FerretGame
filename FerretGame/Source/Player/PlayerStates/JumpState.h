//*********************************************************************************************************************
//
// File: JumpState.h
//
// Description:
//    The standard state of the player, allowing basic movement and directional change.
//
//*********************************************************************************************************************

#ifndef JumpState_H
#define JumpState_H

#include "PlayerState.h"
#include "../Player.h"

namespace FerretGame
{
   class JumpState : public PlayerState
   {
      //***************************************************************************************************************
      // Methods - Start
      //***************************************************************************************************************

      public:

         //************************************************************************************************************
         //
         // Method: JumpState
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
         JumpState(Player* apPlayer, Bebop::Bebop* apEngine);

         //************************************************************************************************************
         //
         // Method: ~JumpState
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
         ~JumpState();

         //************************************************************************************************************
         //
         // Method: Update
         //
         // Description:
         //    Overrides the parent class of this method to implement the functionality for this required method. This
         //    method updates the player based on the key presses. In this state the player can move forward and
         //    continues rising while the jump button is pressed and vertical velcoity is positive, otherwise the
         //    player descends.
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
         Player* mpPlayer;

         // Tracks the first release of the jump button.
         bool mFirstLetGoOfJump;

		   // Tracks the velocity of the players jump.
         float mJumpVelocity;

      //***************************************************************************************************************
      // Member Variables - End
      //***************************************************************************************************************
   };
}

#endif // JumpState_H