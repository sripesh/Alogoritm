//Given an array of nonnegative integers, design an algorithm and a program to count 
//the number of pairs of integers such that their difference is equal to a given key, K.

#include<iostream>
using namespace std;


/*********************************
 ****      SORTING_ARRAY      ****
 *********************************/
void merge(int arr[],int b,int mid,int h)
{
    int l=mid-b+1,r=h-mid;                              //number of elemens in left part and right part
    
    int left[l];                                        
    int right[r];

    for(int i=0;i<l;i++)
    {
        left[i]=arr[b+i];                               //collect the left part of the array
    }
    for(int i=0;i<r;i++)
    {
        right[i]=arr[mid+i+1];                          //collect the right part of the array
    }

    int i=0,j=0;
    while(i<l && j<r)                                   //loop while either of left or right part of array is completely arranged to the main array
    {
        if(left[i]<right[j])                            //condition for sorting in ascending order
        {
            arr[b++]=left[i++];
        }
        else
        {
            arr[b++]=right[j++];
        }
    }
    while(i<l)                                          //if left part of array is left to arrange
    {
        arr[b++]=left[i++];
    }
    while(j<r)                                          //if right part of array is left to arrange
    {
        arr[b++]=right[j++];
    }
}
void sort(int arr[],int l,int r)
{
    if(l>=r)                                            //base condition that lower bound should not exceed upper bound
        return;
    int mid=l+(r-l)/2;                                  //calculate mid
    sort(arr,l,mid);                                    //recursion of left part of the divided array
    sort(arr,mid+1,r);                                  //recursion of right part of the divided array
    merge(arr,l,mid,r);                                 //merge the divided array while sorting

}


/*********************************
 ****      BINARY_SEARCH      ****
 *********************************/

int bs(int ar[],int l,int r,int arr,int key)
{
    int mid=l+(r-l)/2;                                  //calculate the mid
    
    if(l>r)                                             //if lower limit is equal to upper limit
    return -1;                                          //return key element is not present(0)

    if(ar[mid]-arr==key)                                //if [ higher indexed element - lower indexed element = key ]
    return 1;                                           //return the subtraction is present(1)

    else if((ar[mid]-arr)>key)                          //else if key element is present before mid index
    return bs(ar,l,mid-1,arr,key);                      //recursion for elements before mid index

    else                                                //else if key element is present after mid index
    return bs(ar,mid+1,r,arr,key);                      //recursion for elements after mid index
}


/********************************
 ****          MAIN          ****
 ********************************/

int main()
{
    int ca;
    cin>>ca;                                            //input for number of test cases
    while(ca--)                                         //loop for the number of test cases
    {
        int num;                                    
        cin>>num;                                       //input the size of array

        int arr[num];
        for(int i=0;i<num;i++)
        {
            cin>>arr[i];                                //input the element in the array
        }
        
        sort(arr,0,num-1);                              //sorting in ascending order

        int key;
        cin>>key;                                       //input the key element

        int j=0;
        for(int i=0;i<num-1;i++)                        //loop for i indexed element
        {
            int temp=bs(arr,i+1,num-1,arr[i],key);      //BINARY SEARCH of higer indexed element that satisfies [ higher indexed element - lower indexed element = key ]
            j+=temp>0?temp:0;                           //count number the pairs available in the array
        }                                               
        cout<<j<<endl;                                 
    }
    return 0;
}