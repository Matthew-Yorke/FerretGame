//*********************************************************************************************************************
//
// File: Player.h
//
// Description:
//    TODO: Add description.
//
//*********************************************************************************************************************

#ifndef Player_H
#define Player_H

#include "../Objects/Ferret.h"
#include "PlayerStates/PlayerState.h"
#include "Bebop.h"

namespace FerretGame
{
   class Player
   {
      //***************************************************************************************************************
      // Methods - Start
      //***************************************************************************************************************

      public:

         //************************************************************************************************************
         //
         // Method: Player
         //
         // Description:
         //    TODO: Add description.
         //
         // Arguments:
         //    apEngine = Pointer to the engine.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         Player(Bebop::Bebop* apEngine);

         //************************************************************************************************************
         //
         // Method: ~Player
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
         ~Player();

         //************************************************************************************************************
         //
         // Method: ChangeState
         //
         // Description:
         //    TODO: Add description.
         //
         // Arguments:
         //    apNewState - TODO: Add description.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void ChangeState(PlayerState* apNewState);

         //************************************************************************************************************
         //
         // Method: GetFerret
         //
         // Description:
         //    Retrieves pointer to the player's ferret object.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Return pointer to the player's ferret object.
         //
         //************************************************************************************************************
         Ferret* GetFerret();

         //************************************************************************************************************
         //
         // Method: Update
         //
         // Description:
         //    Updates the player based on their state.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void Update();

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

         // The ferret the player is.
         Ferret* mpFerret;

         // Tracks the current state of the player.
         PlayerState* mpPlayerState;

         // Pointer to reference the engine.
         Bebop::Bebop* mpEngine;

      //***************************************************************************************************************
      // Member Variables - End
      //***************************************************************************************************************
   };
}

#endif // Player_H