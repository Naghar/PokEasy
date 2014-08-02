CFLAGS=-W -Wall -ansi -pedantic -std=c99 -pthread

all: Pokeasy clean

Pokeasy: main.o p_pokemon.o p_road.o p_encounter.o p_species.o p_stats.o types.o
	gcc -lpthread -o Pokeasy main.o p_pokemon.o p_road.o p_encounter.o p_species.o p_stats.o types.o $(CFLAGS)

types.o: types.c
	gcc -o types.o -c types.c $(CFLAGS)

p_stats.o: p_stats.c types.h
	gcc -o p_stats.o -c p_stats.c $(CFLAGS)

p_species.o: p_species.c p_stats.h
	gcc -o p_species.o -c p_species.c $(CFLAGS)

p_encounter.o: p_encounter.c p_species.h
	gcc -o p_encounter.o -c p_encounter.c $(CFLAGS)

p_road.o: p_road.c p_encounter.h
	gcc -o p_road.o -c p_road.c $(CFLAGS)

p_pokemon.o: p_pokemon.c p_road.h
	gcc -o p_pokemon.o -c p_pokemon.c $(CFLAGS)

main.o: main.c p_pokemon.h
	gcc -o main.o -c main.c $(CFLAGS)

clean:
	rm -rf *.o
