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
#include "../lib_malo/malo.h" // ATENTION : bibliothèque écrite en C
#include <iostream>


   // assembleur
Perso::Perso (SDL_Renderer *renderer, TTF_Font *font) {
   ld_img_cpp (&m_img_perso [0], renderer, "imgs/Dos_perso.bmp");
   ld_img_cpp (&m_img_perso [1], renderer, "imgs/Droite_perso.bmp");
   ld_img_cpp (&m_img_perso [2], renderer, "imgs/Face_perso.bmp");
   ld_img_cpp (&m_img_perso [3], renderer, "imgs/Gauche_perso.bmp");

   ld_img_cpp (&m_when_dead, renderer, "imgs/skull.bmp");

   m_orientation = 2; // vers le bas
   m_depl = 5;
   m_porte = 350;
   m_vie = 100;
   m_degats = 15;
   m_is_alive = true;

   m_is_fighting = false;
   ld_img_cpp (&m_fleche [0], renderer, "imgs/fleche.bmp");
   ld_img_cpp (&m_fleche [1], renderer, "imgs/fleche_droite.bmp");
   ld_img_cpp (&m_fleche [2], renderer, "imgs/fleche_bas.bmp");
   ld_img_cpp (&m_fleche [3], renderer, "imgs/fleche_gauche.bmp");
   ld_img_cpp (&m_special_fleche [0], renderer, "imgs/special_fleche.bmp");
   ld_img_cpp (&m_special_fleche [1], renderer, "imgs/special_fleche_droite.bmp");
   ld_img_cpp (&m_special_fleche [2], renderer, "imgs/special_fleche_bas.bmp");
   ld_img_cpp (&m_special_fleche [3], renderer, "imgs/special_fleche_gauche.bmp");
   m_Rfleche = (SDL_Rect) {0, 0, m_porte * 50, 50};

   m_R_perso = (SDL_Rect) {400, 250, 50, 50};

   m_name = "anonymous";

   m_C_perso = (SDL_Color) {128, 50, 0};
   m_Rpseudo = (SDL_Rect) {375, 190, 100, 30};
   m_Rvie = (SDL_Rect) {375, 230, 100, 10};
   m_Rvie_tot = (SDL_Rect) {375, 230, 100, 10};
   ttf_print_B_cpp (m_name.c_str (), &m_pseudo, renderer, font, m_C_perso);
}

   // assembleur
Perso::Perso (SDL_Renderer *renderer, std::string name, TTF_Font *font) {
   ld_img_cpp (&m_img_perso [0], renderer, "imgs/Dos_perso.bmp");
   ld_img_cpp (&m_img_perso [1], renderer, "imgs/Droite_perso.bmp");
   ld_img_cpp (&m_img_perso [2], renderer, "imgs/Face_perso.bmp");
   ld_img_cpp (&m_img_perso [3], renderer, "imgs/Gauche_perso.bmp");

   ld_img_cpp (&m_when_dead, renderer, "imgs/skull.bmp");

   m_orientation = 2; // vers le bas
   m_depl = 5;
   m_porte = 350;
   m_vie = 100;
   m_degats = 15;
   m_is_alive = true;

   m_is_fighting = false;
   ld_img_cpp (&m_fleche [0], renderer, "imgs/fleche.bmp");
   ld_img_cpp (&m_fleche [1], renderer, "imgs/fleche_droite.bmp");
   ld_img_cpp (&m_fleche [2], renderer, "imgs/fleche_bas.bmp");
   ld_img_cpp (&m_fleche [3], renderer, "imgs/fleche_gauche.bmp");
   ld_img_cpp (&m_special_fleche [0], renderer, "imgs/special_fleche.bmp");
   ld_img_cpp (&m_special_fleche [1], renderer, "imgs/special_fleche_droite.bmp");
   ld_img_cpp (&m_special_fleche [2], renderer, "imgs/special_fleche_bas.bmp");
   ld_img_cpp (&m_special_fleche [3], renderer, "imgs/special_fleche_gauche.bmp");
   m_Rfleche = (SDL_Rect) {0, 0, m_porte * 50, 50};

   m_R_perso = (SDL_Rect) {400, 250, 50, 50};

   m_name = name;

   m_C_perso = (SDL_Color) {128, 50, 0};
   m_Rpseudo = (SDL_Rect) {375, 190, 100, 30};
   m_Rvie = (SDL_Rect) {375, 230, 100, 10};
   m_Rvie_tot = (SDL_Rect) {375, 230, 100, 10};
   ttf_print_B_cpp (m_name.c_str (), &m_pseudo, renderer, font, m_C_perso);
}


   // assembleur
