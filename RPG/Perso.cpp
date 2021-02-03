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
Perso::Perso (SDL_Renderer *renderer, SDL_Renderer *renderer2, TTF_Font *font) {

   ld_img_cpp (&m_img_perso [0], renderer, "imgs/Dos_perso.bmp");
   ld_img_cpp (&m_img_perso [1], renderer, "imgs/Droite_perso.bmp");
   ld_img_cpp (&m_img_perso [2], renderer, "imgs/Face_perso.bmp");
   ld_img_cpp (&m_img_perso [3], renderer, "imgs/Gauche_perso.bmp");

   ld_img_cpp (&m_img_perso2 [0], renderer2, "imgs/Dos_perso.bmp");
   ld_img_cpp (&m_img_perso2 [1], renderer2, "imgs/Droite_perso.bmp");
   ld_img_cpp (&m_img_perso2 [2], renderer2, "imgs/Face_perso.bmp");
   ld_img_cpp (&m_img_perso2 [3], renderer2, "imgs/Gauche_perso.bmp");

   ld_img_cpp (&m_when_dead, renderer, "imgs/skull.bmp");
   ld_img_cpp (&m_when_dead2, renderer2, "imgs/skull.bmp");

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
   ttf_print_B_cpp (m_name.c_str (), &m_pseudo2, renderer2, font, m_C_perso);
}

   // assembleur
Perso::Perso (SDL_Renderer *renderer, SDL_Renderer *renderer2, std::string name, TTF_Font *font) {
   ld_img_cpp (&m_img_perso [0], renderer, "imgs/Dos_perso.bmp");
   ld_img_cpp (&m_img_perso [1], renderer, "imgs/Droite_perso.bmp");
   ld_img_cpp (&m_img_perso [2], renderer, "imgs/Face_perso.bmp");
   ld_img_cpp (&m_img_perso [3], renderer, "imgs/Gauche_perso.bmp");

   ld_img_cpp (&m_img_perso2 [0], renderer2, "imgs/Dos_perso.bmp");
   ld_img_cpp (&m_img_perso2 [1], renderer2, "imgs/Droite_perso.bmp");
   ld_img_cpp (&m_img_perso2 [2], renderer2, "imgs/Face_perso.bmp");
   ld_img_cpp (&m_img_perso2 [3], renderer2, "imgs/Gauche_perso.bmp");

   ld_img_cpp (&m_when_dead, renderer, "imgs/skull.bmp");
   ld_img_cpp (&m_when_dead2, renderer2, "imgs/skull.bmp");

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
   ttf_print_B_cpp (m_name.c_str (), &m_pseudo2, renderer2, font, m_C_perso);
}


   // assembleur
Perso::Perso (SDL_Renderer *renderer, SDL_Renderer *renderer2, std::string name, SDL_Color C, TTF_Font *font) {
   ld_img_cpp (&m_img_perso [0], renderer, "imgs/Dos_perso.bmp");
   ld_img_cpp (&m_img_perso [1], renderer, "imgs/Droite_perso.bmp");
   ld_img_cpp (&m_img_perso [2], renderer, "imgs/Face_perso.bmp");
   ld_img_cpp (&m_img_perso [3], renderer, "imgs/Gauche_perso.bmp");

   ld_img_cpp (&m_img_perso2 [0], renderer2, "imgs/Dos_perso.bmp");
   ld_img_cpp (&m_img_perso2 [1], renderer2, "imgs/Droite_perso.bmp");
   ld_img_cpp (&m_img_perso2 [2], renderer2, "imgs/Face_perso.bmp");
   ld_img_cpp (&m_img_perso2 [3], renderer2, "imgs/Gauche_perso.bmp");

   ld_img_cpp (&m_when_dead, renderer, "imgs/skull.bmp");
   ld_img_cpp (&m_when_dead2, renderer2, "imgs/skull.bmp");

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
   ttf_print_B_cpp (m_name.c_str (), &m_pseudo2, renderer2, font, m_C_perso);
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
   SDL_DestroyTexture (m_special_fleche [0]);
   SDL_DestroyTexture (m_special_fleche [1]);
   SDL_DestroyTexture (m_special_fleche [2]);
   SDL_DestroyTexture (m_special_fleche [3]);
   SDL_DestroyTexture (m_pseudo);
   SDL_DestroyTexture (m_pseudo2);
}


