#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água (valor 0)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se é possível posicionar um navio
int podePosicionar(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int vertical) {
    if (vertical) {
        if (linha + TAM_NAVIO > TAM_TABULEIRO) return 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != AGUA) return 0;
        }
    } else {
        if (coluna + TAM_NAVIO > TAM_TABULEIRO) return 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != AGUA) return 0;
        }
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int vertical) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (vertical)
            tabuleiro[linha + i][coluna] = NAVIO;
        else
            tabuleiro[linha][coluna + i] = NAVIO;
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("TABULEIRO:\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais fixas para os dois navios
    int linha1 = 2, coluna1 = 4; // Navio horizontal
    int linha2 = 5, coluna2 = 7; // Navio vertical

    // Verificação e posicionamento
    if (podePosicionar(tabuleiro, linha1, coluna1, 0)) {
        posicionarNavio(tabuleiro, linha1, coluna1, 0);
    } else {
        printf("Erro: Não foi possível posicionar o navio horizontal.\n");
    }

    if (podePosicionar(tabuleiro, linha2, coluna2, 1)) {
        posicionarNavio(tabuleiro, linha2, coluna2, 1);
    } else {
        printf("Erro: Não foi possível posicionar o navio vertical.\n");
    }

    // Exibição final do tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}