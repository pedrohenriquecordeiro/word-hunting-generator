#include"fila_encadeada.h"

char matriz_15[15][15];
char matriz_20[20][20];
char matriz_15_resposta[15][15];
char matriz_20_resposta[20][20];
char letter;
int modo=3,zero=10;
int organizacao;
int set=1;//inicio de configuração
int num_palavra=0;
int linha,coluna;

FILA *animais;
FILA *frutas;

/* char letras[] = {
  'A', 'B', 'C', 'D', 'E', 'F',
  'G', 'H', 'I', 'J', 'K', 'L',
  'M', 'N', 'O', 'P', 'Q', 'R',
  'S', 'T', 'U', 'V', 'W', 'X',
  'Y', 'Z'
};*/

char letras[] = {
  'a', 'b', 'c', 'd', 'e', 'f',
  'g', 'h', 'i', 'j', 'k', 'l',
  'm', 'n', 'o', 'p', 'q', 'r',
  's', 't', 'u', 'v', 'w', 'x',
  'y', 'z'
};

void get_matriz_15()
{
  int selecionada;
  for(int i=0 ; i<15 ;i++)
  {
    for( int j=0 ; j<15 ; j++)
    {
      if(matriz_15[i][j] == '\0')
      {
        selecionada = rand() % 26;
        matriz_15[i][j]=letras[selecionada];
        matriz_15_resposta[i][j]='#';
      }
    }
  }
}

void push_matriz_15()
{
  for(int i=0 ; i<15 ;i++)
  {
    for( int j=0 ; j<15 ; j++)
    {
        printf("[%c]",matriz_15[i][j]);
    }
    printf("\n");
  }
}

void get_matriz_20()
{
  srand( (unsigned)time(NULL) );
  int selecionada;
  for(int i=0 ; i<20 ;i++)
  {
    for( int j=0 ; j<20 ; j++)
    {
      if(matriz_20[i][j] == '\0')
      {
        selecionada = rand() % 26;
        matriz_20[i][j]=letras[selecionada];
        matriz_20_resposta[i][j]='#';
      }
    }
  }
}

void push_matriz_20()
{
  for(int i=0 ; i<20 ;i++)
  {
    for( int j=0 ; j<20 ; j++)
    {
        printf("[%c]",matriz_20[i][j]);
    }
    printf("\n");
  }
}

void make(FILA *fila,int tipo_fila) // 0 animais 1 frutas
{
  char letra,palavra[20];
  int contador=0,linha;

  if(tipo_fila == 0)
  {
    char arquivo[]="animais.txt";
    FILE *ptr;
    ptr = fopen(arquivo,"r");

    if( arquivo == NULL)
    {
        printf("Erro\n");
    }
    else
    {
        linha = rand() % 39;
        do
        {
          fscanf(ptr,"%s\n",palavra);
          contador++;
        }while(contador <= (linha));// desce a pilha pra chegar na palavra escolhida

        while(letra != '\n')
        {
          letra=fgetc(ptr);
          if( letra != '\n')
          {
            insere(fila,letra); //coloca as letras da palvra sorteada na fila
          }
        }
        fclose(ptr);
    }
  }
  else if( tipo_fila == 1)
  {
    char arquivo[]="frutas.txt";
    FILE *ptr;
    ptr = fopen(arquivo,"r");

    if( arquivo == NULL)
    {
        printf("Erro\n");
    }
    else
    {
        linha = rand() % 39;
        do
        {
          fscanf(ptr,"%s\n",palavra);
          contador++;
        }while(contador <= (linha));

        while(letra != '\n')
        {
          letra=fgetc(ptr);
          if( letra != '\n')
          {
            insere(fila,letra); //coloca as letras da palvra sorteada na pilha
          }
        }
        fclose(ptr);
    }
  }
  else
  {
    printf("ERRO MAKE\n");
    exit(1);
  }
}


void selec(int set)
{
  if(set == 1)
  {
    printf("\n{MODO DE JOGO : TABELA 15x15 COM NOMES DE ANIMAIS}\n\nNOTA:São 15 palavras a serem encontradas\n");

  }
  else if(set == 2)
  {
    printf("\n{MODO DE JOGO :  TABELA 15x15 COM NOMES DE FRUTAS}\n\nNOTA:São 15 palavras a serem encontradas");
  }
  else if(set == 3)
  {
    printf("\n{MODO DE JOGO :  TABELA 20x20 COM NOMES DE ANIMAIS}\n\nNOTA:São 15 palavras a serem encontradas");
  }
  else if(set == 4)
  {
    printf("\n{MODO DE JOGO :  TABELA 20x20 COM NOMES DE FRUTAS}\n\nNOTA:São 15 palavras a serem encontradas");
  }
  else
  {
    printf("OPÇÃO INVALIDA\n");
  }
}


