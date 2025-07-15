#include <iostream>      //导入 <iostream> 头文件
using namespace std;     //使用 std 命名空间
//const int MAX=1e9;
int main(){
//------程序入口-------
	
	int i;
	for(i=22006;i<=22996;i=i+10)
	{
		if(i%56==0)
		{
			printf("%d ",i);
		}
	}
	
//------程序出口------- 
return 0;
}
