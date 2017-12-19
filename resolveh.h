
unsigned short int* procuraNaMatriz(char matriz[20][20], unsigned short int tamanho, char *palavra) {
  // procura palavra na matriz
  unsigned short int i, j, ii, jj, linha, coluna, aux, direcao, letras, letra;
  short int horizontal, vertical;
  char ch[2];
  unsigned short int pos[8][2][2][2];
  static unsigned short int resultado[3];

  letras = strlen(palavra); // numero de caracteres

  // primeira e ultima letras
  ch[0] = palavra[0];
  ch[1] = palavra[(letras - 1)];

  // pos -> faixas de posicoes possiveis para cada direcao e letra
  // [8] => 8 direcoes, [2] => 2 letras, [2] => i e j, [2] => min e max

  // horizontal da esquerda para a direita
  // primeira letra
  pos[0][0][0][0] = 0;
  pos[0][0][0][1] = tamanho - 1; // qualquer linha
  pos[0][0][1][0] = 0;
  pos[0][0][1][1] = tamanho - letras; // coluna max
  // ultima letra
  // tambem qualquer linha (claro)
  pos[0][1][0][0] = pos[0][0][0][0];
  pos[0][1][0][1] = pos[0][0][0][1];
  pos[0][1][1][0] = letras - 1; // tem coluna min
  pos[0][1][1][1] = tamanho - 1; // ate ultima coluna

  // horizontal da direita para esquerda
  // mesma linha do sentido oposto
  pos[1][0][0][0] = pos[0][0][0][0];
  pos[1][0][0][1] = pos[0][0][0][1];
  pos[1][1][0][0] = pos[0][0][0][0];
  pos[1][1][0][1] = pos[0][0][0][1];
  // inverte coluna min e max entre as letras do sentido oposto
  pos[1][0][1][0] = pos[0][1][1][0];
  pos[1][0][1][1] = pos[0][1][1][1];
  pos[1][1][1][0] = pos[0][0][1][0];
  pos[1][1][1][1] = pos[0][0][1][1];

  // vertical de cima para baixo
  // inverte i e j do horizontal da esquerda para a direita
  pos[2][0][0][0] = pos[0][0][1][0];
  pos[2][0][0][1] = pos[0][0][1][1];
  pos[2][1][0][0] = pos[0][1][1][0];
  pos[2][1][0][1] = pos[0][1][1][1];
  pos[2][0][1][0] = pos[0][0][0][0];
  pos[2][0][1][1] = pos[0][0][0][1];
  pos[2][1][1][0] = pos[0][1][0][0];
  pos[2][1][1][1] = pos[0][1][0][1];

  // vertical de baixo para cima
  // inverte i e j do horizontal da direita para esquerda
  pos[3][0][0][0] = pos[1][0][1][0];
  pos[3][0][0][1] = pos[1][0][1][1];
  pos[3][1][0][0] = pos[1][1][1][0];
  pos[3][1][0][1] = pos[1][1][1][1];
  pos[3][0][1][0] = pos[1][0][0][0];
  pos[3][0][1][1] = pos[1][0][0][1];
  pos[3][1][1][0] = pos[1][1][0][0];
  pos[3][1][1][1] = pos[1][1][0][1];

  // diagonal para baixo e direita
  // colunas iguais a horizontal da direita para esquerda
  pos[4][0][1][0] = pos[0][0][1][0];
  pos[4][0][1][1] = pos[0][0][1][1];
  pos[4][1][1][0] = pos[0][1][1][0];
  pos[4][1][1][1] = pos[0][1][1][1];
  // linhas igual vertical de cima para baixo
  pos[4][0][0][0] = pos[2][0][0][0];
  pos[4][0][0][1] = pos[2][0][0][1];
  pos[4][1][0][0] = pos[2][1][0][0];
  pos[4][1][0][1] = pos[2][1][0][1];

  // diagonal para baixo e esquerda
  // colunas iguais a horizontal da esquerda para direita
  pos[5][0][1][0] = pos[1][0][1][0];
  pos[5][0][1][1] = pos[1][0][1][1];
  pos[5][1][1][0] = pos[1][1][1][0];
  pos[5][1][1][1] = pos[1][1][1][1];
  // linhas igual vertical de cima para baixo
  pos[5][0][0][0] = pos[2][0][0][0];
  pos[5][0][0][1] = pos[2][0][0][1];
  pos[5][1][0][0] = pos[2][1][0][0];
  pos[5][1][0][1] = pos[2][1][0][1];

  // diagonal para cima e esquerda
  // colunas iguais a horizontal da esquerda para direita
  pos[6][0][1][0] = pos[1][0][1][0];
  pos[6][0][1][1] = pos[1][0][1][1];
  pos[6][1][1][0] = pos[1][1][1][0];
  pos[6][1][1][1] = pos[1][1][1][1];
  // linhas igual vertical de baixo para cima
  pos[6][0][0][0] = pos[3][0][0][0];
  pos[6][0][0][1] = pos[3][0][0][1];
  pos[6][1][0][0] = pos[3][1][0][0];
  pos[6][1][0][1] = pos[3][1][0][1];

  // diagonal para cima e direita
  // colunas iguais a horizontal da direita para esquerda
  pos[7][0][1][0] = pos[0][0][1][0];
  pos[7][0][1][1] = pos[0][0][1][1];
  pos[7][1][1][0] = pos[0][1][1][0];
  pos[7][1][1][1] = pos[0][1][1][1];
  // linhas igual vertical de baixo para cima
  pos[7][0][0][0] = pos[3][0][0][0];
  pos[7][0][0][1] = pos[3][0][0][1];
  pos[7][1][0][0] = pos[3][1][0][0];
  pos[7][1][0][1] = pos[3][1][0][1];

  // procura primeira ou ultima letra
  // percorre toda a matriz
  for (i = 0; i < tamanho; i++) {
    for (j = 0; j < tamanho; j++) {
      for (letra = 0; letra < 2; letra++) {
        // duas letras (primeira e ultima)
        if (matriz[i][j] == ch[letra]) {
          // encontrou letra
          // verifica direcoes possiveis
          for (direcao = 0; direcao < 8; direcao++) {
            // 8 direcoes existentes
            // checar posicoes max e min
            if (i >= pos[direcao][letra][0][0] && i <= pos[direcao][letra][0][1]) {
              // linha valida
              if (j >= pos[direcao][letra][1][0] && j <= pos[direcao][letra][1][1]) {
                // coluna valida

                // definir movimento de posicoes na busca
                switch (direcao) {
                  case 0:
                    // horizontal da esquerda para a direita
                    vertical = 0; // movimento na vertical apos cada letra
                    horizontal = 1; // horizontal apos cada letra
                    break;

                  case 1:
                    // horizontal da direita para esquerda
                    vertical = 0;
                    horizontal = -1;
                    break;

                  case 2:
                    // vertical de cima para baixo
                    vertical = 1;
                    horizontal = 0;
                    break;

                  case 3:
                    // vertical de baixo para cima
                    vertical = -1;
                    horizontal = 0;
                    break;

                  case 4:
                    // diagonal para baixo e direita
                    vertical = 1;
                    horizontal = 1;
                    break;

                  case 5:
                    // diagonal para baixo e esquerda
                    vertical = 1;
                    horizontal = -1;
                    break;

                  case 6:
                    // diagonal para cima e esquerda
                    vertical = -1;
                    horizontal = -1;
                    break;

                  case 7:
                    // diagonal para cima e direita
                    vertical = -1;
                    horizontal = 1;
                    break;
                }

                if (letra == 0) {
                  // ja ta na primeira letra
                  linha = i;
                  coluna = j;
                } else {
                  // volta pra primeira letra
                  linha = i - vertical * letras;
                  coluna = j - horizontal * letras;
                }

                // procura resto da palavra
                ii = linha + vertical;
                jj = coluna + horizontal;
                for (aux = 1; aux < letras; aux++) {
                  if (matriz[ii][jj] != palavra[aux]) {
                    // nao achou
                    aux = 99; // [aux] == 99 => return FALSE
                    break;
                  }
                  ii += vertical;
                  jj += horizontal;
                }

                if (aux < 99) {
                  // achou a palavra
                  resultado[0] = linha;
                  resultado[1] = coluna;
                  resultado[2] = direcao;
                  return resultado;
                }
              }
            }
          }
        }
      }
    }
  }

  return NULL; // nao encontrou
}

void dirToStr (char *direcao, unsigned short int dir) {
  // pega o id da direcao e retorna a respectiva string
  switch (dir) {
    case 0:
      strcpy(direcao, "horizontal da esquerda para a direita");
      break;
    case 1:
      strcpy(direcao, "horizontal da direita para a esquerda");
      break;
    case 2:
      strcpy(direcao, "vertical de cima para baixo");
      break;
    case 3:
      strcpy(direcao, "vertical de baixo para cima");
      break;
    case 4:
      strcpy(direcao, "diagonal para baixo e direita");
      break;
    case 5:
      strcpy(direcao, "diagonal para baixo e esquerda");
      break;
    case 6:
      strcpy(direcao, "diagonal para cima e esquerda");
      break;
    default:
      strcpy(direcao, "diagonal para cima e direita");
  }
}
