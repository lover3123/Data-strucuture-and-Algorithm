/*
 * C Program to find the largest number in an array using recursion
 */
 
#include <stdio.h>
#include <math.h>
//Function to find max of two numbers
int max(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}
int largest(int arr[],int size,int i)
{
    if(i == size-1)
    return arr[i];
    return max(arr[i], largest(arr,size,i+1));
}
int main()
{
    int size;
    printf("Enter Size of Array: ");
    scanf("%d",&size);
 
    //Declaring array
    int arr[size];
 
    //Input array elements
    printf("Enter Array Elements: ");
    for(int i=0;i<size;i++)
    scanf("%d",&arr[i]);
    printf("Largest Element is: %d",largest(arr,size,0));
 
    return 0;
}