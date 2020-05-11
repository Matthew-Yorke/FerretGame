//*********************************************************************************************************************
//
// File: FileName.cpp
//
// Description:
//    TODO: Add description.
//
//*********************************************************************************************************************

#include "Ferret.h"
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
   //    TODO: Add Description.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   Ferret::Ferret() :
      mLocation(0.0F, 0.0F), mRotation(0.0F)
   {
      mSprite = new Bebop::Graphics::AnimatedSprite("../Images/TestFerret.png", Bebop::Math::Vector2D<int>(0, 0), 64, 64, mLocation, 1, 1, 0.0F);
      mBackHitBox = new Bebop::Objects::CircleObject(Bebop::Math::Vector2D<float>(32, 52), 10, Bebop::Graphics::Color(0,0,255,160), true);
      mMiddleHitBox = new Bebop::Objects::CircleObject(Bebop::Math::Vector2D<float>(32, 32), 10, Bebop::Graphics::Color(0,0,255,160), true);
      mFrontHitBox = new Bebop::Objects::CircleObject(Bebop::Math::Vector2D<float>(32, 12), 10, Bebop::Graphics::Color(0,0,255,160), true);
   }
   
   //******************************************************************************************************************
   //
   // Method: ~Ferret
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
   //******************************************************************************************************************
   Ferret::~Ferret()
   {
      delete mSprite;
      delete mBackHitBox;
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
   //    TODO: Add description.
   //
   // Arguments:
   //    aMovement - TODO: Add description.
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
   //    TODO: Add description.
   //
   // Arguments:
   //    aRotationChange - TODO: Add description.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Ferret::Rotate(float aRotationChange)
   {
      mRotation += aRotationChange;
      mRotation = fmod(mRotation, 360.0F);
      if (mRotation < 0.0F)
      {
         mRotation += 360.0F;
      }

      mSprite->UpdateRotation(mRotation * (3.14F/180.0F)); // TODO: Make constant for degree->radians.

      float BackHitboxX = (mLocation.GetComponentX() + 32.0F) + 20.0F * cos((90.0F + mRotation) * (3.14F/180.0F));
      float BackHitboxY = (mLocation.GetComponentY() + 32.0F) + 20.0F * sin((90.0F + mRotation) * (3.14F/180.0F));
      mBackHitBox->SetCoordinateX(BackHitboxX);
      mBackHitBox->SetCoordinateY(BackHitboxY);

      float FrontHitboxX = (mLocation.GetComponentX() + 32.0F) + 20.0F * cos((-90.0F + mRotation) * (3.14F/180.0F));
      float FrontHitboxY = (mLocation.GetComponentY() + 32.0F) + 20.0F * sin((-90.0F + mRotation) * (3.14F/180.0F));
      mFrontHitBox->SetCoordinateX(FrontHitboxX);
      mFrontHitBox->SetCoordinateY(FrontHitboxY);
   }

   //******************************************************************************************************************
   //
   // Method: GetAngleRadians
   //
   // Description:
   //    TODO: Add description.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    TODO: Add description.
   //
   //******************************************************************************************************************
   float Ferret::GetAngleRadians()
   {
      return mRotation * (3.14F/180.0F); // TODO: Make constant for degree->radians.
   }

   Bebop::Objects::CircleObject* Ferret::GetBackHitbox()
   {
      return mBackHitBox;
   }

   Bebop::Objects::CircleObject* Ferret::GetMiddleHitbox()
   {
      return mMiddleHitBox;
   }

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