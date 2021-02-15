#include <iostream>
#include <string>
#include "arme.h"
#include "modele_arme.h"

#define CPP

#include "../lib_malo/malo.h"

   // assembleur
Arme::Arme (SDL_Renderer *renderer, SDL_Renderer *renderer2, Modele modeles) {

   m_name = "epee_rouille";

   std::string path;

   modeles.copie_modele ("epee_rouille", &m_degats, &m_degats_str, &path);

   ld_img_cpp (&m_text1, renderer, path);
   ld_img_cpp (&m_text2, renderer2, path);

   if (m_text1 == NULL || m_text2 == NULL)
      std::cout << "DANGER : texture NULL ! invalid path." << std::endl << "error :" << SDL_GetError () << std::endl;

   m_rect = (SDL_Rect) {0, 0, 100, 30};

   m_delta = 0;
   m_delta_max = 150;
   m_delta_dep = 15;
   m_delta_begining = 0;

   m_used = false;

   m_center.x = 100;
   m_center.y = 30;
}


   // assembleur
Arme::Arme (SDL_Renderer *renderer, SDL_Renderer *renderer2, Modele modeles, std::string name) {

   m_name = name;

   std::string path;

   modeles.copie_modele (name, &m_degats, &m_degats_str, &path);

   ld_img_cpp (&m_text1, renderer, path);
   ld_img_cpp (&m_text2, renderer2, path);

   if (m_text1 == NULL || m_text2 == NULL)
      std::cout << "DANGER : texture NULL ! invalid path." << std::endl << "error :" << SDL_GetError () << std::endl;

   m_rect = (SDL_Rect) {0, 0, 100, 30};

   m_delta = 0;
   m_delta_max = 150;
   m_delta_dep = 15;
   m_delta_begining = 0;

   m_used = false;

   m_center.x = 100;
   m_center.y = 30;
}


   // destructeur
Arme::~Arme () {
   SDL_DestroyTexture (m_text1);
   SDL_DestroyTexture (m_text2);
}


void Arme::afficher (SDL_Renderer *renderer, int id_renderer) {
   if (m_used == false)
      return;

   if (m_delta + 5 < m_delta_max)
      m_delta += 5;
   else
      m_used = false;

   if (id_renderer == 1)
      SDL_RenderCopyEx (renderer, m_text1, NULL, &m_rect, m_delta_begining + m_delta, &m_center, SDL_FLIP_NONE);
   else if (id_renderer == 2)
      SDL_RenderCopyEx (renderer, m_text2, NULL, &m_rect, m_delta_begining + m_delta, &m_center, SDL_FLIP_NONE);
   else
      std::cout << "error : unknow renderer #" << id_renderer << " ; renderer #" << id_renderer << " inconnu" << std::endl;
}


void Arme::begin_attaque (int orientation, SDL_Point coo) {

   m_used = true;
   m_peut_toucher = true;

   switch (orientation) {
      case 1:
         m_delta_begining = 0;
         m_rect.x = coo.x;
         m_rect.y = coo.y;
     break;
      case 2:
         m_delta_begining = 90;
         m_rect.x = coo.x - 90;
         m_rect.y = coo.y + 70;
     break;
      case 3:
         m_delta_begining = 180;
         m_rect.x = coo.x - 140;
         m_rect.y = coo.y - 20;
     break;
      case 0:
         m_delta_begining = 270;
         m_rect.x = coo.x - 50;
         m_rect.y = coo.y - 60;
     break;
   }

   m_delta = 0;

   return;
}


SDL_Rect Arme::get_rect () const {
   if (!m_used || !m_peut_toucher)
      return (SDL_Rect) {-50, -50, 0, 0};


   if (m_delta < 40) // pour avoir un temps entre le moment où l'arme se dégaine et celui où les dégats sont infligés
      return (SDL_Rect) {-50, -50, 0, 0};

   if (m_delta_begining == 0) // si orienté droite
      return (SDL_Rect {m_rect.x, m_rect.y, m_rect.w * 2, m_rect.w});
   else if (m_delta_begining == 90) // si orienté bas
      return (SDL_Rect {m_rect.x, m_rect.y, m_rect.w, m_rect.w});
   else if (m_delta_begining == 180) // si orienté gauche
      return (SDL_Rect {m_rect.x, m_rect.y, m_rect.w * 2, m_rect.w});
   else if (m_delta_begining == 270) // si orienté haut
      return (SDL_Rect {m_rect.x, m_rect.y - 50, m_rect.w, m_rect.w * 2});

   return (SDL_Rect) {-50, -50, 0, 0};
}

void Arme::a_touche () {
   m_peut_toucher = false;
}


int Arme::get_degats () const {
   return m_degats;
}


const char* Arme::get_degats_str () const {
   return m_degats_str.c_str ();
}


SDL_Texture* Arme::get_texture (int id_renderer) {

   if (id_renderer == 1)
      return m_text1;
   else if (id_renderer == 2)
      return m_text2;

   return NULL;
}


void Arme::synchro_with_modele (Modele modeles, const int id, SDL_Renderer *renderer, SDL_Renderer *renderer2) {

   std::string path;

   modeles.copie_modele_id (id, &m_name, &m_degats, &m_degats_str, &path);

   SDL_DestroyTexture (m_text1);
   ld_img_cpp (&m_text1, renderer, path);

   SDL_DestroyTexture (m_text2);
   ld_img_cpp (&m_text2, renderer2, path);
}



