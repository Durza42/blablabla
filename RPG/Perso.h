#ifndef PERSO_H
#define PERSO_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <string>
#include "arme.h"
#include "modele_arme.h"

class Perso {

  public:

   Perso (SDL_Renderer *renderer, SDL_Renderer *renderer2, Modele modeles, TTF_Font *font, int* x, int* y, int nb_droite, int nb_bas, Back map, SDL_Rect screen);
   Perso (SDL_Renderer *renderer, SDL_Renderer *renderer2, Modele modeles, std::string name, TTF_Font *font, int* x, int* y, int nb_droite, int nb_bas, Back map, SDL_Rect screen);
   Perso (SDL_Renderer *renderer, SDL_Renderer *renderer2, Modele modeles, std::string name, SDL_Color C, TTF_Font *font, int* x, int* y, int nb_droite, int nb_bas, Back map, SDL_Rect screen);
   Perso (SDL_Renderer *renderer, SDL_Renderer *renderer2, Modele modeles, std::string name, std::string nom_arme, SDL_Color C, TTF_Font *font, int* x, int* y, int nb_droite, int nb_bas, Back map, SDL_Rect screen);
   ~Perso ();

   void afficher (SDL_Renderer *renderer, int id_renderer, TTF_Font *font); /* affiche le perso */

   int droite (Back& map, SDL_Rect screen); /* déplace le perso vers la droite */
   int gauche (Back& map, SDL_Rect screen); /* déplace le perso vers la gauche */
   int haut (Back& map, SDL_Rect screen); /* déplace le perso vers le haut */
   int bas (Back& map, SDL_Rect screen); /* déplace le perso vers le bas */

   void vise_special (); /* switch m_is_fighting to true and switch fight_use_special to true */
   void vise (); /* switch m_is_fighting to true and switch fight_use_special to false */
   int attaquer (); /* appelle attaquer_physique ou attaquer_special */
   void attaquer_physique (); /* attaque physique (clic gauche) */
   void attaquer_special (); /* attaque physique (clic droit) */

   void perdre_vie (int vie_perdue, SDL_Renderer *renderer, TTF_Font *font);
   void dead ();
   bool up (Magie *magie, int degats_poss, SDL_Renderer *renderer, TTF_Font *font);
   bool up_arme (Arme *arme, int degats_poss, SDL_Renderer *renderer, TTF_Font *font);
   bool up_pos (Back& map, SDL_Renderer *renderer, TTF_Font *font);

   void take_arme (Back* map, Modele modeles, SDL_Renderer *renderer, SDL_Renderer *renderer2, TTF_Font *font);

   bool is_touched (SDL_Rect rect) const;
   int get_degats () const;
   bool is_dead () const;
   int get_porte () const;
   int get_orientation () const;
   SDL_Rect get_pos ();
   Arme* get_arme ();
   int get_degats_arme () const;

  private:

   SDL_Texture *m_img_perso [4]; // images du perso selon son orientation
   SDL_Texture *m_img_perso2 [4]; // images du perso selon son orientation
   SDL_Texture *m_when_dead;
   SDL_Texture *m_when_dead2;
   int m_orientation; // vaut 0 si le perso monte, 1 si droite, 2 si bas et 3 si gauche
   SDL_Rect m_R_perso; // emplacement du perso dans la fenetre

   SDL_Rect Screen; // portion de la map à afficher.

      /* pseudo, vie, bref infos sur le perso. */
   SDL_Color m_C_perso;

   SDL_Texture *m_pseudo;
   SDL_Texture *m_pseudo2;
   SDL_Rect m_Rpseudo;

   int m_depl;
   int m_porte;

   int m_vie;
   SDL_Rect m_Rvie_bas_txt;

   int m_degats_magie;

   bool m_is_alive;

   Arme m_arme;

   bool m_is_fighting, m_fight_use_special;
   SDL_Texture *m_fleche [4], *m_special_fleche [4];
   SDL_Rect m_Rfleche;

      /* autour du perso */
   SDL_Rect m_Rvie;
   SDL_Rect m_Rvie_orange;
   SDL_Rect m_Rvie_tot;

      /* en bas de l'écran */
   SDL_Rect m_Rvie_bas;
   SDL_Rect m_Rvie_orange_bas;
   SDL_Rect m_Rvie_tot_bas;
   SDL_Rect m_rect_arme_bas;
   SDL_Rect m_rect_txt_arme;
   SDL_Texture *m_txt_arme;
   SDL_Rect m_rect_pouvoir_special_bas;
   SDL_Rect m_rect_txt_pouvoir;
   SDL_Texture *m_txt_pouvoir;
   SDL_Texture *m_text_pouvoir;

   bool m_a_tire;

   int touche_lave;
   int last_hill;

   std::string m_name;
};


#endif
