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
 *         Author:  Carlos Garcia,
 *   Organization:  Hackvilion Inc.
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "lib/framework.h"
#include "lib/gui.h"
#include <ncurses.h>
#include <string.h>

int main(int argc, char *argv[])
{

  //crea un objeto del tipo GAME object y crea el punter *mygame para recibir la direccion de memoria.
/*     GAME object;
  GAME *mygame = &object;  //Getting the mem addrs
  start(mygame);
*/
 welcome_scene();

  return 0;
}

