cd ../lib_malo
g++ -c imgs.cpp `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer -g -o imgs.o
cd ../RPG

g++ -c class.cpp `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer -g -o class.o
g++ -c main.cpp `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer -g -o main.o
g++ -c autres.cpp `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer -g -o autres.o
g++ -c Perso.cpp `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer -g -o perso.o
g++ -c back.cpp `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer -g -o back.o
g++ -c magie.cpp `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer -g -o magie.o
g++ -c boucle.cpp `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer -g -o boucle.o

g++ main.o autres.o class.o perso.o back.o magie.o boucle.o ../lib_malo/imgs.o `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer -g -o RPG

