#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000000 + 7,M=2e7;
int c[M];
int f(int n, int k)
{
	if(n==1) return 1;
    //拆出所有质因数
    memset(c,0,sizeof(c));
    int tk=0,ln=1;
    for(int i=2;i<=n;i++){
    	if(n%i==0) tk++;
    	while(n%i==0){
    		ln=i;
    		n/=i;
    		c[tk]++;
		}
	}if(n!=1){
		c[++tk]=1;
		ln=n;
	}
	cout<<"ln:"<<ln<<endl;
	long long re=ln*k%MOD;
	for(int i=tk-1;i>=1;i--){
		re=re*c[i+1]*c[i]*k%MOD;
	}return re;
}

int main()
{
    int m, k;
    cin >> m >> k;
    int ans = 0;
    for (int i = 1; i <= m; i++){
//    	cout<<f(i,k)<<endl;
    	ans = ans ^ f(i, k);
	}
        
    cout << ans;
    return 0;
}

