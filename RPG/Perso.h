#ifndef PERSO_H
#define PERSO_H


class Perso {

  public:

   Perso (SDL_Renderer *renderer);
   Perso (SDL_Renderer *renderer, std::string name);
   ~Perso ();
   void afficher (SDL_Renderer *renderer); /* affiche le perso */
   void droite (Back& map); /* déplace le perso vers la droite */
   void gauche (Back& map); /* déplace le perso vers la gauche */
   void haut (Back& map); /* déplace le perso vers le haut */
   void bas (Back& map); /* déplace le perso vers le bas */
   void vise_special (); /* switch m_is_fighting to true and switch fight_use_special to true */
   void vise (); /* switch m_is_fighting to true and switch fight_use_special to false */
   int attaquer (); /* appelle attaquer_physique ou attaquer_special */
   void attaquer_physique (); /* attaque physique (clic gauche) */
   void attaquer_special (); /* attaque physique (clic droit) */
   SDL_Rect* get_pos ();
   int get_orientation () const;
   int get_porte () const;
   int recevoir_degats (int degats);

  private:

   SDL_Texture *m_img_perso [4]; // images du perso selon son orientation
   int m_orientation; // vaut 0 si le perso monte, 1 si droite, 2 si bas et 3 si gauche
   SDL_Rect m_R_perso; // emplacement du perso dans la fenetre

   int m_depl;
   int m_porte;

   bool m_is_fighting, m_fight_use_special;
   SDL_Texture *m_fleche [4], *m_special_fleche [4];
   SDL_Rect m_Rfleche;

   bool m_a_tire;

   std::string m_name;
};


#endif
