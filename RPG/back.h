#ifndef BACK_H
#define BACK_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "modele_arme.h"

class Back {

  public:

   Back (SDL_Renderer *renderer, Modele modele);
   ~Back ();
   void afficher (SDL_Renderer *renderer, SDL_Rect show);
   void afficher (SDL_Renderer *renderer);
   void init_map (SDL_Renderer *renderer, Modele modele);
   unsigned short int get_value (const short int x, const short int y) const;
   void change_to (const int x, const int y, const short int mode);
   void change_to_rect (SDL_Rect rect, int mode);
   void add_arme (const int id_arme, const int x, const int y);
   void delete_arme (const int x, const int y);
   const int get_id_arme (const int x, const int y);

  private:


      /* ces 3 textures sont des modèles vers lesquels les cases de m_text_map se pointeront. */
   SDL_Texture *m_mode_chemin;
   SDL_Texture *m_mode_mur;
   SDL_Texture *m_mode_lave;
   SDL_Texture *m_mode_soin;

   SDL_Rect m_map [91][60]; // les emplacements des rectangles de la map
   SDL_Texture *m_text_map [91][60]; // les textures des rectangles de la map
   unsigned short int m_values_map [91][60]; // vaut 1 si chemin, 2 si mur, 3 si lave. 4 si chemin + arme, 5 si mur + arme, 6 si lave + arme. vaut 7 si soin.
   short int m_id_armes [91][60]; // identifiant des armes déposées sur la map
   SDL_Texture *m_text_armes [91][60];

   SDL_Texture *m_img_map; //texture contenant la map, afin de ne pas coller l'ensemble des textures à chaque rafraichissement.
};

#endif
