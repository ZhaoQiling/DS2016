#include <stdio.h>
#include <stdlib.h>
typedef struct Queue Queue;
struct Queue{
    int arr[100];
    int front, rear;
};
Queue* createQueue(){
    Queue* ret = (Queue*) malloc(sizeof(Queue));
    ret->rear = -1; ret->front = 0;
    return ret;
}
void pushElement(Queue* que, int value){
    que->rear++;
    que->arr[que->rear] = value;
}
void popElement(Queue* que){
    que->front++;
}
int sizeQueue(Queue* que){
    return que->rear - que->front + 1;
}
int frontElement(Queue* que){
    return que->arr[que->front];
}
int leftChild[20];
int rightChild[20];
int nNode;
int getRoot(int key){
    for(int i = 0; i < nNode; i++){
        if(rightChild[i] == key || leftChild[i] == key)
            return getRoot(i);
    }
    return key;
}

int main(){
    scanf("%d", &nNode);
    getchar();
    for(int i = 0; i < nNode; i++){
        char l, r;
        scanf("%c %c", &l, &r);
        getchar();
        leftChild[i] = (l >= '0' && l <= '9') ? (l - '0') : -1;
        rightChild[i] = (r >= '0' && r <= '9') ? (r - '0') : -1;
    }
    // printf("\n");
    // for(int i = 0; i < nNode; i++){
    //     printf("%d %d\n", leftChild[i], rightChild[i]);
    // }
    int flag = 0;
    int root = getRoot(0);
    // printf("%d", root);
    Queue* que = createQueue();
    pushElement(que, root);
    while(sizeQueue(que) != 0){
        int front = frontElement(que);
        if(leftChild[front] == -1 && rightChild[front] == -1){
            if(flag == 1)
                printf(" ");
            printf("%d", front);
            flag = 1;
        }
        if(leftChild[front] != -1){
            pushElement(que, leftChild[front]);

        }
        if(rightChild[front] != -1){
            pushElement(que, rightChild[front]);
        }
        popElement(que);
    }
    return 0;
}
