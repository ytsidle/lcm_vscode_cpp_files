#include <bits/stdc++.h> 
using namespace std;
const long long P=1e5+7;
long long n;
long long a[60][60],sum[60][60],ans;
vector<long long> ha[(P+12)];
long long cnt(long long ux,long long uy,long long dx,long long dy){
	long long re=0;
	for(long long i=ux;i<=dx;i++)re+=sum[i][dy]-sum[i][uy-1];
	return re;
}
void insert(long long x){
	ha[(x+500000)%P].push_back(x);
}
long long find(long long x){
	long long nus=0;
	for(long long tp:ha[(x+500000)%P]){
		if(tp==x) nus++;
	}return nus;
}
void allc(){
	for(long long i=0;i<=P;i++){
		ha[i].clear();
	}
}
void solve(long long pi,long long pj){
	//枚举上半部分的左上角 
	for(long long i=1;i<=pi;i++) {
		for(long long j=1;j<=pj;j++){
			insert(cnt(i,j,pi,pj));
		}
	}
	//枚举下半部分
	for(long long i=pi+1;i<=n;i++) {
		for(long long j=pj+1;j<=n;j++){
			ans+=find(cnt(pi+1,pj+1,i,j));
		}
	}
	//allc
	allc();
	for(long long i=1;i<=pi;i++) {
		for(long long j=pj;j<=n;j++){
			insert(cnt(i,pj,pi,j));
		}
	}
	//枚举下半部分
	for(long long i=pi+1;i<=n;i++) {
		for(long long  j=1;j<=pj-1;j++){
			ans+=find(cnt(pi+1,j,i,pj-1));
		}
	}
	allc();
}
signed main(){
	cin>>n;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			cin>>a[i][j];
			sum[i][j]=sum[i][j-1]+a[i][j];
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			solve(i,j);
		}
	}cout<<ans;
	return 0;
}