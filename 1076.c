#include <stdio.h>
#include <math.h>

#define TAM_MAX 49

void buscaEmLargura(int matrizAdj[TAM_MAX][TAM_MAX], int vertices, int inicio, int conectados[TAM_MAX])
{
    int fila[TAM_MAX], frente = 0, tras = 0;
    int visitados[TAM_MAX] = {0};
    visitados[inicio] = 1;
    fila[tras++] = inicio;
    while (frente < tras)
    {
        int atual = fila[frente++];
        conectados[atual] = 1;
        for (int i = 0; i < vertices; i++)
        {
            if (matrizAdj[atual][i] == 1 && !visitados[i])
            {
                visitados[i] = 1;
                fila[tras++] = i;
            }
        }
    }
}

int main()
{
    int casos, noInicial, vertices, arestas, inicioAresta, fimAresta, totalMovimentos;
    int grafo[TAM_MAX][TAM_MAX], conectados[TAM_MAX] = {0};
    scanf("%d", &casos);
    for (int i = 0; i < casos; i++)
    {
        scanf("%d", &noInicial);
        scanf("%d %d", &vertices, &arestas);
        for (int j = 0; j < TAM_MAX; j++)
        {
            for (int k = 0; k < TAM_MAX; k++)
            {
                grafo[j][k] = 0;
            }
        }
        for (int j = 0; j < arestas; j++)
        {
            scanf("%d %d", &inicioAresta, &fimAresta);
            grafo[inicioAresta][fimAresta] = 1;
            grafo[fimAresta][inicioAresta] = 1;
        }
        totalMovimentos = 0;
        buscaEmLargura(grafo, vertices, noInicial, conectados);
        for (int j = 0; j < vertices; j++)
        {
            for (int k = 0; k < vertices; k++)
            {
                if(grafo[j][k] == 1 && conectados[j] == 1 && conectados[k] == 1){
                    totalMovimentos++;
                }
            }
        }
        printf("%d\n", totalMovimentos);
    }
    return 0;
}
