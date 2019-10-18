#include<stdio.h>
#define MAX(a,b) a>b?a:b

/*
** Program to implement fractional knapsack problem
** Made by - Abhishek Chand
*/

typedef struct item{
	int no;
	float v;
	float w;
	float x;
}item;

void knapsack(item I[],int n,int W)
{   
    int i,tp=0,tv;
	for(i=0;i<n;i++){
		I[i].x=0;
	}
	for(i=0;i<n;i++){
		if (I[i].w>W)
		   break;
		else
		{
		  I[i].x=1;
		  tp=tp+ I[i].v;
		  W=W-I[i].w;	
		}
    }
    if(i<n)
    {
    	I[i].x=W/I[i].w;
	  	tp+=(I[i].x*I[i].v);	  
	}
	i=0;
	printf("\nSelected Items:");
	printf("\nItem no\tValue\tWeight\tRatio");
	while(I[i].x!=0)
	{
		printf("\n%d\t%.2f\t%.2f\t%.2f\t",I[i].no,I[i].v,I[i].w,I[i].x);
		i++;
	}
	printf("\n\nMax Value: %d",tp);
}

int main()
{
	int i,j,n,W;
	printf("\nEnter the no. of item : ");
	scanf("%d",&n);
	item I[n],temp;
	printf("\nEnter the value and weight of items : ");
	    for(i=0;i<n;i++)
	    {
	       I[i].no=i+1;
	   	   scanf("%f %f",&I[i].v,&I[i].w);
	   	   I[i].x=I[i].v/I[i].w;
	    }
	printf("\nEnter the capacity of the bag : ");
	    scanf("%d",&W);
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(I[i].x<I[j].x)
			{
			 temp=I[j];
			 I[j]=I[i];
			 I[i]=temp;
			}
		}
	}
	knapsack(I,n,W);
	return 0;
}
