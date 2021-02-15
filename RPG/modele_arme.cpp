#include "modele_arme.h"

#include <iostream>
#include <string>
#include <vector>


   // assembleur
Modele::Modele () {

   add_modele ("epee_rouille", 5, "5", "imgs/epee_rouille.bmp");
   add_modele ("epee_normalle", 10, "10", "imgs/epee_normalle.bmp");
   add_modele ("epee_riche", 20, "20", "imgs/epee_riche.bmp");
   add_modele ("epee_futur", 33, "33", "imgs/epee_futur.bmp");
}


void Modele::add_modele (std::string name, int degats, std::string degats_str, std::string path) {
   m_path.push_back (path);
   m_name.push_back (name);
   m_degats.push_back (degats);
   m_degats_str.push_back (degats_str);
   m_id.push_back (m_name.size ());
}


void Modele::delete_modele (int id) {

   for (size_t i = id ; i < m_name.size () ; i++) {

      m_name [i] = m_name [i + 1];

      m_degats [i] = m_degats [i + 1];

      m_degats_str [i] = m_degats_str [i + 1];

   }

   m_name.pop_back ();
   m_degats.pop_back ();
   m_degats_str.pop_back ();
   m_id.pop_back ();
}


void Modele::delete_modele (std::string name) {

   for (size_t i = 0 ; i < m_name.size () ; i++)
      if (m_name [i] == name)
         delete_modele (i);
}


void Modele::copie_modele (std::string name, int* degats, std::string* degats_str, std::string* path) {

   for (size_t i = 0 ; i < m_name.size () ; i++) {

      if (m_name [i] == name) {

         *degats = m_degats [i];
         *degats_str = m_degats_str [i];
         *path = m_path [i];
         return;

      }
   }
}


void Modele::copie_modele_id (const int id, std::string* name, int* degats, std::string* degats_str, std::string* path) {

   for (size_t i = 0 ; i < m_name.size () ; i++) {

      if (m_id [i] == id) {

         *path = m_path [i];
         *name = m_name [i];
         *degats = m_degats [i];
         *degats_str = m_degats_str [i];
         return;

      }
   }
}


const char* Modele::get_path (const int id) {
   return m_path [id].c_str ();
}