void Perso::afficher (SDL_Renderer *renderer, int id_renderer) {

   SDL_SetRenderDrawColor (renderer, 150, 0, 0, 0);
   SDL_RenderFillRect (renderer, &m_Rvie);

   SDL_SetRenderDrawColor (renderer, 0, 0, 0, 0);
   SDL_RenderDrawRect (renderer, &m_Rvie_tot);

   if (id_renderer == 1) {
      SDL_RenderCopy (renderer, m_pseudo, NULL, &m_Rpseudo);
      SDL_RenderCopy (renderer, m_img_perso [m_orientation], NULL, &m_R_perso);

      if (m_is_fighting) {
         if (m_fight_use_special)
            SDL_RenderCopy (renderer, m_fleche [m_orientation], NULL, &m_Rfleche);
         else
            SDL_RenderCopy (renderer, m_special_fleche [m_orientation], NULL, &m_Rfleche);
      }
   }
   else {
      SDL_RenderCopy (renderer, m_pseudo2, NULL, &m_Rpseudo);
      SDL_RenderCopy (renderer, m_img_perso2 [m_orientation], NULL, &m_R_perso);
   }
}


int Perso::droite (Back& map, SDL_Rect screen) {

   if (!m_is_alive)
      return 0;

   m_orientation = 1;

   if (m_is_fighting) {

      m_Rfleche.w = m_porte;
      m_Rfleche.h = 50;
      m_Rfleche.x = m_R_perso.x + m_R_perso.w;
      m_Rfleche.y = m_R_perso.y;

      return 0;
   }

   if (m_R_perso.x + m_R_perso.w < screen.x + 450) {

      if (map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x + m_depl + m_R_perso.w, false), convert_cooWindY_to_cooMapY (m_R_perso.y, false)) != 2 && map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x + m_R_perso.w + m_depl, false), convert_cooWindY_to_cooMapY (m_R_perso.y + m_R_perso.h, false)) != 2) { // si il peut aller à gauche

         m_R_perso.x += m_depl;
         m_Rpseudo.x += m_depl;
         m_Rvie.x += m_depl;
         m_Rvie_tot.x += m_depl;

         return 0;
      }
   }
   else if (screen.x + 900 + m_depl > 90 * 25) { // si l'écran ne peux pas aller plus à gauche normallement

      if (screen.x + 900 > 90 * 25) { // si l'écran peut encore aller plus en bas, mais moins que de m_depl

         if (map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x + m_R_perso.w + m_depl, false), convert_cooWindY_to_cooMapY (m_R_perso.y, false)) != 2 && map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x + m_R_perso.w + m_depl, false), convert_cooWindY_to_cooMapY (m_R_perso.y + m_R_perso.h, false)) != 2) { // si il peut aller en bas

            m_R_perso.x += m_depl;
            m_Rpseudo.x += m_depl;
            m_Rvie.x += m_depl;
            m_Rvie_tot.x += m_depl;

            return 90 * 25 - (screen.x + 900);
         }
      }

      if (map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x + m_R_perso.w + m_depl, false), convert_cooWindY_to_cooMapY (m_R_perso.y, false)) != 2 && map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x + m_R_perso.w + m_depl, false), convert_cooWindY_to_cooMapY (m_R_perso.y + m_R_perso.h, false)) != 2) { // si il peut aller à gauche

         m_R_perso.x += m_depl;
         m_Rpseudo.x += m_depl;
         m_Rvie.x += m_depl;
         m_Rvie_tot.x += m_depl;

         return 0;
      }
   }
   else {

      if (map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x + m_R_perso.w + m_depl, false), convert_cooWindY_to_cooMapY (m_R_perso.y, false)) != 2 && map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x + m_R_perso.w + m_depl, false), convert_cooWindY_to_cooMapY (m_R_perso.y + m_R_perso.h, false)) != 2) { // si il peut aller à gauche

         m_R_perso.x += m_depl;
         m_Rpseudo.x += m_depl;
         m_Rvie.x += m_depl;
         m_Rvie_tot.x += m_depl;

         return m_depl;
      }
   }
   return 0;
}


