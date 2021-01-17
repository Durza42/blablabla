#ifndef class_H
#define class_H

class Basic {

  public:

   Basic ();
   ~Basic ();
   SDL_Renderer* get_renderer () const;
   void render_present ();
   void clear ();

  private:

   SDL_Window *m_fenetre;
   SDL_Renderer *m_renderer;
   SDL_Texture *m_render;
   int m_long_wind, m_haut_wind;

//   Imgs imgs;
};

#endif
