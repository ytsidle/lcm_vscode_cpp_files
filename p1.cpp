#include <bits/stdc++.h>
using namespace std;
/*
建造灯塔O2
题目描述
TDOG 主题小镇由 N
 个村庄组成，并且从 1
 到 N
 进行编号。这些村庄之间有 N−1
 条道路，第 i
 条道路连接 Xi
 和 Yi
 两个不同的村庄，并且两个村庄之间直连道路最多只有一条。显然，任意两个村庄之间是互相可达的。

每个村庄地理位置不同，因此风景优美程度也不同，有些村庄比起其他村庄风景更加优美。我们将第 i
 个村庄的优美程度用 Bi
 表示。由于部分村庄环境治理不当，因此存在 Bi
 为负的可能。

某天，建筑师小T接到一项任务，要选取一些村庄，在这些村庄中建设灯塔。假如某村庄中建有灯塔，或者与该村庄直连的其他村庄建有灯塔，则该村庄会被点亮。

由于经费十分充足，因此小T可以自由安排要选取的村庄数量。但小T希望能找到一种选取的方案，使得所有灯塔建造完毕后，被点亮村庄的优美程度之和最大。

现在，你来帮小T计算出这个最大值是多少吧！

输入格式
第一行一个整数 T
 ，表示共有 T
 组数据。每组数据格式如下：

第一行一个整数 N
 ，表示村庄数量。

第二行 N
 个整数， 第 i
 个整数即为对应编号村庄的优美程度 Bi
接下来的 N−1
 行，每行两个整数 Xi
 和 Yi
，表示该道路连接着编号为 Xi
 和 Yi
 的村庄

输出格式
共 T
 行，每行对应一组数据的答案

样例数据
输入样例 #1
3
9
-10 4 -10 8 20 30 -2 -3 7
1 4
2 4
4 3
9 4
9 8
7 5
6 7
7 9
4
-2 20 20 20
1 2
1 3
1 4
5
-5 -10 8 -7 -2
5 4
4 3
3 2
2 1
输出样例 #1
67
58
0
数据范围
对于 50%
 的数据，1≤N≤15
对于所有数据点，1≤T≤100,2≤N≤105,−105≤Bi≤105,1≤Xi,Yi≤N
，数据保证 Xi≠Yi
 且任意两个村庄之间互相可达。
*/
int t, n, node[130][3],b[130],maxs=INT_MIN,dp[130],res[130];
//bool cmp(int a[],int c[]){
//    int num1 = max(b[a[0]], b[a[1]]);
//    int num2 = max(b[c[0]], c[b[1]]);
//    return num1 < num2;
//}
int main(){
    //输入
    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> n;
        for (int i = 1; i <= n;i++) cin >> b[i];
        for (int i = 1; i < n; i++)
        {
            cin >> node[i][1] >> node[i][2];
        }
//        sort(node, node + n * 2 - 1, cmp);
        for(int i=1;i<=n;i++){//i是有i棵树的情况下
            int smaxs=INT_MIN;
            for(int j=1;j<=n;j++){//试用点亮j
                int num=b[j];
                for(int k=1;k<n;k++){//遍历找出与j相连的点

                    if(node[k][1]==j){
                        num+=b[node[k][2]];
                    }else if(node[k][2]==j) num+=b[node[k][1]];
                }
                num=max(max(num+dp[i-1],dp[i-1]),num);
//                dp[i]=num;
                if(num>maxs) maxs=num;
                if(num>smaxs) smaxs=num;
            }
        }
        res[i]=maxs;
//        for(int i=1;i<=n;i++) cout<<dp[i]<<endl;
        maxs=INT_MIN;
        memset(node,0,sizeof(node));
        memset(b,0,sizeof(b));
        memset(dp,0,sizeof(dp));
    }

    for(int i=1;i<=t;i++) cout<<res[i]<<endl;
    return 0;
}