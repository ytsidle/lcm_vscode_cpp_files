# KMP算法理解

首先我们可以求出 $border[i]$ 表示 $s[1...i]$ 的 $border$ 长度

我们可以这样实现字符串比较
```cpp
    for(int i=1,j=0;i<=n;i++){
        while(j&&(j==m||s[i]!=s2[j+1])){
            j=nxt[j];
        }
        if(s[i]==s2[j+1]) j++;
        f[i]=j;
    }
```

**Boder计算代码：**
```cpp
    scanf("%s%s",s+1,s2+1);
    n=strlen(s+1);
    m=strlen(s2+1);
    //求出nxt
    for(int i=2;i<=m;i++){
        int j=nxt[i-1];//s[1...i-1]的Border
        while(j!=0){
            if(s2[j+1]==s2[i]) break;
            j=nxt[j];
        }
        if(s2[i]==s2[j+1]) j++;
        nxt[i]=j;
    }
```