// -------------------------------------------------------------------------------------------------
int look_15(int linha,int coluna,int organizacao,FILA *fila) //se 0 pode gravar na matriz
{
  int tamanho;
  tamanho=tam_fila(fila);
  if(organizacao == 0)
  {
    for( int m=coluna ; m<=(coluna+tamanho-1) ; m++)
    {
      if(matriz_15[linha][m] != '\0')
      {
        return 1;
        break;
      }
    }
    return 0;
  }
  else if(organizacao == 1)
  {
    while( (tamanho-1) >= 0)
    {
      if(matriz_15[linha][coluna] != '\0')
        {
          return 1;
          break;
        }
      tamanho--;
      coluna--;
    }
    return 0;
  }
  else if(organizacao == 2)
  {
    for( int m=linha ; m<=(linha+tamanho-1) ; m++)
    {
      if(matriz_15[m][coluna] != '\0')
      {
        return 1;
        break;
      }
    }
    return 0;
  }
  else if(organizacao == 3)
  {
    while( (tamanho-1) >= 0)
    {
      if(matriz_15[linha][coluna] != '\0')
        {
          return 1;
          break;
        }
      tamanho--;
      linha--;
    }
    return 0;
  }
  else if(organizacao == 4)
  {
    for( int m=coluna ; m<=(coluna+tamanho-1) ; m++)
    {
      if(matriz_15[linha][m] != '\0')
      {
        return 1;
        break;
      }
      linha++;
    }
    return 0;
  }
  else if(organizacao == 5)
  {
    while( (tamanho-1) >= 0)
    {
      if(matriz_15[linha][coluna] != '\0')
        {
          return 1;
          break;
        }
      tamanho--;
      coluna--;
      linha--;
    }
    return 0;
  }
}


int look_20(int linha,int coluna,int organizacao,FILA *fila) //se 0 pode gravar na matriz
{
  int tamanho;
  tamanho=tam_fila(fila);
  if(organizacao == 0)
  {
    for( int m=coluna ; m<=(coluna+tamanho-1) ; m++)
    {
      if(matriz_20[linha][m] != '\0')
      {
        return 1;
        break;
      }
    }
    return 0;
  }
  else if(organizacao == 1)
  {
    while( (tamanho-1) >= 0)
    {
      if(matriz_20[linha][coluna] != '\0')
        {
          return 1;
          break;
        }
      tamanho--;
      coluna--;
    }
    return 0;
  }
  else if(organizacao == 2)
  {
    for( int m=linha ; m<=(linha+tamanho-1) ; m++)
    {
      if(matriz_20[m][coluna] != '\0')
      {
        return 1;
        break;
      }
    }
    return 0;
  }
  else if(organizacao == 3)
  {
    while( (tamanho-1) >= 0)
    {
      if(matriz_20[linha][coluna] != '\0')
        {
          return 1;
          break;
        }
      tamanho--;
      linha--;
    }
    return 0;
  }
  else if(organizacao == 4)
  {
    for( int m=coluna ; m<=(coluna+tamanho-1) ; m++)
    {
      if(matriz_20[linha][m] != '\0')
      {
        return 1;
        break;
      }
      linha++;
    }
    return 0;
  }
  else if(organizacao == 5)
  {
    while( (tamanho-1) >= 0)
    {
      if(matriz_20[linha][coluna] != '\0')
        {
          return 1;
          break;
        }
      tamanho--;
      coluna--;
      linha--;
    }
    return 0;
  }
}


