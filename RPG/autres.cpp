#ifndef CPP
#define CPP
#endif



int convert_cooWindX_to_cooMapX (const int x, bool arondi_dessus) {

   if (arondi_dessus)
      if (x % 25 != 0)
         return x / 25 + 1;
      else
         return x / 25;
   else
      return x / 25;
}


int convert_cooWindY_to_cooMapY (const int y, bool arondi_dessus) {

   if (arondi_dessus)
      if (y % 25 != 0)
         return y / 25 + 1;
      else
         return y / 25;
   else
      return y / 25;
}


