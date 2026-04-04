/*
 * C program to delete an element from an array by value
 */
 
#include <stdio.h>
void main()
{
    int arr[10];
    int i, n, pos, element, found = 0;
 
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: \n");
    for (i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
 
    printf("Enter the value of the element to be deleted:\n");
    scanf("%d", &element);
 
    for (i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            found = 1;
            pos = i;
            break;
        }
    }
 
    if (found == 1)
    {
        for (i = pos; i <  n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
 
        printf("The array after deleting the element is: \n");
        for (i = 0; i < n - 1; i++)
        {
            printf("%d\n", arr[i]);
        }
 
    }
    else
    printf("Element %d is not found in the array\n", element);
}