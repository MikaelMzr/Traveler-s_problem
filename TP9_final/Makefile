# Dos Santos Loïc
# Mikael Mezouar
# Création : 13-04-2021
# Dernière modification : 26-04-2021
CC = gcc
CFLAGS = -ansi -Wall -pedantic -lm -lMLV
OBJ = Main.o Test.o Graphique.o Genetique.o Visite.o Carte.o Ville.o

Voyageur: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

Main.o: Main.c Test.h Genetique.h Graphique.h

Test.o: Test.c Test.c Genetique.h

Graphique.o: Graphique.c Graphique.h Visite.h Carte.h

Genetique.o: Genetique.c Genetique.h Visite.h

Visite.o: Visite.c Visite.h Carte.h

Carte.o: Carte.c Carte.h Ville.h

Ville.o: Ville.c Ville.h

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o