#include<stdio.h>
#include<conio.h>
#define max_vertices 100

void main()
  {
    int adj[max_vertices][max_vertices]={0};
    int nv=0,ne=0,i,j,u,v;
    clrscr();
    printf("enter no. of vertices\n");
    scanf("%d",&nv);
    printf("enter no. of edges\n");
    scanf("%d",&ne);
    printf("enter the edges (u,v) \n");
    for(i=0;i<ne;i++)
      {
	scanf("%d%d",&u,&v);
	adj[u][v]=1;
	adj[v][u]=1;
      }
    printf("The adjacency matrix\n");
    for(i=0;i<nv;i++)
      {
	for(j=0;j<nv;j++)
	  {
	    printf("%d",adj[i][j]);
	  }
	printf("\n");
      }
    getch();
  }