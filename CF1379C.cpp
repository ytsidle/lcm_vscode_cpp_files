#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,s[100010];
pair<int,int> g[100010];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            cin>>g[i].first>>g[i].second;
        }
      sort(g+1,g+1+m);
      s[0]=0;
      for(int i=1;i<=m;i++){
        s[i]=s[i-1]+g[i].first;
      }
      int ans=0;
      for(int i=1;i<=m;i++){
        int nx=g[i].first,ny=g[i].second;
        int fp=lower_bound(g+1,g+1+m,(pair<int,int>){ny,0})-g;
        int tt=s[m]-s[max(fp-1,m-n)];
        int ta=tt;
        if(fp>i&&n-(m-max(fp-1,m-n))>0) ta+=nx;
        // ta+=(n-1-(max(m-1,fp-1+n-1)-fp+1))*ny;
        ta+=max(0ll,n-(m-max(fp-1,m-n))-(fp>i))*ny;
        ans=max(ans,ta);
      }
      cout<<ans<<"\n";
    }
    return 0;
}