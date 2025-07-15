#include <bits/stdc++.h>
using namespace std;
//quick sort
#define auto int
int* quicksort(int lists){
	if(lists.length()==0){
		return;
	}else if(lists.size()==1){
		return lists[0];
	}else{
		int mid=lists[auto(lists.size()/2)];
		auto l[]={};
		auto r[]={};
		auto m[]={};
		auto ln=0,rn=0,mn=0;
		for(auto i=0;i<lists.size();i++){
			if(lists[i]<mid){
				l[++ln]=lists[i];
			}else if(lists[i]==mid){
				m[++mn]=lists[i]
			}else{
				r[++rn]=lists[i];
			}
		}
		memset(lists,0,sizeof(lists));
		l.splice(l.end(),quicksort(m));
		l.splice(l.end(),quicksort(r));
		lists=l;
		return l;
		
	}
}
int main(){
	ls[5]={1,2,5,3,2};
	quicksort(ls);
	for(int i=0;i<ls.size();i++){
		cout<<ls[i]<<" ";
	}
	return 0;
}
