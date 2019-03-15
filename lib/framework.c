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



#define SALTO "\n"


void msg(char msg[])
{
  printf("%s \n", msg);
}

void checkSpaces(GAME *mygame) {
  //Revisa el arreglo board con valores de 0
  for (int x = 0; x <= 3; ++x) {
        for (int y = 0; y <= 3; ++y) {
                if (mygame->board[x][y] == 1) {
                       printf("%d %d-> <NO DISPONIBLE> \n ", x, y);
                }else { printf("%d %d-> *DISPONIBLE \n", x, y);  }
        }
  }

}




void resetBoard(GAME *mygame){

  //Inicializa el arreglo board con valores de 0
  for (int x = 0; x <= 3; ++x) {
        for (int y = 0; y <= 3; ++y) {
          mygame->board[x][y] = 0;
        }
  }

  //Inicializa el arreglo symbol board con valores de \0
  for (int x = 0; x <= 3; ++x) {
        for (int y = 0; y <= 3; ++y) {
          mygame->symbol[x][y] = '\0';
        }
  }

}


void sound(int state){
 if (state==TRUE) { system("/usr/bin/mpg123 sound/sound-1.mp3  > /dev/null 2>&1&");}
}



void initializeBoard(GAME *mygame){
  //Set initial value for the structure board
  msg("Iniciando la estructura\n");
  mygame->points = 0;
  if ((mygame->HUMAN_player==NULL)) {
      msg("HUMAN_player no está seteado!");
  }
///  mygame->nameplayer="Carlos G";
 ///  printf("Player: %s \n", mygame->nameplayer);
  resetBoard(mygame);
}

void showBoard(GAME *mygame, int numeric, int symbolic){

  if (numeric == TRUE) {
      msg("\t \t \t TABLERO DE VALORES");
      msg("\t \t --------------");
      printf("\t \t %d |  %d  |  %d \n ", mygame->board[0][0], mygame->board[0][1], mygame->board[0][2]);
      printf("\t \t %d |  %d  |  %d \n ", mygame->board[1][0], mygame->board[1][1], mygame->board[1][2]);
      printf("\t \t %d |  %d  |  %d \n ", mygame->board[2][0], mygame->board[2][1], mygame->board[2][2]);
      msg("\t \t --------------");
  }

  if (symbolic == TRUE) {
      msg("\t \t \t TABLERO DE SIMBOLOS!");

      msg("\t \t --------------");
      printf("\t \t %c  |  %c  |  %c \n ", mygame->symbol[0][0], mygame->symbol[0][1], mygame->symbol[0][2]);
      printf("\t \t %c  |  %c  |  %c \n ", mygame->symbol[1][0], mygame->symbol[1][1], mygame->symbol[1][2]);
      printf("\t \t %c  |  %c  |  %c \n ", mygame->symbol[2][0], mygame->symbol[2][1], mygame->symbol[2][2]);
      msg("\t \t --------------");
  }

}

void markMovement(GAME *mygame){


     printf("\t \t \t \t  \t \t \t \t  Turno => %d  \n",mygame->turn);
     printf("\t \t \t \t  \t \t \t \t  Jugando => %s  \n",mygame->current_player);
     printf("\t \t \t \t  \t \t \t \t  Partidas Ganadas => %d  \n", mygame->points);
     msg("Instrucciones: Introduce un movimiento por coordenada");
     //MOSTRAR COORDENADAS DISPONIBLES
     checkSpaces(mygame);
     int my_move_x = 0; // pone en null la variable my_move
     int my_move_y = 0; // pone en null la variable my_move

     if (mygame->current_player=="Carlos") {
         msg("X=> ?");
         scanf("%d", &my_move_x); //1
         msg("Y=> ?");
         scanf("%d", &my_move_y); //1
         fflush( stdin );
     }
     else
     {
         msg("Turno de la maquina!");
         mygame->current_player=mygame->IA_player;
         markMovementIA(mygame);
     }

     if(mygame->board[my_move_x][my_move_y] == 1){
        msg("NO PUEDO MARCAR MOVIMIENTO..\n");
        msg("Pierdes un turno!..\n");
        system("sleep 2");
        mygame->current_player=mygame->IA_player;
        system("sleep 2");
        markMovementIA(mygame);
     }
     system("sleep 2");
     msg("Marcando movimiento..\n");
     printf("X=> %d,  Y=> %d \n", my_move_x, my_move_y);

     mygame->board[my_move_x][my_move_y] = 1;
     mygame->symbol[my_move_x][my_move_y] = 'X';

     printf("Continuando..\n");

     if (mygame->turn % 1 == 0) {
       mygame->turn=mygame->turn + 1;
       mygame->current_player=mygame->HUMAN_player;
       markMovement(mygame);
     }
     else{
       markMovementIA(mygame);
     }


}

void markMovementIA(GAME *mygame)
{

  //Volviendo ..
  system("sleep 2;clear");
  msg("IA MOVIMIENTO TERMINADO!");
  mygame->turn=mygame->turn + 1;
  mygame->current_player="Carlos";
  markMovement(mygame);

}

void start(GAME *mygame){
  msg(SYSNAME SYSVER);
  mygame->turn = 0;

  // Iniciando la variable HUMAN_player en null
  //
  mygame->IA_player = "Machine IA";
  mygame->board[0][0] = 0;

  msg("Welcome");

  initializeBoard(mygame);
  sound(FALSE);
  //showBoard(mygame,1,1);
  //markMovement(mygame);
}
