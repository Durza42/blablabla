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
   TTF_Font* get_font ();

  private:

   SDL_Window *m_fenetre;
   SDL_Renderer *m_renderer;
   SDL_Texture *m_render;
   TTF_Font *m_font;
};

#endif
