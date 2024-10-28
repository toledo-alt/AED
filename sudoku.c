#include <stdio.h>

int verifica_valor(int valor, int frequencia[]) {
    if (valor < 1 || valor > 9 || frequencia[valor] == 1) return 1;
    frequencia[valor] = 1;
    return 0;
}

int valida_linhas(int grade[9][9]) {
    for (int linha = 0; linha < 9; linha++) {
        int frequencia[10] = {0};
        for (int coluna = 0; coluna < 9; coluna++) {
            if (verifica_valor(grade[linha][coluna], frequencia)) return 1;
        }
    }
    return 0;
}

int valida_colunas(int grade[9][9]) {
    for (int coluna = 0; coluna < 9; coluna++) {
        int frequencia[10] = {0};
        for (int linha = 0; linha < 9; linha++) {
            if (verifica_valor(grade[linha][coluna], frequencia)) return 1;
        }
    }
    return 0;
}

int valida_bloco(int grade[9][9], int linha_inicio, int coluna_inicio) {
    int frequencia[10] = {0};
    for (int desloca_linha = 0; desloca_linha < 3; desloca_linha++) {
        for (int desloca_coluna = 0; desloca_coluna < 3; desloca_coluna++) {
            int valor = grade[linha_inicio + desloca_linha][coluna_inicio + desloca_coluna];
            if (verifica_valor(valor, frequencia)) return 1;
        }
    }
    return 0;
}

int valida_blocos(int grade[9][9]) {
    for (int linha_inicio = 0; linha_inicio < 9; linha_inicio += 3) {
        for (int coluna_inicio = 0; coluna_inicio < 9; coluna_inicio += 3) {
            if (valida_bloco(grade, linha_inicio, coluna_inicio)) return 1;
        }
    }
    return 0;
}

int main(void) {
    int total_instancias;
    scanf("%d", &total_instancias);
    for (int caso = 1; caso <= total_instancias; caso++) {
        int grade[9][9];
        for (int linha = 0; linha < 9; linha++) {
            for (int coluna = 0; coluna < 9; coluna++) {
                scanf("%d", &grade[linha][coluna]);
            }
        }

        printf("Instancia %d\n", caso);
        if (valida_linhas(grade) == 0 && valida_colunas(grade) == 0 && valida_blocos(grade) == 0) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }
    return 0;
}
