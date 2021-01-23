#include "magie.h"

   // assembleur
Magie::Magie (SDL_Renderer *renderer, SDL_Rect* empl_dep, int orientation, int trajet) {
   ld_img_cpp (&m_magie, renderer, "imgs/magie.bmp");
   m_Rmagie = *empl_dep;
   m_orientation = orientation;
   m_trajet = trajet;
}


   // destructeur
Magie::~Magie () {
   SDL_DestroyTexture (m_magie);
}


void Magie::remake_magie (SDL_Rect* empl_dep, int orientation, int trajet) {
   m_Rmagie = *empl_dep;
   m_orientation = orientation;
   m_trajet = trajet;
}


SDL_Rect Magie::Up () {

   if (m_orientation == 0) {

//      if (back.get_value (convert_cooWindX_to_cooMapX (m_Rmagie.x, false), convert_cooWindY_to_cooMapY (m_Rmagie.y - 10, false)) != 2)

      if (m_trajet - 10 >= 0) {
         m_Rmagie.y -= 10;
         m_trajet -= 10;
      }
      else {
         return (SDL_Rect) {0, 0, 0, 0};
      }
   }
   else if (m_orientation == 1) {

//      if (back.get_value (convert_cooWindX_to_cooMapX (m_Rmagie.x + 10, false), convert_cooWindY_to_cooMapY (m_Rmagie.y, false)) != 2)

      if (m_trajet - 10 >= 0) {
         m_Rmagie.x += 10;
         m_trajet -= 10;
      }
      else {
         return (SDL_Rect) {0, 0, 0, 0};
      }
   }
   else if (m_orientation == 2) {

//      if (back.get_value (convert_cooWindX_to_cooMapX (m_Rmagie.x, false), convert_cooWindY_to_cooMapY (m_Rmagie.y + 10, false)) != 2)

      if (m_trajet - 10 >= 0) {
         m_Rmagie.y += 10;
         m_trajet -= 10;
      }
      else {
         return (SDL_Rect) {0, 0, 0, 0};
      }
   }
   else if (m_orientation == 3) {

//      if (back.get_value (convert_cooWindX_to_cooMapX (m_Rmagie.x - 10, false), convert_cooWindY_to_cooMapY (m_Rmagie.y, false)) != 2)

      if (m_trajet - 10 >= 0) {
         m_Rmagie.x -= 10;
         m_trajet -= 10;
      }
      else {
         return (SDL_Rect) {0, 0, 0, 0};
      }
   }

   return m_Rmagie;
}


void Magie::afficher (SDL_Renderer *renderer) {
   SDL_RenderCopy (renderer, m_magie, NULL, &m_Rmagie);
}


