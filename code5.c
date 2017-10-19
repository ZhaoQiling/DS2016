#include <stdio.h>
#include <stdlib.h>
typedef struct Queue Queue;
struct Queue{
    int arr[1200];
    int front, rear;
};
Queue* createQueue(){
    Queue* ret = (Queue*) malloc(sizeof(Queue));
    ret->front = 0;
    ret->rear = -1;
    return ret;
}
int ans[1200];
int curAns = 0;
void addAns(int val){
    ans[curAns++] = val;
}
void pushElement(Queue* que, int val){
    que->arr[++que->rear] = val;
}
int popElement(Queue* que){
    return que->arr[que->front++];
}
int getQueueSize(Queue* que){
    return que->rear - que->front + 1;
}
int main(){
    Queue* queA = createQueue();
    Queue* queB = createQueue();
    int nCostum;
    scanf("%d", &nCostum);
    for(int i = 0; i < nCostum; i++){
        int num;
        scanf("%d", &num);
        pushElement((num % 2) ? queA : queB, num);
    }

    while(getQueueSize(queA) != 0 || getQueueSize(queB) != 0){
        if(getQueueSize(queA) != 0){
            addAns(popElement(queA));
        }
        if(getQueueSize(queA) != 0){
            addAns(popElement(queA));
        }
        if(getQueueSize(queB) != 0){
            addAns(popElement(queB));
        }
    }
    for(int i = 0; i < curAns; i++){
        if(i != 0)
            printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}
