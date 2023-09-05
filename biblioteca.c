#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include"biblioteca.h"

#define ENTER 13

//foi ultilizada a rosa dos ventos como base para os comentarios relacionados a posição
// rosa dos ventos disponivel na pasta do projeto


int existe= 0,gol1=0,gol2=0;

void mgotoxy(int x,int y){
     
    COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

void gol(){    
   int imprimirTrave;
   //gol  
   for(imprimirTrave=11;imprimirTrave<=15;imprimirTrave++){//travessão
   mgotoxy(5,imprimirTrave);   
   printf("%c",179);   
   mgotoxy(63,imprimirTrave);   
   printf("%c",179);     
} 

 //furquilhas
   mgotoxy(5,10);//NO
   printf("%c",218);
   mgotoxy(5,16);//SO
   printf("%c",192);
   
   mgotoxy(63,10);//NO
   printf("%c",191);
   mgotoxy(63,16);//SO
   printf("%c",217);
   //traves   
   mgotoxy(6,10);
   printf("%c",196);
   mgotoxy(7,10);
   printf("%c",196);
   mgotoxy(7,16);
   printf("%c",196);
   mgotoxy(6,16);
   printf("%c",196);   
   //traves
   mgotoxy(62,10);
   printf("%c",196);
   mgotoxy(61,10);
   printf("%c",196);
   mgotoxy(62,16);
   printf("%c",196);
   mgotoxy(61,16);
   printf("%c",196);   
   //gol L 
}

 void campo(){
    char tecla='a'; 
    int imprimirLinha=0;
    //,d=2,cx=0,cy=7;
       
	mgotoxy(9, 0);  
    for(imprimirLinha=0;imprimirLinha<=50;imprimirLinha++){//lateral N
          printf("%c", 196);
	}     
    
    mgotoxy(9, 26);
    for(imprimirLinha=0;imprimirLinha<=50;imprimirLinha++){ //lateral S
        printf("%c",196);
	} 
    
   for(imprimirLinha=1;imprimirLinha<26;imprimirLinha++){ //linha de fundo O
       mgotoxy(8,imprimirLinha);       
       printf("%c",179);}            
      
   for(imprimirLinha=1;imprimirLinha<26;imprimirLinha++){ // linha de fundo L
      mgotoxy(60,imprimirLinha);
      printf("%c",179);}    
        
   for(imprimirLinha=1;imprimirLinha<26;imprimirLinha++){ //meio de campo
      mgotoxy(34,imprimirLinha);       
      printf("%c",179);} 
      
    //escanteios
    mgotoxy(8,0);
    printf("%c",218);//  esquerdo NO
    mgotoxy(60,0);    
    printf("%c",191);// escanteio NE
    mgotoxy(60,26);
    printf("%c",217); //escanteio SE  
    mgotoxy(8,26);
    printf("%c",192); //escanteio SO
    
    //dobra meio de campo
    mgotoxy(34,0);
    printf("%c",194);
    mgotoxy(34,26);
    printf("%c",193);    
}

void desenhaJogador(int coluna, int linha) {
	 
    mgotoxy(coluna,linha);
    if(existe ==0){ 
    existe = 1;   
    printf("%c",1);
    }else{ 
    existe =0;
    printf("%c",2);
    }
}

void desenhaBola(int colunaBola, int linhaBola) {
	mgotoxy(colunaBola, linhaBola);
    printf("o");
  
}

void mostraTempo(time_t tagora, time_t tfinal) {
    mgotoxy(62,6);
    tagora = time(NULL);
    printf("Tempo: %.1f seg", difftime(tfinal, tagora)*(-1));
}

void mostraPlacar(){
    mgotoxy(65,20);
    printf("\tGols");
    mgotoxy(65,22);
    printf("jogador %c: %i",1,gol1);
    mgotoxy(65,23);
    printf("jogador %c: %i",2,gol2);
    
    }

void moveJogador(int* coluna, int* linha, int movColuna, int movLinha) {
    if(*coluna + movColuna > 7 && *coluna + movColuna < 61)
		*coluna = *coluna + movColuna;
	if(*linha +  movLinha > -1 && *linha +  movLinha < 27)
		*linha = *linha + movLinha;
}

int verificarChutarBola(int colunaJ, int linhaJ, int* colunaBola, int* linhaBola, int movColuna, int movLinha) {
     
	if((colunaJ==*colunaBola)&&(linhaJ == *linhaBola)){ 
		if(*colunaBola + movColuna > 2 && *colunaBola + movColuna < 65){
			*colunaBola = *colunaBola + movColuna;	
 		*linhaBola = *linhaBola + movLinha;
       }else if(*linhaBola + movLinha > 0 && *colunaBola + movColuna < 26){
			*linhaBola = *linhaBola + movLinha;	
         *colunaBola = *colunaBola + movColuna;	
       }
    }
   

    if ((*colunaBola>60) && (*linhaBola>11 && *linhaBola<16)){
      
        
        system("C:\\Progra~1\\Window~3\\wmplayer.exe /fullscreen /play /close D:\\e.1\\gol\\gol.mp4");
        Sleep(3);
        system("TASKKILL /IM wmplayer.exe");
        printf("\n\n\n\n\n");
        gol1++;
	   return main();
      
       //system("pause");
       
        }else  if ((*colunaBola<8) && (*linhaBola>11 && *linhaBola<16)){
        
               
        system("C:\\Progra~1\\Window~3\\wmplayer.exe /fullscreen /play /close  D:\\e.1\\gol\\gol.mp4");
        Sleep(3);      
        system("TASKKILL /IM wmplayer.exe");
        printf("\n\n\n\n\n");
        gol2++;
       return main();
      // system("pause");
        }
       //return desenhaBola(colunaBola,linhaBola);
       return 0;
}
                                     
int jogador(int colunaJ1, int linhaJ1, int colunaBola, int linhaBola){
    
    int tecla,tamanho,i,verificar=2;
 
    int colunaJ2 = 35+15, linhaJ2 = 12;
    
    time_t tfinal, tagora;
    
    tagora = time(NULL);
    tfinal = tagora ;
    
system("color 2F");
system("mode con:cols=80 lines=27");
//printf("alksdfjlaskjdflkajsdf");
    
    // while(verificar == 2){
       
	   
	   while(tecla!=ENTER){
    	system("cls");
    	campo(); 
  		gol();    	
		desenhaJogador(colunaJ1, linhaJ1);
		desenhaJogador(colunaJ2, linhaJ2);
		desenhaBola(colunaBola, linhaBola);
		mostraTempo( tagora, tfinal);

      mostraPlacar(gol1,gol2);
		
	
    	tecla=getch(); 
    	
    	switch(tecla){
         case 's'://s  
    		   moveJogador(&colunaJ1, &linhaJ1, 0, 1);
			   verificar = verificarChutarBola(colunaJ1, linhaJ1, &colunaBola, &linhaBola, 0, 3);
			break;
         case 'd': //d
    		   moveJogador(&colunaJ1, &linhaJ1, 1, 0);
			   verificar = verificarChutarBola(colunaJ1, linhaJ1, &colunaBola, &linhaBola, 3, 0);
         break;
         case 'w'://w
    		   moveJogador(&colunaJ1, &linhaJ1, 0, -1);
			   verificar=verificarChutarBola(colunaJ1, linhaJ1, &colunaBola, &linhaBola, 0, -3);
    	   break;
    	   case 'a': //a
    		   moveJogador(&colunaJ1, &linhaJ1, -1, 0);
			   verificar=verificarChutarBola(colunaJ1, linhaJ1, &colunaBola, &linhaBola, -3, 0);
   		break;   		
   		case 'P'://para baixo  
    		   moveJogador(&colunaJ2, &linhaJ2, 0, 1);
	    	   verificar=verificarChutarBola(colunaJ2, linhaJ2, &colunaBola, &linhaBola, 0, 3);
         break;  	
		   case 'M': //para direita
    		   moveJogador(&colunaJ2, &linhaJ2, 1, 0);
			   verificar=verificarChutarBola(colunaJ2, linhaJ2, &colunaBola, &linhaBola, 3, 0);
    	   break;
    	   case 'H': //para cima
    		   moveJogador(&colunaJ2, &linhaJ2, 0, -1);
				verificar=verificarChutarBola(colunaJ2, linhaJ2, &colunaBola, &linhaBola, 0, -3);
    	   break;
         case 'K': //para esquerda
    		moveJogador(&colunaJ2, &linhaJ2, -1, 0);
			verificar=verificarChutarBola(colunaJ2, linhaJ2, &colunaBola, &linhaBola, -3, 0);
   		break;
   		
   		
   		
   		
        }
        }
		printf("exit");
        
        
       
	
		//return main();
		system("pause");
	    }
    
          
