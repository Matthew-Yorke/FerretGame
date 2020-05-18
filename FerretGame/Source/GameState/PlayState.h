//*********************************************************************************************************************
//
// File: PlayState.h
//
// Description:
//    TODO: Add description.
//
//*********************************************************************************************************************

#ifndef PlayState_H
#define PlayState_H

#include "GameState.h"
#include "../GameScene.h"
// TODO: Remove when moved to appropriate clas.
#include "../Player/Player.h"

namespace FerretGame
{
   class PlayState : public GameState
   {
      //***************************************************************************************************************
      // Methods - Start
      //***************************************************************************************************************

      public:

         //************************************************************************************************************
         //
         // Method: PlayState
         //
         // Description:
         //    Constructor that sets member variables to default states.
         //
         // Arguments:
         //    apEngine - Pointer to refrence the game engine for the game.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         PlayState(Bebop::Bebop* apEngine);

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
         ~PlayState();

         //************************************************************************************************************
         //
         // Method: Update
         //
         // Description:
         //    Overrides the parent class of this method to implement the functionality for this required method. This
         //    method updates the game engine and updates objects in the game based on the input checks for keys being
         //    pressed/released.
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

         // TODO: Remove later, this is only for testing purposes.
         void SetupTestGame();

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

         // Tracks the current scene of the game.
         GameScene* mpCurrentScene;

         // TODO: Remvoe when put in appropriate class.
         Player* mpCharacter;
         float mSprint;

      //***************************************************************************************************************
      // Member Variables - End
      //***************************************************************************************************************
   };
}

#endif // PlayState_H