#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <MMsystem.h>
#include <pthread.h>


#define ANSI_COLOR_RED     	"\x1b[31m" //cores em ANSI utilizadas 
#define ANSI_COLOR_GRAY    	"\e[0;37m"
#define ANSI_COLOR_DARK_GRAY 	"\e[1;30m"
#define ANSI_COLOR_GREEN	"\e[0;32m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_BLUE "\e[0;34m"
#define ANSI_COLOR_YELLOW "\e[0;33m"

#define YELB "\e[43m"
#define WHTB "\e[47m"

#define ANSI_COLOR_CYN "\e[0;36m"

/*#ifndef _WIN32
#include <curses.h> //Biblioteca para linux
#else
#include <conio.h> //Biblioteca para windows
#endif*/

#include <time.h>



FILE *save;

//Mapas -- Variáveis Globais.
char mapa1[12][70];
char mapa2[12][70];
char mapa3[12][70];
char mapa4[12][70];
char mapa5[12][70];
char mapa6[12][70];

char mapa1_r[12][70];
char mapa2_r[12][70];
char mapa3_r[12][70];
char mapa4_r[12][70];
char mapa5_r[12][70];
char mapa6_r[12][70];
//Mapas -- Variáveis Globais.

//Sistema
char nick[3];
char saveNick[10][3];
int stageAtual;
int posX, posY, posAnteX, posAnteY;
int musicControler;
//Sistema

//Player
int points;
int vida, magia, maxvida, maxmagia, xp;
int level, pocaov, pocaom;
int defesa, ataquenormal, ataMagia3,ataFantasminha4,ataPacMan5,ataMartelo6,ataVirus7,ataLinux8;
int vidaEnemy;
//Player

//Funções

void telaInimigoGenerico();
void telaFantasminha();
void telaFoguinho();
void telaAvast();
void telaPacman();
void telaDK();
void telaWindows();
void telaMenuInicial();
void limpaTela();
void telaStartGame();
void telaStatusSup();
void telaAtaqueInimigo(int acao, int dano);
void telaSeuAtaque(int acao, int dano);
void telaMenuAtaques();
void startSetup();
void resetMap();
void xpUp();
void limitadorStatus();

void verificalevel(int testaLevel);
void mecanicaMovimentoMapa(char *mapax);
void controleBatalhaInimigo();
int ataqueInimigoGerado();
void atualizarRanking(int *v_ranking, int *v_posRank);
void showRanking(int *v_ranking, int *v_posRank, int tam);
void nickFunctionSave(int pos);
void salvarRanking(int *v_ranking, int *v_posRank);
void carregarRanking(int *v_ranking, int *v_posRank);

void carregaMapaSound();
void inimigoAutomatico();
//Funções
