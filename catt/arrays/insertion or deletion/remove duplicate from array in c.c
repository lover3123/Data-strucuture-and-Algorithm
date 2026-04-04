/*
 * C Program to remove duplicates from array using nested for loop
 */
 
#include <stdio.h>
int main()
{
    int n, count = 0;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    int arr[n], temp[n];
    if(n==0)
    {
        printf("No element inside the array.");
        exit(0);
    }
    printf("Enter elements in the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
 
    printf("\nArray Before Removing Duplicates: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
 
    // To store unique elements in temp after removing the duplicate elements
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < count; j++)
        {
          if (arr[i] == temp[j])
            break;
        }
        if (j == count)
        {
          temp[count] = arr[i];
          count++;
        }
    }
 
    printf("\nArray After  Removing Duplicates: ");
    for (int i = 0; i < count; i++)
        printf("%d ", temp[i]);
 
    return 0;
}


/* 
 * C Program to remove duplicates from array using sort function with extra space
 */
 
#include<stdio.h>
#include<stdlib.h>
 
//function cmpfunc to compare two numbers
int cmpfunc(const void *a, const void *b)
{
    return(*(int*)a - *(int*)b);
}
 
//main function
int main()
{
    int n;
    printf("Enter number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
 
    printf("Enter elements in the array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
 
    //if array is empty
    if(n==0)
    {
        printf("No element inside the array.");
        exit(0);
    }
 
    printf("\nArray Before Removing Duplicates: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
 
    //inbuilt function qsort to sort the array
    qsort(arr,n,sizeof(int),cmpfunc);
 
    //temporary array to store only unique elements
    int temp[n];
    int i = 0, j = 0;
    temp[j++] = arr[i++];
 
    //loop to remove duplicate elements and store
    //unique elements in the array temp
    for( ; i<n; i++)
    {
        if(arr[i] != arr[i-1])
        {
            temp[j++] = arr[i];
        }
    }
 
    //print the array after removing all the duplicate elements
    printf("\nArray After Removing Duplicates: ");
    for(i=0;i<j;i++)
        printf("%d ",temp[i]);
 
    return 0;
}




/* 
 * C Program to remove duplicates from array using sort function without extra space
 */
 
#include<stdio.h>
#include<stdlib.h>
 
//function cmpfunc to compare two numbers
int cmpfunc(const void *a, const void *b)
{
    return(*(int*)a - *(int*)b);
}
 
//main function
int main()
{
    int n;
    printf("Enter number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
 
    printf("Enter elements in the array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
 
    //if array is empty
    if(n==0)
    {
        printf("No element inside the array.");
        exit(0);
    }
 
    printf("\nArray Before Removing Duplicates: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
 
    //inbuilt function qsort to sort the array
    qsort(arr,n,sizeof(int),cmpfunc);
 
    int j = 0;
    for(int i=1; i<n; i++)
    {
        if(arr[i] != arr[i-1])
        {
            arr[++j]=arr[i];
        }
    }
 
    printf("\nArray After Removing Duplicates: ");
    for(int i=0;i<j+1;i++)
        printf("%d ",arr[i]);
 
    return 0;
}




