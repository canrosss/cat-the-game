cat-game: src/main.c lib/framework.c
	gcc -o bin/cat-game src/main.c lib/framework.c -I. -lncurses

debug: src/main.c lib/framework.c
	gcc -g -o bin/cat-game src/main.c lib/framework.c -I.

clean:
	$(RM) bin/cat-game

