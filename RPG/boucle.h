#ifndef boucle_H
#define boucle_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

int boucle ();
void update_screen (Perso *perso_1, Back *map, Basic *var, SDL_Texture *text_perso_adv);
void update_screen (Perso *perso_1, Back *map, Basic *var, Magie *magie, SDL_Texture *text_perso_adv);
void update_screen (Perso *perso_1, Back *map, Basic *var, Magie *magie, Magie *magie2, SDL_Texture *text_perso_adv);

#endif
