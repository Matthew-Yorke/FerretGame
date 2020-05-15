//*********************************************************************************************************************
//
// File: RegularState.cpp
//
// Description:
//    The standard state of the player, allowing basic movement and directional change.
//
//*********************************************************************************************************************

#include "RegularState.h"

namespace FerretGame
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   RegularState::RegularState(Ferret* apPlayer, Bebop::Bebop* apEngine) :
      mpPlayer(apPlayer), mpEngine(apEngine), mSprint(1.0F)
   {
   }
   
   //******************************************************************************************************************
   //
   // Method: ~PlayState
   //
   // Description:
   //    Destructor the cleans up any used memory this class handles upon the destruction of an object of this class.
   //    
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   RegularState::~RegularState()
   {
   }

   //******************************************************************************************************************
   //
   // Method: Update
   //
   // Description:
   //    Overrides the parent class of this method to implement the functionality for this required method. This method
   //    updates the player based on the key presses. In this state the player can move and chane direction.
   //    
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void RegularState::Update()
   {
      if (mpEngine->GetKeyStatus(ALLEGRO_KEY_LSHIFT) == true)
      {
         mSprint = 3.0F;
      }
      else
      {
         mSprint = 1.0F;
      }
      
      if (mpEngine->GetKeyStatus(ALLEGRO_KEY_W) == true)
      {
         mpPlayer->Move(Bebop::Math::Vector2D<float>(sin(mpPlayer->GetAngleRadians()) * mSprint, -cos(mpPlayer->GetAngleRadians()) * mSprint));
      }
      if (mpEngine->GetKeyStatus(ALLEGRO_KEY_S) == true)
      {
         mpPlayer->Move(Bebop::Math::Vector2D<float>(-sin(mpPlayer->GetAngleRadians()) * mSprint, cos(mpPlayer->GetAngleRadians()) * mSprint));
      }
      if (mpEngine->GetKeyStatus(ALLEGRO_KEY_A) == true)
      {
         mpPlayer->Rotate(-1.0F);
      }
      if (mpEngine->GetKeyStatus(ALLEGRO_KEY_D) == true)
      {
         mpPlayer->Rotate(1.0F);
      }
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

   // There are currently no private methods for this class.

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
}