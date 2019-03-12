cat-game: src/main.c lib/framework.c
	gcc -o bin/cat-game src/main.c lib/framework.c lib/gui.c -I. -lncurses

debug: src/main.c lib/framework.c
	gcc -g -o bin/cat-game src/main.c lib/framework.c lib/gui.c -I. -lncurses

clean:
	$(RM) bin/cat-game

