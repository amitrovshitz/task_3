CC=gcc
FLAGS= -Wall -g
all:txtfind isort 
txtfind:txtfind.c
	$(CC) $(FLAGS) -o txtfind txtfind.c
isort:isort.c 
	$(CC) $(FLAGS) -o isort isort.c 
clean:
	rm -f *.o isort txtfind
.PHONY: clean all
