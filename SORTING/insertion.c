
// program odf sorting using insertion sort*/
// Author udhayamoorthi
// the insertion sort proceeds by inserting each ele at the proper place in a sorted list.

#include<stdio.h>
#define MAX 100//all lines that start with # are processed by preprocessor
int main()
{
	int arr[MAX],i,k,j,n;
	
	printf("Enter the num of ele:");//programmer has to enter the value
	scanf("%d",&n);

	/*insertion sort*/
	for(i=0;i<n;i++)//this is for the input suppose 10,30,20,4,5
	{
		printf("enter ele %d:",i+1);
		scanf("%d",&arr[i]);
	}
	for(i=1;i<n;i++)
	{
		k=arr[i];/* k is to be inserted at proper place*/
		for(j=i-1;j>=0 && k<arr[j];j--)

			arr[j+1]=arr[j];
		arr[j+1]=k;//the element to be inserted (arr[i] is stored in k
	}
	printf("sorted list is:\n");//this is for output 4 5 10 20 30
	for(i=0;i<n;i++)
		printf("%d",arr[i]);


}/*end of line*/
