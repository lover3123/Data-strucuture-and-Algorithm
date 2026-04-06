/*
     * C Program to Check Array bounds while Inputing Elements into the Array
     */
 
    #include <stdio.h>
    int main(void)
    {
 
        int array[5], b, c;
        for (b = 0; b < 10 && (scanf("%d", &c)); b++)
                array[b] = c;
 
        for (b = 0; b < 15; b++)
        	printf("%d ", array[b]);
 
        return 0;
    }