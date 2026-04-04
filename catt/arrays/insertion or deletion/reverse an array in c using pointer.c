/* 
 *  C program to reverse an array using pointers
 */
 
#include <stdio.h>
int *rev_array(int arr[],int n)
{
    //start points to start, end points to last & temp is for swapping two elements
    int *start,*end,temp;
    start=arr;
    end=arr;
 
    //pointing end to last index
    for(int i=0;i<n-1;i++)
    end++;
    for(int i=0;i<n/2;i++)
    {
        //Swapping elements at start and end places
        temp=*start;
        *start=*end;
        *end=temp;
 
        //Incrementing start and decrementing end elements
        start++;
        end--;
    }
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
    int *rev=rev_array(arr,size);
 
    //Printing reversed array
    printf("\nReversed array is: ");
    for(int i=0;i<size;i++)
    printf("%d ",rev[i]);
 
    return 0;
}