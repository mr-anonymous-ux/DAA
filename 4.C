#include<stdio.h>
#include<conio.h>
int a[20][20],reach[20],n;

void dfs(int v)
  {
    int i;
    reach[v]=1;
    for(i=1;i<=n;i++)
      if(a[v][i] && !reach[i])
	{
	  printf("\n%d-->%d",v,i);
	  dfs(i);
	}
  }

 int q[20],visited[30],i,j,f=0,r=-1;
 void bfs(int v)
   {
     for(i=1;i<=n;i++)
       if(a[v][i] && !visited[i])
	 q[++r]=i;
	 if(f<=r)
	   {
	     visited[q[f]]=1;
	     bfs(q[f++]);
	   }
   }

 void main()
   {
     int i,j,count=0,v;
     clrscr();
     printf("enter no.of vertices\n");
     scanf("%d",&n);
     for(i=1;i<=n;i++)
       {
	 reach[i]=0;
	 for(j=1;j<=n;j++)
	   a[i][j]=0;
       }
     printf("enter adjacency matrix\n");
     for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
	 scanf("%d",&a[i][j]);
     printf("in dfs algorithm : ");
     dfs(1);
     for(i=1;i<=n;i++)
       {
	 if(reach[i])
	   count++;
       }
     if(count==n)
       printf("graph is connected\n");
       else
	 printf("Graph is not connected\n");
     printf("\n\nBfs algorithm : ");
     for(i=1;i<=n;i++)
       {
	 q[i]=0;
	 visited[i]=0;
       }
     bfs(1);
     printf("\n the nodes which are reachable are\n");
     for(i=1;i<=n;i++)
       {
	 if(visited[i])
	   printf("%d\t",i);
	 else
	   {
	     printf("\n bfs is not possible as not all nodes are reachable");
	     break;
	   }
       }
     getch();
 }