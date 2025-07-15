#include <bits/stdc++.h>
using namespace std;
int ans,n;
int main(){
	cin>>n;
	for(int i=1;i<=900;i++){
		for(int j=1;j<=900;j++){
			for(int x=1;x<=900;x++){
//				cout<<"a:"<<i<<" "<<j*2<<" "<<x*5<<endl;
				if(i*8+j*2+x*1==n*10&&i+j+x>30){
//					cout<<i<<" "<<j*2<<" "<<x*5<<endl;
					ans++;
				}
			}
		}
	}cout<<ans<<endl;
	return 0;
}
