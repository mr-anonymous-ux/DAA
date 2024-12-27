 #include<stdio.h>
#include<conio.h>
int a,b,u,v,n,i,j,m=1,min,cost[40][40],mincost=0;
int p[30];
int find(int);
int un(int i,int j);
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
	      {
		cost[i][j]=999;
	      }
	  }
      }
    while(m<n)
      {
	min=999;
	for(i=1;i<=n;i++)
	  {
	    for(j=1;j<=n;j++)
	      {
		if(cost[i][j]<min)
		  {
		    min=cost[i][j];
		    a=u=i;
		    b=v=j;
		  }
	      }
	  }
      u=find(u);
      v=find(v);
      if(un(u,v))
	{
	  printf("edge %d : (%d,%d), cost=%d\n",m++,a,b,min);
	  mincost+=min;
	}
      cost[a][b]=cost[b][a]=999;
    }
    printf("\n Min cost = %d\n",mincost);
    getch();
}

int find(int i)
 {
   while(p[i])
     {
       i=p[i];
     }
   return i;
 }

 int un(int i,int j)
   {
     if(i!=j)
       {
	 p[j]=i;
	 return 1;
       }
     return 0;
   }
