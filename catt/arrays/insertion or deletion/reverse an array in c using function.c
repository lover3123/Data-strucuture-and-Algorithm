/* 
 *  C program to reverse an array using function
 */
 
#include <stdio.h>
int* reverse(int start,int end,int arr[])
{
    // Start variable points at the start of the array
    // End Variables points at the last index of the array
    while(start<end)
    {
        //Swapping elements at start and end
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
 
        //Incrementing start and decrementing end
        start++;
        end--;
    }
    //Returning reversed array
    return arr;
}
int main()
{
    int size;
    printf("Enter size of the array: ");
    scanf("%d",&size);
    printf("Enter Array Elements: ");
    int arr[size];
 
    //Input array elements
    for(int i=0;i<size;i++)
    scanf("%d",&arr[i]);
    printf("Entered Array is: ");
    for(int i=0;i<size;i++)
    printf("%d ",arr[i]);
 
    //Start points at the first element and end points at the last element
    int start=0,end=size-1;
 
    //Printing reversed array
    int *rev=reverse(start,end,arr);
    printf("\nReversed array is: ");
    for(int i=0;i<size;i++)
    printf("%d ",rev[i]);
 
    return 0;
}