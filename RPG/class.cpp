#include "class.h"

   // assembleur
Basic::Basic () /*: imgs (m_renderer) */{

   m_long_wind = 900;
   m_haut_wind = 600;

   m_fenetre = SDL_CreateWindow ("RPG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_long_wind, m_haut_wind, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
   m_renderer = SDL_CreateRenderer (m_fenetre, -1, SDL_RENDERER_ACCELERATED);
   m_render = SDL_CreateTexture (m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, m_long_wind, m_haut_wind);

   SDL_SetRenderTarget (m_renderer, m_render);
}

   // destructeur
Basic::~Basic () {
   SDL_DestroyWindow (m_fenetre);
   SDL_DestroyRenderer (m_renderer);
   SDL_DestroyTexture (m_render);
}

SDL_Renderer* Basic::get_renderer () const {
   return m_renderer;
}

void Basic::render_present () {

   SDL_SetRenderTarget (m_renderer, NULL);

   SDL_RenderClear (m_renderer);

   SDL_RenderCopy (m_renderer, m_render, NULL, NULL);
   SDL_RenderPresent (m_renderer);

   SDL_SetRenderTarget (m_renderer, m_render);
}


void Basic::clear () {
   SDL_SetRenderDrawColor (m_renderer, 200, 100, 100, 150);
   SDL_RenderClear (m_renderer);
}



