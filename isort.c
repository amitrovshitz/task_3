#include <stdio.h>
#define LENGTH 50
void shift_element(int* arr, int i)
{
    for(int j=i-1;j>0;j--)
    {
       *(arr+j)=*(arr+j-1); 
    }    
}
void insertion_sort(int* arr , int len)
{    int key=0;
     int j=0;
    for(int i=1;i<len;i++)
    {
         key=*(arr+i);
         j=i-1;

        while((j>=0)&&(*(arr+j)>key))
        {
          shift_element(arr+j,2);
          j--;
        }
        j++;
        *(arr+j)=key;
    }
}
int main()
{   
    int arr[LENGTH]={0};
    for(int i=0;i<LENGTH;i++)
    {
        scanf("%d",(arr+i));
    }
    insertion_sort(arr,LENGTH);
    for(int j=0;j<LENGTH;j++)
    {
        if(j!=(LENGTH-1))
        {
            printf("%d,",*(arr+j));
        }
        else
        {
            printf("%d\n",*(arr+j));
        }
    }
    return 0;
}
