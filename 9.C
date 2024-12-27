#include<stdio.h>
#include<conio.h>
#define max 10

void accept(int g[][max],int n)
  {
    int i,j;
    for(i=0;i<n;i++)
      {
	for(j=0;j<n;j++)
	  {
	    printf("Edge(v%d,v%d) exists? (yes=1,no=0) : ",i,j);
	    scanf("%d",&g[i][j]);
	  }
      }
  }

  void display(int g[][max],int n)
    {
      int i,j;
      for(i=0;i<n;i++)
	{
	  for(j=0;j<n;j++)
	    {
	      printf("%4d",g[i][j]);
	    }
	  printf("\n");
	}
    }

  void in(int g[][max],int n)
     {
      int i,j,sum;
      for(i=0;i<n;i++)
	{
	  sum=0;
	  for(j=0;j<n;j++)
	    {
	      sum+=g[i][j];
	    }
	  printf("indegree (v%d) : %d\n",i,sum);
	}
    }

   void out(int g[][max],int n)
     {
      int i,j,sum;
      for(i=0;i<n;i++)
	{
	  sum=0;
	  for(j=0;j<n;j++)
	    {
	      sum+=g[i][j];
	    }
	  printf("outdegree (v%d) : %d\n",i,sum);
	}
    }

    void main()
      {
	int g[max][max],n;
	clrscr();
	printf("enter no. of vertices\n");
	scanf("%d",&n);
	accept(g,n);
	printf("adjacency matrix\n");
	display(g,n);
	printf("Indegree : \n");
	in(g,n);
	printf("Outdegree : \n");
	out(g,n);
	getch();
      }

