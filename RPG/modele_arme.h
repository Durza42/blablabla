#ifndef MODELE_ARME_H
#define MODELE_ARME_H

#include <iostream>
#include <string>
#include <vector>

class Modele {

  public:

   Modele ();

   void add_modele (std::string name, int degats, std::string degats_str, std::string path);
   void delete_modele (int id);
   void delete_modele (std::string name);
   void copie_modele (std::string name, int* degats, std::string* degats_str, std::string* path);
   void copie_modele_id (const int id, std::string* name, int* degats, std::string* degats_str, std::string* path);
   const char* get_path (const int id);

  private:

      /* vector pour pouvoir changer facilement le nombre de modèles */
   std::vector <std::string> m_name; // nom
   std::vector <int> m_degats; // degats
   std::vector <std::string> m_degats_str; // chaine de caractère pour les dégats ("15" par exemple)

   std::vector <std::string> m_path; // chemin de l'image correspondante

   std::vector <int> m_id; // identifiant
};

#endif