int Perso::gauche (Back& map, SDL_Rect screen) {

   if (!m_is_alive) // si il est mort, il ne peux pas bouger !
      return 0;

   m_orientation = 3; // il regarde à gauche

   if (m_is_fighting) { // si il se bat, il ne peux pas bouger !

      m_Rfleche.w = m_porte;
      m_Rfleche.h = 50;
      m_Rfleche.x = m_R_perso.x - m_Rfleche.w;
      m_Rfleche.y = m_R_perso.y;

      return 0;
   }

   if (m_R_perso.x > screen.x + 450) {

      if (map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x - m_depl, false), convert_cooWindY_to_cooMapY (m_R_perso.y, false)) != 2 && map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x - m_depl, false), convert_cooWindY_to_cooMapY (m_R_perso.y + m_R_perso.h, false)) != 2) { // si il peut aller à gauche

         m_R_perso.x -= m_depl;
         m_Rpseudo.x -= m_depl;
         m_Rvie.x -= m_depl;
         m_Rvie_tot.x -= m_depl;

         return 0;
      }
   }
   else if (screen.x - m_depl < 0) { // si l'écran ne peux pas aller plus à gauche normallement

      if (screen.x > 0) { // si l'écran peut encore aller plus à gauche, mais moins que de m_depl

         m_R_perso.x -= m_depl;
         m_Rpseudo.x -= m_depl;
         m_Rvie.x -= m_depl;
         m_Rvie_tot.x -= m_depl;

         return screen.x;
      }
      if (m_R_perso.x - m_depl >= 0) {
         if (map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x - m_depl, false), convert_cooWindY_to_cooMapY (m_R_perso.y, false)) != 2 && map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x - m_depl, false), convert_cooWindY_to_cooMapY (m_R_perso.y + m_R_perso.h, false)) != 2) { // si il peut aller à gauche

            m_R_perso.x -= m_depl;
            m_Rpseudo.x -= m_depl;
            m_Rvie.x -= m_depl;
            m_Rvie_tot.x -= m_depl;

            return 0;
         }
      }
   }
   else {

      if (map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x - m_depl, false), convert_cooWindY_to_cooMapY (m_R_perso.y, false)) != 2 && map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x - m_depl, false), convert_cooWindY_to_cooMapY (m_R_perso.y + m_R_perso.h, false)) != 2) { // si il peut aller à gauche

         m_R_perso.x -= m_depl;
         m_Rpseudo.x -= m_depl;
         m_Rvie.x -= m_depl;
         m_Rvie_tot.x -= m_depl;

         return 0 - m_depl;
      }
   }

   return 0;
}


int Perso::haut (Back& map, SDL_Rect screen) {

   if (!m_is_alive)
      return 0;

   m_orientation = 0;

   if (m_is_fighting) {
      m_Rfleche.w = 50;
      m_Rfleche.h = m_porte;
      m_Rfleche.y = m_R_perso.y - m_Rfleche.h;
      m_Rfleche.x = m_R_perso.x;

      return 0;
   }

   if (m_R_perso.y > screen.y + 300) {

      if (map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x, false), convert_cooWindY_to_cooMapY (m_R_perso.y - m_depl, false)) != 2 && map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x + m_R_perso.w, false), convert_cooWindY_to_cooMapY (m_R_perso.y - m_depl, false)) != 2) { // si il peut aller à gauche

         m_R_perso.y -= m_depl;
         m_Rpseudo.y -= m_depl;
         m_Rvie.y -= m_depl;
         m_Rvie_tot.y -= m_depl;

         return 0;
      }
   }
   else if (screen.y - m_depl < 0) { // si l'écran ne peux pas aller plus à gauche normallement

      if (screen.y > 0) { // si l'écran peut encore aller plus à gauche, mais moins que de m_depl

         if (map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x, false), convert_cooWindY_to_cooMapY (m_R_perso.y - m_depl, false)) != 2 && map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x + m_R_perso.w, false), convert_cooWindY_to_cooMapY (m_R_perso.y - m_depl, false)) != 2) { // si il peut aller à gauche

            m_R_perso.y -= m_depl;
            m_Rpseudo.y -= m_depl;
            m_Rvie.y -= m_depl;
            m_Rvie_tot.y -= m_depl;

            return screen.y;
         }
      }

      if (map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x, false), convert_cooWindY_to_cooMapY (m_R_perso.y - m_depl, false)) != 2 && map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x + m_R_perso.w, false), convert_cooWindY_to_cooMapY (m_R_perso.y - m_depl, false)) != 2) { // si il peut aller à gauche

         m_R_perso.y -= m_depl;
         m_Rpseudo.y -= m_depl;
         m_Rvie.y -= m_depl;
         m_Rvie_tot.y -= m_depl;

         return 0;
      }
   }
   else {

      if (map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x, false), convert_cooWindY_to_cooMapY (m_R_perso.y - m_depl, false)) != 2 && map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x + m_R_perso.w, false), convert_cooWindY_to_cooMapY (m_R_perso.y - m_depl, false)) != 2) { // si il peut aller à gauche

         m_R_perso.y -= m_depl;
         m_Rpseudo.y -= m_depl;
         m_Rvie.y -= m_depl;
         m_Rvie_tot.y -= m_depl;

         return 0 - m_depl;
      }
   }

   return 0;
}


