//*********************************************************************************************************************
//
// File: PlayerState.h
//
// Description:
//    Abstract class for the state pattern of the players's states. All state's must implement the pure virtual
//    functions from this class.
//
//*********************************************************************************************************************

#ifndef PlayerState_H
#define PlayerState_H

#include "Bebop.h"

namespace FerretGame
{
   class PlayerState
   {
      //***************************************************************************************************************
      // Methods - Start
      //***************************************************************************************************************

      public:

         //************************************************************************************************************
         //
         // Method: Update
         //
         // Description:
         //    Virtual function to be implemented by all child classes so that the child classes will have
         //    implementation to handle when the update is called.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         virtual void Update() = 0;

      protected:

         // There are currently no protected methods for this class.

      private:

         // There are currently no private methods for this class.

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

         // There are currently no private member variables for this class.

      //***************************************************************************************************************
      // Member Variables - End
      //***************************************************************************************************************
   };
}

#endif // GameState_H