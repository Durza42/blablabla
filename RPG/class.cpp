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
//#include "../lib_malo/malo.h" // ATENTION : bibliothèque écrite en C


   // assembleur
Basic::Basic () {

   m_fenetre = SDL_CreateWindow ("RPG", 0, 0, 900, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
   m_renderer = SDL_CreateRenderer (m_fenetre, -1, SDL_RENDERER_ACCELERATED);
   m_render = SDL_CreateTexture (m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 90 * 25, 60 * 25);
   m_screen = (SDL_Rect) {0, 0, 900, 600};
   m_font = TTF_OpenFont ("../lib_malo/C059.otf", 30);

   SDL_SetRenderTarget (m_renderer, m_render);
}

   // assembleur
Basic::Basic (size_t _long, size_t haut) {

   m_fenetre = SDL_CreateWindow ("RPG", _long, haut, 900, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
   m_renderer = SDL_CreateRenderer (m_fenetre, -1, SDL_RENDERER_ACCELERATED);
   m_render = SDL_CreateTexture (m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 90 * 25, 60 * 25);
   m_screen = (SDL_Rect) {0, 0, 900, 600};
   m_font = TTF_OpenFont ("../lib_malo/C059.otf", 30);

   SDL_SetRenderTarget (m_renderer, m_render);
}

   // destructeur
Basic::~Basic () {
   SDL_DestroyWindow (m_fenetre);
   SDL_DestroyRenderer (m_renderer);
   SDL_DestroyTexture (m_render);
   TTF_CloseFont (m_font);
}

SDL_Renderer* Basic::get_renderer () const {
   return m_renderer;
}

void Basic::render_present () {

   SDL_SetRenderTarget (m_renderer, NULL);

   SDL_RenderClear (m_renderer);

   SDL_RenderCopy (m_renderer, m_render, &m_screen, NULL);
   SDL_RenderPresent (m_renderer);

   SDL_SetRenderTarget (m_renderer, m_render);
}


void Basic::clear () {
   SDL_SetRenderDrawColor (m_renderer, 200, 100, 100, 150);
   SDL_RenderClear (m_renderer);
}


void Basic::change_Xscreen (int ajout) {
   m_screen.x += ajout;
}


void Basic::change_Yscreen (int ajout) {
   m_screen.y += ajout;
}


SDL_Rect Basic::get_Rscreen () const {
   return m_screen;
}


TTF_Font* Basic::get_font () const {
   return m_font;
}







