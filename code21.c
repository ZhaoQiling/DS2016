#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int isPrime(int val){
    if(val == 1)
        return 0;
    for(int i = 2; i <= sqrt(val); i++)
        if(val % i == 0)
            return 0;
    return 1;
}
int hash[50000];
int isVis[50000];
int main(){
    int tableSize, nQuery;
    scanf("%d%d", &tableSize, &nQuery);
    while(!isPrime(tableSize))
        tableSize++;
    int flag = 0;
    for(int i = 0; i < nQuery; i++){
        int loc = -1;
        memset(isVis, 0, sizeof(isVis));
        int key;
        scanf("%d", &key);
        int origin = key;
        for(int i = 0; ; i++){
            // printf("key is %d", key);
            key = (origin + i * i) % tableSize;
            if(isVis[key] == 1)
                break;
            isVis[key] = 1;

            if(hash[key] == 1)
                continue;
            hash[key] = 1;

            loc = key; break;
        }

        if(flag == 1)
            printf(" ");
        if(loc == -1)
            printf("-");
        else
            printf("%d", loc);
        flag = 1;
    }
    return 0;
}
