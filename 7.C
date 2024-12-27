#include<stdio.h>
#include<conio.h>
void part(int a[],int low,int high);
void merge(int a[],int low,int mid,int high);
void main()
  {
    int n,i,a[80],low,high;
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
      int mid;
      if(low<high)
	{
	  mid=(low+high)/2;
	  part(a,low,mid);
	  part(a,mid+1,high);
	  merge(a,low,mid,high);
	}
    }

  void merge(int a[],int low,int mid,int high)
    {
      int c[50];
      int i=low;
      int j=mid+1;
      int k=low;

      while(i<=mid && j<=high)
	{
	   if(a[i]<a[j])
	     {
	       c[k++]=a[i++];
	     }
	   else
	     {
	       c[k++]=a[j++];
	     }
	}
	while(i<=mid)
	  {
	    c[k++]=a[i++];
	  }
	while(j<=high)
	  {
	    c[k++]=a[j++];
	  }
	for(i=low;i<=high;i++)
	  {
	    a[i]=c[i];
	  }
      }