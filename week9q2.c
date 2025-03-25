#include<stdio.h>
#include<stdlib.h>
int main(){
    int r1, c1, n1, r2, c2, n2;
    scanf("%d %d %d",&r1,&c1,&n1);
    int **p1=(int **)malloc(n1*sizeof(int *));
    for(int i=0;i<n1;i++) p1[i] = (int *)malloc(3*sizeof(int));
    for(int i=0;i<n1;i++) scanf("%d %d %d",&p1[i][0],&p1[i][1],&p1[i][2]);
    scanf("%d %d %d",&r2,&c2,&n2);
    int **p2=(int **)malloc(n2*sizeof(int *));
    for(int i=0;i<n2;i++) p2[i] = (int *)malloc(3*sizeof(int));
    for(int i=0;i<n2;i++) scanf("%d %d %d",&p2[i][0],&p2[i][1],&p2[i][2]);
    if((r1==r2)&&(c1==c2)){
        int **p3=(int **)malloc(r1*c1*sizeof(int *));
        for(int i=0;i<r1*c1;i++) p3[i]=(int *)malloc(3*sizeof(int));
        int a=0, b=0;
        for(int i=0;i<r1*c1;i++){
            p3[i][0]=a, p3[i][1]=b++, p3[i][2]=0;
            if(b==c1) b=0, a++;
        }
        for(int i=0;i<n1;i++) for(int j=0;j<r1*c1;j++) if((p3[j][0]==p1[i][0])&&(p3[j][1]==p1[i][1])) p3[j][2]+=p1[i][2];
        for(int i=0;i<n2;i++) for(int j=0;j<r1*c1;j++) if((p3[j][0]==p2[i][0])&&(p3[j][1]==p2[i][1])) p3[j][2]+=p2[i][2];
        for(int i=0;i<r1*c1;i++) if(p3[i][2]!=0) printf("%d %d %d\n",p3[i][0],p3[i][1],p3[i][2]);
        for(int i=0;i<r1*c1;i++) free(p3[i]);
        free(p3);
    }
    else printf("%d",-999);
    for(int i=0;i<n1;i++) free(p1[i]);
    for(int i=0;i<n2;i++) free(p2[i]);
    free(p1);
    free(p2);
}