#ifndef boucle_H
#define boucle_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

int boucle ();
void update_screen (Perso *perso_1, Perso *perso_2, Back *map, Back *map2, Basic *var, Basic *var2);
void update_screen (Perso *perso_1, Perso *perso_2, Back *map, Back *map2, Basic *var, Basic *var2, Magie *magie);
void update_screen (Perso *perso_1, Perso *perso_2, Back *map, Back *map2, Basic *var, Basic *var2, Magie *magie, Magie *magie2);

#endif
