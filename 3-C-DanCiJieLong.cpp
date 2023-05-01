#include<bits/stdc++.h>
#include<string>
#include<cstdio>
using namespace std;

//变量
int n=0;
string word[110000];
int dp[26];
struct wordxy{
    char x;
    char y;
}wordxy[110000];

void input(){
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        cin>>word[i];
        wordxy[i].x=word[i][0];
        int j=0;
        wordxy[i].y=word[i][0];
        while(word[i][j+1]!=' '&&word[i][j+1]!='\0'){
            j++;
        }
        wordxy[i].y=word[i][j];
    }
}
void DpCourse(){
    for(int i=0;i<n;i++){
        int nx=wordxy[i].x-97;
        int ny=wordxy[i].y-97;
        if(dp[ny]<dp[nx]+1){
            dp[ny]=dp[nx]+1;
        }
    }
}
void output(){
    int ans=n;
    for(int i=0;i<26;i++){
        if(ans > n-dp[i]){
            ans=n-dp[i];
        }
    }
    printf("%d",ans);
}
int main(){
    input();
    DpCourse();
    output();
    return 0;
}