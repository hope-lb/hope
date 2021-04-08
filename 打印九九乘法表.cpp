#include<stdio.h>
int main()
{
	int s=0,x,y,n;
	scanf("%d",&n);
	for(x=1;x<=n;x++)
	{
		for(y=1;y<=x;y++)
		{
			s=x*y;
			printf("%d*%d=%-4d"); 
		}
		printf("\n");
	}
	return 0;
}
