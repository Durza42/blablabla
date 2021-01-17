#include "boucle.h"


using namespace std;


int boucle_J1 () {

   Basic var;

   Back map (var.get_renderer ());

   Perso perso_1 (var.get_renderer (), "squelette");
   Perso perso_2 (var.get_renderer (), "viking");

   SDL_Event event;

   while (1) {

      SDL_Delay (15); // 60 fps

      while (SDL_PollEvent (&event)) {
         if (event.type == SDL_WINDOWEVENT) {
            if (event.window.event == SDL_WINDOWEVENT_CLOSE) // Fermeture de la fenêtre
               return 0;
         }
         else if (event.type == SDL_KEYDOWN) {

            if (event.key.keysym.sym == SDLK_RIGHT) // flèche droite
               perso_1.droite ();
            else if (event.key.keysym.sym == SDLK_LEFT) // flèche droite
               perso_1.gauche ();
            else if (event.key.keysym.sym == SDLK_UP) // flèche droite
               perso_1.haut ();
            else if (event.key.keysym.sym == SDLK_DOWN) // flèche droite
               perso_1.bas ();
         }
      }
      update_screen (&perso_1, &map, &var);
   }
}


void update_screen (Perso *perso, Back *map, Basic *var) {
   var -> clear ();
   map -> afficher (var -> get_renderer ());
   perso -> afficher (var -> get_renderer ());
   var -> render_present ();
}






