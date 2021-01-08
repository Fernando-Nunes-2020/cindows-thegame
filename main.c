#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <MMsystem.h>
#include <time.h>
#include "cindows.h" 


main(){
	
	int op;
	int loopstart=1;
	
		
	int ranking[10]={10000,9000,8000,7000,6000,5000,4000,3000,2000,1000};
	int posRankingPessoal[10]={0,0,0,0,0,0,0,0,0,0};
	
	carregarRanking(ranking,posRankingPessoal);
	
	system("MODE con cols=80 lines=30 ");
	
	
	do{
		//startSetup
		startSetup();
		PlaySound(TEXT("sounds/menu.wav"),NULL, SND_LOOP | SND_ASYNC);
		//endStartSetup
		//Start Game
		limpaTela();
		telaMenuInicial();
		scanf("%d",&op);
		switch(op){
			case 1:
				limpaTela();
				telaStartGame();
				while(vida>0){
					limpaTela();
					carregaMapaSound();
					telaStatusSup();
					verificalevel(stageAtual);
					xpUp();
					if(fimdegame==1){
						creditos();
						atualizarRanking(ranking,posRankingPessoal);
						break;
					}
				}
				if(vida<=0){
					PlaySound(NULL,0,0);
					limpaTela();
					atualizarRanking(ranking,posRankingPessoal);
					limpaTela();
					printf(ANSI_COLOR_RED"GAME OVER AMIGO, POR ENQUANTO E RECOMECAR\n"ANSI_COLOR_RESET);
					system("\npause\n");
				}
				break;
			case 2:
				limpaTela();
				printf(ANSI_COLOR_YELLOW"RANKING ATUALIZADO DO GAME:\n"ANSI_COLOR_RESET);
				showRanking(ranking,posRankingPessoal, 0);
				break;
			case 3:
				salvarRanking(ranking,posRankingPessoal);
				loopstart=0;
				break;
			default:
				printf("\nComando invalido\n");
				printf("\nPressione enter para continuar...");
				getchar();
				break;
		}
		//Start Game
 	}while(loopstart==1);
}
