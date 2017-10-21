#include <stdio.h>
int nPeo, nClub;
int arr[100000];
int club[100000];
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
    scanf("%d%d", &nPeo, &nClub);
    for(int i = 1; i <= nPeo; i++){
        arr[i] = i;
    }
    for(int i = 0; i < nClub; i++){
        int n, a, b;
        scanf("%d%d", &n, &a);
        for(int i = 1; i < n; i++){
            scanf("%d", &b);
            merge(a, b);
        }
    }
    int max = 0;
    for(int i = 1; i <= nPeo; i++){
        arr[i] = getFather(arr[i]);
        club[arr[i]]++;
        if(club[arr[i]] > max)
            max = club[arr[i]];
    }
    printf("%d", max);
    return 0;
}
