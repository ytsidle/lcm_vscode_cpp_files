#include <bits/stdc++.h>
using namespace std;
/*
1.生成到n的质数表
2.一个一个试着除,能出就继续除到除不动,判断最后一个数是否是素数,是就cout
*/
int n;
unsigned long long a[110],b[110];
int dfs(int nums,int l){
	
	for(int i=1;i<=l;i++){
		bool type =false;
		if(nums%b[i]==0){
			bool type=true;
		int t=dfs(num/b[i],len);
			if(t!=-1){
				return t;
			} 
		}
	}if(!type) return nums;
}
bool is_prime(int n)
{
	if(n <= 1){
//		cout<<n<<"不是素数"<<endl; 
		return false;
	}
    for (int i = 2; i < n; i++)
    {
        if ((n % i) == 0){
//            cout<<n<<"不是素数"<<endl;
            return false;
        }
    }
//    cout<<n<<"是素数"<<endl;
    return true;
}


int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%llu",&a[i]);
//		cout<<a[i]<<endl;
	}
	for(int k=1;k<=n;k++){
		int num=a[k];
		int len=0
		//生成素数表
		memset(b,0,sizeof(b));
		for(int i=2;i<=(num);i++){
			if(i==2){
				len++;
				b[len]=2;
			}
			bool type =true;
			for(int j=2;j<=sqrt(i)){
				if(i%j==0){
					type=false;
					break;
				}
			}if(type) len++,b[len]=i;
		}
		//试除
		
		if(is_prime(dfs(num,len))){
			cout<<num<<endl;
			exit(0);
		}
		
	}
	
	return 0;
}
