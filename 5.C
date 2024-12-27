#include<stdio.h>
#include<conio.h>
void minmax();
int min,max,a[90];
void main()
  {
    int n,i;
    clrscr();
    printf("enter size\n");
    scanf("%d",&n);
    printf("enter elements\n");
    for(i=0;i<n;i++)
      {
	scanf("%d",&a[i]);
      }
    minmax(0,n-1);
    printf("Min value : %d\n",min);
    printf("Max value : %d\n",max);
    getch();
  }

  void minmax(int i,int j)
    {
      int mid,min1,max1;
      if(i==j)
	{
	  min=max=a[i];
	}
      else
	{
	  if(i==j-1)
	    {
	      if(a[i]>a[j])
		{
		  min=a[j];
		  max=a[i];
		}
	      else
		{
		   min=a[i];
		   max=a[j];
		}
	    }
	  else
	    {
	      mid=(i+j)/2;
	      minmax(i,mid);
	      min1=min;
	      max1=max;
	      minmax(mid+1,j);
	      if(min1<min)
	       {
		min=min1;
	       }
	      if(max1>max)
		{
		  max=max1 ;
		}
	    }
	}
    }



