#ifndef CPP
#define CPP
#endif

#include <iostream>
#include <string> // permet d'utiliser les chaines de charactère dans des variables
#include <cmath> // permet d'obtenir la valeur absolue d'un nombre
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "autres.h"
#include "class.h"
#include "back.h"
#include "magie.h"
#include "Perso.h"
#include "boucle.h"
#include "main.h"
#include "../lib_malo/malo.h" // ATENTION : bibliothèque écrite en C

   // assembleur
Back::Back (SDL_Renderer *renderer) {
   ld_img_cpp (&m_mode_chemin, renderer, "imgs/chemin.bmp");
   ld_img_cpp (&m_mode_mur, renderer, "imgs/mur.bmp");
   ld_img_cpp (&m_mode_lave, renderer, "imgs/lave.bmp");

   init_map ();
}

   // destructeur
Back::~Back () {
   SDL_DestroyTexture (m_mode_chemin);
   SDL_DestroyTexture (m_mode_mur);
   SDL_DestroyTexture (m_mode_lave);

   for (unsigned int i = 0 ; i < 91 ; ++i) {
      for (unsigned int j = 0 ; j < 60 ; ++j) {
         SDL_DestroyTexture (m_text_map [i][j]);
      }
   }
}

void Back::afficher (SDL_Renderer *renderer) {
   for (unsigned int i = 0 ; i < 91 ; ++i)
      for (unsigned int j = 0 ; j < 60 ; ++j)
         SDL_RenderCopy (renderer, m_text_map [i][j], NULL, &m_map [i][j]);
}

void Back::afficher (SDL_Renderer *renderer, SDL_Rect show) {
   for (unsigned int i = convert_cooWindX_to_cooMapX (show.x, false) ; i < convert_cooWindX_to_cooMapX (show.x, false) + convert_cooWindX_to_cooMapX (show.w, true) + 1 ; ++i)
      for (unsigned int j = convert_cooWindY_to_cooMapY (show.y, false) ; j < convert_cooWindY_to_cooMapY (show.y, false) + convert_cooWindY_to_cooMapY (show.h, true) + 1 ; ++j)
         SDL_RenderCopy (renderer, m_text_map [i][j], NULL, &m_map [i][j]);
}


void Back::change_to (const int x, const int y, const short int mode) {
   m_values_map [x][y] = mode;

   if (mode == 1)
      m_text_map [x][y] = m_mode_chemin;
   else if (mode == 2)
      m_text_map [x][y] = m_mode_mur;
   else if (mode == 3)
      m_text_map [x][y] = m_mode_lave;
}


void Back::init_map () {

   for (int i = 0 ; i < 91 ; i += 1) {
      for (int j = 0 ; j < 60 ; j += 1) {
         m_text_map [i][j] = m_mode_mur;
         m_map [i][j] = (SDL_Rect) {i * 25, j * 25, 25, 25};
         m_values_map [i][j] = 2;
      }
   }

   change_to_rect ((SDL_Rect) {17, 10, 3, 49});
   change_to_rect ((SDL_Rect) {10, 10, 79, 3});
   change_to_rect ((SDL_Rect) {10, 5, 16, 14});
}


unsigned short int Back::get_value (const short int x, const short int y) const {
   return m_values_map [x][y];
}


void Back::change_to_rect (SDL_Rect rect) {
   for (unsigned int i = rect.x ; i < rect.x + rect.w ; ++i) {
      for (unsigned int j = rect.y ; j < rect.y + rect.h ; ++j) {
         m_values_map [i][j] = 1;
         m_text_map [i][j] = m_mode_chemin;
      }
   }
}




