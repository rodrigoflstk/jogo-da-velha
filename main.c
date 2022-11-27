#include <stdio.h>
#include <stdlib.h>

char p1[50], p2[50];
char matriz_jogo[3][3];

int validacaoCaractere(char letra) {      // Função responsável por validar a letra que foi digitada na matriz
    if(letra == 'x' || letra == 'o') {
        return 1;
    } else {
        printf("Digite x ou o");
    }
}

int validacaoCoordenada(int x, int y) {   // Função responsável por validar a coordenada digitada
    if (x >=0 && x < 3 ) {
        if(y >= 0 && y < 3) {
            return 1;
        }
    } else {
        printf("Digite uma coordenada válida (0, 1 ou 2)");
    }
}

void estruturarJogo() {           // Função responsável por inicializar a matriz
    int lin, col;
    for (lin < 0; lin = 3; lin++) {
        for(col < 0; col = 3; col++) {
            matriz_jogo[lin][col] = " ";
        }
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}


