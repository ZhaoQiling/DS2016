#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;
#define INFINITY 1000000
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */
typedef int WeightType;

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;

MGraph ReadG(); /* details omitted */

void ShortestDist( MGraph Graph, int dist[], Vertex S );

int main()
{
    int dist[MaxVertexNum];
    Vertex S, V;
    MGraph G = ReadG();

    scanf("%d", &S);
    ShortestDist( G, dist, S );

    for ( V=0; V<G->Nv; V++ )
        printf("%d ", dist[V]);

    return 0;
}


void ShortestDist( MGraph Graph, int dist[], Vertex S ){

    int isVis[MaxVertexNum + 10];
    for(int i = 0; i < Graph->Nv; i++)
        isVis[i] = 0;
    for(int i = 0; i < Graph->Nv; i++)
        dist[i] = Graph->G[S][i];

    for(int i = 0; i < Graph->Nv; i++){
        int min = INFINITY;
        int u;
        for(int j = 0; j < Graph->Nv; j++){
            if(isVis[j])
                continue;
            if(dist[j] < min){
                min = dist[j];
                u = j;
            }
        }
        isVis[u] = 1;
        for(int v = 0; v < Graph->Nv; v++){
            if(dist[v] > min + Graph->G[u][v])
                dist[v] = min + Graph->G[u][v];
        }
    }
    for(int i = 0; i < Graph->Nv; i++){
        if(i == S)
            dist[i] = 0;
        else if(dist[i] == INFINITY)
            dist[i] = -1;
    }
}
