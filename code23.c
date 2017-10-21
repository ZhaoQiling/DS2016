#include <stdio.h>
int degree[1010];
int arr[1010];
int getFather(int a){
    if(a == arr[a])
        return a;
    arr[a] = getFather(arr[a]);
    return arr[a];
}
void merge(int a, int b){
    a = getFather(a);
    b = getFather(b);
    if(a < b)
        arr[b] = a;
    else
        arr[a] = b;
}
int main(){
    int nVertex, nEdge;
    scanf("%d%d", &nVertex, &nEdge);
    for(int i = 1; i <= nVertex; i++)
        arr[i] = i;
    int a, b;
    for(int i = 0; i < nEdge; i++){
        scanf("%d%d", &a, &b);
        degree[a]++; degree[b]++;
        merge(a, b);
    }
    for(int i = 1; i <= nVertex; i++)
        arr[i] = getFather(arr[i]);
    // printf("\n-----------\n");
    // for(int i = 1; i <= nVertex; i++)
    //     printf("%d ", arr[i]);
    // printf("\n");
    // for(int i = 1; i <= nVertex; i++)
    //     printf("%d ", degree[i]);
    // printf("\n-----------\n");
    for(int i = 2; i <= nVertex; i++){
        if(arr[i] != arr[1]){
            printf("0");
            return 0;
        }
    }
    for(int i = 1; i <= nVertex; i++){
        if(degree[i] % 2){
            printf("0");
            return 0;
        }
    }
    printf("1");
    return 0;
}
