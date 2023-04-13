CC = gcc 
CFLAGS = -Wall -Werror -Wextra

all: build | clean

build: core.o gen_cf.o
	$(CC) $(CFLAGS) core.o gen_cf.o -o ../build/cl_mk

gen_cf.o: gen_cf.c
	$(CC) $(CFLAGS) -c gen_cf.c

core.o: core.c
	$(CC) $(CFLAGS) -c core.c

clean: 
	rm -rf *.o
