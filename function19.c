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

// LGraph ReadG(); /* details omitted */

int CountConnectedComponents( LGraph Graph );

int main()
{
    LGraph G;
    // = ReadG();
    printf("%d\n", CountConnectedComponents(G));

    return 0;
}
int CountConnectedComponents( LGraph Graph ){
    if(Graph == NULL || Graph->Nv == 0)
        return 0;
    if(Graph->Ne == 0)
        return Graph->Nv;

    int isVis[500];
    for(int i = 0; i < 500; i++)
        isVis[i] = 0;
    int ans = 0;
    for(int i = 0; i < Graph->Nv; i++){
        if(isVis[i] == 1)
            continue;
        ans++;
        isVis[i] = 1;
        int que[500];
        int head, tail;
        head = tail = 0;
        que[tail++] = i;
        while(head < tail){
            PtrToAdjVNode pCur = Graph->G[que[head++]].FirstEdge;
            for(; pCur != NULL; pCur = pCur->Next){
                if(isVis[pCur->AdjV])
                    continue;
                isVis[pCur->AdjV] = 1;
                que[tail++] = pCur->AdjV;
            }
        }
    }
    return ans;
}
