#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool isMatch(char *s, char *p){
    for(int j=0,i=0;i<strlen(p),j<strlen(s);){
        if(s[j]!=p[i]){
            if(p[i+1]=='*'){
                    i+=2;
                    j++;
            }
            else if(p[i]=='.'){
                    i++;
                    j++;
            }
            else return false;
        }
        else{
            if(p[i+1]=='*'){
                i+=2;
                while(s[j+1]==s[j]){
                    j++;
                }
                j++;
            }
            else{
                i++;
                j++;
            }
        }
    }
    return true;
}
int main(){
    char s[20], p[20];
    scanf("%s %s",s,p);
    char *p1, *p2;
    p1=s;p2=p;
    printf("%d",isMatch(p1,p2));
}