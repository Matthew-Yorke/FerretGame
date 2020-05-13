//*********************************************************************************************************************
//
// File: GameScene.h
//
// Description:
//    TODO: Add description.
//
//*********************************************************************************************************************

#ifndef GameScene_H
#define GameScene_H

#include <vector>
#include "Objects/Ferret.h"
#include "BebopCore/Objects/Object.h"

namespace FerretGame
{
   class GameScene
   {
      //***************************************************************************************************************
      // Methods - Start
      //***************************************************************************************************************

      public:

         //************************************************************************************************************
         //
         // Method: GameScene
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
         //************************************************************************************************************
         GameScene();

         //************************************************************************************************************
         //
         // Method: ~GameScene
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
         //************************************************************************************************************
         ~GameScene();

         //************************************************************************************************************
         //
         // Method: AddFloor
         //
         // Description:
         //    TODO: Add description.
         //
         // Arguments:
         //    aLevel  - Indicates the level the floor belongs to.
         //    apFloor - Pointer to reference a floor object.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void AddFloor(unsigned int aLevel, Bebop::Objects::Object* apFloor);

         //************************************************************************************************************
         //
         // Method: AddFerret
         //
         // Description:
         //    TODO: Add description.
         //
         // Arguments:
         //    apFerret  - Pointer to reference a ferret object.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void AddFerret(Ferret* apFerret);

         //************************************************************************************************************
         //
         // Method: Update
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
         //************************************************************************************************************
         void Update();

      protected:

         // There are currently no protected methods for this class.

      private:

         //************************************************************************************************************
         //
         // Method: FerretFloorCollision
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
         //************************************************************************************************************
         void FerretFloorCollision(Ferret* apFerret);

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

         // Tracks all the floor objects of the scene. The first of the pair indicates the level a floor is on.
         std::vector<std::pair<unsigned int, Bebop::Objects::Object*>> mFloors;

         // Tracks all the ferret objects of the scene.
         std::vector<Ferret*> mFerrets;

      //***************************************************************************************************************
      // Member Variables - End
      //***************************************************************************************************************
   };
}

#endif // GameScene_H