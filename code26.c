#include <stdio.h>
#include <stdlib.h>
#define ARRSIZE 120
#define INF 999999
int nVertex, nEdge;
int edge[ARRSIZE][ARRSIZE];
int main(){
    scanf("%d%d", &nVertex, &nEdge);
    for(int i = 1; i <= nVertex; i++)
        for(int j = 1; j <= nVertex; j++){
            if(i == j)
                edge[i][i] = 0;
            else
                edge[i][j] = INF;
        }

    for(int i = 0; i < nEdge; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edge[a][b] = edge[b][a] = c;
    }
    for(int k = 1; k <= nVertex; k++){
        for(int i = 1; i <= nVertex; i++){
            for(int j = 1; j <= nVertex; j++){
                if(edge[i][k] + edge[k][j] < edge[i][j])
                    edge[i][j] = edge[i][k] + edge[k][j];
            }
        }
    }
    int maxmin = INF;
    int loc = -1;
    for(int i = 1; i <= nVertex; i++){
        int max = 0;
        for(int j = 1; j <= nVertex; j++){
            if(i == j)
                continue;
            // printf("%d ", edge[i][j]);
            if(max < edge[i][j]){
                max = edge[i][j];
            }
        }
        // printf("\n%d's max is %d\n", i, max);
        if(max < maxmin){
            maxmin = max;
            loc = i;
        }
    }
    if(loc == -1)
        printf("0");
    else
        printf("%d %d", loc, maxmin);

    return 0;
}
