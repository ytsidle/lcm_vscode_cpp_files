#include <bits/stdc++.h>

using namespace std;
int d[100999],n,ans;
bool ish(){
    for(int i=1;i<=n;i++){
        if(d[i]!=0) return true;
    }return false;
}
bool check(int l,int r){
    for(int i=l;i<=r;i++){
        if(d[i]-1<0) return false;
    }return true;
}
bool checks(int len){
    for(int i=1,j=len+1;j<=n;i++,j++){
        if(check(i,j)) return true;
    }return false;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&d[i]);
    }
    //二分铺的距离,→边界
    while(ish()){
        int l=1,r=n;
        int mid=(l+r)>>1,len=0;
        while(l<r){
            if(checks(mid)) len=max(len,r-l),l=mid+1;
            else r=mid-1;
            mid=(l+r)/2;
        }
        int i,j;
//        cout<<"len:  "<<len<<endl;

//        len =mid;
        for(i=1,j=len+1;j<=n;i++,j++){
            if(check(i,j)) break;
        }
//        cout<<i<<"  "<<j<<endl;
        for(int x=i;x<=j;x++) d[x]--;
//        cout<<"list: ";
//        for(int k=1;k<=n;k++) cout<<d[k]<<" ";
//        cout<<endl;

        ans++;
//        cout<<ans<<endl;
    }
    printf("%d",ans-1);
    return 0;
}