void get_word_15(FILA *fila,int tipo_fila)
{
  long int control=0;
  organizacao = rand() % 5;
  if(organizacao==0)
  {
    do {
      control++;
      if( control > 1)
      {
        desconstrutor(fila);
      }
      make(fila,tipo_fila);
      linha= rand() % 14;
      coluna = rand() %14;
    }while( (tam_fila(fila) > (15 - coluna)) || look_15(linha,coluna,organizacao,fila));

    while( !vazia(fila) )
    {
      retira(fila,&letter);
      matriz_15[linha][coluna]=letter;
      matriz_15_resposta[linha][coluna]=letter;
      coluna++;
    }
  }
  else if( organizacao == 1)
  {

    do {
      control++;
      if( control > 1)
      {
        desconstrutor(fila);
      }
      make(fila,tipo_fila);
      linha= rand() % 14;
      coluna = rand() %14;
    } while( (tam_fila(fila) > (coluna+1)) || look_15(linha,coluna,organizacao,fila));
    while( !vazia(fila) )
    {
      retira(fila,&letter);
      matriz_15[linha][coluna]=letter;
      matriz_15_resposta[linha][coluna]=letter;
      coluna--;
    }
  }
    else if( organizacao == 2)
    {

      do {
        control++;
        if( control > 1)
        {
          desconstrutor(fila);
        }
        make(fila,tipo_fila);
        linha= rand() % 14;
        coluna = rand() %14;
      } while((tam_fila(fila) > (15 - linha)) || look_15(linha,coluna,organizacao,fila));
      while( !vazia(fila) )
      {
        retira(fila,&letter);
        matriz_15[linha][coluna]=letter;
        matriz_15_resposta[linha][coluna]=letter;
        linha++;
      }
  }
  else if( organizacao == 3)
  {

    do {
      control++;
      if( control > 1)
      {
        desconstrutor(fila);
      }
      make(fila,tipo_fila);
      linha= rand() % 14;
      coluna = rand() %14;;
    } while( (tam_fila(fila) > (linha+1)) || look_15(linha,coluna,organizacao,fila));
    while( !vazia(fila) )
    {
      retira(fila,&letter);
      matriz_15[linha][coluna]=letter;
      matriz_15_resposta[linha][coluna]=letter;
      linha--;
    }
 }
 else if( organizacao == 4)
 {
   do {
     control++;
     if( control > 1)
     {
       desconstrutor(fila);
     }
     make(fila,tipo_fila);
     linha= rand() % 14;
     coluna = rand() %14;
   } while( (tam_fila(fila) > (15-linha))  || (tam_fila(fila) > (15-coluna)) || look_15(linha,coluna,organizacao,fila));
   while( !vazia(fila) )
   {
     retira(fila,&letter);
     matriz_15[linha][coluna]=letter;
     matriz_15_resposta[linha][coluna]=letter;
     linha++;
     coluna++;
   }
 }
 else if( organizacao == 5)
 {
   do {
     control++;
     if( control > 1)
     {
       desconstrutor(fila);
     }
     make(fila,tipo_fila);
     linha= rand() % 14;
     coluna = rand() %14;
   } while( (tam_fila(fila) > (coluna+1)) || (tam_fila(fila) > (linha+1))  || look_15(linha,coluna,organizacao,fila));
   while( !vazia(fila) )
   {
     retira(fila,&letter);
     matriz_15[linha][coluna]=letter;
     matriz_15_resposta[linha][coluna]=letter;
     linha--;
     coluna--;
   }
 }
}


