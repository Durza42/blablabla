#include "Perso.h"

   // assembleur
Perso::Perso (SDL_Renderer *renderer) {
   ld_img_cpp (&m_img_perso [0], renderer, "imgs/Dos_perso.bmp");
   ld_img_cpp (&m_img_perso [1], renderer, "imgs/Droite_perso.bmp");
   ld_img_cpp (&m_img_perso [2], renderer, "imgs/Face_perso.bmp");
   ld_img_cpp (&m_img_perso [3], renderer, "imgs/Gauche_perso.bmp");

   m_orientation = 2; // vers le bas
   m_depl = 25;

   m_R_perso = (SDL_Rect) {410, 250, 40, 50};

   m_name = "anonymous";
}

   // assembleur
Perso::Perso (SDL_Renderer *renderer, std::string name) {
   ld_img_cpp (&m_img_perso [0], renderer, "imgs/Dos_perso.bmp");
   ld_img_cpp (&m_img_perso [1], renderer, "imgs/Droite_perso.bmp");
   ld_img_cpp (&m_img_perso [2], renderer, "imgs/Face_perso.bmp");
   ld_img_cpp (&m_img_perso [3], renderer, "imgs/Gauche_perso.bmp");

   m_orientation = 2; // vers le bas
   m_depl = 25;

   m_R_perso = (SDL_Rect) {410, 275, 40, 50};

   m_name = name;
}

   // destructeur
Perso::~Perso () {
   SDL_DestroyTexture (m_img_perso [0]);
   SDL_DestroyTexture (m_img_perso [1]);
   SDL_DestroyTexture (m_img_perso [2]);
   SDL_DestroyTexture (m_img_perso [3]);
}


void Perso::afficher (SDL_Renderer *renderer) {
   SDL_RenderCopy (renderer, m_img_perso [m_orientation], NULL, &m_R_perso);
}


void Perso::droite () {
   m_orientation = 1;

   if (m_R_perso.x + m_depl <= 900 - m_R_perso.w)
      m_R_perso.x += m_depl;
}


void Perso::gauche () {
   m_orientation = 3;

   if (m_R_perso.x - m_depl >= 0)
      m_R_perso.x -= m_depl;
}


void Perso::haut () {
   m_orientation = 0;

   if (m_R_perso.y - m_depl >= 0)
      m_R_perso.y -= m_depl;
}


void Perso::bas () {
   m_orientation = 2;

   if (m_R_perso.y + m_depl <= 600 - m_R_perso.h)
      m_R_perso.y += m_depl;
}


int Perso::attaquer () {
   return 0;
}


int Perso::recevoir_degats (int degats) {
   return 0;
}






