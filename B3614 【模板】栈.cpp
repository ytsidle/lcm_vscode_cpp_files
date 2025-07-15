#include <bits/stdc++.h>
using namespace std;
int t,n;
unsigned long long x;
string ts;
string scs(){
	char t;
	string as="";
	t=getchar();
	while(t<'a'|t>'z'){
		t=getchar();
	}
	while(t>='a'&&t<='z'){
		as+=t;

		t=getchar();
	}
	return as;
}
int main(){
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		vector <unsigned long long> v;
		for(int i=1;i<=n;i++){
			ts=scs();
			if(ts=="push"){
				scanf("%llu",&x);
				v.push_back(x);
			}else if(ts=="pop"){
				if(v.size()!=0){
					v.pop_back();
				}else{
					printf("Empty\n");
				}
			}else if(ts=="query"){
				if(v.size()!=0){
					printf("%llu\n",v[0]);
				}else{
					printf("Anguei!\n");
				}
			}else if(ts=="size"){
				printf("%d\n",v.size());
			}
		}
	}
	return 0;
}
