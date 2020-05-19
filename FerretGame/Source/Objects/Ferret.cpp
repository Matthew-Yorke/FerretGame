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
      mLocation(aLocation), mRotation(Bebop::Math::DEGREES_ZERO), mHeight(0), mVerticalMovement(VerticalMovement::NONE)
   {
      mSprite = new Bebop::Graphics::AnimatedSprite("../Images/TestFerret.png",
                                                    Bebop::Math::Vector2D<int>(IDLE_FRAME_ROW, FIRST_ANIMATION_FRAME),
                                                    SPRITE_SIZE, SPRITE_SIZE, mLocation, ANIMATION_FPS, IDLE_FRAME_COUNT, mRotation);

      // Add hitboxes
      AddCircleHitbox(CircleHitboxes::BACK,
                      new Bebop::Objects::CircleObject(Bebop::Math::Vector2D<float>(SPRITE_SIZE / HALF, SPRITE_SIZE / HALF + HITBOX_OFFSET),
                                                       HITBOX_RADIUS, new Bebop::Graphics::Color(0,0,255,160)));
      AddCircleHitbox(CircleHitboxes::MIDDLE,
                      new Bebop::Objects::CircleObject(Bebop::Math::Vector2D<float>(SPRITE_SIZE / HALF, SPRITE_SIZE / HALF),
                                                       HITBOX_RADIUS, new Bebop::Graphics::Color(0,0,255,160)));
      AddCircleHitbox(CircleHitboxes::FRONT,
                      new Bebop::Objects::CircleObject(Bebop::Math::Vector2D<float>(SPRITE_SIZE / HALF, SPRITE_SIZE / HALF - HITBOX_OFFSET),
                                                       HITBOX_RADIUS, new Bebop::Graphics::Color(0,0,255,160)));
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

      Bebop::Objects::CircleObject* pCurrentHitbox = GetCircleHitbox(CircleHitboxes::BACK);
      pCurrentHitbox->SetCoordinateX(pCurrentHitbox->GetCoordinateX() + aMovement.GetComponentX());
      pCurrentHitbox->SetCoordinateY(pCurrentHitbox->GetCoordinateY() + aMovement.GetComponentY());

      pCurrentHitbox = GetCircleHitbox(CircleHitboxes::MIDDLE);
      pCurrentHitbox->SetCoordinateX(pCurrentHitbox->GetCoordinateX() + aMovement.GetComponentX());
      pCurrentHitbox->SetCoordinateY(pCurrentHitbox->GetCoordinateY() + aMovement.GetComponentY());

      pCurrentHitbox = GetCircleHitbox(CircleHitboxes::FRONT);
      pCurrentHitbox->SetCoordinateX(pCurrentHitbox->GetCoordinateX() + aMovement.GetComponentX());
      pCurrentHitbox->SetCoordinateY(pCurrentHitbox->GetCoordinateY() + aMovement.GetComponentY());
   }

   //******************************************************************************************************************
   //
   // Method: ChangeHeight
   //
   // Description:
   //    Updates the height of the ferret by the passed in height change.
   //
   // Arguments:
   //    aHeightChange - The height change.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Ferret::ChangeHeight(int aHeightChange)
   {
      mHeight += aHeightChange;
   }

   //******************************************************************************************************************
   //
   // Method: GetHeight
   //
   // Description:
   //    Returns the current height of the ferret.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    Returns the current height.
   //
   //******************************************************************************************************************
   int Ferret::GetHeight()
   {
      return mHeight;
   }

   //******************************************************************************************************************
   //
   // Method: SetVerticalMovement
   //
   // Description:
   //    Updates the vertical movement of the ferret witht he passed in value.
   //
   // Arguments:
   //    aVerticalMovement - The vertical movement to set the ferret to.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Ferret::SetVerticalMovement(VerticalMovement aVerticalMovement)
   {
      mVerticalMovement = aVerticalMovement;
   }
   
   //******************************************************************************************************************
   //
   // Method: GetVerticalMovement
   //
   // Description:
   //    Returns the current vertical movement of the ferret.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    Returns the current vertical movement.
   //
   //******************************************************************************************************************
   VerticalMovement Ferret::GetVerticalMovement()
   {
      return mVerticalMovement;
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

      Bebop::Objects::CircleObject* pCurrentHitbox = GetCircleHitbox(CircleHitboxes::BACK);
      float BackHitboxX = (mLocation.GetComponentX() + (SPRITE_SIZE / HALF)) + HITBOX_OFFSET *
                          cos((HITBOX_ROTATOIN_OFFSET + mRotation) * Bebop::Math::RADIANS_CONVERSION);
      float BackHitboxY = (mLocation.GetComponentY() + (SPRITE_SIZE / HALF)) + HITBOX_OFFSET *
                          sin((HITBOX_ROTATOIN_OFFSET + mRotation) * Bebop::Math::RADIANS_CONVERSION);
      pCurrentHitbox->SetCoordinateX(BackHitboxX);
      pCurrentHitbox->SetCoordinateY(BackHitboxY);

      pCurrentHitbox = GetCircleHitbox(CircleHitboxes::FRONT);
      float FrontHitboxX = (mLocation.GetComponentX() + (SPRITE_SIZE / HALF)) + HITBOX_OFFSET *
                           cos((-HITBOX_ROTATOIN_OFFSET + mRotation) * Bebop::Math::RADIANS_CONVERSION);
      float FrontHitboxY = (mLocation.GetComponentY() + (SPRITE_SIZE / HALF)) + HITBOX_OFFSET *
                           sin((-HITBOX_ROTATOIN_OFFSET + mRotation) * Bebop::Math::RADIANS_CONVERSION);
      pCurrentHitbox->SetCoordinateX(FrontHitboxX);
      pCurrentHitbox->SetCoordinateY(FrontHitboxY);
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
      return GetCircleHitbox(CircleHitboxes::BACK);
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
      return GetCircleHitbox(CircleHitboxes::MIDDLE);
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
      return GetCircleHitbox(CircleHitboxes::FRONT);
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