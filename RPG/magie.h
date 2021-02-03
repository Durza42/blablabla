#ifndef Magie_H
#define Magie_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <vector>

class Magie {

  public:

   Magie (SDL_Renderer *renderer1, SDL_Renderer *renderer2);
   Magie (SDL_Renderer *renderer1, SDL_Renderer *renderer2, SDL_Rect empl_dep, int orientation, int trajet);
   ~Magie ();

   void add_magie (SDL_Rect empl_dep, int orientation, int trajet);
   void delete_magie (const int id);
   void afficher (SDL_Renderer *renderer1, SDL_Renderer *renderer2);
   void afficher (SDL_Renderer *renderer1, SDL_Renderer *renderer2, const int id);
   void a_touche (const int id);
   void Up ();
   void Up (const size_t i);
   SDL_Rect get_rect (const int id);
   int get_nb_magies () const;

  private:

      /* une seulle apparence, mais deux fenêtres */
   SDL_Texture *m_magie1;
   SDL_Texture *m_magie2;

      /* en vector afin de pouvoir changer facilement le nombre de magies */
   std::vector <SDL_Rect> m_Rmagie;
   std::vector <int> m_orientation;
   std::vector <int> m_trajet;
   int m_nb_magie;
};

#endif
