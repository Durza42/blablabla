#include "back.h"

   // assembleur
Back::Back (SDL_Renderer *renderer) {
   ld_img_cpp (&m_mode_chemin, renderer, "imgs/chemin.bmp");
   ld_img_cpp (&m_mode_mur, renderer, "imgs/mur.bmp");
   ld_img_cpp (&m_mode_lave, renderer, "imgs/lave.bmp");

   init_map ();
}

   // destructeur
Back::~Back () {
   SDL_DestroyTexture (m_mode_chemin);
   SDL_DestroyTexture (m_mode_mur);
   SDL_DestroyTexture (m_mode_lave);

   for (unsigned int i = 0 ; i < 18 ; i += 1) {
      for (unsigned int j = 0 ; j < 12 ; j += 1) {
         SDL_DestroyTexture (m_text_map [i][j]);
      }
   }
}

void Back::afficher (SDL_Renderer *renderer) {
   for (unsigned int i = 0 ; i < 18 ; i += 1)
      for (unsigned int j = 0 ; j < 12 ; j += 1)
         SDL_RenderCopy (renderer, m_text_map [i][j], NULL, &m_map [i][j]);
}


void Back::change_to (const int x, const int y, const short int mode) {
   m_values_map [x][y] = mode;

   if (mode == 1)
      m_text_map [x][y] = m_mode_chemin;
   else if (mode == 2)
      m_text_map [x][y] = m_mode_mur;
   else if (mode == 3)
      m_text_map [x][y] = m_mode_lave;
}


void Back::init_map () {

   for (int i = 0 ; i < 18 ; i += 1) {
      for (int j = 0 ; j < 12 ; j += 1) {
         m_text_map [i][j] = m_mode_mur;
         m_map [i][j] = (SDL_Rect) {i * 50, j * 50, 50, 50};
         m_values_map [i][j] = 2;
      }
   }

   change_to (6, 3, 1);
   change_to (6, 4, 1);
   change_to (6, 5, 1);
   change_to (6, 6, 1);
   change_to (6, 7, 1);

   change_to (7, 3, 1);
   change_to (7, 4, 1);
   change_to (7, 5, 1);
   change_to (7, 6, 1);
   change_to (7, 7, 1);

   change_to (8, 3, 1);
   change_to (8, 4, 1);
   change_to (8, 5, 1);
   change_to (8, 6, 1);
   change_to (8, 7, 1);

   change_to (9, 3, 1);
   change_to (9, 4, 1);
   change_to (9, 5, 1);
   change_to (9, 6, 1);
   change_to (9, 7, 1);

   change_to (10, 3, 1);
   change_to (10, 4, 1);
   change_to (10, 5, 1);
   change_to (10, 6, 1);
   change_to (10, 7, 1);

   change_to (11, 3, 1);
   change_to (11, 4, 1);
   change_to (11, 5, 1);
   change_to (11, 6, 1);
   change_to (11, 7, 1);

   change_to (12, 5, 1);
   change_to (13, 5, 1);
   change_to (13, 6, 1);
}


unsigned short int Back::get_value (const short int x, const short int y) {
   return m_values_map [x][y];
}







