# 20260705 S模拟赛


## B

 一般的我们可以不难发现修改后的道路产生的结果其实为 **$\sum{min\{dist_{u\to v},dist_{u\to x}+dist_{y\to v},dist_{u\to y}+dist_{x\to v}\}*c_{u,v}}$**

易得如果有贡献则
$dist_{u\to x}+dist_{y\to v}<dist_{u\to v}$(此处 $x$,$y$可交换)
$dist_{u\to v}-dist_{u\to x}-dist_{y\to v}$

>于是我们可以想到枚举 $u,x,v$
>>$\therefore dist_{y\to v}<dist_{u\to v}-dist_{u\to x}$
>>>我们可以发现$dist_{u\to v}-dist_{u\to x}$ 已知,其中若先枚举${u,v}$,再使得$dist_{u\to x}$单调性,那么限制也就具有单调性
>>>>所以解决了,双指针,注意让限制单调递增 ,可以双指针实现$O(n^3)$而不是二分$O(n^3 \log_2{n}) $