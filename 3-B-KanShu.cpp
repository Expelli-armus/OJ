#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

const int MAXN = 200005;
bool vis[MAXN];
int n,m,x,y,u[MAXN],v[MAXN];


//存边*******************************
struct Edge {
    int to,w,next;
};Edge edges[MAXN];
int head[MAXN], cur = 0;
void addEdge(int u, int v, int w) {
    edges[cur].to = v;
    edges[cur].w = w;
    edges[cur].next = head[u];
    head[u] = cur;
    cur++;
}

//dfs寻找路径*********************************
int Joint[MAXN];int flag=0;
void dfs(int u,int v){
    for (int j = head[u]; j != -1; j = edges[j].next){
        if(edges[j].to==v){
        Joint[j/2]++;flag=1;
        return;
        }
    }
    vis[u]=1;
    for (int i = head[u]; i != -1; i = edges[i].next){
        if(!vis[edges[i].to]){
        vis[edges[i].to]=1;Joint[i/2]++;
        int p=edges[i].to;
        dfs(p,v);
        if(flag==0){
            Joint[i/2]--;
        }
        }
    }return;
}
//*************************************
void input(){
    
    scanf("%d%d",&n,&m);
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&x,&y);
        addEdge(x,y,0);
        addEdge(y,x,0);
    }
    for (int i = 0; i < m; i++){
        scanf("%d%d",u+i,v+i);
        dfs(u[i],v[i]);
        flag=0;
        for(int i=0;i<=n-1;i++){
            vis[i]=0;
        }
    }
}
//***********************************
int main(){
    memset(head, -1, sizeof(head));
    input();
    int ans=n-2;
    while(ans>=0){
        if(Joint[ans]==m){
            printf("%d",ans+1);
            return 0;
        }
        ans--;
    }
    printf("%d",ans);
    return 0;
}