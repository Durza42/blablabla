#ifndef class_H
#define class_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

class Basic {

  public:

   Basic ();
   Basic (size_t _long, size_t haut);
   ~Basic ();
   SDL_Renderer* get_renderer () const;
   void render_present ();
   void clear ();
   TTF_Font* get_font () const;
   SDL_Rect get_Rscreen () const;
   void change_Xscreen (int ajout);
   void change_Yscreen (int ajout);

  private:

   SDL_Window *m_fenetre;
   SDL_Renderer *m_renderer;
   SDL_Texture *m_render; // le rendu n'est pas copié sur le renderer, mais sur la texture m_render, et enfin m_render sur le renderer pour permetre facilement de redimentionnement de la fenêtre.
   SDL_Rect m_screen; // portion de m_render affiché.
   TTF_Font *m_font;
};

#endif
