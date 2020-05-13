//*********************************************************************************************************************
//
// File: PlayState.cpp
//
// Description:
//    TODO: Add description.
//
//*********************************************************************************************************************

#include "PlayState.h"

namespace FerretGame
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   PlayState::PlayState(Bebop::Bebop* apEngine) :
      mpEngine(apEngine), mSprint(1.0F), mpCurrentScene(nullptr)
   {
      mpCharacter = new Ferret(Bebop::Math::Vector2D<float>(0.0F, 0.0F));
      // TODO: Remove when moved to appropriate class.
      mpEngine->GetScene()->GetLayer(0)->AddAnimatedSprite(mpCharacter->GetSprite());
      mpEngine->GetScene()->GetLayer(0)->AddParticle(new Bebop::Graphics::Particle(mpCharacter->GetBackHitbox(), nullptr, 10.0F));
      mpEngine->GetScene()->GetLayer(0)->AddParticle(new Bebop::Graphics::Particle(mpCharacter->GetMiddleHitbox(), nullptr, 10.0F));
      mpEngine->GetScene()->GetLayer(0)->AddParticle(new Bebop::Graphics::Particle(mpCharacter->GetFrontHitbox(), nullptr, 10.0F));
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
   PlayState::~PlayState()
   {
      delete mpCharacter;
   }

   //******************************************************************************************************************
   //
   // Method: Update
   //
   // Description:
   //    Overrides the parent class of this method to implement the functionality for this required method. This method
   //    updates the game engine and updates objects in the game based on the input checks for keys being
   //    pressed/released.
   //    
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void PlayState::Update()
   {
      if (mpEngine->Update() == true)
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
            mpCharacter->Move(Bebop::Math::Vector2D<float>(sin(mpCharacter->GetAngleRadians()) * mSprint, -cos(mpCharacter->GetAngleRadians()) * mSprint));
         }
         if (mpEngine->GetKeyStatus(ALLEGRO_KEY_S) == true)
         {
            mpCharacter->Move(Bebop::Math::Vector2D<float>(-sin(mpCharacter->GetAngleRadians()) * mSprint, cos(mpCharacter->GetAngleRadians()) * mSprint));
         }
         if (mpEngine->GetKeyStatus(ALLEGRO_KEY_A) == true)
         {
            mpCharacter->Rotate(-1.0F);
         }
         if (mpEngine->GetKeyStatus(ALLEGRO_KEY_D) == true)
         {
            mpCharacter->Rotate(1.0F);
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

   // TODO: Remove later, this is only for testing purposes.
   void PlayState::SetupTestGame()
   {
      mpCurrentScene = new GameScene();
      mpCurrentScene->AddFloor(0, new Bebop::Objects::RectangleObject(Bebop::Math::Vector2D<float>(0.0F,0.0F), 0, 0, nullptr));
      mpCurrentScene->AddFerret(mpCharacter);
   }

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
}