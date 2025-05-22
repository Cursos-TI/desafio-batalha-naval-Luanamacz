#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5
#define TAM_HABILIDADE 5 // Tamanho das matrizes de habilidade (5x5)

void inicializarTabuleiro(int tabuleiro[TAM][TAM]){
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAM][TAM]){
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == AGUA)
                printf("~ ");
            else if (tabuleiro[i][j] == NAVIO)
                printf("N ");
            else if (tabuleiro[i][j] == HABILIDADE)
                printf("* ");
        }
        printf("\n");
    }
}

void posicionarNavios(int tabuleiro[TAM][TAM]){
    for (int i = 0; i < 3; i++){
        tabuleiro[1][2 + i] = NAVIO;
    }

    for (int i = 0; i < 3; i++){
        tabuleiro[5 + i][7] = NAVIO;
    }

    for (int i = 0; i < 3; i++) {
        tabuleiro[3 + i][3 + i] = NAVIO;
    }

    for (int i = 0; i < 3; i++){
        tabuleiro[5 + i][6 - i] = NAVIO;
    }
}

void gerarCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]){
    for (int i = 0; i < TAM_HABILIDADE; i++){
        for (int j = 0; j < TAM_HABILIDADE; j++){
            if (i >= j - 2 && i >= 2 - j)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void gerarCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]){
    for (int i = 0; i < TAM_HABILIDADE; i++){
        for (int j = 0; j < TAM_HABILIDADE; j++){
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void gerarOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]){
    for (int i = 0; i < TAM_HABILIDADE; i++){
        for (int j = 0; j < TAM_HABILIDADE; j++){
            if (abs(i - 2) + abs(j - 2) <= 2) 
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAM][TAM], 
    int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], 
    int linhaCentro, int colunaCentro){
    int offset = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++){
        for (int j = 0; j < TAM_HABILIDADE; j++){
            int linhaTab = linhaCentro - offset + i;
            int colunaTab = colunaCentro - offset + j;

            if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM){
                if (habilidade[i][j] == 1 && tabuleiro[linhaTab][colunaTab] == AGUA){
                    tabuleiro[linhaTab][colunaTab] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    aplicarHabilidade(tabuleiro, cone, 2, 2);      
    aplicarHabilidade(tabuleiro, cruz, 5, 5);     
    aplicarHabilidade(tabuleiro, octaedro, 7, 2);   

    printf("\nLegenda: ~ = Água | N = Navio | * = Habilidade\n\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
