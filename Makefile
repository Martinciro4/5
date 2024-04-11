CC=gcc
CFLAGS = -pedantic-errors -Wall -O3 -std=gnu89
PHEADER = -I./

all = clean programa1

%.o: %.c
	$(CC) -c $(CFLAGS) $(PHEADER) $< -o $@

productor: productor.o semaforos.o
	$(CC) -o $@ $^

consumidor: consumidor.o semaforos.o
	$(CC) -o $@ $^

clean:
	rm -f *.o programa1
