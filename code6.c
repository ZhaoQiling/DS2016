#include <stdio.h>
#include <string.h>
char strIn[50];
int curIn = 0;
int isRow[50];
int main(){
    scanf("%s", strIn);
    for(int i = 0; i < strlen(strIn); i++)
        isRow[i] = 1;
    for(int i = 0; i < strlen(strIn); i++){
        char c = strIn[i];
        if(c >= '0' && c <= '9')
            isRow[i] = 0;
        if(strIn[i] == '.')
            isRow[i] = 0;
        if(!(strIn[i - 1] >= '0' && strIn[i - 1] <= '9') && (c == '-' ) && (strIn[i + 1] >= '0' && strIn[i + 1] <= '9'))
        // if(!(strIn[i - 1] >= '0' && strIn[i - 1] <= '9') && (c == '-') && ())
            isRow[i] = 0;
    }
    // for(int i = 0; i < strlen(strIn); i++){
    //     printf("%d", isRow[i]);
    // }
    // printf("\n");
    int start = 0;
    if(strIn[0] == '+'){
        printf("+");
        start = 1;
    }
    for(int i = start; i < strlen(strIn); i++){
        if(isRow[i])
            printf("\n");
        printf("%c", strIn[i]);
        if(isRow[i] == 1 && isRow[i + 1] == 0)
            printf("\n");
    }
    return 0;
}
