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
#include <unistd.h>


void cat_logo()
{
  char cat_1[]= "|\\---/|\n";
  char cat_2[]= "| o_o |\n";
  char cat_3[]= " \\_^_/ \n";
  char growl[]="Miauuu! \n";

  move(10,70);
  refresh();
  printw("%s", cat_1);
  refresh();
  sleep(2);
  move(11,70);
  printw("%s", cat_2);
  refresh();
  sleep(2);
  move(12,70);
  refresh();
  printw("%s", cat_3);
  sleep(2);
  refresh();
  move(13,82);
  printw("%s", growl);
  sleep(2);
  refresh();
}

void welcome_scene(){
  char message[]="Bienvenido al juego del gato";
  char str[80];
  int row, col;

  initscr();
  getmaxyx(stdscr,row,col);
  mvprintw(row/2, (col-strlen(message))/2, "%s", message);
  cat_logo();
  getstr(str);
  mvprintw(LINES-2,0,"Has ingresado: %s", str);
  getch();
  endwin();
  raw();
}
