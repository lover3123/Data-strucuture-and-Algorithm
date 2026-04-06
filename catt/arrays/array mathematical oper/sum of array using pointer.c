/*
 * C Program to Find Sum of Array Elements using Pointers
 */
 
#include <stdio.h>
 
int main()
{
    int size;
    printf("Enter size of the array: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter array elements\n");
    for(int i=0;i<size;i++)
    scanf("%d",&arr[i]);
    int sum=0;
 
    // pointer ptr points at the first element
    int *ptr=&arr[0];
    for(int i=0;i<size;i++)
    {
        sum+=*ptr;
 
        //Incrementing pointer to next element
        ptr++;
    }
    printf("Sum of the array is: %d",sum);
 
    return 0;
}