#include <stdio.h>
#include <stdlib.h>

char p1[50], p2[50];
char matriz_jogo[3][3];

int validacaoCaractere(char letra) {      
    if(letra == 'x' || letra == 'o') {
        return 1;
    }
    printf("Digite um caractere válido (x ou o)");
    return 0;
}

int validacaoCoordenada(int x, int y) {   
    if (x >=0 && x < 3) {
        if(y >= 0 && y < 3) {
            return 1;
        }
    }
    printf("A coordenada digitada é inválida (utilize 'x' ou 'o')");
    return 0;
}

int validacaoPosicaoVazia(int x, int y) {
    if (matriz_jogo[x][y] != 'x' && matriz_jogo[x][y] != 'o' ) {
        return 1;
    }
    printf("Essa posição já foi ocupada!");
    return 0;
}

void estruturarJogo() {           
    int lin, col;
    for (lin < 0; lin = 3; lin++) {
        for(col < 0; col = 3; col++) {
            matriz_jogo[lin][col] = ' ';
        }
    }
}

int validacaoGanharPelaLinha() { // REFATORAR
    int lin, col, contador = 1;

    for(lin = 0; lin < 3; lin++) {
        for(col = 0; col < 2; col++) {
            if(validacaoCaractere(matriz_jogo[lin][col]) && matriz_jogo[lin][col] == matriz_jogo[lin][col + 1]) {
                contador++;
            }
        }
        if(contador == 3) {
            return 1;
        }
        contador = 1;
    }
    return 0;
}

int validacaoGanharPelaColuna() { // REFATORAR
    int lin, col, contador = 1;

    for(lin = 0; lin < 3; lin++) {
        for(col = 0; col < 2; col++) {
            
            if(validacaoCaractere(matriz_jogo[col][lin]) && matriz_jogo[col][lin] == matriz_jogo[col + 1][lin]) {
                contador++;
            }
        }
        if(contador == 3) {
            return 1;
        }
        contador = 1;
    }
    return 0;
}

int validacaoGanharPelaDiagonalPrimaria() { // REFATORAR
    int lin, contador = 1;
    for(lin = 0; lin < 2; lin++) {
        if(validacaoCaractere(matriz_jogo[lin][lin] && matriz_jogo[lin][lin] == matriz_jogo[lin+1][lin+1])) {
            contador ++;
        }
    }
    if(contador == 3) {
        return 1;
    } else {
        return 0;
    }
}

int validacaoGanharPelaDiagonalSecundaria() { // REFATORAR
    int lin, contador = 1;
    for(lin = 0; lin < 2; lin++) {
        if(validacaoCaractere(matriz_jogo[lin][lin] && matriz_jogo[lin][3-lin-1] == matriz_jogo[lin+1][3-lin-1])) {
            contador ++;
        }
    }
    if(contador == 3) {
        return 1;
    } else {
        return 0;
    }
}

void imprimirMatrizJogo() {
    int lin, col;
    
    printf("\n\t   0   1   2\n");
    for(lin = 0; lin < 3; lin++) {
        printf("\t%d ", lin);
        
        for(col = 0; col < 3; col++) {
            if(col < 2) {
                printf(" %c  |", matriz_jogo[lin][col]);
            }    
            else {
                printf(" %c ", matriz_jogo[lin][col]);
            }  
        }

        if(lin < 2) {
            printf("\n\t   ---------\n");
        }
            
    }
}

void iniciarJogo() { // REFATORAR
    int lin, col, validacao, jogadas = 0, ganhou = 0, ordem = 1;
    
    do {
        do {
            imprimirMatrizJogo();
            
            printf("\n\nDigite a linha que deseja jogar: ");
            scanf("%d", &lin);

            printf("Digite a coluna que deseja jogar: ");
            scanf("%d", &col);

            validacao = validacaoCoordenada(lin, col);

            if(validacao = 1) {
                validacao += validacaoPosicaoVazia(lin, col);
            }
        } while (validacao != 2);

        if(ordem == 1) {
            matriz_jogo[lin][col] = 'x';
        } else {
            matriz_jogo[lin][col] = 'o';
        }
        
        jogadas++;
        ordem++;

        if(ordem == 3) {
            ordem = 1;
        }

        ganhou += validacaoGanharPelaLinha();
        ganhou += validacaoGanharPelaColuna();
        ganhou += validacaoGanharPelaDiagonalPrimaria();
        ganhou += validacaoGanharPelaDiagonalSecundaria();
    } while(ganhou == 0 && jogadas < 9);

    if(ganhou != 0) {
        if(ordem - 1 == 1) {
            printf("\n Parabéns %s. Você foi o vencedor!!\n", p1);
        } else {
            printf("\n Parabéns %s. Você foi o vencedor !!\n", p2);
        } 
    } else {
        printf("\n DEU RUIM!! O jogo ficou empatado.\n\n");
    }
}

int main(int argc, char const *argv[])
{
    int op;

    printf("Digite o nome do jogador 1: ");
    fgets(p1, 50, stdin);

    printf("Digite o nome do jogador 2: ");
    fgets(p2, 50, stdin);

    do {
        iniciarJogo();
        printf("Deseja jogar novamente?\n 1- sim\n 2 - não");
        scanf("%d", &op);
    } while(op == 1);

    return 0;
}
