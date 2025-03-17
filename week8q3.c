#include<stdio.h>
#include<string.h>
char ans[4500];
char* RLE(char str[]){
    int j=0;
    for(int i=0;i<strlen(str);){
        int count=1;
        while((i+1)<strlen(str)&&(str[i+1]==str[i])){
            i++;
            count++;
        }
        ans[j++]=(count+'0');
        ans[j++]=str[i++];
    }
    ans[j]='\0';
    return ans;
}
char* CAS(int n){
    if(n==1) return "1";
    else{
        char temp[4500];
        strcpy(temp, CAS(n - 1));
        return RLE(temp);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%s",CAS(n));
}