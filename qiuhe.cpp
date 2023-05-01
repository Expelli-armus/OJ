#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,q,a[1000005],l,r,S[1000005],ans[10005];
int main()
{
    cin>>n>>q;
    S[0]=0;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
        S[i]=S[i-1]+a[i];
    }
    for (int i = 1; i <= q; i++)
    {
        cin>>l>>r;
        ans[i]=S[r]-S[l-1];
    }
    for (int i = 1; i <= q; i++)
    {
        cout<<ans[i]<<endl;
    }
    
    return 0;
}