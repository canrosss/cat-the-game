/*
 * =====================================================================================
 *
 *       Filename:  framework.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  01/03/19 14:29:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#define SYSNAME "Juego del Gato "
#define SYSVER  "0.1 \n"

//BOOLEAN TYPE

enum BOOLEAN { FALSE = 0, TRUE = 1 };

/* Estructura del tablero del juego */
typedef struct {
  int points;
  int board[3][3];  //array
  char symbol[3][3];
  char *HUMAN_player;
  char *IA_player;
  char *current_player;
  int turn;
} GAME;

//Recibe un string y muestra en pantalla
void msg(char msg[]);

// Board Function
void initializeBoard(GAME *mygame);
void resetBoard(GAME *mygame);
void showBoard(GAME *mygame, int numeric, int symbolic);

void markMovement(GAME *mygame);
void markMovementIA(GAME *mygame);

void checkStateBoard(GAME *mygame);
void checkSpaces(GAME *mygame);
void sound(int state);

void start(GAME *mygame);


