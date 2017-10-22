#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Peo Peo;
struct Peo{
    char name[20];
    int age;
    int worth;
};
Peo namelist[100100];
int cmp(const void* pa, const void* pb){
    const Peo* a = (const Peo*)pa;
    const Peo* b = (const Peo*)pb;
    if(a->worth != b->worth)
        return b->worth - a->worth;
    if(a->age != b->age)
        return a->age - b->age;
    return strcmp(a->name, b->name);
}
int main(){
    int nPeo, nQuery;
    scanf("%d%d", &nPeo, &nQuery);
    for(int i = 0; i < nPeo; i++){
        scanf("%s %d %d", &namelist[i].name, &namelist[i].age, &namelist[i].worth);
    }
    qsort(namelist, nPeo, sizeof(Peo), cmp);
    int mOut, aMin, aMax;
    for(int i = 1; i <= nQuery; i++){
        scanf("%d%d%d", &mOut, &aMin, &aMax);
        printf("Case #%d:\n", i);
        int cnt = 0;
        for(int i = 0; i < nPeo; i++){
            if(namelist[i].age >= aMin && namelist[i].age <= aMax){
                cnt++;
                printf("%s %d %d\n", namelist[i].name, namelist[i].age, namelist[i].worth);
            }
            if(cnt == mOut)
                break;
        }
        if(cnt == 0)
            printf("None");
    }
    return 0;
}
