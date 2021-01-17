#ifndef PERSO_H
#define PERSO_H


class Perso {

  public:

   Perso (SDL_Renderer *renderer);
   Perso (SDL_Renderer *renderer, std::string name);
   ~Perso ();
   void afficher (SDL_Renderer *renderer); /* affiche le perso */
   void droite (); /* déplace le perso vers la droite */
   void gauche (); /* déplace le perso vers la gauche */
   void haut (); /* déplace le perso vers le haut */
   void bas (); /* déplace le perso vers le bas */
   int attaquer ();
   int recevoir_degats (int degats);

  private:

   SDL_Texture *m_img_perso [4]; // images du perso selon son orientation
   int m_orientation; // vaut 0 si le perso monte, 1 si droite, 2 si bas et 3 si gauche
   SDL_Rect m_R_perso; // emplacement du perso dans la fenetre

   int m_depl;

   std::string m_name;
};


#endif
