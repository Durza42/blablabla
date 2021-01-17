#ifndef BACK_H
#define BACK_H

class Back {

  public:

   Back (SDL_Renderer *renderer);
   ~Back ();
   void afficher (SDL_Renderer *renderer);
   void change_to (const int x, const int y, const short int mode);
   void init_map ();

  private:

      /* ces 3 textures sont des modèles vers lesquels les cases de m_text_map se pointeront. */
   SDL_Texture *m_mode_chemin;
   SDL_Texture *m_mode_mur;
   SDL_Texture *m_mode_lave;

   SDL_Rect m_map [18][12]; // les emplacements des rectangles de la map
   SDL_Texture *m_text_map [18][12]; // les textures des rectangles de la map
   unsigned short int m_values_map [18][12]; // vaut 1 si chemin, 2 si mur, 3 si lave.
};

#endif
