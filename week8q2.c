#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
bool isMatch(const char *s,const char *p){
    int n=strlen(s),m=strlen(p);
    bool **dp=(bool **)malloc((n+1)*sizeof(bool *));
    for(int i=0;i<=n;i++){
        dp[i]=(bool *)malloc((m+1)*sizeof(bool));
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++) {
            dp[i][j]=false;
        }
    }
    dp[0][0]=true;
    for(int i=0;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(p[j-1]=='*'){
                dp[i][j]=dp[i][j-2]||(i>0&&(s[i-1]==p[j-2]||p[j-2]=='.')&&dp[i-1][j]);
            }
            else{
                dp[i][j]=i>0&&dp[i-1][j-1]&&(s[i-1]==p[j-1]||p[j-1]=='.');
            }
        }
    }
    bool result=dp[n][m];
    for(int i=0;i<=n;i++){
        free(dp[i]);
    }
    free(dp);
    return result;
}
int main(){
    char s[100], p[100];
    scanf("%99s",s);
    scanf("%99s",p);
    printf("%d\n",isMatch(s,p)?1:0);
}
