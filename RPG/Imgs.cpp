#include "Imgs.h"

   // assembleur
Imgs::Imgs () {
   Perso [0] = 0;
   Perso [1] = 0;
   Perso [2] = 0;
   Perso [3] = 0;
}

Imgs::Imgs (SDL_Renderer *renderer) {

   ld_img_cpp (&Perso [0], renderer, "imgs/Dos_perso.bmp");
   if (Perso [0] == 0)
      std::cout << "error, risque de crash..." << std::endl;

   ld_img_cpp (&Perso [1], renderer, "imgs/Droite_perso.bmp");
   if (Perso [1] == 0)
      std::cout << "error, risque de crash..." << std::endl;

   ld_img_cpp (&Perso [2], renderer, "imgs/Bas_perso.bmp");
   if (Perso [2] == 0)
      std::cout << "error, risque de crash..." << std::endl;

   ld_img_cpp (&Perso [3], renderer, "imgs/Gauche_perso.bmp");
   if (Perso [3] == 0)
      std::cout << "error, risque de crash..." << std::endl;
}

   // destructeur
Imgs::~Imgs () {

}
