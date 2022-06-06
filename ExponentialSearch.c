//Given an already sorted array of positive integers, design an algorithm and implement it using a
//program to find whether a given key element is present in the sorted array or not. For an array
//arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2^k] and so on. Once the interval 
//(arr[2^k]<key<arr[ 2k+1]) is found, perform a linear search operation from the index 2k to find 
//the element key. (Complexity < O(n), where n is the number of elements need to be scanned for 
//searching) Also, for each test case output the number of comparisons required to search the key.

#include<stdio.h>


/********************************
 ****          MAIN          ****
 ********************************/

int main()
{
    int ca;                                     
    scanf("%d",&ca);                                    //input for number of test cases
    while(ca--)                                         //loop for the number of test cases
    {
        int num,loop=1,key,i=2,f=0;                     
        scanf("%d",&num);                               //input the size of array
        int arr[num];
        for(int i=0;i<num;i++)
            scanf("%d",&arr[i]);                        //input the element in the array
        scanf("%d",&key);                               //input the key element to search
        if(arr[0]==key)                                 //if key element is present in index 0
            f=1;                                        //set flag as 1

        else if(arr[2]>key&&(++loop)&&arr[1]==key)      //else if key is less than element at index 2 and equal to element at index 1; increment loop
            f=1;                                        //set flag as 1

        else                                            //else if key element is present from index 2 onwards;
        {
            for(;i<num;i=(i*2<num)?i*2:num-1)           //loop for exponential search
            {
                loop++;                                 //count the number of comparisons
                if(key==arr[i])                         //if the key element is present
                {
                    f=1;                                //set flag as 1
                    break;                              //breaks out of the loop
                }
                else if(arr[(i*2<num)?i*2:num-1]>key)   //else if key element is less than the next exponential index
                {
                    num=(i*2<num)?i*2:num-1;            //set the num as next exponential index
                    i++;                                
                    while(i<num)                        //linear search
                    {
                        loop++;                         //count the number of comparisons
                        if(arr[i]==key)                 //if key element is present
                        {
                            f=1;                        //set flag as 1
                            break;                      //break out of linear search
                        }
                        i++;                            //increment i for linear search
                    }
                }
                if(f||i>=num-1)                         //if key element is present or i >= num-1
                break;                                  //break out of exponential search
                
            }
        }
        if(f)                                           //if flag is 1
        printf("Present %d\n",loop);                    //key element is PRESENT
        else                                            //if flag is 0
        printf("Not Present %d\n",loop);                //key element is NOT PRESENT
    }
}