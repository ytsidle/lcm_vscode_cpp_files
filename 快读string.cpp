#include <bits/stdc++.h>
using namespace std;
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
int sci(){
	int s = 0, w = 1,a=0;
	char ch = getchar();
	while (ch < '0' || ch>'9')
	{
		if (ch == '-')
			w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	a = s * w;
	return a;
}
int main(){
	string a=scs();
	int b=0;scanf("%d",&b);
	
	cout<<b<<endl<<a;
	return 0;
}
