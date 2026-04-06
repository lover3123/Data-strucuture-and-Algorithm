int  sum(int n,int arr[],int i)
{
   if(i==n)
   return 0;
   else
   return arr[i]  + sum(n,arr,i+1);
}