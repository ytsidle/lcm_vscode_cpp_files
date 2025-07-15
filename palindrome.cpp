#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+10;
const int mod=998244353;
long long n,v[30],vc=INT_MAX,f[30][30],g[30][30],t[MAX];
long long sum,ans=INT_MAX;
string s;
long long calc(int x,int y){
	if(x==y)return 0ll;
	return min(v[x],min(v[y],2*vc));
}
int main(){
//	freopen("palindrome.in","r",stdin);
//	freopen("palindrome.out","w",stdout);
	cin>>n;
	for(int i=1;i<=26;i++){
		cin>>v[i];
		vc=min(vc,v[i]);
	}
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)t[i]=s[i]-'a'+1;
	for(int i=1;i<=26;i++){
		for(int j=1;j<=26;j++){
			f[i][j]=calc(i,j);
		}
	}
	for(int i=1;i<=n/2;i++){
		g[min(t[i],t[n-i+1])][max(t[i],t[n-i+1])]++;
	}
	for(int i=1;i<=26;i++){
		for(int j=i;j<=26;j++){
			sum+=1ll*g[i][j]*f[i][j];
		}
	}
//	cout<<sum;
	ans=sum;
	for(int a=1;a<=26;a++){
		for(int b=a;b<=26;b++){
			if(g[a][b]){
				g[a][b]--;			
				for(int c=1;c<=26;c++){
					for(int d=c;d<=26;d++){
						if(g[c][d]){
							long long t=sum-f[a][b]-f[c][d]+f[a][d]+f[b][c];
							ans=min(ans,t);
							t=sum-f[a][b]-f[c][d]+f[a][c]+f[b][d];
							ans=min(ans,t);
						}

					}
				}
				g[a][b]++;
			}
		}
	}
	cout<<ans;
	return 0;
}
