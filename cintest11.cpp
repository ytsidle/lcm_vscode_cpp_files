// 不能读入空格、回车等
#include <iostream>
using namespace std;

int main(){
    char ch;
    while (cin >> ch){
        cout << ch<<endl;
    }
    
    return 0;
}

