#include<stdio.h>
#include<conio.h>
int n,visited[10],a[10][10],i,j,cost=0;
void tsp(int c);
void main()
  {
    clrscr();
    printf("enter no.of cities\n");
    scanf("%d",&n);
    printf("enter cost matrix\n");
    for(i=0;i<n;i++)
      {
	for(j=0;j<n;j++)
	  {
	    scanf("%d",&a[i][j]);
	  }
      }
    for(i=0;i<n;i++)
      visited[i]=0;
    printf("The path is : \n");
    tsp(0);
    printf("cost of the path is : %d\n",cost);
    getch();
  }

  void tsp(int c)
    {
      int min=999,av=999,k;
      visited[c]=1;
      printf("%d-->",c+1);
      for(k=0;k<n;k++)
	{
	  if((a[c][k]!=0) && (visited[k]==0))
	    {
	      if(a[c][k]<min)
		{
		  min=a[c][k];
		  av=k;
		}
	    }
	}
      if(min!=999)
	{
	  cost=cost+min;
	}
      if(av==999)
	{
	  av=0;
	  printf("%d\n",av+1);
	  cost=cost+a[c][av];
	  return;
	}
      tsp(av);
  }