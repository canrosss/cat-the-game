/*
 * =====================================================================================
 *
 *       Filename:  framework.c
 *
 *    Description:  Esta libreria contiene las funciones basicas
 *
 *        Version:  1.0
 *        Created:  01/03/19 14:29:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Carlos G,
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lib/framework.h"
#include <ctype.h>
#include <ncurses.h>


void welcome_scene(){
  char message[]="Bienvenido al juego del gato";
  char str[80];
  int row, col;

  initscr();
  getmaxyx(stdscr,row,col);
  mvprintw(row/2, (col-strlen(message))/2, "%s", message);
  getstr(str);
  mvprintw(LINES-2,0,"Has ingresado: %s", str);
  getch();
  endwin();
  raw();
}