Perso::Perso (SDL_Renderer *renderer, std::string name, SDL_Color C, TTF_Font *font) {
   ld_img_cpp (&m_img_perso [0], renderer, "imgs/Dos_perso.bmp");
   ld_img_cpp (&m_img_perso [1], renderer, "imgs/Droite_perso.bmp");
   ld_img_cpp (&m_img_perso [2], renderer, "imgs/Face_perso.bmp");
   ld_img_cpp (&m_img_perso [3], renderer, "imgs/Gauche_perso.bmp");

   ld_img_cpp (&m_when_dead, renderer, "imgs/skull.bmp");

   m_orientation = 2; // vers le bas
   m_depl = 5;
   m_porte = 350;
   m_vie = 100;
   m_degats = 15;
   m_is_alive = true;

   m_is_fighting = false;
   ld_img_cpp (&m_fleche [0], renderer, "imgs/fleche.bmp");
   ld_img_cpp (&m_fleche [1], renderer, "imgs/fleche_droite.bmp");
   ld_img_cpp (&m_fleche [2], renderer, "imgs/fleche_bas.bmp");
   ld_img_cpp (&m_fleche [3], renderer, "imgs/fleche_gauche.bmp");
   ld_img_cpp (&m_special_fleche [0], renderer, "imgs/special_fleche.bmp");
   ld_img_cpp (&m_special_fleche [1], renderer, "imgs/special_fleche_droite.bmp");
   ld_img_cpp (&m_special_fleche [2], renderer, "imgs/special_fleche_bas.bmp");
   ld_img_cpp (&m_special_fleche [3], renderer, "imgs/special_fleche_gauche.bmp");
   m_Rfleche = (SDL_Rect) {0, 0, m_porte * 50, 50};

   m_R_perso = (SDL_Rect) {400, 250, 50, 50};

   m_name = name;

   m_C_perso = C;
   m_Rpseudo = (SDL_Rect) {375, 190, 100, 30};
   m_Rvie = (SDL_Rect) {375, 230, 100, 10};
   m_Rvie_tot = (SDL_Rect) {375, 230, 100, 10};
   ttf_print_B_cpp (m_name.c_str (), &m_pseudo, renderer, font, m_C_perso);
}

   // destructeur
Perso::~Perso () {
   SDL_DestroyTexture (m_img_perso [0]);
   SDL_DestroyTexture (m_img_perso [1]);
   SDL_DestroyTexture (m_img_perso [2]);
   SDL_DestroyTexture (m_img_perso [3]);
   SDL_DestroyTexture (m_fleche [0]);
   SDL_DestroyTexture (m_fleche [1]);
   SDL_DestroyTexture (m_fleche [2]);
   SDL_DestroyTexture (m_fleche [3]);
   SDL_DestroyTexture (m_special_fleche [0]);
   SDL_DestroyTexture (m_special_fleche [1]);
   SDL_DestroyTexture (m_special_fleche [2]);
   SDL_DestroyTexture (m_special_fleche [3]);
}


void Perso::afficher (SDL_Renderer *renderer, SDL_Texture *text_perso_adv) {

   SDL_RenderCopy (renderer, text_perso_adv, NULL, &m_RadvPerso);

   SDL_RenderCopy (renderer, m_pseudo, NULL, &m_Rpseudo);

   SDL_SetRenderDrawColor (renderer, 150, 0, 0, 0);
   SDL_RenderFillRect (renderer, &m_Rvie);

   SDL_SetRenderDrawColor (renderer, 0, 0, 0, 0);
   SDL_RenderDrawRect (renderer, &m_Rvie_tot);

   SDL_RenderCopy (renderer, m_img_perso [m_orientation], NULL, &m_R_perso);


   SDL_Point center;
   center.x = m_Rfleche.x + (m_Rfleche.w / 2);
   center.y = m_Rfleche.y + (m_Rfleche.h / 2);

   if (m_is_fighting) {
      if (m_fight_use_special)
         SDL_RenderCopy (renderer, m_fleche [m_orientation], NULL, &m_Rfleche);
      else
         SDL_RenderCopy (renderer, m_special_fleche [m_orientation], NULL, &m_Rfleche);
   }
}


void Perso::droite (Back& map) {

   if (!m_is_alive)
      return;

   m_orientation = 1;

   if (!m_is_fighting) {

      if (m_R_perso.x + m_R_perso.w + m_depl < 900 && map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x + m_R_perso.w + m_depl, false), convert_cooWindY_to_cooMapY (m_R_perso.y, false)) != 2 && map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x + m_R_perso.w + m_depl, false), convert_cooWindY_to_cooMapY (m_R_perso.y + m_R_perso.h, false)) != 2) {
         m_R_perso.x += m_depl;
         m_Rpseudo.x += m_depl;
         m_Rvie.x += m_depl;
         m_Rvie_tot.x += m_depl;
      }

   }
   else {
      m_Rfleche.w = m_porte;
      m_Rfleche.h = 50;
      m_Rfleche.x = m_R_perso.x + m_R_perso.w;
      m_Rfleche.y = m_R_perso.y;
   }
}


