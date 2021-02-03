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


int boucle () {

   Basic var (0, 0);
   Basic var2 (100, 600);

      /* deux map sont malheureusement obligatoires, car une texture est affiliée à un renderer et ne peut s'afficher sur un autre. */
   Back map (var.get_renderer ());
   Back map2 (var2.get_renderer ());

   Perso perso_1 (var.get_renderer (), var2.get_renderer (), "squelette", (SDL_Color) {128, 128, 128}, var.get_font ());
   Perso perso_2 (var2.get_renderer (), var.get_renderer (), "viking", (SDL_Color) {50, 50, 150}, var.get_font ());

   SDL_Event event;

   Magie magie (var.get_renderer (), var2.get_renderer (), (SDL_Rect) {-50, -50, 50, 50}, perso_1.get_orientation (), perso_1.get_porte ());
   Magie magie2 (var.get_renderer (), var2.get_renderer (), (SDL_Rect) {-50, -50, 50, 50}, perso_2.get_orientation (), perso_2.get_porte ());

   unsigned int right = 0, left = 0, up = 0, down = 0;

   while (1) {

      SDL_Delay (15); // 60 fps

      if (right + 500 > SDL_GetTicks ()) {
         var2.change_Xscreen (perso_2.droite (map, var2.get_Rscreen ()));
      }
      else if (left + 500 > SDL_GetTicks ()) {
         var2.change_Xscreen (perso_2.gauche (map, var2.get_Rscreen ()));
      }
      else if (up + 500 > SDL_GetTicks ()) {
         var2.change_Yscreen (perso_2.haut (map, var2.get_Rscreen ()));
      }
      else if (down + 500 > SDL_GetTicks ()) {
         var2.change_Yscreen (perso_2.bas (map, var2.get_Rscreen ()));
      }

      while (SDL_PollEvent (&event)) {
         if (event.type == SDL_WINDOWEVENT) {
            if (event.window.event == SDL_WINDOWEVENT_CLOSE) // Fermeture de la fenêtre
               return 0;
         }
         else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_RIGHT) {
               var2.change_Xscreen (perso_2.droite (map, var2.get_Rscreen ()));
               right = SDL_GetTicks ();
            }
            else if (event.key.keysym.sym == SDLK_LEFT) {
               var2.change_Xscreen (perso_2.gauche (map, var2.get_Rscreen ()));
               left = SDL_GetTicks ();
            }
            else if (event.key.keysym.sym == SDLK_UP) {
               var2.change_Yscreen (perso_2.haut (map, var2.get_Rscreen ()));
               up = SDL_GetTicks ();
            }
            else if (event.key.keysym.sym == SDLK_DOWN) {
               var2.change_Yscreen (perso_2.bas (map, var2.get_Rscreen ()));
               down = SDL_GetTicks ();
            }
            else if (event.key.keysym.sym == SDLK_a) {
               perso_2.vise ();
            }
            else if (event.key.keysym.sym == SDLK_d) {
               perso_2.vise_special ();
            }
         }
         else if (event.type == SDL_KEYUP) {
            if (event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_d) {
               if (perso_2.attaquer () == 1) { // attaquer renvoie 0 si c'est une attaque physique et 1 si c'est une attaque spéciale
                  magie2.add_magie (perso_2.get_pos (), perso_2.get_orientation (), perso_2.get_porte ());
               }
            }
            else if (event.key.keysym.sym == SDLK_RIGHT) {
               right = 0;
            }
            else if (event.key.keysym.sym == SDLK_LEFT) {
               left = 0;
            }
            else if (event.key.keysym.sym == SDLK_UP) {
               up = 0;
            }
            else if (event.key.keysym.sym == SDLK_DOWN) {
               down = 0;
            }
         }
         else if (event.type == SDL_MOUSEMOTION) {

            if (std::abs (event.motion.xrel) > std::abs (event.motion.yrel)) { // si la souris s'est plus déplacée en x que en y

               if (event.motion.xrel > 0) // droite
                  var.change_Xscreen (perso_1.droite (map, var.get_Rscreen ()));
               else if (event.motion.xrel < 0) // gauche
                  var.change_Xscreen (perso_1.gauche (map, var.get_Rscreen ()));

            }
            else if (std::abs (event.motion.xrel) < std::abs (event.motion.yrel)) { // si la souris s'est plus déplacée en x que en y

               if (event.motion.yrel < 0) // haut
                  var.change_Yscreen (perso_1.haut (map, var.get_Rscreen ()));
               else if (event.motion.yrel > 0) // bas
                  var.change_Yscreen (perso_1.bas (map, var2.get_Rscreen ()));
            }
         }
         else if (event.type == SDL_MOUSEBUTTONDOWN) { // on appuie sur une touche de la souris

            if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON (1)) // left clic
               perso_1.vise_special ();
            else // other clic
               perso_1.vise ();
         }
         else if (event.type == SDL_MOUSEBUTTONUP) { // on relache sur une touche de la souris
            if (perso_1.attaquer () == 1) { // attaquer renvoie 0 si c'est une attaque physique et 1 si c'est une attaque spéciale
               magie.add_magie (perso_1.get_pos (), perso_1.get_orientation (), perso_1.get_porte ());
            }
         }
      }
      if (magie.get_nb_magies () > 0) {

         magie.Up ();

         perso_2.up (&magie, perso_1.get_degats ());

         if (magie2.get_nb_magies () == 0) {
            update_screen (&perso_1, &perso_2, &map, &map2, &var, &var2, &magie);
         }
      }
      if (magie2.get_nb_magies () > 0) {

         magie2.Up ();

         if (magie.get_nb_magies () == 0) {
            update_screen (&perso_1, &perso_2, &map, &map2, &var, &var2, &magie2);
         }

         perso_1.up (&magie2, perso_2.get_degats ());

      }
      if (magie.get_nb_magies () > 0 && magie2.get_nb_magies () > 0) {
            update_screen (&perso_1, &perso_2, &map, &map2, &var, &var2, &magie, &magie2);
      }
      if (magie.get_nb_magies () == 0 && magie2.get_nb_magies () == 0) {
            update_screen (&perso_1, &perso_2, &map, &map2, &var, &var2);
      }
   }
}


