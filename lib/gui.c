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
  sleep(1);
  move(11,70);
  printw("%s", cat_2);
  refresh();
  sleep(1);
  move(12,70);
  refresh();
  printw("%s", cat_3);
  sleep(1);
  refresh();
  move(13,82);
  printw("%s", growl);
  sleep(1);
  move(LINES-2, 0);
  refresh();
}

void welcome_scene(GAME *mygame){
  char message[]="Bienvenido al juego del gato";
  char str[80];
  int row, col;

  initscr();
  getmaxyx(stdscr,row,col);
///  cat_logo();
  sleep(1);
  mvprintw(row/2, (col-strlen(message))/2, "%s", message);
  move(LINES-1,0);
  printw("%s", "¿Cuál es tu nombre? ");

  getstr(str);
  //Pasando el string a la estructura
  mygame->HUMAN_player;
  mvprintw(LINES-2,0,"Jugador: %s", str);
  getch();

  move(LINES-2,0);
  printw("%s", "Presiona cualquier tecla para continuar ");
//  endwin();
 //  raw();
}

void show_board(GAME *mygame){

  int i = 0;
  int j = 0;
  clear();
  refresh();


  move(5,58);
  addch(ACS_VLINE);

  move(6,58);
  addch(ACS_VLINE);

  move(7,58);
  addch(ACS_VLINE);

  //Dibujando la otra linea
  move(5,67);
  addch(ACS_VLINE);

  move(6,67);
  addch(ACS_VLINE);

  move(7,67);
  addch(ACS_VLINE);

  move(8,50);for(i=0;i<8;i++){ addch(ACS_S3);}addch(ACS_DIAMOND);for(int i=0;i<8;i++){ addch(ACS_S3);}addch(ACS_DIAMOND);
  move(8,66);addch(ACS_DIAMOND);move(8,67);for(int i=0;i<8;i++){ addch(ACS_S3); }

  move(10,50);for(i=0;i<8;i++){ addch(ACS_S3);}addch(ACS_DIAMOND);for(int i=0;i<8;i++){ addch(ACS_S3);}addch(ACS_DIAMOND);
  move(10,66);addch(ACS_DIAMOND);move(10,67);for(int i=0;i<8;i++){ addch(ACS_S3); }


  move(11,58);
  addch(ACS_VLINE);

  move(12,58);
  addch(ACS_VLINE);

  move(11,67);
  addch(ACS_VLINE);

  move(12,67);
  addch(ACS_VLINE);


  move(15,50);printw("[0,0]");
  move(15,60);printw("[0,1]");
  move(15,70);printw("[0,2]");

  move(16,50);printw("[1,0]");
  move(16,60);printw("[1,1]");
  move(16,70);printw("[1,2]");

  move(17,50);printw("[2,0]");
  move(17,60);printw("[2,1]");
  move(17,70);printw("[2,2]");

  move(LINES-1,0);
  printw("%s", "¿Cuál es tu Coordenada X ");

  refresh();
}
