/*
 * C Program to find the largest number in an array using pointers
 */
 
#include <stdio.h>
#include <math.h>
void largest_elem(int arr[],int size,int *largest)
{
    //Declaring Largest element as the first element
    *largest=arr[0];
    for(int i=1;i<size;i++)
    {
        //Updating largest element if current element is greater than largest element
        if(arr[i] > *largest)
        *largest=arr[i];
    }
}
int main()
{
    int size;
    printf("Enter Size of Array: ");
    scanf("%d",&size);
 
    //Declaring array
    int arr[size],largest;
 
    //Input array elements
    printf("Enter Array Elements: ");
    for(int i=0;i<size;i++)
    scanf("%d",&arr[i]);
    largest_elem(arr,size,&largest);
    printf("Largest Element is: %d",largest);
 
    return 0;
}