//Given an already sorted array of positive integers, design an algorithm and implement it using a
//program to find whether given key element is present in the array or not. Also, find total number
//of comparisons for each input case. (Time Complexity = O(nlogn), where n is the size of input).


#include<stdio.h>

/*********************************
 ****      BINARY_SEARCH      ****
 *********************************/

int bs(int ar[],int l,int r,int *lo,int key)
{
    int mid=l+(r-l)/2;                              //calculate the mid
    *lo=*lo+1;                                      //increment the count of camparisons

    if(l==r)                                        //if lower limit is equal to upper limit
    return 0;                                       //return key element is not present(0)

    if(ar[mid]==key)                                //if key element is present in mid index
    return 1;                                       //return key element is present(1)

    else if(ar[mid]>key)                            //else if key element is present before mid index
    return bs(ar,l,mid-1,lo,key);                   //recursion for elements before mid index

    else                                            //else if key element is present after mid index
    return bs(ar,mid+1,r,lo,key);                   //recursion for elements after mid index
}

/********************************
 ****          MAIN          ****
 ********************************/

int main()
{
    int ca;
    scanf("%d",&ca);                                 //input for number of test cases
    while(ca--)                                     //loop for the number of test cases
    {
        int num;                                    
        scanf("%d",&num);                            //input the size of array
        int arr[num];
        for(int i=0;i<num;i++)
        {
            scanf("%d",&arr[i]);                     //input the element in the array
        }
        int key;
        scanf("%d",&key);                            //input the key element to search
        int loop=0;
        if(bs(arr,0,num-1,&loop,key))               //if key element is present in the array
        {
            printf("Present %d\n",loop);            //print that the key is PRESENT
        }
        else                                        //else if key element is not present in the array
        {
            printf("Not Present %d\n",loop);        //print that the key is NOT PRESENT
        }
    }
}