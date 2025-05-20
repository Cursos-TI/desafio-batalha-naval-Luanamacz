#include <stdio.h>

#define tamanho_tabuleiro 10
#define tamanho_navio 3

int main() {
    int tabuleiro[tamanho_tabuleiro][tamanho_tabuleiro];

    int navioHorizontal[tamanho_navio] = {3, 3, 3};
    int navioVertical[tamanho_navio] = {3, 3, 3};

    for (int i = 0; i < tamanho_tabuleiro; i++) {
        for (int j = 0; j < tamanho_tabuleiro; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int linhaH = 2, colunaH = 1; 
    int linhaV = 5, colunaV = 4; 

    int podeColocarHorizontal = 1;
    if (colunaH + tamanho_navio <= tamanho_tabuleiro) {
        for (int i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[linhaH][colunaH + i] != 0) {
                podeColocarHorizontal = 0;
                break;
            }
        }
    } else {
        podeColocarHorizontal = 0;
    }

    if (podeColocarHorizontal) {
        for (int i = 0; i < tamanho_navio; i++) {
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites ou sobreposto.\n");
    }

    int podeColocarVertical = 1;
    if (linhaV + tamanho_navio <= tamanho_tabuleiro) {
        for (int i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                podeColocarVertical = 0;
                break;
            }
        }
    } else {
        podeColocarVertical = 0;
    }

    if (podeColocarVertical) {
        for (int i = 0; i < tamanho_navio; i++) {
            tabuleiro[linhaV + i][colunaV] = navioVertical[i];
        }
    } else {
        printf("Erro: Navio vertical fora dos limites ou sobreposto.\n");
    }

    printf("\nTabuleiro:\n");
    for (int i = 0; i < tamanho_tabuleiro; i++) {
        for (int j = 0; j < tamanho_tabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
