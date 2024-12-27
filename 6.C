#include<stdio.h>
#include<conio.h>
void part(int a[],int low,int high);
int quick(int a[],int low,int high);
void main()
  {
    int a[90],n,i,low,high;
    clrscr();
    printf("enter size\n");
    scanf("%d",&n);
    printf("enter elements\n");
    for(i=0;i<n;i++)
      {
	scanf("%d",&a[i]);
      }
      low=0;
      high=n-1;
      part(a,low,high);
      printf("sorted array\n");
      for(i=0;i<n;i++)
	{
	  printf("%d\n",a[i]);
	}
      getch();
  }

  void part(int a[],int low,int high)
    {
      int j;
      if (low<high)
	{
	  j=quick(a,low,high);
	  part(a,low,j-1);
	  part(a,j+1,high);
	}
    }

  int quick(int a[],int low,int high)
    {
      int p=a[low],i=low+1,j=high,t;
      while(i<=j)
	{
	  while(p>a[i])
	    i++;
	  while(p<a[j])
	    j--;

	  if(i<j)
	    {
	      t=a[i];
	      a[i]=a[j];
	      a[j]=t;
	    }
	}
	if(i>j)
	  {
	    t=a[low];
	    a[low]=a[j];
	    a[j]=t;
	  }
	return j;
    }



