# Jogo futebol 8 bit

Um jogo de futebol retrô feito em linagem C inspirado no classico Snake.






<div align="left">
  <img src="https://github.com/gui-celino/Jogo-Futebol-8-bit/blob/main/imagens-jogo/jogando.png"/>
</div>



## Instruções


```bash
Baixe o arquivo .exe e excute ou rode o arquivo .dev no DevCpp
```

### Como jogar

Jogador 1 se move com as teclas `←` `↑` `↓` `→` 

Jogador 2 se move com as Teclas `A` `W` `S` `D`


#### Jogabilidade

Ao tocar na bola o jogador chuta a bola 3 casas para a frente conforme a direção que o jogador esta seguindo.
#### Objetivo
Mover a bola para dentro do gol adversário assim somando 1 gol ao placar.





## Screenshots

<div align="left">
  <img src="https://github.com/gui-celino/Jogo-Futebol-8-bit/blob/main/imagens-jogo/tela-inicial.png"/>
</div>
<div align="left">
  <img src="https://github.com/gui-celino/Jogo-Futebol-8-bit/blob/main/imagens-jogo/instrucoes-jogo.png"/>
</div>

<div align="left">
  <img src="https://github.com/gui-celino/Jogo-Futebol-8-bit/blob/main/imagens-jogo/jogo-comecando.png"/>
</div>

<div align="left">
  <img src="https://github.com/gui-celino/Jogo-Futebol-8-bit/blob/main/imagens-jogo/jogando.png"/>
</div>

## História

A proposta inicial do projeto foi levantada em um 
trabalho interdisciplinar do 1º semestre do curso de 
Análise e Desenvolvimento de Sistemas (ADS) do 
IFSP-HTO. Ao longo do curso a professora apenas por curiosidade extra classe disponibilizou o codigo do jogo **Snake** assim observei por dias sua mecanica de jogo e decidi criar algo parecido mas com o futebol.


## Materiais e métodos

Para desenhar o campo utilizamos a função `gotoxy()` nesta função é possivel passar duas coordenadas, assim ela insere o conteudo do seu proximo "printf()" na coordenada inserida, vemos seu uso no codigo abaixo.

```
#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

main(){    
    gotoxy(10, 5);
    printf("Ola Mundo");
}
```
#### Resultado
<div align="left">
  <img src="https://github.com/gui-celino/Jogo-Futebol-8-bit/blob/main/imagens-jogo/codigo-gotoxy.png"/>
</div>

#### Desenho do campo
Com este código, utilizando caracteres da tabela ASCII foi posivel desenhar o campo.
Para nao escrever muitas vezes a função `printf()` para desenhar o campo todo, utilizei alguns laços de repetição alterando o valor de X ou Y da função `gotoxy()`
```
 int i;
  
  for (i = 3; i <= 13; i++)
  {
  	gotoxy( 3, i);
    printf("%c",179);
    gotoxy( 43, i);
    printf("%c",179);
  }
  
  for (i = 3; i <= 43; i++)
  {
  	gotoxy( i, 3);
    printf("%c", 196);
    gotoxy( i, 13);
    printf("%c", 196);
  }
```


