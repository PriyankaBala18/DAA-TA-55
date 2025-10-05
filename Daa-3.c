#include<stdio.h>
#include<string.h>
#define N 4
int overlap(char *a,char *b) {
    int lenA=strlen(a);
    int lenB=strlen(b);
    int maxOverlap=0;
    for(int i=1;i<=lenA&&i<=lenB;i++) {
        if(strncmp(a+lenA-i,b,i)==0) {
            maxOverlap=i;
        }
    }
    return maxOverlap;
}
int main() {
    char fragments[N][10]={"AGT","GTC","TCA","CAT"};
    int used[N]={0};
    char assembled[50]="";
    strcat(assembled,fragments[0]);
    used[0]=1;
    for(int count=1;count<N;count++) {
        int last=strlen(assembled);
        int maxO=-1,next=-1;
        for(int i=0;i<N;i++) {
            if(!used[i]){
                int ov=overlap(assembled,fragments[i]);
                if(ov>maxO) {
                    maxO=ov;
                    next=i;
                }
            }
        }
        strncat(assembled,fragments[next]+maxO,strlen(fragments[next])-maxO);
        used[next]=1;
    }
    printf("Assembled DNA Sequence:%s\n",assembled);
    return 0;
}
