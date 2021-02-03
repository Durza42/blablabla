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
#include <vector>
#include <string> // permet d'utiliser les chaines de charactère dans des variables
#include <cmath> // permet d'obtenir la valeur absolue d'un nombre
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "../lib_malo/malo.h" // ATENTION : bibliothèque écrite en C


   // assembleur
Magie::Magie (SDL_Renderer *renderer1, SDL_Renderer *renderer2) {
   ld_img_cpp (&m_magie1, renderer1, "imgs/magie.bmp");
   ld_img_cpp (&m_magie2, renderer2, "imgs/magie.bmp");
}

   // assembleur
Magie::Magie (SDL_Renderer *renderer1, SDL_Renderer *renderer2, SDL_Rect empl_dep, int orientation, int trajet) {
   ld_img_cpp (&m_magie1, renderer1, "imgs/magie.bmp");
   ld_img_cpp (&m_magie2, renderer2, "imgs/magie.bmp");
   add_magie (empl_dep, orientation, trajet);
}

   // destructeur
Magie::~Magie () {
   SDL_DestroyTexture (m_magie1);
   SDL_DestroyTexture (m_magie2);
}


void Magie::add_magie (SDL_Rect empl_dep, int orientation, int trajet) {

   m_nb_magie += 1;

   m_Rmagie.push_back (empl_dep);

   m_orientation.push_back (orientation);

   m_trajet.push_back (trajet);
}


void Magie::delete_magie (const int id) {

   for (size_t i = id ; i < m_nb_magie - 1 ; i++) {

      m_Rmagie [i] = m_Rmagie [i + 1];

      m_orientation [i] = m_orientation [i + 1];

      m_trajet [i] = m_trajet [i + 1];

   }

   m_Rmagie.pop_back ();
   m_orientation.pop_back ();
   m_trajet.pop_back ();

   m_nb_magie -= 1;

}




void Magie::Up () {

   for (size_t i = 0 ; i < m_nb_magie ; i++) {

      if (m_orientation [i] == 0) {

         if (m_trajet [i] - 10 >= 0) {
            m_Rmagie [i] .y -= 10;
            m_trajet [i] -= 10;
         }
         else {
            delete_magie (i);
         }
      }
      else if (m_orientation [i] == 1) {

         if (m_trajet [i] - 10 >= 0) {
            m_Rmagie [i] .x += 10;
            m_trajet [i] -= 10;
         }
         else {
            delete_magie (i);
         }
      }
      else if (m_orientation [i] == 2) {

         if (m_trajet [i] - 10 >= 0) {
            m_Rmagie [i] .y += 10;
            m_trajet [i] -= 10;
         }
         else {
            delete_magie (i);
         }
      }
      else if (m_orientation [i] == 3) {

         if (m_trajet [i] - 10 >= 0) {
            m_Rmagie [i] .x -= 10;
            m_trajet [i] -= 10;
         }
         else {
            delete_magie (i);
         }
      }
   }
}


void Magie::Up (const size_t i) {

   if (m_orientation [i] == 0) {

      if (m_trajet [i] - 10 >= 0) {
         m_Rmagie [i] .y -= 10;
         m_trajet [i] -= 10;
      }
   }
   else if (m_orientation [i] == 1) {

      if (m_trajet [i] - 10 >= 0) {
         m_Rmagie [i] .x += 10;
         m_trajet [i] -= 10;
      }
   }
   else if (m_orientation [i] == 2) {

      if (m_trajet [i] - 10 >= 0) {
         m_Rmagie [i] .y += 10;
         m_trajet [i] -= 10;
      }
   }
   else if (m_orientation [i] == 3) {

      if (m_trajet [i] - 10 >= 0) {
         m_Rmagie [i] .x -= 10;
         m_trajet [i] -= 10;
      }
   }
}


void Magie::afficher (SDL_Renderer *renderer1, SDL_Renderer *renderer2) {
   for (size_t i = 0 ; i < m_nb_magie ; i += 1) {
      SDL_RenderCopy (renderer1, m_magie1, NULL, &m_Rmagie [i]);
      SDL_RenderCopy (renderer2, m_magie2, NULL, &m_Rmagie [i]);
   }
}


void Magie::afficher (SDL_Renderer *renderer1, SDL_Renderer *renderer2, const int id) {
   SDL_RenderCopy (renderer1, m_magie1, NULL, &m_Rmagie [id]);
   SDL_RenderCopy (renderer2, m_magie2, NULL, &m_Rmagie [id]);
}


void Magie::a_touche (const int id) {
   m_Rmagie [id] .x = -50;
   m_Rmagie [id] .y = -50;
}


SDL_Rect Magie::get_rect (const int id) {
   return m_Rmagie [id];
}


int Magie::get_nb_magies () const {
   return m_nb_magie;
}



