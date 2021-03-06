#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
    Vertex AdjV;
    PtrToAdjVNode Next;
};

typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

LGraph ReadG(); /* details omitted */
LGraph ReadG(){
    PtrToGNode ret = (PtrToGNode)malloc(sizeof(struct GNode));
    for(int i = 0; i < MaxVertexNum; i++){
        ret->G[i].FirstEdge = NULL;
    }
    int nVertex, nEdge;
    scanf("%d%d", &nVertex, &nEdge);
    ret->Nv = nVertex;
    ret->Ne = nEdge;
    for(int i = 0; i < nEdge; i++){
        int a, b;
        scanf("%d%d", &a, &b);

        PtrToAdjVNode pTemp = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
        pTemp->AdjV = b; pTemp->Next = NULL;
        PtrToAdjVNode pCur = ret->G[a].FirstEdge;

        if(pCur == NULL)
            ret->G[a].FirstEdge = pTemp;
        else if(pCur != NULL){
            pTemp->Next = ret->G[a].FirstEdge;
            ret->G[a].FirstEdge = pTemp;
        }
    }
    return ret;
}
void OutputG(LGraph Graph){
    for(int i = 0; i < Graph->Nv; i++){
        printf("%d", i);
        PtrToAdjVNode pCur = Graph->G[i].FirstEdge;
        while(pCur != NULL){
            printf(" %d", pCur->AdjV);
            pCur = pCur->Next;
        }
        printf("\n");
    }
}
bool TopSort( LGraph Graph, Vertex TopOrder[] );

int main()
{
    int i;
    Vertex TopOrder[MaxVertexNum];
    LGraph G = ReadG();
    // OutputG(G);
    // printf("\n\n");
    if ( TopSort(G, TopOrder)==true )
        for ( i=0; i<G->Nv; i++ )
            printf("%d ", TopOrder[i]);
    else
        printf("ERROR");
    printf("\n");

    return 0;
}

bool TopSort( LGraph Graph, Vertex TopOrder[] ){
    int ansCur = 0;
    int inDegree[Graph->Nv + 10];
    for(int i = 0; i < Graph->Nv; i++){
        inDegree[i] = 0;
    }
    for(int i = 0; i < Graph->Nv; i++){
        PtrToAdjVNode pCur = Graph->G[i].FirstEdge;
        for(; pCur != NULL; pCur = pCur->Next){
            inDegree[pCur->AdjV]++;
        }
    }
    int que[MaxVertexNum + 10];

    int head = 0;
    int tail = 0;
    for(int i = 0; i < Graph->Nv; i++){
        if(inDegree[i] == 0){
            que[tail++] = i;
            break;
        }
    }

    while(head < tail){
        Vertex front = que[head++];
        // printf("%d ", front);
        TopOrder[ansCur++] = front;

        PtrToAdjVNode pCur = Graph->G[front].FirstEdge;
        while(pCur != NULL){
            inDegree[pCur->AdjV]--;
            if(inDegree[pCur->AdjV] == 0){
                que[tail++] = pCur->AdjV;
            }
            pCur = pCur->Next;
        }
    }
    if(ansCur != Graph->Nv)
        return false;
    return true;
}
