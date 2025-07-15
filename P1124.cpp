#include <bits/stdc++.h>
using namespace std;
int n,p,k;
const int N=10010;
char so[N],s[N],ans[N];
int main(){
	scanf("%d%s%d",&n,s+1,&p);
	strcpy(so+1,s+1);
	sort(so+1,so+1+n);
//	cout<<so[1];
	k=n+1;
	for(int i=1;i<=n;++i) if(so[i]==s[p]) { p=i;break; }
	while(k>1){
		ans[--k]=s[p];
		so[p]='#';
		for(int i=n;i>=1;--i) if(so[i]==s[p]) {p=i;break;}
		
	}
//	printf("%s",ans+1);
	for(int i=1;i<=n;i++) printf("%c",ans[i]);
	return 0;
}
