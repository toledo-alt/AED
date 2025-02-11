#include <stdio.h>

int main()
{
    int tabuleiro[9][9], numInstancias, i, linha, coluna, instancia, valido, linhaQuadrante, colunaQuadrante;
    scanf("%d", &numInstancias);
    int resultados[numInstancias];
    for (instancia = 0; instancia < numInstancias; instancia++)
    {
        valido = 0;
        for (linha = 0; linha < 9; linha++)
        {
            for (coluna = 0; coluna < 9; coluna++)
            {
                tabuleiro[linha][coluna] = 0;
            }
        }
        for (linha = 0; linha < 9; linha++)
        {
            for (coluna = 0; coluna < 9; coluna++)
            {
                scanf("%d", &tabuleiro[linha][coluna]);
                for (i = 0; i < 9; i++)
                {
                    if (i != linha)
                    {
                        if (tabuleiro[linha][coluna] == tabuleiro[i][coluna])
                        {
                            valido = 1;
                        }
                    }
                }
                for (i = 0; i < 9; i++)
                {
                    if (i != coluna)
                    {
                        if (tabuleiro[linha][coluna] == tabuleiro[linha][i])
                        {
                            valido = 1;
                        }
                    }
                }
                linhaQuadrante = linha / 3;
                colunaQuadrante = coluna / 3;
                switch (linhaQuadrante)
                {
                case 1:
                    linhaQuadrante = 3;
                    break;
                case 2:
                    linhaQuadrante = 6;
                    break;
                }
                switch (colunaQuadrante)
                {
                case 1:
                    colunaQuadrante = 3;
                    break;
                case 2:
                    colunaQuadrante = 6;
                    break;
                }
                for (i = linhaQuadrante; i < linhaQuadrante + 3; i++)
                {
                    for (int j = colunaQuadrante; j < colunaQuadrante + 3; j++)
                    {
                        if (i != linha && j != coluna)
                        {
                            if (tabuleiro[linha][coluna] == tabuleiro[i][j])
                            {
                                valido = 1;
                            }
                        }
                    }
                }
            }
        }
        resultados[instancia] = valido;
    }
    for (instancia = 0; instancia < numInstancias; instancia++)
    {
        printf("Instancia %d\n", instancia + 1);
        if (resultados[instancia] == 0)
        {
            printf("SIM\n\n");
        }
        else
        {
            printf("NAO\n\n");
        }
    }
    return 0;
}
