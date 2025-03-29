#include <stdio.h>
#include <stdlib.h>

// Definindo constantes
#define LINHAS 10
#define COLUNAS 10
#define TAM_HABILIDADE 5
#define AGUA 0

void mostrarTabuleiro(int matriz[LINHAS][COLUNAS]);
void aplicarHabilidade(int matriz[LINHAS][COLUNAS], int tipo, int centro_linha, int centro_coluna);

int main() {
    // Matriz do tabuleiro
    int matriz[LINHAS][COLUNAS];
    
    // Inicializa o tabuleiro com água 
    for(int i = 0; i < LINHAS; i++) {
        for(int j = 0; j < COLUNAS; j++) {
            matriz[i][j] = AGUA;
        }
    }
    
    // Aplicando as habilidades
    aplicarHabilidade(matriz, 1, 3, 4); // Cone em D5
    aplicarHabilidade(matriz, 2, 6, 2); // Cruz em G3
    aplicarHabilidade(matriz, 3, 7, 7); // Octaedro em H8 
    
    // Mostrando o resultado
    printf("TABULEIRO DE HABILIDADES - BATALHA NAVAL\n\n");
    mostrarTabuleiro(matriz);
    
    return 0;
}

void mostrarTabuleiro(int matriz[LINHAS][COLUNAS]) {
    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    
    // Cabeçalho das colunas
    printf("   ");
    for(int j = 0; j < COLUNAS; j++) {
        printf("%2d ", j+1);
    }
    printf("\n");
    
    // Corpo do tabuleiro
    for(int i = 0; i < LINHAS; i++) {
        printf("%2c ", letras[i]);
        for(int j = 0; j < COLUNAS; j++) {
            if(matriz[i][j] == AGUA) {
                printf(" . ");
            } else {
                printf(" %d ", matriz[i][j]);
            }
        }
        printf("\n");
    }
}

void aplicarHabilidade(int matriz[LINHAS][COLUNAS], int tipo, int centro_linha, int centro_coluna) {
    int meio = TAM_HABILIDADE / 2;
    
    for(int i = 0; i < TAM_HABILIDADE; i++) {
        for(int j = 0; j < TAM_HABILIDADE; j++) {
            int lin = centro_linha - meio + i;
            int col = centro_coluna - meio + j;
            
            if(lin >= 0 && lin < LINHAS && col >= 0 && col < COLUNAS) {
                int aplicar = 0;
                
                // Padrão do Cone (1)
                if(tipo == 1) {
                    if(j >= i && j < TAM_HABILIDADE - i) aplicar = 1;
                } 
                // Padrão da Cruz (2)
                else if(tipo == 2) {
                    if(i == meio || j == meio) aplicar = 1;
                } 
                // Padrão do Octaedro (3)
                else if(tipo == 3) {
                    if(abs(i - meio) + abs(j - meio) <= meio) aplicar = 1;
                }
                
                if(aplicar) matriz[lin][col] = tipo;
            }
        }
    }
}
