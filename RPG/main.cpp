#ifndef CPP
#define CPP
#endif

#include "autres.h"
#include "class.h"
#include "back.h"
#include "magie.h"
#include "Perso.h"
#include "boucle.h"
#include "main.h"
#include <iostream>
#include <string> // permet d'utiliser les chaines de charactère dans des variables
#include <cmath> // permet d'obtenir la valeur absolue d'un nombre
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "../lib_malo/malo.h" // ATENTION : bibliothèque écrite en C



using namespace std;


int main () {
   if (!Init ()) {
      cout << "program interupted." << endl;
      Quit ();
   }

   boucle ();

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







