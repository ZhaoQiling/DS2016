#include <stdio.h>
#include <string.h>
int origin[2100];
int check[2100];
void insertNode(int * arr, int value){
    int key = 1;
    while(arr[key] != -1){
        if(arr[key] < value)
            key *= 2;
        else
            key = 2 * key + 1;
    }
    arr[key] = value;
}
int checkNode(){
    for(int i = 0; i < 2100; i++){
        if(origin[i] != check[i])
            return 0;
    }
    return 1;
}
int main(){
    int nNode, nCheckSeq;
    while(scanf("%d%d", &nNode, &nCheckSeq) && nNode){
        int value;
        memset(origin, -1, sizeof(origin));
        for(int i = 0; i < nNode; i++){
            scanf("%d", &value);
            insertNode(origin, value);
        }
        for(int i = 0; i < nCheckSeq; i++){
            memset(check, -1, sizeof(check));
            for(int j = 0; j < nNode; j++){
                scanf("%d", &value);
                insertNode(check, value);
            }
            if(checkNode())
                printf("Yes\n");
            else
                printf("No\n");
        }

    }
    return 0;
}
