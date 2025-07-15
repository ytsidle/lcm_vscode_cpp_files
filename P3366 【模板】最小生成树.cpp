#include <bits/stdc++.h>
using namespace std;
int n,m,a[5010][5010],b[5010][5010],ta,tb,tc,sen[5010],cnt;
bool is_hui(int t,int num,int count){
	cout<<"Im"<<num<<endl;
	if(count>n) return false;
	if(t==num) return 1;
	else{
		for(int i=1;i<=n;i++){
			if(b[t][i]!=0&&i!=num){
				if(is_hui(i,num,count+1)==1) return 1;
			}
		}
	}return 0;
}int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&ta,&tb,&tc);
		a[ta][tb]=tc;
		a[tb][ta]=tc;
	}
	a[0][0]=INT_MAX-1;
	
	cnt++;
	sen[cnt]=1;
	while(cnt<n){
		int min_pi=0,min_pj=0;
		for(int i=1;i<=cnt;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]!=0){
					if(a[i][j]<a[min_pi][min_pj]){
						//判断是否能选
						b[i][j]=1,b[j][i]=1;
						if(!(is_hui(i,i,1)||is_hui(j,j,1))){
							min_pi=i,min_pj=j;
						}b[i][j]=0,b[j][i]=0;
					}
				}
			}
		}
		b[min_pi][min_pj]=1,b[min_pj][min_pi]=1;
		cnt++;
		sen[cnt]=min_pj;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<b[i][j]<<" ";
			
		}cout<<endl;
		
	}
	return 0;
}
