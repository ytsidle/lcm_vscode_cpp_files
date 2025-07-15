#include <bits/stdc++.h>
using namespace std;
char a;
int main(){
	scanf("%c",&a);
	if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9')){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
	return 0;
}
