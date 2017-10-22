#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
int s2i(char* str){
    return (str[0] - 'A') * 26 * 26 * 10 +
            (str[1] - 'A') * 26 * 10+
            (str[2] - 'A') * 10 +
            (str[3] - '0');
}
char* i2s(int val){
    char* ret = (char*)malloc(sizeof(char) * 5);
    ret[0] = val / (26 * 26 * 10) + 'A';
    ret[1] = val / (26 * 10) % 26 + 'A';
    ret[2] = val / 10 % 26 + 'A';
    ret[3] = val % 10 + '0';
    ret[4] = '\0';
    return ret;
}
typedef struct Vector Course;
struct Vector{
    int arr[40010];
    int size;
};

int cmp ( const void *a , const void *b ){
    return *(int *)a - *(int *)b;
}
int main(){
    int nStu, nCour;
    scanf("%d%d", &nStu, &nCour);
    Course* courselist = (Course*) malloc(sizeof(Course) * (nCour + 10));
    for(int i = 1; i <= nStu; i++){
        char name[5];
        scanf("%s", name);
        int key = s2i(name);
        int n;
        scanf("%d", &n);
        int co;
        for(int j = 0; j < n; j++){
            scanf("%d", &co);
            courselist[co].arr[courselist[co].size++] = key;
        }
    }
    for(int i = 1; i <= nCour; i++){
        printf("%d %d\n", i, courselist[i].size);
        qsort(courselist[i].arr, courselist[i].size, sizeof(int), cmp);
        for(int j = 0; j < courselist[i].size; j++){
            printf("%s\n", i2s(courselist[i].arr[j]));
        }
    }
    return 0;
}
