#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100010
int proces(char t[], int x)
{
	char *p;
	int i, j = 0, s = 0;
	p = &t[0];
	for(i=0; i<x; i++)
	{
	   if(p[i] == '.')
	   {
	      for(; i<x-1; i++)
	      {
	         p[i] = p[i+1];
	         s++;
	      }
	      if(s)
	        p[i] = '0';
	      break;
	   }
	}
	while(p[0] == '0'&&j < x)
	{
		for(i=0; i<x-1; i++)
		  p[i] = p[i+1];
		p[i] = '0';
		s++, j++;
	}
	if(j == x)
	{
	   printf("结果为：0   \n(你真无聊!)");
	   exit(0);
   }
	return s;
}
int main(void)
{
   char t[N+1]={0}, a[N+1]={0}, b[N+1]={0};
	long int c[2*N+1]={0}, d[2*N+1]={0};
	int i, j, k, x1, x2, s1, s2, m;
	printf("请输入一个数：\n");
   scanf("%s",t);
   x1 = strlen(t);
   s1 = proces(t, x1);
   if(s1)  s1++;
	for(j=0,i=strlen(t)-1; i>=0; i--)
	  a[j++] = t[i] - '0';
	printf("请输入另一个数：\n");
	scanf("%s",t);
	x2 = strlen(t);
	s2 = proces(t, x2);
	if(s2)  s2++;
	s1 += s2;
//	printf("%d\n", s1);
	for(j=0,i=strlen(t)-1; i>=0; i--)
	  b[j++] = t[i] - '0';//开始与之前两个一致
	for(i=0; i<x1; i++)
	  for(j=0; j<x2; j++)
	  	 c[i+j] += a[i]*b[j];
	for(i=m=0; i<2*N; i++)
	{
		c[i] += m;
		d[i] = c[i] % 10;
		m = c[i] / 10;
	}
	printf("乘法计算结果为：\n");
   for(i=2*N; i>=0; i--)
   {
	  if(d[i] != 0)
	  {
	     for(; i>=s1; i--)
		    printf("%d",d[i]);
		  if(s1)  printf(".");
	     for(; i>=0; i--)
	       printf("%d",d[i]);	
		  break;
	  }
	  else if(i == s1)
	  {
	  	  printf("%d.", d[i]);
	  	  for(i--; i>=0; i--)
	  	    printf("%d", d[i]);
	  }
   }   
	return 0;
}
