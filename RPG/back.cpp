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
Back::Back (SDL_Renderer *renderer, Modele modele) {

   ld_img_cpp (&m_mode_chemin, renderer, "imgs/chemin.bmp");
   ld_img_cpp (&m_mode_mur, renderer, "imgs/mur.bmp");
   ld_img_cpp (&m_mode_lave, renderer, "imgs/lave.bmp");
   ld_img_cpp (&m_mode_soin, renderer, "imgs/soin.bmp");

   m_img_map = SDL_CreateTexture (renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 90 * 25, 60 * 25);

   init_map (renderer, modele);

   SDL_SetRenderTarget (renderer, m_img_map);

   for (unsigned int i = 0 ; i < 90 ; ++i)
      for (unsigned int j = 0 ; j < 60 ; ++j)
         SDL_RenderCopy (renderer, m_text_map [i][j], NULL, &m_map [i][j]);

   SDL_SetRenderTarget (renderer, NULL);

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


void Back::afficher (SDL_Renderer *renderer, SDL_Rect show) {
   SDL_RenderCopy (renderer, m_img_map, &show, NULL);

   for (size_t i = 0 ; i < 91 ; i++)
      for (size_t j = 0 ; j < 60 ; j++)
         if (m_id_armes [i][j] != -1)
            SDL_RenderCopy (renderer, m_text_armes [i][j], NULL, &m_map [i][j]);
}


void Back::afficher (SDL_Renderer *renderer) {
   SDL_RenderCopy (renderer, m_img_map, NULL, NULL);

   for (size_t i = 0 ; i < 91 ; i++)
      for (size_t j = 0 ; j < 60 ; j++)
         if (m_id_armes [i][j] != -1)
            SDL_RenderCopy (renderer, m_text_armes [i][j], NULL, &m_map [i][j]);
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


void Back::init_map (SDL_Renderer *renderer, Modele modele) {

   for (int i = 0 ; i < 91 ; i += 1) {
      for (int j = 0 ; j < 60 ; j += 1) {
         m_text_map [i][j] = m_mode_mur;
         m_map [i][j] = (SDL_Rect) {i * 25, j * 25, 25, 25};
         m_values_map [i][j] = 2;
         m_id_armes [i][j] = -1;
      }
   }

   change_to_rect ((SDL_Rect) {17, 10, 3, 30}, 1);
   change_to_rect ((SDL_Rect) {10, 10, 50, 3}, 1);
   change_to_rect ((SDL_Rect) {57, 10, 3, 30}, 1);
   change_to_rect ((SDL_Rect) {10, 36, 50, 3}, 1);

   change_to_rect ((SDL_Rect) {10, 5, 16, 14}, 1);
   change_to_rect ((SDL_Rect) {50, 5, 16, 14}, 1);
   change_to_rect ((SDL_Rect) {10, 30, 16, 14}, 1);
   change_to_rect ((SDL_Rect) {50, 30, 16, 14}, 1);

   change_to_rect ((SDL_Rect) {30, 20, 16, 13}, 1);
   change_to_rect ((SDL_Rect) {40, 30, 10, 3}, 1);

   change_to_rect ((SDL_Rect) {33, 28, 13, 2}, 3);
   change_to_rect ((SDL_Rect) {33, 23, 2, 5}, 3);
   change_to_rect ((SDL_Rect) {35, 23, 8, 2}, 3);

   change_to_rect ((SDL_Rect) {10, 5, 2, 2}, 7);

   change_to (37, 26, 4);
   ld_img_cpp (&m_text_armes [37][26], renderer, modele.get_path (3));
   add_arme (3, 37, 26);

   change_to (11, 42, 4);
   ld_img_cpp (&m_text_armes [11][42], renderer, modele.get_path (2));
   add_arme (2, 11, 42);

   change_to (64, 6, 4);
   ld_img_cpp (&m_text_armes [64][6], renderer, modele.get_path (2));
   add_arme (2, 64, 6);

   change_to (24, 31, 4);
   ld_img_cpp (&m_text_armes [24][31], renderer, modele.get_path (1));
   add_arme (1, 24, 31);

   change_to (51, 17, 4);
   ld_img_cpp (&m_text_armes [51][17], renderer, modele.get_path (1));
   add_arme (1, 51, 17);
}


unsigned short int Back::get_value (const short int x, const short int y) const {
   return m_values_map [x][y];
}


void Back::change_to_rect (SDL_Rect rect, int mode) {

   if (mode == 1 || mode == 4) {
      for (unsigned int i = rect.x ; i < rect.x + rect.w ; ++i) {
         for (unsigned int j = rect.y ; j < rect.y + rect.h ; ++j) {
            m_values_map [i][j] = 1;
            m_text_map [i][j] = m_mode_chemin;
         }
      }
   }
   else if (mode == 2 || mode == 5) {
      for (unsigned int i = rect.x ; i < rect.x + rect.w ; ++i) {
         for (unsigned int j = rect.y ; j < rect.y + rect.h ; ++j) {
            m_values_map [i][j] = 2;
            m_text_map [i][j] = m_mode_mur;
         }
      }
   }
   else if (mode == 3 || mode == 6) {
      for (unsigned int i = rect.x ; i < rect.x + rect.w ; ++i) {
         for (unsigned int j = rect.y ; j < rect.y + rect.h ; ++j) {
            m_values_map [i][j] = 3;
            m_text_map [i][j] = m_mode_lave;
         }
      }
   }
   else if (mode == 7) {
      for (unsigned int i = rect.x ; i < rect.x + rect.w ; ++i) {
         for (unsigned int j = rect.y ; j < rect.y + rect.h ; ++j) {
            m_values_map [i][j] = 7;
            m_text_map [i][j] = m_mode_soin;
         }
      }
   }
   else {
      std::cout << "error :" << std::endl << "Back::change_to_rect (SDL_Rect, int) : mode inconnu." << std::endl;
   }
}


void Back::add_arme (const int id_arme, const int x, const int y) {
   m_id_armes [x][y] = id_arme;
}


void Back::delete_arme (const int x, const int y) {
   m_id_armes [x][y] = -1;
}


const int Back::get_id_arme (const int x, const int y) {
   return m_id_armes [x][y] + 1;
}