void Perso::gauche (Back& map) {

   if (!m_is_alive)
      return;

   m_orientation = 3;

   if (!m_is_fighting) {

      if (m_R_perso.x - m_depl > 0 && map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x - m_depl, false), convert_cooWindY_to_cooMapY (m_R_perso.y, false)) != 2 && map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x - m_depl, false), convert_cooWindY_to_cooMapY (m_R_perso.y + m_R_perso.h, false)) != 2) {
         m_R_perso.x -= m_depl;
         m_Rpseudo.x -= m_depl;
         m_Rvie.x -= m_depl;
         m_Rvie_tot.x -= m_depl;
      }

   }
   else {
      m_Rfleche.w = m_porte;
      m_Rfleche.h = 50;
      m_Rfleche.x = m_R_perso.x - m_Rfleche.w;
      m_Rfleche.y = m_R_perso.y;
   }
}


void Perso::haut (Back& map) {

   if (!m_is_alive)
      return;

   m_orientation = 0;

   if (!m_is_fighting) {

      if (m_R_perso.y - m_depl > 0 && map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x, false), convert_cooWindY_to_cooMapY (m_R_perso.y - m_depl, false)) != 2 && map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x + m_R_perso.w, false), convert_cooWindY_to_cooMapY (m_R_perso.y - m_depl, false)) != 2) {
         m_R_perso.y -= m_depl;
         m_Rpseudo.y -= m_depl;
         m_Rvie.y -= m_depl;
         m_Rvie_tot.y -= m_depl;
      }

   }
   else {
      m_Rfleche.w = 50;
      m_Rfleche.h = m_porte;
      m_Rfleche.y = m_R_perso.y - m_Rfleche.h;
      m_Rfleche.x = m_R_perso.x;
   }
}


void Perso::bas (Back& map) {

   if (!m_is_alive)
      return;

   m_orientation = 2;

   if (!m_is_fighting) {

      if (m_R_perso.y + m_R_perso.h + m_depl < 600 && map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x, false), convert_cooWindY_to_cooMapY (m_R_perso.y + m_R_perso.h + m_depl, false)) != 2 && map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x + m_R_perso.w, false), convert_cooWindY_to_cooMapY (m_R_perso.y + m_R_perso.h + m_depl, false)) != 2) {
         m_R_perso.y += m_depl;
         m_Rpseudo.y += m_depl;
         m_Rvie.y += m_depl;
         m_Rvie_tot.y += m_depl;
      }

   }
   else {
      m_Rfleche.w = 50;
      m_Rfleche.h = m_porte;
      m_Rfleche.y = m_R_perso.y + m_R_perso.h;
      m_Rfleche.x = m_R_perso.x;
   }
}


void Perso::vise () {

   if (!m_is_alive)
      return;

   m_is_fighting = true;
   m_fight_use_special = false;
}


void Perso::vise_special () {

   if (!m_is_alive)
      return;

   m_is_fighting = true;
   m_fight_use_special = true;
}


int Perso::attaquer () {

   if (!m_is_alive)
      return -1;

   if (m_is_fighting) {
      if (m_fight_use_special) {
         attaquer_special ();
         return 1;
      }
      else {
         attaquer_physique ();
         return 0;
      }
   }
   else {
      return -1;
   }
}


void Perso::attaquer_physique () {

   if (!m_is_alive)
      return;

   m_is_fighting = false;
   m_fight_use_special = false;
}


void Perso::attaquer_special () {

   if (!m_is_alive)
      return;

   m_is_fighting = false;
   m_fight_use_special = false;

   m_a_tire = true;
}


   /* ne peux pas être constant, car retourne un pointeur pouvant être modifié par les fonctions de la SDL. */
SDL_Rect* Perso::get_pos () {
   return &m_R_perso;
}


int Perso::get_orientation () const {
   return m_orientation;
}


int Perso::get_porte () const {
   return m_porte;
}


bool Perso::is_touched (SDL_Rect rect) const {
   return SDL_HasIntersection (&rect, &m_R_perso);
}


void Perso::perdre_vie (int vie_perdue) {

   if (!m_is_alive)
      return;

   if (m_vie - vie_perdue > 0)
      m_vie -= vie_perdue;
   else
      m_vie = 0;
}


bool Perso::is_dead () const {
   return m_vie == 0;
}


int Perso::get_degats () const {
   return m_degats;
}


void Perso::dead () {
   m_is_alive = false;
   m_img_perso [0] = m_when_dead;
   m_img_perso [1] = m_when_dead;
   m_img_perso [2] = m_when_dead;
   m_img_perso [3] = m_when_dead;
   return;
}


   /* return false if the perso is died, or true if it is alive. */
bool Perso::up (Magie *magie, int degats_poss) {

   if (!m_is_alive)
      return false;

   if (is_touched (magie -> get_rect ())) {
      perdre_vie (degats_poss);
      magie -> a_touche ();
   }

   m_Rvie.w = m_vie;

   if (is_dead ()) {
      dead ();
      return false;
   }
   else {
      return true;
   }
}


SDL_Texture* Perso::get_text () const {
   return m_img_perso [m_orientation];
}




