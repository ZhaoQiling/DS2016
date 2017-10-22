#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Stu Stu;
struct Stu{
    int isSub;
    int id;
    int sumScore;
    int proScore[10];
    int nPerfect;
};
Stu ranklist[10100];
int prob_score[10];
int cmp(const void* pa, const void* pb){
    const Stu* a = (const Stu *)pa;
    const Stu* b = (const Stu *)pb;

    if(a->sumScore != b->sumScore)
        return b->sumScore - a->sumScore;
    if(a->nPerfect != b->nPerfect)
        return b->nPerfect - a->nPerfect;
    return a->id - b->id;
}
int main(){
    int nUser, nProb, nSubm;
    scanf("%d%d%d", &nUser, &nProb, &nSubm);
    for(int i = 1; i <= nUser; i++){
        ranklist[i].isSub = 0;
        ranklist[i].id = i;
        ranklist[i].sumScore = 0;
        memset(ranklist[i].proScore, -1, sizeof(ranklist[i].proScore));
        ranklist[i].nPerfect = 0;
    }
    for(int i = 1; i <= nProb; i++)
        scanf("%d", &prob_score[i]);
    for(int i = 0; i < nSubm; i++){
        int userid, proid, score;
        scanf("%d%d%d", &userid, &proid, &score);
        if(score == -1 && ranklist[userid].proScore[proid] == -1){
            ranklist[userid].proScore[proid] = 0;
            continue;
        }
        ranklist[userid].isSub = 1;

        if(score > ranklist[userid].proScore[proid]){
            if(score == prob_score[proid])
                ranklist[userid].nPerfect++;

            if(ranklist[userid].proScore[proid] < 0)
                ranklist[userid].sumScore += score;
            else
                ranklist[userid].sumScore += score - ranklist[userid].proScore[proid];

            ranklist[userid].proScore[proid] = score;
        }
    }


    qsort(ranklist + 1, nUser, sizeof(Stu), cmp);

    int lastRank = 0;
    int lastScore = 9999999;
    for(int i = 1; i <= nUser; i++){
        if(ranklist[i].isSub == 0)
            continue;
        if(ranklist[i].sumScore == lastScore)
            printf("%d", lastRank);
        else{
            printf("%d", i);
            lastRank = i;
            lastScore = ranklist[i].sumScore;
        }
        printf(" %05d %d", ranklist[i].id, ranklist[i].sumScore);
        for(int j = 1; j <= nProb; j++){
            if(ranklist[i].proScore[j] == -1)
                printf(" -");
            else
                printf(" %d", ranklist[i].proScore[j]);
        }
        printf("\n");
    }
    return 0;
}
