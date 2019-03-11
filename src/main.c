/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  01/03/19 14:22:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "lib/framework.h"
#include <ncurses.h>
#include <string.h>

int main(int argc, char *argv[])
{

  //crea un objeto del tipo GAME object y crea el punter *mygame para recibir la direccion de memoria.
/*     GAME object;
  GAME *mygame = &object;  //Getting the mem addrs
  start(mygame);
*/

  char msg[]="Testing 123";
  int row, col;
  initscr();
  raw();
  keypad(stdscr,TRUE);
  getmaxyx(stdscr,row,col);
  mvprintw(row/2, (col-strlen(msg))/2, "%s", msg);
  mvprintw(row-2,0,"Esta pantalla tiene %d rows and %d columns \n", row, col);
  printw("try Resizing your window");
  refresh();
  getch();
  endwin();

  return 0;
}

