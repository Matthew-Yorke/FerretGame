//*********************************************************************************************************************
//
// File: FileName.cpp
//
// Description:
//    This class handles the creation and changes of a ferret object within the game. A ferret is able to turn and move
//    throughout a game scene.
//
//*********************************************************************************************************************

#include "Ferret.h"
#include "FerretConstants.h"
#include "BebopCore/Math/MathConstants.h"
#include "BebopCore/Graphics/Color.h"

namespace FerretGame
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
   //
   // Method: Ferret
   //
   // Description:
   //    Constructor the sets member variables to default values.
   //
   // Arguments:
   //    aLocation - the X/Y-Coordinate of thwere the object is created on the scene.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   Ferret::Ferret(const Bebop::Math::Vector2D<float> aLocation) :
      mLocation(aLocation), mRotation(Bebop::Math::DEGREES_ZERO)
   {
      mSprite = new Bebop::Graphics::AnimatedSprite("../Images/TestFerret.png",
                                                    Bebop::Math::Vector2D<int>(IDLE_FRAME_ROW, FIRST_ANIMATION_FRAME),
                                                    SPRITE_SIZE, SPRITE_SIZE, mLocation, ANIMATION_FPS, IDLE_FRAME_COUNT, mRotation);
      mBackHitBox = new Bebop::Objects::CircleObject(Bebop::Math::Vector2D<float>(SPRITE_SIZE / HALF, SPRITE_SIZE / HALF + HITBOX_OFFSET),
                                                     HITBOX_RADIUS, new Bebop::Graphics::Color(0,0,255,160));
      mMiddleHitBox = new Bebop::Objects::CircleObject(Bebop::Math::Vector2D<float>(SPRITE_SIZE / HALF, SPRITE_SIZE / HALF),
                                                       HITBOX_RADIUS, new Bebop::Graphics::Color(0,0,255,160));
      mFrontHitBox = new Bebop::Objects::CircleObject(Bebop::Math::Vector2D<float>(SPRITE_SIZE / HALF, SPRITE_SIZE / HALF - HITBOX_OFFSET),
                                                      HITBOX_RADIUS, new Bebop::Graphics::Color(0,0,255,160));
   }
   
   //******************************************************************************************************************
   //
   // Method: ~Ferret
   //
   // Description:
   //    Destructor that cleans up any allocated memory before the object is destroyed.
   //    
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   Ferret::~Ferret()
   {
      delete mSprite;
      delete mBackHitBox;
      delete mMiddleHitBox;
      delete mFrontHitBox;
   }

   //******************************************************************************************************************
   //
   // Method: GetSprite
   //
   // Description:
   //    Returns the sprite information for the ferret. 
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    Return the current sprite information for the ferret.
   //
   //******************************************************************************************************************
   Bebop::Graphics::AnimatedSprite* Ferret::GetSprite()
   {
      return mSprite;
   }

   //******************************************************************************************************************
   //
   // Method: Move
   //
   // Description:
   //    Updates the forward movement of the ferret by the passed in x/y change.
   //
   // Arguments:
   //    aMovement - The X/Y-Coordinate position change.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Ferret::Move(Bebop::Math::Vector2D<float> aMovement)
   {
      mLocation += aMovement;
      mSprite->UpdatePosition(mLocation);
      mBackHitBox->SetCoordinateX(mBackHitBox->GetCoordinateX() + aMovement.GetComponentX());
      mBackHitBox->SetCoordinateY(mBackHitBox->GetCoordinateY() + aMovement.GetComponentY());
      mMiddleHitBox->SetCoordinateX(mMiddleHitBox->GetCoordinateX() + aMovement.GetComponentX());
      mMiddleHitBox->SetCoordinateY(mMiddleHitBox->GetCoordinateY() + aMovement.GetComponentY());
      mFrontHitBox->SetCoordinateX(mFrontHitBox->GetCoordinateX() + aMovement.GetComponentX());
      mFrontHitBox->SetCoordinateY(mFrontHitBox->GetCoordinateY() + aMovement.GetComponentY());
   }

   //******************************************************************************************************************
   //
   // Method: Rotate
   //
   // Description:
   //    Rotate the ferret angle using the passed in rotational change.
   //
   // Arguments:
   //    aRotationChange - The rotational change.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Ferret::Rotate(float aRotationChange)
   {
      mRotation += aRotationChange;
      mRotation = fmod(mRotation, Bebop::Math::DEGREES_THREE_SIXTY);
      if (mRotation < Bebop::Math::DEGREES_ZERO)
      {
         mRotation += Bebop::Math::DEGREES_THREE_SIXTY;
      }

      mSprite->UpdateRotation(mRotation * Bebop::Math::RADIANS_CONVERSION);
      float BackHitboxX = (mLocation.GetComponentX() + (SPRITE_SIZE / HALF)) + HITBOX_OFFSET *
                          cos((HITBOX_ROTATOIN_OFFSET + mRotation) * Bebop::Math::RADIANS_CONVERSION);
      float BackHitboxY = (mLocation.GetComponentY() + (SPRITE_SIZE / HALF)) + HITBOX_OFFSET *
                          sin((HITBOX_ROTATOIN_OFFSET + mRotation) * Bebop::Math::RADIANS_CONVERSION);
      mBackHitBox->SetCoordinateX(BackHitboxX);
      mBackHitBox->SetCoordinateY(BackHitboxY);

      float FrontHitboxX = (mLocation.GetComponentX() + (SPRITE_SIZE / HALF)) + HITBOX_OFFSET *
                           cos((-HITBOX_ROTATOIN_OFFSET + mRotation) * Bebop::Math::RADIANS_CONVERSION);
      float FrontHitboxY = (mLocation.GetComponentY() + (SPRITE_SIZE / HALF)) + HITBOX_OFFSET *
                           sin((-HITBOX_ROTATOIN_OFFSET + mRotation) * Bebop::Math::RADIANS_CONVERSION);
      mFrontHitBox->SetCoordinateX(FrontHitboxX);
      mFrontHitBox->SetCoordinateY(FrontHitboxY);
   }

   //******************************************************************************************************************
   //
   // Method: GetAngleRadians
   //
   // Description:
   //    Returns the angle in radians of the current rotation of the ferret.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    Returns the current rotation in radians.
   //
   //******************************************************************************************************************
   float Ferret::GetAngleRadians()
   {
      return mRotation * Bebop::Math::RADIANS_CONVERSION;
   }

   //******************************************************************************************************************
   //
   // Method: GetBackHitbox
   //
   // Description:
   //    Retrieveal the back hitbox of the ferret.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    Returns a pointer to reference the back hitbox of the ferret.
   //
   //******************************************************************************************************************
   Bebop::Objects::CircleObject* Ferret::GetBackHitbox()
   {
      return mBackHitBox;
   }

   //******************************************************************************************************************
   //
   // Method: GetMiddleHitbox
   //
   // Description:
   //    Retrieveal the middle hitbox of the ferret.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    Returns a pointer to reference the middle hitbox of the ferret.
   //
   //******************************************************************************************************************
   Bebop::Objects::CircleObject* Ferret::GetMiddleHitbox()
   {
      return mMiddleHitBox;
   }

   //******************************************************************************************************************
   //
   // Method: GetFrontHitbox
   //
   // Description:
   //    Retrieveal the frontal hitbox of the ferret.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    Returns a pointer to reference the frontal hitbox of the ferret.
   //
   //******************************************************************************************************************
   Bebop::Objects::CircleObject* Ferret::GetFrontHitbox()
   {
      return mFrontHitBox;
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