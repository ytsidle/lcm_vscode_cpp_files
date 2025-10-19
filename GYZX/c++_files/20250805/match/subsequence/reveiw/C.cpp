#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int M=3e5+10;
bool vis[M];
int n,a[M],ed[M];
int main(){
	freopen("subsequence.in","r",stdin);
	freopen("subsequence.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    priority_queue<int,deque<int>,greater<int> > q;
    priority_queue<pii,deque<pii>,greater<pii> > q1,q2;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
        ed[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        q.emplace(ed[a[i]]);
    }
    q.emplace(INT_MAX);
    for(int i=1;i<=q.top();i++){
        q1.push({-a[i],i});
        q2.push({a[i],i});
    }
    vector<int> ans;
    while(!q2.empty()){//为什么是q2.empty()?
        auto he=(ans.size()%2==0)?q1.top():q2.top();
        int x=he.first,p=he.second;
        if(ans.size()%2==0){
            x*=-1;
            q1.pop();
        }else{
            q2.pop();
        }
        ans.push_back(x);
        vis[x]=1;
        while((q.top()!=INT_MAX)&&vis[a[q.top()]]){//非空且已被占用
            int j=q.top()+1;
            q.pop();
            for(int k=j;k<=min(n,q.top());k++){
                q1.push({-a[k],k});
                q2.push({a[k],k});
            }
        }
        //单调队列
        while(!q1.empty()&&(vis[-q1.top().first]||q1.top().second<=p)) q1.pop();
        while(!q2.empty()&&(vis[q2.top().first]||q2.top().second<=p)) q2.pop();
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return  0;
}