
#include "main.h"


using namespace std;


int main () {
   if (!Init ()) {
      cout << "program interupted." << endl;
      Quit ();
   }

   boucle_J1 ();

   Quit ();
   return EXIT_SUCCESS;
}

bool Init () {
   if (SDL_Init (SDL_INIT_VIDEO) < 0) {
      cout << "fatal error : " << SDL_GetError () << endl;
      return false;
   }

   if (TTF_Init () < 0) {
      cout << "fatal error : " << TTF_GetError () << endl;
      return false;
   }

   if (Mix_OpenAudio (MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0) {
      cout << "fatal error : " << Mix_GetError () << endl;
      return false;
   }

   return true;
}

void Quit () {

   SDL_Quit ();
   TTF_Quit ();

   exit (EXIT_FAILURE);
}







