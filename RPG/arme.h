#ifndef HEADER
#define HEADER


#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <string>
#include "arme.h"
#include "modele_arme.h"


class Arme {

  public:

   Arme (SDL_Renderer *renderer, SDL_Renderer *renderer2, Modele modeles);
   Arme (SDL_Renderer *renderer, SDL_Renderer *renderer2, Modele modeles, std::string name);
   ~Arme ();
   void afficher (SDL_Renderer *renderer, int id_renderer);
   void begin_attaque (int orientation, SDL_Point coo);
   void a_touche ();
   void synchro_with_modele (Modele modeles, const int id, SDL_Renderer *renderer, SDL_Renderer *renderer2);
   SDL_Texture* get_texture (int id_renderer);
   SDL_Rect get_rect () const;
   int get_degats () const;
   const char* get_degats_str () const;

  private:

   std::string m_name; // nom de l'arme
   int m_degats; // degats de l'arme
   std::string m_degats_str; // degats de l'arme, en chaine de caractères

   SDL_Texture *m_text1, *m_text2; // apparence de l'arme sur les deux renderer
   SDL_Rect m_rect; // emplacement de l'arme

   int m_delta; // angle d'inclinaison de l'arme
   int m_delta_max; // inclinaison maximum de l'arme
   int m_delta_dep; // delta de départ.
   int m_delta_begining; // delta au début de l'attaque (peut varier selon l'orientation du personnage.)

   bool m_used; // true si utilisé, false sinon

   SDL_Point m_center; // centre de rotation.

   bool m_peut_toucher;
};




#endif
