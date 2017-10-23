
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
#define MinData -1

typedef struct HeapStruct *PriorityQueue;
struct HeapStruct {
    ElementType  *Elements;
    int Capacity;
    int Size;
};

PriorityQueue Initialize( int MaxElements ){
    PriorityQueue ret = (PriorityQueue)malloc(sizeof(struct HeapStruct));
    ret->Capacity = MaxElements;
    ret->Size = 0;
    ret->Elements = (ElementType* )malloc(sizeof(ElementType) * MaxElements);
    ret->Elements[0] = - 1;
    return ret;
}
void PercolateUp( int p, PriorityQueue H );
void PercolateDown( int p, PriorityQueue H );

void Insert( ElementType X, PriorityQueue H )
{
    int p = ++H->Size;
    H->Elements[p] = X;
    // printf("flag");
    PercolateUp( p, H );
}

ElementType DeleteMin( PriorityQueue H )
{
    ElementType MinElement;
    MinElement = H->Elements[1];
    H->Elements[1] = H->Elements[H->Size--];
    PercolateDown( 1, H );
    return MinElement;
}

int main()
{
    int n, i, op, X;
    PriorityQueue H;

    scanf("%d", &n);
    H = Initialize(n);
    for ( i=0; i<n; i++ ) {
        scanf("%d", &op);
        switch( op ) {
        case 1:
            scanf("%d", &X);
            Insert(X, H);
            break;
        case 0:
            printf("---%d----\n", DeleteMin(H));
            break;
        }
    }
    printf("\nInside H:");
    for ( i=1; i<=H->Size; i++ )
        printf(" %d", H->Elements[i]);
    return 0;
}

void PercolateUp( int p, PriorityQueue H ){
    // printf("H->Elements[p] is %d H->Elements[p / 2] is %d",
    //         H->Elements[p], H->Elements[p / 2]);
    while(H->Elements[p] < H->Elements[p / 2]){
        int temp = H->Elements[p];
        H->Elements[p] = H->Elements[p / 2];
        H->Elements[p / 2] = temp;
        p /= 2;
    }
}
void PercolateDown( int p, PriorityQueue H ){
    while(H->Elements[p] > H->Elements[p * 2] ||
            H->Elements[p] > H->Elements[p * 2 + 1]){
        int child = (H->Elements[p * 2] < H->Elements[p * 2 + 1]) ? (p * 2) : (p * 2 + 1);
        int temp = H->Elements[child];
        H->Elements[child] = H->Elements[p];
        H->Elements[p] = temp;
        if(child == p * 2)
            p = p * 2;
        else
            p = p * 2 + 1;
        if(p * 2 > H->Size)
            break;
    }
}
