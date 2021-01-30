#ifndef PERSO_H
#define PERSO_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <string>

class Perso {

  public:

   Perso (SDL_Renderer *renderer, TTF_Font *font);
   Perso (SDL_Renderer *renderer, std::string name, TTF_Font *font);
   Perso (SDL_Renderer *renderer, std::string name, SDL_Color C, TTF_Font *font);
   ~Perso ();

   void afficher (SDL_Renderer *renderer, SDL_Texture *text_perso_adv); /* affiche le perso */

   void droite (Back& map); /* déplace le perso vers la droite */
   void gauche (Back& map); /* déplace le perso vers la gauche */
   void haut (Back& map); /* déplace le perso vers le haut */
   void bas (Back& map); /* déplace le perso vers le bas */

   void vise_special (); /* switch m_is_fighting to true and switch fight_use_special to true */
   void vise (); /* switch m_is_fighting to true and switch fight_use_special to false */
   int attaquer (); /* appelle attaquer_physique ou attaquer_special */
   void attaquer_physique (); /* attaque physique (clic gauche) */
   void attaquer_special (); /* attaque physique (clic droit) */

   void perdre_vie (int vie_perdue);
   void dead ();
   bool up (Magie *magie, int degats_poss);

   bool is_touched (SDL_Rect rect) const;
   int get_degats () const;
   bool is_dead () const;
   int get_porte () const;
   int get_orientation () const;
   SDL_Texture* get_text () const;
   SDL_Rect* get_pos ();

  private:

   SDL_Texture *m_img_perso [4]; // images du perso selon son orientation
   SDL_Texture *m_when_dead;
   int m_orientation; // vaut 0 si le perso monte, 1 si droite, 2 si bas et 3 si gauche
   SDL_Rect m_R_perso; // emplacement du perso dans la fenetre

   SDL_Rect m_RadvPerso; // emplacement du perso adverse sur l'écran de ce perso.

      /* pseudo, vie, bref infos sur le perso. */
   SDL_Color m_C_perso;
   SDL_Texture *m_pseudo;
   SDL_Rect m_Rpseudo;
   int m_depl;
   int m_porte;
   int m_vie;
   int m_degats;
   bool m_is_alive;

   bool m_is_fighting, m_fight_use_special;
   SDL_Texture *m_fleche [4], *m_special_fleche [4];
   SDL_Rect m_Rfleche;
   SDL_Rect m_Rvie;
   SDL_Rect m_Rvie_tot;

   bool m_a_tire;

   std::string m_name;
};


#endif
