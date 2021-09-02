
// program odf sorting using bubble sort*/
// Author udhayamoorthi
// the bubble sort proceeds by inserting each ele at the proper place in a sorted list.

#include<stdio.h>
#define MAX 100
int main()
{
	int arr[MAX],i,k,j,n;
	
	printf("Enter the num of ele:");
	scanf("%d",&n);

	/*insertion sort*/
	for(i=0;i<n;i++)
	{
		printf("enter ele %d:",i+1);
		scanf("%d",&arr[i]);
	}
	for(i=1;i<n;i++)
	{
		k=arr[i];/* k is to be inserted at proper place*/
		for(j=i-1;j>=0 && k<arr[j];j--)

			arr[j+1]=arr[j];
		arr[j+1]=k;
	}
	printf("sorted list is:\n");
	for(i=0;i<n;i++)
		printf("%d",arr[i]);


}/*end of line*/
