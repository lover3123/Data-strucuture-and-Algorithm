#include<stdio.h>

int main()
{
    int size;
    printf("enter the size of the array: ");
    scanf("%d",&size);
    printf("enter array elements: ");
    int arr[size];

    //input array elements 
    for(int i-0;i<size;i++)
    scanf("%d",&arr[i]);
    printf("enter array is: ");
    for(int i=0;i<size;i++)
    printf("%d ",arr[i]);

    //start points at the first element and end points at the last element

    int start=0, end=size-1;
    while(start<end)
    {
        //swapping elements
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;

        //Incrementing start and decrementing end
        start++;
        end--;

    }


    //printing the reversed array 
    printf("\n Reversed array is :");
    for(int i=0;i<size;i++)
    printf("%d ", arr[i]);
    return 0;
}