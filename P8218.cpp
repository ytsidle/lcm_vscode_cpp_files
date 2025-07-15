#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int n,a[MAX],b[MAX],m,ia,ib;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        b[i]=b[i-1]+a[i];
    }
//    for (int i = 1; i <= n ; ++i) {
//        printf("%d ",b[i]);
//    }printf("\n");
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&ia,&ib);
        printf("%d\n",b[ib]-b[ia-1]);
    }
    return 0;
}