#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10,MAXS=1e8+10;
int t,n,k,len;
int a[MAX][3],f[MAXS];
void useful(int num){
	bool flag=0;
	for(int i=a[num][1];i<=a[num][2];i++){
			if(f[i]>=f[k]){
				flag=1;
				break;
			}
	}if(flag){
		for(int i=a[num][1];i<=a[num][2];i++){
			f[i]--;
		}
	}
}bool check(){
	for(int i=1;i<=len;i++){
		if(f[i]>=f[k]&&i!=k){
			return false;
		}
	}return true;
}
int main(){
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d%d",&n,&k);
		memset(f,0,sizeof(f));
		for(int j=1;j<=n;j++){
			scanf("%d%d",&a[j][1],&a[j][2]);
			for(int x=a[j][1];x<=a[j][2];x++) f[x]++;
			len=max(len,a[j][2]);
		}
		if(f[k]==0) printf("NO\n");
		else{
			for(int j=1;j<=n;j++){
				if(!(a[j][1]<=k&&k<=a[j][2])) useful(j);
			}
			if(check()){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
	return 0;
}
