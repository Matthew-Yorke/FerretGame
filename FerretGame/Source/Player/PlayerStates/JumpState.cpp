//*********************************************************************************************************************
//
// File: RegularState.cpp
//
// Description:
//    The standard state of the player, allowing basic movement and directional change.
//
//*********************************************************************************************************************

#include "JumpState.h"
#include "RegularState.h"

namespace FerretGame
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   JumpState::JumpState(Player* apPlayer, Bebop::Bebop* apEngine) :
      mpPlayer(apPlayer), mpEngine(apEngine), mFirstLetGoOfJump(false), mJumpVelocity(3.0F)
   {
      mpPlayer->GetFerret()->SetVerticalMovement(VerticalMovement::RISING);
   }
   
   //******************************************************************************************************************
   //
   // Method: ~JumpState
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
   JumpState::~JumpState()
   {
   }

   //******************************************************************************************************************
   //
   // Method: Update
   //
   // Description:
   //    Overrides the parent class of this method to implement the functionality for this required method. This method
   //    updates the player based on the key presses. In this state the player can move forward and continues rising
   //    while the jump button is pressed and vertical velcoity is positive, otherwise the player descends.
   //    
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void JumpState::Update()
   {
      // Check if player is now descending.
      if (mpPlayer->GetFerret()->GetVerticalMovement() == VerticalMovement::DESCENDING)
      {
         mJumpVelocity -= 0.5F;
         
         // TODO: Remove, this will be done in the game collision check. Only here to not get stuck in jump state forever.
         mpPlayer->ChangeState(new RegularState(mpPlayer, mpEngine));
         return;
      }

      // Allow forward movement during jumping.
      if (mpEngine->GetKeyStatus(ALLEGRO_KEY_W) == true)
      {
         mpPlayer->GetFerret()->Move(Bebop::Math::Vector2D<float>(sin(mpPlayer->GetFerret()->GetAngleRadians()),
                                                                  -cos(mpPlayer->GetFerret()->GetAngleRadians())));
      }
      // Jump key is being pressed.
      if (mpEngine->GetKeyStatus(ALLEGRO_KEY_SPACE) == true)
      {
         // If the jump key was never released, continue to ascendwhile jump velcoity is positive.
         if (mpPlayer->GetFerret()->GetVerticalMovement() == VerticalMovement::RISING)
         {
            mpPlayer->GetFerret()->ChangeHeight(mJumpVelocity);

            mJumpVelocity -= 0.5F;
            // Once velocity is no longer position, reset velocity and begin descending.
            if(mJumpVelocity <= 0.0F)
            {
               mJumpVelocity = 0.0F;
               mpPlayer->GetFerret()->SetVerticalMovement(VerticalMovement::DESCENDING);
            }
         }
      }
      // Jump key is released.
      else
      {
         // On first time release of the jump key, reset velocity and begin descending.
         if (mFirstLetGoOfJump == false)
         {
            mJumpVelocity = 0.0F;
            mpPlayer->GetFerret()->SetVerticalMovement(VerticalMovement::DESCENDING);
            mFirstLetGoOfJump = true;
         }
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