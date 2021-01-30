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


   // assembleur
Magie::Magie (SDL_Renderer *renderer, SDL_Rect* empl_dep, int orientation, int trajet) {
   ld_img_cpp (&m_magie, renderer, "imgs/magie.bmp");
   m_Rmagie = *empl_dep;
   m_orientation = orientation;
   m_trajet = trajet;
}


   // destructeur
Magie::~Magie () {
   SDL_DestroyTexture (m_magie);
}


void Magie::remake_magie (SDL_Rect* empl_dep, int orientation, int trajet) {
   m_Rmagie = *empl_dep;
   m_orientation = orientation;
   m_trajet = trajet;
}


SDL_Rect Magie::Up () {

   if (m_orientation == 0) {

      if (m_trajet - 10 >= 0) {
         m_Rmagie.y -= 10;
         m_trajet -= 10;
      }
      else {
         return (SDL_Rect) {0, 0, 0, 0};
      }
   }
   else if (m_orientation == 1) {

      if (m_trajet - 10 >= 0) {
         m_Rmagie.x += 10;
         m_trajet -= 10;
      }
      else {
         return (SDL_Rect) {0, 0, 0, 0};
      }
   }
   else if (m_orientation == 2) {

      if (m_trajet - 10 >= 0) {
         m_Rmagie.y += 10;
         m_trajet -= 10;
      }
      else {
         return (SDL_Rect) {0, 0, 0, 0};
      }
   }
   else if (m_orientation == 3) {

      if (m_trajet - 10 >= 0) {
         m_Rmagie.x -= 10;
         m_trajet -= 10;
      }
      else {
         return (SDL_Rect) {0, 0, 0, 0};
      }
   }

   return m_Rmagie;
}


void Magie::afficher (SDL_Renderer *renderer) {
   SDL_RenderCopy (renderer, m_magie, NULL, &m_Rmagie);
}


SDL_Rect Magie::get_rect () {
   return m_Rmagie;
}


void Magie::a_touche () {
   m_Rmagie.x = -50;
   m_Rmagie.y = -50;
}







