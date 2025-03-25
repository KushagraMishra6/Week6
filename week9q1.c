#include<stdio.h>
typedef struct{
    int coeff;
    int exp;
} Term;
typedef struct{
    Term terms[201];
    int numTerms;
} Polynomial;
int main(){
    Polynomial p1, p2, sum, prdct;
    for(int i=0;i<201;i++) p1.terms[i].exp=i, p1.terms[i].coeff=0, p2.terms[i].exp=i, p2.terms[i].coeff=0, sum.terms[i].exp=i, sum.terms[i].coeff=0, prdct.terms[i].exp=i, prdct.terms[i].coeff=0;
    scanf("%d",&p1.numTerms);
    int c, e;
    for(int i=0;i<p1.numTerms;i++) scanf("%d %d",&c,&e), p1.terms[e].coeff+=c, sum.terms[e].coeff+=c;
    scanf("%d",&p2.numTerms);
    for(int i=0;i<p2.numTerms;i++) scanf("%d %d",&c,&e), p2.terms[e].coeff+=c, sum.terms[e].coeff+=c;
    for(int i=0;i<201;i++) for(int j=0;j<201;j++) prdct.terms[i+j].coeff+=p1.terms[i].coeff*p2.terms[j].coeff;
    for(int i=200;i>=0;i--) if(sum.terms[i].coeff!=0) printf("(%d,%d) ",sum.terms[i].coeff,sum.terms[i].exp);
    printf("\n");
    for(int i=200;i>=0;i--) if(prdct.terms[i].coeff!=0) printf("(%d,%d) ",prdct.terms[i].coeff,prdct.terms[i].exp);
}