#include<stdio.h>
#include<string.h>
char p;
char ans[402];
char* ptr=ans;
long long int power(long long int n,int x){
    if(x==0) return 1;
    else if(x>0) return n*power(n,x-1);
}
void revarr(char *pntr,int n,int i){
    if(i>=n/2) return;
    char temp=*(pntr+i);
    *(pntr+i)=*(pntr+n-1-i);
    *(pntr+n-1-i)=temp;
    revarr(pntr,n,i+1);
}
char* multiply(char* num1, char* num2){
    if((*num1=='0')||(*num2=='0')){
        p='0';
        return &p;
    }
    else{
        long long int n1=0, n2=0, s1, s2;
        s1=strlen(num1);s2=strlen(num2);
        for(int i=0;i<s1;i++){
            n1+=power(10,s1-i-1)*((*(num1+i))-'0');
        }
        for(int i=0;i<s2;i++){
            n2+=power(10,s2-i-1)*((*(num2+i))-'0');
        }
        long long int prdct=n1*n2;
        int q=0;
        while(prdct>0){
            int a=prdct%10;
            ans[q]='0'+a;
            prdct/=10;
            q++;
        }
        ans[q]='\0';
        revarr(ptr,q,0);
        return ptr;
    }
}
int main(){
    char num1[200],num2[200];
    scanf("%s %s",num1,num2);
    char *p1, *p2;
    p1=num1;p2=num2;
    char* product=multiply(p1,p2);
    printf("%s",product);
}