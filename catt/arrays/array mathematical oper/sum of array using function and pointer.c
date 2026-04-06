/*
 * C Program to Find Sum of Array Elements using Function and Pointer
 */
 
#include <stdio.h>
int sum(int *ptr,int n)
{
   int s=0;
   for(int i=0;i<n;i++)
   {
       s += *ptr;
 
       //Incrementing pointer to next element
       ptr++;
   }
   return s;
}
 
int main()
{
    int size;
    printf("Enter size of the array: ");
    scanf("%d",&size);
    int arr[size];
 
    //Input array elements
    printf("Enter array elements\n");
    for(int i=0;i<size;i++)
    scanf("%d",&arr[i]);
 
    // Calling function by passing address of first element
    printf("Sum of array is: %d",sum(arr,size));
 
    return 0;
}