#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"biblioteca.h"

#define ENTER 13
int gol1;
int gol2;


int main(){

 	int x=33-15,y=12,b=34,o=13;
 	int menu;
     system("color F2");
     
     do {
     system("cls");
     system("mode con:cols=50 lines=20");
     printf("\n\n\n\t\tMini Jogo de Futebol");
    
     
     printf("\n\n\t\tMenu");
     printf("\n\t jogar             - 1");
     printf("\n\t instrucoes        - 2");

     printf("\n\t Jogar novamente   - 3");
     printf("\n\t Sair              - 4");
     printf("\n\t Escolha uma opcao: ");
     
     scanf("%i",&menu);
     
     switch (menu){
            case 1:
                 jogador(x,y,b,o);
                 while(jogador(x,y,b,o)==0){
                    jogador(x,y,b,o);
                 }
                 
                 
            break;
            case 2: 
                 gol1=0;gol2=0;
                 system("cls");
                 system("mode con:cols=70 lines=20");
                 printf("\n\n\t\t\t Jogo em de futebol C\n\n\tPara jogar necessita dois jogadores.\n\to jogador 1 joga com as setas do teclado\n\to jogador 2 joga com as teclas A, S, D, W.\n\n\to objetivo do jogo e de fazer gols\n\tVoce movimenta a bola tocando nela com o jogador\n\tcada toque na bola a bola anda 3 casas para frente.\n\n\tCaso queira sair do jogo em execucao aperte a tecla enter\n\n\n\tDIVIRTAM-SE!!!");
                 getch();
            break;
            case 4:
                
                 system ("cls");
                 printf("\t\t\t\n\n\n Obrigado pela experiencia!");
                 getch();
                 return 0;
            break;
            case 3:
                
                 jogador(x,y,b,o);
                 while(jogador(x,y,b,o)==0){
                    jogador(x,y,b,o);
                 }
            break;
            default:            
            printf("\n\tOpcao invalida");
            getch();
            break;
            }
     } while(menu <= 4);    
        
     
       
 return 0;       
}
