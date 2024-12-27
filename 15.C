#include<stdio.h>
#include<conio.h>
int a,b,u,v,n,i,j,ne=1,visited[40]={0};
int min,mincost=0,cost[40][40];

void main()
  {
    clrscr();
    printf("enter the no.of nodes\n");
    scanf("%d",&n);
    printf("enter adjacency matrix\n");
    for(i=1;i<=n;i++)
      {
	for(j=1;j<=n;j++)
	  {
	    scanf("%d",&cost[i][j]);
	    if(cost[i][j]==0)
	      cost[i][j]=999;
	  }
      }
    visited[1]=1;
    while(ne<n)
      {
	min=999;
	for(i=1;i<=n;i++)
	  {
	    for(j=1;j<=n;j++)
	      {
		if(cost[i][j]<min)
		  if(visited[i]!=0)
		    {
		      min=cost[i][j];
		      a=u=i;
		      b=v=j;
		    }
	      }
	  }
	if(visited[u]==0 || visited[v]==0)
	  {
	    printf("\n edge : %d : (%d,%d) cost : %d\n",ne++,a,b,min);
	    mincost+=min;
	    visited[b]=1;
	  }
	cost[a][b]=cost[b][a]=999;
    }

    printf("\n min cost : %d",mincost);
    getch();
}