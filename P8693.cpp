#include <bits/stdc++.h>
using namespace std;
int n,k,a[310][310];
int fx[4] = {0, 1, 0, -1};
int fy[4] = {1, 0, -1, 0};
char f[310][310];//0='+',1='*'
char t;
const int MAX=9e4+100;
struct point{
	int x,y,time;
}q[MAX];
void bfs(){
	point h;
	h.x=3,h.y=3;
	
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%s",&f[i][1]);
	}
	bfs()
	return 0;
}
