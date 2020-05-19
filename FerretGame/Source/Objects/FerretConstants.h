//*********************************************************************************************************************
//
// File: FerretConstants.h
//
// Description:
//    This files handles all the constants for the graphics namespace.
//
//*********************************************************************************************************************

#ifndef FerretConstants_H
#define FerretConstants_H

#include <allegro5/allegro_primitives.h>

namespace FerretGame
{
   // The size of the width/height of an individual frame of a ferret.
	const float SPRITE_SIZE = 64.0F;

   // The radius of an individual hitbox for the ferret.
   const float HITBOX_RADIUS = 10.0F;

   // The offset from the center of the ferret for a hitbox of the front and back.
   const float HITBOX_OFFSET = 20.0F;

   // The rotation offset for the hitbox front and back, wehn the ferret is rotating.
   const float HITBOX_ROTATOIN_OFFSET = 90.0F;

   // The value to half another value when dividing.
   const float HALF = 2.0F;

   // The number of frames/sec for an animation.
   const int ANIMATION_FPS = 1;

   // The location of the idle frame in the sprite sheet.
   const int IDLE_FRAME_ROW = 0;
   
   // The location of the first frame in an animation.
   const int FIRST_ANIMATION_FRAME = 0;

   // The number of frames in the idle animation.
   const int IDLE_FRAME_COUNT = 1;

   // The set of circular hitboxes.
   enum CircleHitboxes {FRONT, MIDDLE, BACK};

   // The set of vertical movement of the ferret.
   enum VerticalMovement {RISING, DESCENDING, NONE};
}

#endif // FerretConstants_H