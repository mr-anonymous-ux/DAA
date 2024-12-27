#include<stdio.h>
#include<conio.h>
int x[50],n,a=0;
void queen(int n);
void display(int n);
int place(int k);
void main()
  {

    int n;
    clrscr();
    printf("enter no. of queens\n");
    scanf("%d",&n);
    queen(n);
    getch();
  }


  int place(int k)
    {
      int i;
      for(i=1;i<k;i++)
	{
	  if(x[i]==x[k]||abs(x[i]-x[k])==abs(i-k))
	     return 0;
	}
      return 1;
    }

  void queen(int n)
    {
      int k=1;
      x[k]=0;
      while(k!=0)
	{
	  x[k]=x[k]+1;
	  while((x[k]<=n) && !place(k))
	      x[k]=x[k]+1;
	  if(x[k]<=n)
	    {
	      if(k==n)
		{
		  display(n);
		}
	      else
		{
		 k++;
		 x[k]=0;
		}
	    }
	  else
	    k--;
	}
    }

    void display(int n)
      {
	int i,j;
	a++;
	printf("solution answer : %d\n",a);
	for(i=1;i<=n;i++)
	  {
	    for(j=1;j<=n;j++)
	      {
		if(x[i]==j)
		  printf("Q\t");
		else
		  printf("X\t");
	      }
	    printf("\n");
	}
    }