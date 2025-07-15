#include <cstdio>
#include <climits>
#define LL long long
#define max(a,b) (a>b)?a:b
using namespace std;
const int N=1e6+10;
const long long mod=1e17;
struct lint{
	int p1,p2;
}ans,pre;

lint plus(lint a,LL b){
    lint ans;
    ans.p2 = a.p2 + b;
    ans.p1 = a.p1;
    if(ans.p2 > 1e15){
    	ans.p1 += ans.p2 / mod;
    	ans.p2 = ans.p2 % mod;
    }
    return ans;
}
lint mx(lint a,lint b){
	if(a.p1>b.p1) return a;
	if(b.p1>a.p1) return b;
	if(a.p2>b.p2) return a;
	return b;
}
LL n,f[N],P,dp[N];
int main(){
	scanf("%lld%lld",&n,&P);
	LL sum=LONG_LONG_MIN;
	for(int i=1;i<=n;i++){
		LL x;
		scanf("%lld",&x);
		dp[i]=max(x,dp[i-1]+x);
		sum=max(sum,dp[i]);
		f[i]=sum;
//		f[i]%=P;
	}
	//ans[i]=ans,ma=pre
	ans.p1=0;
	pre.p1=0;
	ans.p2=f[1];
	pre.p2=f[1]*2;
//	cout<<ans[1]<<" ";
	for(int i=2;i<=n;i++){
		ans=mx(pre,ans);
		pre=mx(pre,plus(pre,f[i]));
	}
	printf("%lld\n",((ans.p1 % P) * (mod % P) + (ans.p2 % P)) % P);
	return 0;
}
