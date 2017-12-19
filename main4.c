
#include "biblioteca4.h"

int main()
{
  srand( (unsigned)time(NULL) );

  animais=construtor();
  frutas=construtor();

  INICIO:
  system("clear");
  printf("\n\n----------------------------------------\n");
  printf("BEM VINDO AO JOGO DE CAÇA PALAVRAS\n\n");
  selec(set);
  printf("\n\nComeça o jogo (2)\n\n");
  printf("Configurações (1)\n\n");
  printf("Sair (0)");
  printf("\n\n-----------------------------------------\n\n\n");
  scanf("%d",&modo);



  switch (modo) {
    case 2:
    jogo(set);
    printf("\n\n\n digite 0 para sair\n\n");
    printf(" digite 1 para voltar ao menu\n\n");
    printf(" digite 2 para salvar no arquivo\n\n");
    scanf("%d",&zero);
    if(zero == 0)
    {
      exit(1);
    }
    else if(zero == 1)
    {
      goto INICIO;
    }
    else if( zero ==2)
    {
      if ( set == 1 || set ==2)
      {
        grava(15);
      }
      else if( set == 3 || set == 4)
      {
        grava(20);
      }
      printf("Salvo\n");
    }
    else
    {
      printf("Entrada Inválida\n\n");
      exit(1);
    }
    break;

    case 1:
    printf("Tabela 15x15 com nomes de animais -> Digite (1)\n");
    printf("Tabela 15x15 com nomes de frutas  -> Digite (2)\n");
    printf("Tabela 20x20 com nomes de animais -> Digite (3)\n");
    printf("Tabela 20x20 com nomes de frutas  -> Digite (4)\n");
    scanf("%d",&set);
    if( set == 1 || set == 2 || set == 3 || set == 4)
    {
      goto INICIO;
    }
    else
    {
      printf("Entrada Inválida\n\n");
      exit(1);
    }
    break;

    case 0:
    exit(1);
    break;

    default:
    printf("OPÇÃO INVÁLIDA - TENTE NOVAMENTE\n\n");
    exit(1);
    break;
  }

  desconstrutor(animais);
  desconstrutor(frutas);
}
