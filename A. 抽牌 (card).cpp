#include <bits/stdc++.h>
using namespace std;
int cnt[110],a[5];
void read(int num){
	string t;
	cin>>t;
	int ans=0;
	ans+=(t[0]-'0')*10;
	//m,p,s
	if(t[1]=='m') ans+=1;
	if(t[1]=='p') ans+=2;
	if(t[1]=='s') ans+=3;
	a[num]=ans;
	cnt[ans]++;
}
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	for(int i=1;i<=3;i++){
		read(i);
	}
	sort(a+1,a+4);
	int len=0,ans=0;
	for(int i=1;i<=3;i++){
		if(cnt[a[i]]==3) {
			cout<<0;
			exit(0);
		}
		if(cnt[a[i]]==2){
//			ans=min(ans,1);
			ans=1;
		}
		if(i>=2){
			if(a[i]-10==a[i-1]){
				len++;
			}
			if(a[i]-20==a[i-1]||a[i]-20==a[i-2]) ans=1;
		}
	}
	if(len==2){
		cout<<0;
		exit(0);
	}
	if(a[1]+20==a[3]||a[1]+20==a[2]||a[2]+20==a[3]){
		cout<<1;
		exit(0);
	}if(len==1||ans){
		cout<<1;
		exit(0);
	}
	cout<<2;
	return 0;
}
