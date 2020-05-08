//*********************************************************************************************************************
//
// File: Game.cpp
//
// Description:
//    Thee main game classes. This class intializes the game settings before launching into the main game loop which
//    calls to update the current state of the game until the game has completed.
//
//*********************************************************************************************************************

#include "Game.h"
// TODO: Remove when put in appropriate place.
#include "Objects/Ferret.h"
#include "BebopCore/Graphics/Light.h"
#include "GameState/PlayState.h"

namespace FerretGame
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   Game::Game() :
      mRunning(false), mpCurrentState(nullptr)
   {
      mpEngine = new Bebop::Bebop();

      if (InitializeEngine() == true)
      {
         RunGameLoop();
      }
   }
   
   //******************************************************************************************************************
   //
   // Method: ~ClassName
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
   //******************************************************************************************************************
   Game::~Game()
   {
      delete mpEngine;
   }

//*********************************************************************************************************************
// Public Methods - End
//*********************************************************************************************************************

//*********************************************************************************************************************
// Protected Methods - Start
//*********************************************************************************************************************

   // There are currently no protected methods for this class.

//*********************************************************************************************************************
// Protected Methods - End
//*********************************************************************************************************************

//*********************************************************************************************************************
// Private Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   bool Game::InitializeEngine()
   {
      if (mpEngine->InitializeBebop() == true &&
          mpEngine->InitializeGraphics() == true &&
          mpEngine->InitializeEvents() == true)
      {
         mpEngine->CreateWindow(640, 360);
         return true;
      }

      return false;
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void Game::RunGameLoop()
   {
      bool timedOut = false;

      if (InitializeEngine() == true)
      {
         mRunning = true;

         // TODO: Remove when appropriate placement in another class.
         mpEngine->CreateScene();
         mpEngine->GetScene()->AddNewLayer(0);
         mpCurrentState = new PlayState(mpEngine);
      }

      while (mRunning == true)
      {
          mpCurrentState->Update();
      }
   }

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
}