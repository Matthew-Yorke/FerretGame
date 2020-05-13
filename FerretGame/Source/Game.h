//*********************************************************************************************************************
//
// File: Game.h
//
// Description:
//    The main game classes. This class intializes the game settings before launching into the main game loop which
//    calls to update the current state of the game until the game has completed.
//
//*********************************************************************************************************************

#ifndef Game_H
#define Game_H

#include "Bebop.h"
#include "GameScene.h"
#include "GameState/GameState.h"

namespace FerretGame
{
   class Game
   {
      //***************************************************************************************************************
      // Methods - Start
      //***************************************************************************************************************

      public:

         //************************************************************************************************************
         //
         // Method: Game
         //
         // Description:
         //    Constructor that sets member variables to default values.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         Game();

         //************************************************************************************************************
         //
         // Method: ~Game
         //
         // Description:
         //    Destructor to release any allocated memory from this class.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         ~Game();

      protected:

         // There are currently no protected methods for this class.

      private:

         //************************************************************************************************************
         //
         // Method: InitializeEngine
         //
         // Description:
         //    Attempt to intialize the Bebop engine.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    True  - All initialization of Bebop successful.
         //    False - A Bebop initialization failed.
         //
         //************************************************************************************************************
         bool InitializeEngine();

         //************************************************************************************************************
         //
         // Method: RunGameLoop
         //
         // Description:
         //    Run the main game loop for the game.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void RunGameLoop();

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

         // Handles the Bebop game engine.
         Bebop::Bebop* mpEngine;

         // Boolean to track if the game is still running.
         bool mRunning;

         // Tracks the current state of the game.
         GameState* mpCurrentState;

      //***************************************************************************************************************
      // Member Variables - End
      //***************************************************************************************************************
   };
}

#endif // Game_H