#include<stdio.h>
#include<conio.h>
void sel(int a[],int n);
void main()
  {
     int n,i,a[90];
     clrscr();
     printf("enter size\n");
     scanf("%d",&n);
     printf("enter elements\n");
     for(i=0;i<n;i++)
       {
	 scanf("%d",&a[i]);
       }
     sel(a,n);
     printf("sorted array\n");
     for(i=0;i<n;i++)
       {
	 printf("%d\n",a[i]);
       }
     getch();
  }

  void sel(int a[],int n)
    {
      int i,j,t,pos;
      for(i=0;i<n-1;i++)
	{
	  pos=i;
	  for(j=i+1;j<n;j++)
	    {
	      if(a[j]<a[pos])
		{
		  pos=j;
		}
	    }
	  if(i!=pos)
	    {
	      t=a[pos];
	      a[pos]=a[i];
	      a[i]=t;
	    }
	}
    }