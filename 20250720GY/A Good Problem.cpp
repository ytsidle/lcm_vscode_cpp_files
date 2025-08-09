#include <bits/stdc++.h>
using namespace std;
/*
对于二进制结果下的第i为,与的结果是对于
所有a的第i为是否都为1,异或的为a的第i为1的数量
是否是奇数
要相等则说明a第i项都为1且n是奇数
或者a的第i项中1的个数是偶数
判断有解:
n==1 l
n%2==1 and 存在l<=2^k-1<=r O(64),2^k-1的最小值
n%2==0:
存在最小的(a,b)使得a&b==0
Finally:
n%2==1 :l
n%2==0:
pow(2,log(l)+1)<=r
n-2:l,2,pow(2,log(l)+1)

*/
long long T,n,l,r,k;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
//	cout<<"dd: "<<log2(2)<<" "<<log2(3)<<" "<<log2(4)<<"\n";
	cin>>T;
	while(T--) {
		cin>>n>>l>>r>>k;
		if(n==2){
			//特判
			cout<<-1<<"\n";
			continue;
		}
		if(n%2==1) {
			cout<<l<<"\n";
			continue;
		} else {
			/*pow(2,log(l)+1)<=r
			n-2:l,2,pow(2,log(l)+1)*/
			long long to=pow(2,(long long)log2(l)+1);
//			cout<<(long long)log2(l)+1<<"  s  "<<l<<"  d  "<<r<<"  d  "<<to<<"\n";
			if(to>r) cout<<"-1\n";
			else {
				if(k<=n-2) cout<<l<<"\n";
				else cout<<to<<"\n";
			}
		}
	}
	return 0;
}
