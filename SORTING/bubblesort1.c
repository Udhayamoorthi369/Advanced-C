
// program odf sorting using bubble sort*/
// Author udhayamoorthi
// the bubble sort scanning the list and excange the adjacent if they are out of order with respect to each other.

#include<stdio.h>
#define MAX 100// all lines that start with # are prepocessed by preprocessor
int main()
{
	int arr[MAX],i,k,j,n,temp,xchanges;
	
	printf("Enter the num of ele:");// program has to enter the value
	scanf("%d",&n);

	/*bumble sort*/
	for(i=0;i<n-1;i++)//value n-1 
	{
		xchanges =0;
		for(j=0;j<n-1-i;j++)//value n-1-i
		{
			if(arr[j]>arr[j+1])//a[j] will be compared with arr[j+1]
			{
				temp=arr[j];/* if arr[j]>arr[j+1] then they will be swapped*/
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				xchanges++;
	}
		}
		if(xchanges==0)/*if lis is sorted*/
			break;
	}
		printf("sorted list is:\n");//this printf for print the output
	for(i=0;i<n;i++)
		printf("%d",arr[i]);


}/*end of line*/
