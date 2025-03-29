#include <stdio.h>

int main () {

    //Impressão do título do jogo
    printf("TABULEIRO BATALHA NAVAL\n\n");

    //Definição do tabuleiro 10x10 - inicialização com 0 (água)
    int tabuleiro[10][10];
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }

    //Definição das letras para linhas e numeração das colunas
    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int numeros[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //Navio horizontal
    int navio_horizontal[3];
    int linha_h = 2; //Linha C (índice 2)
    int coluna_h = 3; //Coluna 4 (índice 3)

    //Valida se o navio horizontal cabe no tabuleiro
    if (coluna_h + 2 >= 10) {
        printf("ERRO: Navio Horizontal não cabe nas colunas selecionadas.\n");
        return 1;
    }

    //Posiciona o navio horizontal
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_h][coluna_h + i] = 3;
    }


    //Navio vertical 
    int navio_vertical[3];
    int linha_v = 5; //Linha F (índice 5)
    int coluna_v = 7; //Coluna 8 (índice 7)

    //Valida se o navio vertical cabe no tabuleiro
    if (linha_v + 2 >= 10) {
        printf("ERRO: Navio vertical não cabe nas linhas selecionadas.\n");
        return 1;
    }


    //Valida se os navios não se sobrepoem
    for (int i = 0; i < 3; i++){
        if (tabuleiro[linha_v + i][coluna_v] == 3){
            printf("ERRO: Navios se sobrepondo na posição %c %d.\n", letras[linha_v + 1], numeros[coluna_v]);
            return 1;
        }
    }


    //Posiciona o navio verticalmente
    for (int i = 0; i < 3; i++){
        tabuleiro[linha_v + i][coluna_v] = 3;
    }


    //Imprime o cabeçalho das colunas
    printf("  ");
    for (int j = 0; j < 10; j++) {
        printf("%2d", numeros[j]);
    }
    printf("\n");

    //Imprime o tabuleiro com as letras das linhas
    for (int i = 0; i < 10; i++){
        printf("%2c", letras[i]);
        for (int j = 0; j < 10; j++) {
            printf("%2d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;


}
