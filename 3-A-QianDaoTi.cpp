#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;

int n,a[N],k,b,mod,maxbit[N];

int min_p[N][21];
int max_p[N][21];
int or_val[N][21];
int judge(int x,int y){
    if(a[x]<a[y]) return x;
    return y;
}
int judge2(int x,int y){
    if(a[x]>a[y]) return x;
    return y;
}
int checkmin(int l,int r){
    int len=r-l+1; int k=maxbit[len];
    return judge(min_p[l][k],min_p[r-(1<<k)+1][k]);
}
int checkmax(int l,int r){
    int len=r-l+1; int k=maxbit[len];
    return judge2(max_p[l][k],max_p[r-(1<<k)+1][k]);
}
int checkor(int l,int r){
    int len=r-l+1; int k=maxbit[len];
    return or_val[l][k]|or_val[r-(1<<k)+1][k];
}
__int128_t evalue(int l,int r){
    __int128_t minval=a[checkmin(l,r)],maxval=a[checkmax(l,r)],orval=checkor(l,r);
    return minval*maxval*orval*(r-l+1);
}
__int128_t Divide(int l,int r){
    if(l>r) return 0;
    int mid=checkmin(l,r);
    __int128_t ans=evalue(l,r);
    __int128_t Lans=Divide(l,mid-1);
    __int128_t Rans=Divide(mid+1,r);
    return max(ans,max(Lans,Rans));
}
int main(){
    scanf("%d%d%d%d%d",&n,&a[0],&k,&b,&mod);
    maxbit[0]=-1;
    for(int i=1;i<=n;++i) maxbit[i]=maxbit[i>>1]+1;
    for(int i=1;i<=n;++i) a[i]=(1ll*a[i-1]*k+b)%mod;
    for(int i=1;i<=n;++i){
        min_p[i][0]=i;
        max_p[i][0]=i;
        or_val[i][0]=a[i];
    }
    for(int k=1;k<=20;++k){
        for(int i=1;i+(1<<k)-1<=n;++i){
            min_p[i][k]=judge(min_p[i][k-1],min_p[i+(1<<(k-1))][k-1]);
            max_p[i][k]=judge2(max_p[i][k-1],max_p[i+(1<<(k-1))][k-1]);
            or_val[i][k]=or_val[i][k-1]|or_val[i+(1<<(k-1))][k-1];
        }
    }
    int ret=Divide(1,n)%998244353;
    printf("%d\n",ret);
    return 0;
}
 