void get_word_20(FILA *fila,int tipo_fila)
{
  long int control=0;
  organizacao = rand() % 5;
  if(organizacao==0)
  {
    do {
      control++;
      if( control > 1)
      {
        desconstrutor(fila);
      }
      make(fila,tipo_fila);
      linha= rand() % 19;
      coluna = rand() %19;
    }while( (tam_fila(fila) > (20 - coluna)) || look_20(linha,coluna,organizacao,fila));

    while( !vazia(fila) )
    {
      retira(fila,&letter);
      matriz_20[linha][coluna]=letter;
      matriz_20_resposta[linha][coluna]=letter;
      coluna++;
    }
  }
  else if( organizacao == 1)
  {
    do {
      control++;
      if( control > 1)
      {
        desconstrutor(fila);
      }
      make(fila,tipo_fila);
      linha= rand() % 19;
      coluna = rand() %19;
    } while( (tam_fila(fila) > (coluna+1)) || look_20(linha,coluna,organizacao,fila));
    while( !vazia(fila) )
    {
      retira(fila,&letter);
      matriz_20[linha][coluna]=letter;
      matriz_20_resposta[linha][coluna]=letter;
      coluna--;
    }
  }
    else if( organizacao == 2)
    {
      do {
        control++;
        if( control > 1)
        {
          desconstrutor(fila);
        }
        make(fila,tipo_fila);
        linha= rand() % 19;
        coluna = rand() %19;
      } while((tam_fila(fila) > (20 - linha)) || look_20(linha,coluna,organizacao,fila));
      while( !vazia(fila) )
      {
        retira(fila,&letter);
        matriz_20[linha][coluna]=letter;
        matriz_20_resposta[linha][coluna]=letter;
        linha++;
      }
  }
  else if( organizacao == 3)
  {
    do {
      control++;
      if( control > 1)
      {
        desconstrutor(fila);
      }
      make(fila,tipo_fila);
      linha= rand() % 19;
      coluna = rand() %19;
    } while( (tam_fila(fila) > (linha+1)) || look_20(linha,coluna,organizacao,fila));
    while( !vazia(fila) )
    {
      retira(fila,&letter);
      matriz_20[linha][coluna]=letter;
      matriz_20_resposta[linha][coluna]=letter;
      linha--;
    }
 }
 else if( organizacao == 4)
 {
   do {
     control++;
     if( control > 1)
     {
       desconstrutor(fila);
     }
     make(fila,tipo_fila);
     linha= rand() % 19;
     coluna = rand() %19;
   } while( (tam_fila(fila) > (20-linha))  || (tam_fila(fila) > (20-coluna)) || look_20(linha,coluna,organizacao,fila));
   while( !vazia(fila) )
   {
     retira(fila,&letter);
     matriz_20[linha][coluna]=letter;
     matriz_20_resposta[linha][coluna]=letter;
     linha++;
     coluna++;
   }
 }
 else if( organizacao == 5)
 {
   do {
     control++;
     if( control > 1)
     {
       desconstrutor(fila);
     }
     make(fila,tipo_fila);
     linha= rand() % 19;
     coluna = rand() %19;
   } while( (tam_fila(fila) > (coluna+1)) || (tam_fila(fila) > (linha+1)) || look_20(linha,coluna,organizacao,fila));
   while( !vazia(fila) )
   {
     retira(fila,&letter);
     matriz_20[linha][coluna]=letter;
     matriz_20_resposta[linha][coluna]=letter;
     linha--;
     coluna--;
   }
 }
}


void jogo(int set)
{
  if(set == 1)
  {
    num_palavra=0;
    while( num_palavra < 16)
    {
      get_word_15(animais,0);
      num_palavra++;
    }
    get_matriz_15();
    push_matriz_15(0);
  }
  else if(set == 2)
  {
    num_palavra=0;
    while( num_palavra < 16)
    {
      get_word_15(frutas,1);
      num_palavra++;
    }
    get_matriz_15();
    push_matriz_15(0);
  }
  else if(set == 3)
  {
    num_palavra=0;
    while( num_palavra < 16)
    {
      get_word_20(animais,0);
      num_palavra++;
    }
    get_matriz_20();
    push_matriz_20(0);
  }
  else if(set == 4)
  {
    num_palavra=0;
    while( num_palavra < 16)
    {
      get_word_20(frutas,1);
      num_palavra++;
    }
    get_matriz_20();
    push_matriz_20(0);
  }
}

void grava(int tam)
{
  char arquivo[]="matriz.txt";
  FILE *ptr;
  ptr = fopen(arquivo,"w");
  if(!ptr)
  {printf("ERRO NA GRAVAÇÃO\n"); }
  else
  {
  if(tam == 15)
  {
    for(int i=0; i<15 ; i++)
    {
      for(int j=0 ; j<15 ; j++)
      {
        // aux=matriz_15[i][j];
        putc(matriz_15[i][j],ptr);
        putc(' ',ptr);
      }
      fputs("\n",ptr);
    }
    for(int i=0; i<15 ; i++)
    {
      for(int j=0 ; j<15 ; j++)
      {
        // aux=matriz_15[i][j];
        putc(matriz_15_resposta[i][j],ptr);
        putc(' ',ptr);
      }
      fputs("\n",ptr);
    }
  }
  else if(tam == 20)
  {

    for(int i=0; i<20 ; i++)
    {
      for(int j=0 ; j<20 ; j++)
      {
        // aux=matriz_20[i][j];
        putc(matriz_20[i][j],ptr);
        putc(' ',ptr);
      }
      fputs("\n",ptr);
    }
    for(int i=0; i<20 ; i++)
    {
      for(int j=0 ; j<20 ; j++)
      {
        // aux=matriz_15[i][j];
        putc(matriz_20_resposta[i][j],ptr);
        putc(' ',ptr);
      }
      fputs("\n",ptr);
    }
  }
  fclose(ptr);
  }
}
