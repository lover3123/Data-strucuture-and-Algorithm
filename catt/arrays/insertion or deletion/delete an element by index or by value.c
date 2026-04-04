/*
 * C program to delete an element from an array by index or value
 */
 
#include <stdio.h>
#include <stdlib.h>
 
int n;
 
void delete_element_by_index(int arr[], int index)
{
    int i;
    for (i = index; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n -= 1;
}
 
void delete_element_by_value(int arr[], int value)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            for (; i < n - 1; i++)
                arr[i] = arr[i + 1];
                n -= 1;
                break;
        }
    }
}
 
void print_array(int arr[])
{
    int i;
    printf("\n[ ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("]\n");
}
 
void init_array(int arr[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d: ", i);
        scanf("%d", &arr[i]);
    }
}
 
int main(void)
{
    int index, value, arr[10], choice;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: \n");
    init_array(arr);
    printf("You can delete an element by index or value.\n1. Delete by index\n2. Delete by value\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Enter the index of the element to be deleted: ");
        scanf("%d", &index);
        delete_element_by_index(arr, index);
    }
    else
    {
        printf("Enter the value of the element to be deleted: ");
        scanf("%d", &value);
        delete_element_by_value(arr, value);
    }
    print_array(arr);
}