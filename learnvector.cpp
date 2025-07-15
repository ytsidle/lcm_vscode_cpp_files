#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> obj1;//创建vector对象,大小为0;
	
	obj1.push_back(1);
	obj1.push_back(11);
	obj1.push_back(111);
	cout<<"obj1:";
	for(int i=0;i<obj1.size();i++){
		printf("%d ",obj1[i]);
	}//初始化2,创建包含五个元素的vector对象
	vector<int> obj2(5);
	obj2[2]=114514;
	cout<<"\nobj2: ";
	for(int i=0;i<obj2.size();i++){
		cout<<obj2[i]<<" ";
	}//初始化三,创建一个包含n个元素,值为m的vector对象,
	int n,m;
//	cin>>n>>m;
	vector<int> obj3(100);
	iota(obj3.begin(),obj3.end(),11);
//	obj3.itoa(obj3.begin(),obj3.begin()+100,1);
	obj3[3]=114;
	obj3.insert(obj3.begin()+1,666);
//	obj3.erase(obj3.begin()+4);
	cout<<"f&b:"<<obj3.front()<<" "<<obj3.back()<<endl;
	for(int i=0;i<obj3.size();i++){
		cout<<*(obj3.end()-i)<<" "<<*(obj3.begin()+i)<<endl;
	}
	
	return 0;
}
