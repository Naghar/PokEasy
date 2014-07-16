CFLAGS=-W -Wall -ansi -pedantic

all: Pokeasy clean

Pokeasy: main.o p_pokemon.o p_route.o p_rencontre.o p_espece.o p_stats.o types.o
	gcc -o Pokeasy main.o p_pokemon.o p_route.o p_rencontre.o p_espece.o p_stats.o types.o $(CFLAGS)

types.o: types.c
	gcc -o types.o -c types.c $(CFLAGS)

p_stats.o: p_stats.c types.h
	gcc -o p_stats.o -c p_stats.c $(CFLAGS)

p_espece.o: p_espece.c p_stats.h
	gcc -o p_espece.o -c p_espece.c $(CFLAGS)

p_rencontre.o: p_rencontre.c p_espece.h
	gcc -o p_rencontre.o -c p_rencontre.c $(CFLAGS)

p_route.o: p_route.c p_rencontre.h
	gcc -o p_route.o -c p_route.c $(CFLAGS)

p_pokemon.o: p_pokemon.c p_route.h
	gcc -o p_pokemon.o -c p_pokemon.c $(CFLAGS)

main.o: main.c p_pokemon.h
	gcc -o main.o -c main.c $(CFLAGS)

clean:
	rm -rf *.o