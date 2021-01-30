#ifndef Magie_H
#define Magie_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

class Magie {

  public:

   Magie (SDL_Renderer *renderer, SDL_Rect* empl_dep, int orientation, int trajet);
   ~Magie ();
   void remake_magie (SDL_Rect* empl_dep, int orientation, int trajet);
   SDL_Rect Up ();
   void afficher (SDL_Renderer *renderer);
   SDL_Rect get_rect ();
   void a_touche ();

  private:

   SDL_Texture *m_magie;
   SDL_Rect m_Rmagie;
   int m_orientation;
   int m_trajet;
};

#endif
