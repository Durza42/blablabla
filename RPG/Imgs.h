#ifndef HEADER
#define HEADER

class Imgs {

  public:

   Imgs ();
   Imgs (SDL_Renderer *renderer);
   ~Imgs ();

  private:

   SDL_Texture *Perso [4];
};

#endif
