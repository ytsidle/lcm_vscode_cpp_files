#include <bits/stdc++.h>
using namespace std;
const int M=2e5+10;
struct soider{
	int id , l , r;
	bool operator<(const soider& b) const{
		return l<b.l;
	}
}s[2*M];
int n,m,f[2*M][30],ans[2*M];
void pre(){
    //预处理
    for(int i=1,p=i;i<=2*n;i++){
		while(p<=2*n&&s[p].l<=s[i].r){
			p++;
		}
		f[i][0]=p-1;//表示从i从出发经过2^0次条到达最远区间编号
    }
	for(int j=1;j<=__lg(2*n)+1;j++){
		for(int i=1;i<=2*n;i++){
			f[i][j]=f[f[i][j-1]][j-1];//状态转移
		}
	}
}
//search函数
void search(int k){
	int rk=k,rr=s[k].l+m,anss=1;//一开始的区间初始化
	for(int i=__lg(2*n)+1;i>=0;i--){
		if(f[k][i]&&s[f[k][i]].r<rr){
			anss+=(1<<i);
			k=f[k][i];
		}
	}
	if(f[k][0]&&s[k].r<rr) anss++;
	ans[s[rk].id]=anss;

}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>s[i].l>>s[i].r;
		if(s[i].r<s[i].l)s[i].r+=m;
		s[i].id=i;
	}
	sort(s+1,s+1+n);
	for(int i=1;i<=n;i++){
		
		s[i+n]=s[i];
		s[i+n].l+=m;
		s[i+n].r+=m;
	}
    //输入完 了
    //预处理准备
    pre();
    for(int i=1;i<=n;i++){
		search(i);
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;	
}