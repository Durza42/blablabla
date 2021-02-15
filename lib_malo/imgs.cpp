#ifndef imgs_cpp
#define imgs_cpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <string>

SDL_Texture* load_img_cpp (const char path[], SDL_Renderer *renderer) {

   SDL_Surface *tmp = NULL;
   SDL_Texture *tex = NULL;

   tmp = SDL_LoadBMP(path);

   if (tmp == NULL) {
      printf("Erreur SDL_LoadBMP : %s\n", SDL_GetError());
      return 0;
   }

   SDL_SetColorKey(tmp, SDL_TRUE, SDL_MapRGB (tmp -> format, 255, 255, 255));

   tex = SDL_CreateTextureFromSurface(renderer, tmp);

   SDL_FreeSurface(tmp);

   if (tex == NULL) {
      printf ("Erreur SDL_CreateTextureFromSurface : %s\n", SDL_GetError());
      return 0;
   }

   return tex;
}

   /*chargement d'une image + test*/
bool ld_img_cpp (SDL_Texture **text, SDL_Renderer *rend, std::string img) {

   *text = load_img_cpp (img.c_str (), rend);//chargement de l'image
   if (text == NULL) {//echec
      printf ("erreur à l'image %s : %s \n", img.c_str (), SDL_GetError ());//message d'erreur
      return false;//retour d'erreur
   }

   return true;
}











   /*print directement sur la texture, en solide*/
bool ttf_print_so_cpp (const char str [], SDL_Texture **T, SDL_Renderer *R, TTF_Font *pol, SDL_Color C) {

   if (pol == NULL) {
      std::cout << "erreur : ptr \"pol\" null. " << std::endl;
      return false;
   }

   SDL_Surface *texte = NULL;
   texte = TTF_RenderText_Solid (pol, str, C);

   *T = SDL_CreateTextureFromSurface (R, texte);
   SDL_FreeSurface (texte);

   return true;
}


   /*print directement sur la texture, en shaded*/
bool ttf_print_sh_cpp (const char str [], SDL_Texture **T, SDL_Renderer *R, TTF_Font *pol, SDL_Color C, SDL_Color F) {

   if (pol == NULL) {
      std::cout << "erreur : ptr \"pol\" null. " << std::endl;
      return false;
   }

   SDL_Surface *texte = NULL;
   texte = TTF_RenderText_Shaded (pol, str, C, F);

   *T = SDL_CreateTextureFromSurface (R, texte);
   SDL_FreeSurface (texte);

   return true;
}


   /*print directement sur la texture, en Blended*/
bool ttf_print_B_cpp (const char str [], SDL_Texture **T, SDL_Renderer *R, TTF_Font *pol, SDL_Color C) {

   if (pol == NULL) {
      std::cout << "error : ptr \"pol\" null. " << std::endl;
      return false;
   }

   SDL_Surface *texte = NULL;
   texte = TTF_RenderText_Blended (pol, str, C);

   *T = SDL_CreateTextureFromSurface (R, texte);
   SDL_FreeSurface (texte);

   return true;
}



std::string itostr (int integer) {
   char* c_str;

   sprintf (c_str, "%d", integer);

   return c_str;
}


char* itoCstr (int integer) {
   char* c_str;

   sprintf (c_str, "%d", integer);

   return c_str;
}




#endif
