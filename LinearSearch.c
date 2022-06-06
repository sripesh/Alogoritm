//Given an array of nonnegative integers, design a linear algorithm and implement it using a
//program to find whether given key element is present in the array or not. Also, find total number
//of comparisons for each input case. (Time Complexity = O(n), where n is the size of input)


#include<stdio.h>


/********************************
 ****          MAIN          ****
 ********************************/

int main()
{
    int ca;                                     
    scanf("%d",&ca);                                 //input for number of test cases
    while(ca--)                                     //loop for the number of test cases
    {
        int num,loop=0,key,i=0;                     
        scanf("%d",&num);                            //input the size of array
        int arr[num];
        for(int i=0;i<num;i++)
        scanf("%d",&arr[i]);                         //input the element in the array
        scanf("%d",&key);                            //input the key element to search
        for(;i<num;i++)                             //loop for linear search
        {
            loop++;                                 //count the number of comparisons
            if(key==arr[i])                         //if the key element is present
            {
                printf("Present %d\n",loop);        //print that the key is PRESENT
                break;                              //breaks out of the loop
            }
        }
        if(i==num)                                  //if the 'i' is equal to size of array
        printf("Not Present %d\n",loop);            //key element is NOT PRESENT
    }
}