int Perso::bas (Back& map, SDL_Rect screen) {

   if (!m_is_alive)
      return 0;

   m_orientation = 2;

   if (m_is_fighting) {

      m_Rfleche.w = 50;
      m_Rfleche.h = m_porte;
      m_Rfleche.y = m_R_perso.y + m_R_perso.h;
      m_Rfleche.x = m_R_perso.x;

      return 0;
   }

   if (m_R_perso.y + m_R_perso.h < screen.y + 300) {

      if (map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x, false), convert_cooWindY_to_cooMapY (m_R_perso.y + m_R_perso.h + m_depl, false)) != 2 && map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x + m_R_perso.w, false), convert_cooWindY_to_cooMapY (m_R_perso.y + m_R_perso.h + m_depl, false)) != 2) { // si il peut aller à gauche

         m_R_perso.y += m_depl;
         m_Rpseudo.y += m_depl;
         m_Rvie.y += m_depl;
         m_Rvie_tot.y += m_depl;

         return 0;
      }
   }
   else if (screen.y + 600 + m_depl > 60 * 25) { // si l'écran ne peux pas aller plus à gauche normallement

      if (screen.y + 600 > 60 * 25) { // si l'écran peut encore aller plus en bas, mais moins que de m_depl

         if (map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x, false), convert_cooWindY_to_cooMapY (m_R_perso.y + m_R_perso.h + m_depl, false)) != 2 && map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x + m_R_perso.w, false), convert_cooWindY_to_cooMapY (m_R_perso.y + m_R_perso.h + m_depl, false)) != 2) { // si il peut aller en bas

            m_R_perso.y += m_depl;
            m_Rpseudo.y += m_depl;
            m_Rvie.y += m_depl;
            m_Rvie_tot.y += m_depl;

            return 60 * 25 - (screen.y + 600);
         }
      }

      if (map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x, false), convert_cooWindY_to_cooMapY (m_R_perso.y + m_R_perso.h + m_depl, false)) != 2 && map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x + m_R_perso.w, false), convert_cooWindY_to_cooMapY (m_R_perso.y + m_R_perso.h + m_depl, false)) != 2) { // si il peut aller à gauche

         m_R_perso.y += m_depl;
         m_Rpseudo.y += m_depl;
         m_Rvie.y += m_depl;
         m_Rvie_tot.y += m_depl;

         return 0;
      }
   }
   else {

      if (map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x, false), convert_cooWindY_to_cooMapY (m_R_perso.y + m_R_perso.h + m_depl, false)) != 2 && map.get_value (convert_cooWindX_to_cooMapX (m_R_perso.x + m_R_perso.w, false), convert_cooWindY_to_cooMapY (m_R_perso.y + m_R_perso.h + m_depl, false)) != 2) { // si il peut aller à gauche

         m_R_perso.y += m_depl;
         m_Rpseudo.y += m_depl;
         m_Rvie.y += m_depl;
         m_Rvie_tot.y += m_depl;

         return m_depl;
      }
   }
   return 0;
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
SDL_Rect Perso::get_pos () {
   return m_R_perso;
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
   m_img_perso2 [0] = m_when_dead2;
   m_img_perso2 [1] = m_when_dead2;
   m_img_perso2 [2] = m_when_dead2;
   m_img_perso2 [3] = m_when_dead2;
   return;
}


   /* return false if the perso is died, or true if it is alive. */
bool Perso::up (Magie *magie, int degats_poss) {

   if (!m_is_alive)
      return false;

   for (size_t i = 0 ; i < magie -> get_nb_magies () ; i++) {
      if (is_touched (magie -> get_rect (i))) {
         perdre_vie (degats_poss);
         magie -> a_touche (i);
      }
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