void update_screen (Perso *perso_1, Perso *perso_2, Back *map, Back *map2, Basic *var, Basic *var2) {
   var -> clear ();
   var2 -> clear ();
   map -> afficher (var -> get_renderer (), var -> get_Rscreen ());
   map2 -> afficher (var2 -> get_renderer (), var2 -> get_Rscreen ());
   perso_1 -> afficher (var -> get_renderer (), 1);
   perso_1 -> afficher (var2 -> get_renderer (), 2);
   perso_2 -> afficher (var -> get_renderer (), 2);
   perso_2 -> afficher (var2 -> get_renderer (), 1);
   var -> render_present ();
   var2 -> render_present ();
}


void update_screen (Perso *perso_1, Perso *perso_2, Back *map, Back *map2, Basic *var, Basic *var2, Magie *magie) {
   var -> clear ();
   var2 -> clear ();
   map -> afficher (var -> get_renderer (), var -> get_Rscreen ());
   map2 -> afficher (var -> get_renderer (), var -> get_Rscreen ());
   perso_1 -> afficher (var -> get_renderer (), 1);
   perso_1 -> afficher (var2 -> get_renderer (), 2);
   perso_2 -> afficher (var -> get_renderer (), 2);
   perso_2 -> afficher (var2 -> get_renderer (), 1);
   magie -> afficher (var -> get_renderer (), var2 -> get_renderer ());
   var -> render_present ();
}


void update_screen (Perso *perso_1, Perso *perso_2, Back *map, Back *map2, Basic *var, Basic *var2, Magie *magie, Magie *magie2) {
   var -> clear ();
   var2 -> clear ();
   map -> afficher (var -> get_renderer (), var -> get_Rscreen ());
   map -> afficher (var2 -> get_renderer (), var2 -> get_Rscreen ());
   map2 -> afficher (var -> get_renderer (), var -> get_Rscreen ());
   map2 -> afficher (var2 -> get_renderer (), var2 -> get_Rscreen ());
   perso_1 -> afficher (var -> get_renderer (), 1);
   perso_1 -> afficher (var2 -> get_renderer (), 2);
   perso_2 -> afficher (var -> get_renderer (), 2);
   perso_2 -> afficher (var2 -> get_renderer (), 1);
   magie -> afficher (var -> get_renderer (), var2 -> get_renderer ());
   magie2 -> afficher (var -> get_renderer (), var2 -> get_renderer ());
   var -> render_present ();
   var2 -> render_present ();
}






