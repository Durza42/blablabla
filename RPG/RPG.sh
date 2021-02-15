cd ../lib_malo
g++ -c imgs.cpp `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer -g -pg -o imgs.o
cd ../RPG

g++ -c class.cpp `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer -g -pg -o class.o
g++ -c main.cpp `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer -g -pg -o main.o
g++ -c autres.cpp `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer -g -pg -o autres.o
g++ -c Perso.cpp `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer -g -pg -o perso.o
g++ -c back.cpp `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer -g -pg -o back.o
g++ -c modele_arme.cpp `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer -g -pg -o modele_arme.o
g++ -c magie.cpp `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer -g -pg -o magie.o
g++ -c arme.cpp `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer -g -pg -o arme.o
g++ -c boucle.cpp `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer -g -pg -o boucle.o

g++ main.o autres.o arme.o class.o perso.o back.o modele_arme.o magie.o boucle.o ../lib_malo/imgs.o `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer -g -pg -o RPG
