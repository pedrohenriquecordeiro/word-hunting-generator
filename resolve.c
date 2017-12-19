#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"resolveh.h"

char matriz_15[15][15];
char matriz_15_resposta[15][15];
char matriz_20[20][20];
char matriz_20_resposta[20][20];
char direcao[50];
char *palavra;
unsigned short int* busca;;
int def;
int main()
{
  char arquivo[]="matriz.txt";
  int contador=0;
  char caracter[1],espaco;
  FILE *ptr;
  ptr = fopen(arquivo,"r");

  if(!ptr){printf("ERRONAABERTURA\n");}
  else
  {
     while( fscanf(ptr,"%c ",caracter) != EOF )
     {
       contador++;
     }
     fseek(ptr,0,SEEK_SET);

     if(contador == 450)
     {
       for(int i=0; i<15; i++)
       {
         for(int j=0; j<15; j++)
         {
           if(getc(ptr) != '\n')
           {
             fseek(ptr,-1,SEEK_CUR);
             matriz_15[i][j]=getc(ptr);
             espaco=getc(ptr);
           }
           else
           {
             matriz_15[i][j]=getc(ptr);
             espaco=getc(ptr);
           }
         }
       }
       for(int i=0; i<15; i++)
       {
         for(int j=0; j<15; j++)
         {
           if(getc(ptr) != '\n')
           {
             fseek(ptr,-1,SEEK_CUR);
             matriz_15_resposta[i][j]=getc(ptr);
             espaco=getc(ptr);
           }
           else
           {
             matriz_15_resposta[i][j]=getc(ptr);
             espaco=getc(ptr);
           }
         }
       }
     }
     else
     {
       for(int i=0; i<20; i++)
       {
         for(int j=0; j<20; j++)
         {
           if(getc(ptr) != '\n')
           {
             fseek(ptr,-1,SEEK_CUR);
             matriz_20[i][j]=getc(ptr);
             espaco=getc(ptr);
           }
           else
           {
             matriz_20[i][j]=getc(ptr);
             espaco=getc(ptr);
           }
         }
       }
       for(int i=0; i<20; i++)
       {
         for(int j=0; j<20; j++)
         {
           if(getc(ptr) != '\n')
           {
             fseek(ptr,-1,SEEK_CUR);
             matriz_20_resposta[i][j]=getc(ptr);
             espaco=getc(ptr);
           }
           else
           {
             matriz_20_resposta[i][j]=getc(ptr);
             espaco=getc(ptr);
           }
         }
       }
     }
   }

// -----------------


  if( contador == 450)// matriz de 15
  {
    printf("\nMATRIZ RECEBIDA\n\n");
    for(int i=0;i<15;i++)
    {
      for(int j=0;j<15;j++)
      {
        printf("%c ",matriz_15[i][j]);
      }
      printf("\n");
    }
    printf("\n\n digite 1 para procurar palavra\n");
    printf(" digite 2 para procurar ver resposta\n");
    scanf("%d",&def);
    if( def == 1)
    {
      printf("\n\nEntre com a palavra: ");
      scanf("%s", palavra);
      printf("ERRO1");
      busca = procuraNaMatriz(matriz_20, 15, palavra);
      printf("ERRO2");
      if (busca != NULL)
      {
        dirToStr(direcao, busca[2]);
        printf("\n\nPalavra inicia na linha %hu e coluna %hu\n\nDireção %s\n",busca[0] + 1, busca[1] + 1, direcao);
      }
      else
      {
        printf("Palavra não encontrada\n");
      }
      printf("Para ver a resposta digite 2\n");

    }
    else if(def == 2)
    {
      printf("RESPOSTA\n\n");
      for(int i=0;i<15;i++)
      {
        for(int j=0;j<15;j++)
        {
          printf("%c ",matriz_15_resposta[i][j]);
        }
        printf("\n");
      }
    }
  }
  else
    {
      printf("\nMATRIZ RECEBIDA\n\n");
      for(int i=0;i<20;i++)
      {
        for(int j=0;j<20;j++)
        {
          printf("%c ",matriz_20[i][j]);
        }
        printf("\n");
      }
      printf("\n\n digite 1 para procurar palavra\n");
      printf(" digite 2 para procurar ver resposta\n");
      scanf("%d",&def);
      if( def == 1)
      {
        printf("\n\nEntre com a palavra: ");
        scanf("%s", palavra);
        printf("ERRO1");
        busca = procuraNaMatriz(matriz_20, 20, palavra);
        printf("ERRO2");
        if (busca != NULL)
        {
          dirToStr(direcao, busca[2]);
          printf("\n\nPalavra inicia na linha %hu e coluna %hu\n\nDireção %s\n",busca[0] + 1, busca[1] + 1, direcao);
        }
        printf("Para ver a resposta digite 2\n");
      }
      else if(def == 2)
      {
        printf("RESPOSTA\n\n");
        for(int i=0;i<20;i++)
        {
          for(int j=0;j<20;j++)
          {
            printf("%c ",matriz_20_resposta[i][j]);
          }
          printf("\n");
        }
      }
    }
  }
