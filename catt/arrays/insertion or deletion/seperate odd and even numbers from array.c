 /*
     * C Program to accept N integer number and store them in an array AR.
     * The odd elements in the AR are copied into OAR and other elements
     * are copied into EAR. Display the contents of OAR and EAR.
    */
 
    #include <stdio.h>
    void main()
    {
 
        long int ARR[10], OAR[10], EAR[10];
        int i, j = 0, k = 0, n;
 
        printf("Enter the size of array AR n");
        scanf("%d", &n);
 
        printf("Enter the elements of the array n");
        for (i = 0; i < n; i++)
        {
            scanf("%ld", &ARR[i]);
            fflush(stdin);
        }
 
        /*  Copy odd and even elements into their respective arrays */
 
        for (i = 0; i < n; i++)
        {
            if (ARR[i] % 2 == 0)
            {
                EAR[j] = ARR[i];
                j++;
            }
            else
            {
                OAR[k] = ARR[i];
                k++;
            }
        }
 
        printf("The elements of OAR are n");
        for (i = 0; i < k; i++)
        {
            printf("%ldn", OAR[i]);
        }
 
        printf("The elements of EAR are n");
        for (i = 0; i < j; i++)
        {
            printf("%ldn", EAR[i]);
        }
 
    }