#include <bits/stdc++.h>
using namespace std;
int d[5000][5000],n,m,ans[5000],cnt[5000];
vector<int> a[5000];
typedef pair<int,int> pa;
vector<vector<int> > s,hcon;
bool f[5000];
void bfs(int num){
	memset(f,0,sizeof(f));
	queue<int> q;
	f[num]=1;
	q.push(num);
	while(!q.empty()){
		int head=q.front();
		
		q.pop();
		for(auto i:a[head]){
			cout<<head<<"s"<<i<<endl;
			if(!f[i]){
				q.push(i);
				f[i]=1;
				d[num][i]=d[num][head]+1;
				s.push_back({d[num][i],head,i});
				s.push_back({d[num][i],i,head});
			}
		}
	}
}
int main(){
//	freopen("tour.in","r",stdin);
//	freopen("tour.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	sort(s.begin(),s.end());
	hcon.push_back(s[0]);
	ans[0]=s[0][0];
	cnt[0]=1;
	cout<<s.size();
	for(int i=s.size()-1;i>0;i--){
		printf("%d %d %d\n",s[i][0],s[i][1],s[2][1]);
//		if(hcon.find({s[i][0],s[i][2],s[i][1]})==-1){
//			
//			
//		}
		for(int k=0;k<hcon.size();k++){
			if(s[k][2]==s[i][2]){
				hcon.push_back(s[i]);
				cnt[hcon.size()-1]=cnt[k]+1;
				ans[hcon.size()-1]=ans[k]+s[i][0];
				if(	cnt[hcon.size()-1]==3) {
					printf("%d",ans[hcon.size()-1]);
					return 0;
				}
			}
		}
	}
	return 0;
}
