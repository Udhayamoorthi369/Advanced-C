
// program odf sorting using bubble sort*/
// Author udhayamoorthi
// the bubble sort scanning the list and excange the adjacent if they are out of order with respect to each other.

#include<stdio.h>
#define MAX 100
int main()
{
	int arr[MAX],i,k,j,n,temp,xchanges;
	
	printf("Enter the num of ele:");
	scanf("%d",&n);

	/*bumble sort*/
	for(i=0;i<n-1;i++)
	{
		xchanges =0;
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				xchanges++;
	}
		}
		if(xchanges==0)/*if lis is sorted*/
			break;
	}
		printf("sorted list is:\n");
	for(i=0;i<n;i++)
		printf("%d",arr[i]);


}/*end of line*/
