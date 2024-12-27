#include<stdio.h>
#include<conio.h>
void knapsack(int n,float p[],float w[],float c);
void main()
  {
    float m,p[40]={0},w[50]={0},r[40]={0},temp;
    int n,i,j;
    clrscr();
    printf("enter no.of objects\n");
    scanf("%d",&n);
    printf("enter capacity\n");
    scanf("%f",&m);
    printf("enter weights\n");
    for(i=0;i<n;i++)
      {
	scanf("%f",&w[i]);
      }
    printf("enter profits\n");
    for(i=0;i<n;i++)
      {
	scanf("%f",&p[i]);
      }
    for(i=0;i<n;i++)
      {
	r[i]=p[i]/w[i];
      }
    for(i=0;i<n;i++)
      {
	for(j=i+1;j<n;j++)
	  {
	    if(r[i]<r[j])
	      {
		temp=r[j];
		r[j]=r[i];
		r[i]=temp;

		temp=w[j];
		w[j]=w[i];
		w[i]=temp;

		temp=p[j];
		p[j]=p[i];
		p[i]=temp;
	      }
	  }
      }
  knapsack(n,p,w,m);
  getch();
}

void knapsack(int n,float p[],float w[],float c)
  {
    float x[30],tp=0.0;
    int i,j,m;
    m=c;
    for(i=0;i<n;i++)
      x[i]=0.0;
    for(i=0;i<n;i++)
      {
	if(w[i]>m)
	  break;
	else
	  {
	    x[i]=1.0;
	    tp=tp+p[i];
	    m=m-w[i];
	  }
      }
      if(i<n)
	{
	  x[i]=m/w[i];
	  tp=tp+(x[i]*p[i]);
	}

      printf("_____________________________________________________________\n");
      printf("object\t w[i]\t p[i]\t x[i]\t p[i]*x[i]\t capacity\n");
      printf("_____________________________________________________________\n");
      for(i=0;i<n;i++)
	{
	  printf("%d\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\n",i+1,w[i],p[i],x[i],p[i]*x[i],c=c-w[i]*x[i]);
	}
	printf("Total profit = %.2f\n",tp);
    }