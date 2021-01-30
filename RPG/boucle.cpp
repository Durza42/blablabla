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


int boucle () {

   Basic var (0, 0);
   Basic var2 (100, 600);

      /* deux map sont malheureusement obligatoires, car une texture est affiliée à un renderer et ne peut s'afficher sur un autre. */
   Back map (var.get_renderer ());
   Back map2 (var2.get_renderer ());

   Perso perso_1 (var.get_renderer (), "squelette", (SDL_Color) {128, 128, 128}, var.get_font ());
   Perso perso_2 (var2.get_renderer (), "viking", (SDL_Color) {50, 50, 150}, var.get_font ());

   SDL_Event event;

   Magie magie (var.get_renderer (), perso_1.get_pos (), perso_1.get_orientation (), perso_1.get_porte ());
   Magie magie2 (var.get_renderer (), perso_2.get_pos (), perso_2.get_orientation (), perso_2.get_porte ());
   bool magie_existe = false;
   bool magie_existe2 = false;
   SDL_Rect temporaire_R;

   unsigned int right = 0, left = 0, up = 0, down = 0;

   while (1) {

      SDL_Delay (15); // 60 fps

      if (right + 500 > SDL_GetTicks ()) {
         perso_2.droite (map);
      }
      else if (left + 500 > SDL_GetTicks ()) {
         perso_2.gauche (map);
      }
      else if (up + 500 > SDL_GetTicks ()) {
         perso_2.haut (map);
      }
      else if (down + 500 > SDL_GetTicks ()) {
         perso_2.bas (map);
      }

      while (SDL_PollEvent (&event)) {
         if (event.type == SDL_WINDOWEVENT) {
            if (event.window.event == SDL_WINDOWEVENT_CLOSE) // Fermeture de la fenêtre
               return 0;
         }
         else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_RIGHT) {
               perso_2.droite (map2);
               perso_2.droite (map2);
               right = SDL_GetTicks ();
            }
            else if (event.key.keysym.sym == SDLK_LEFT) {
               perso_2.gauche (map2);
               perso_2.gauche (map2);
               left = SDL_GetTicks ();
            }
            else if (event.key.keysym.sym == SDLK_UP) {
               perso_2.haut (map2);
               perso_2.haut (map2);
               up = SDL_GetTicks ();
            }
            else if (event.key.keysym.sym == SDLK_DOWN) {
               perso_2.bas (map2);
               perso_2.bas (map2);
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
                  magie_existe2 = true;
                  magie2.remake_magie (perso_2.get_pos (), perso_2.get_orientation (), perso_2.get_porte ());
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
                  perso_1.droite (map);
               else if (event.motion.xrel < 0) // gauche
                  perso_1.gauche (map);

            }
            else if (std::abs (event.motion.xrel) < std::abs (event.motion.yrel)) { // si la souris s'est plus déplacée en x que en y

               if (event.motion.yrel < 0) // haut
                  perso_1.haut (map);
               else if (event.motion.yrel > 0) // bas
                  perso_1.bas (map);
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
               magie_existe = true;
               magie.remake_magie (perso_1.get_pos (), perso_1.get_orientation (), perso_1.get_porte ());
            }
         }
      }
      if (magie_existe) {

         temporaire_R = magie.Up ();

         if (temporaire_R.x == 0 && temporaire_R.y == 0 && temporaire_R.w == 0 && temporaire_R.h == 0)
            magie_existe = false;

         perso_2.up (&magie, perso_1.get_degats ());

         if (!magie_existe2) {
            update_screen (&perso_1, &map, &var, &magie, perso_2.get_text ());
            update_screen (&perso_2, &map2, &var2, perso_1.get_text ());
         }
      }
      if (magie_existe2) {

         temporaire_R = magie2.Up ();
         if (temporaire_R.x == 0 && temporaire_R.y == 0 && temporaire_R.w == 0 && temporaire_R.h == 0) {
            magie_existe2 = false;
         }
         if (!magie_existe) {
            update_screen (&perso_1, &map, &var, &magie2, perso_2.get_text ());
            update_screen (&perso_2, &map2, &var2, perso_1.get_text ());
         }

         perso_1.up (&magie2, perso_2.get_degats ());

      }
      if (magie_existe && magie_existe2) {
         update_screen (&perso_1, &map, &var, &magie, &magie2, perso_2.get_text ());
         update_screen (&perso_2, &map2, &var2, &magie, &magie2, perso_1.get_text ());
      }
      if (!magie_existe && !magie_existe2) {
         update_screen (&perso_1, &map, &var, perso_2.get_text ());
         update_screen (&perso_2, &map2, &var2, perso_1.get_text ());
      }
   }
}


void update_screen (Perso *perso_1, Back *map, Basic *var, SDL_Texture *text_perso_adv) {
   var -> clear ();
   map -> afficher (var -> get_renderer ());
   perso_1 -> afficher (var -> get_renderer (), text_perso_adv);
   var -> render_present ();
}


void update_screen (Perso *perso_1, Back *map, Basic *var, Magie *magie, SDL_Texture *text_perso_adv) {
   var -> clear ();
   map -> afficher (var -> get_renderer ());
   perso_1 -> afficher (var -> get_renderer (), text_perso_adv);
   magie -> afficher (var -> get_renderer ());
   var -> render_present ();
}


void update_screen (Perso *perso_1, Back *map, Basic *var, Magie *magie, Magie *magie2, SDL_Texture *text_perso_adv) {
   var -> clear ();
   map -> afficher (var -> get_renderer ());
   perso_1 -> afficher (var -> get_renderer (), text_perso_adv);
   magie -> afficher (var -> get_renderer ());
   magie2 -> afficher (var -> get_renderer ());
   var -> render_present ();
}



