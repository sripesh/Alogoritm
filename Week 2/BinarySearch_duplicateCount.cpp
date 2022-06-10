//Given a sorted array of positive integers containing few duplicate elements, design an algorithm
//and implement it using a program to find whether the given key element is present in the array
//or not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))

#include<iostream>
using namespace std;

/*********************************
 ****      BINARY_SEARCH      ****
 *********************************/

int bs(int ar[],int l,int r,int key)
{
    int mid=l+(r-l)/2;                                  //calculate the mid
    
    if(l==r)                                            //if lower limit is equal to upper limit
    return 0;                                           //return key element is not present(0)

    if(ar[mid]==key)                                    //if key element is present in mid index
    return mid;                                           //return key element is present(1)

    else if(ar[mid]>key)                                //else if key element is present before mid index
    return bs(ar,l,mid-1,key);                          //recursion for elements before mid index

    else                                                //else if key element is present after mid index
    return bs(ar,mid+1,r,key);                          //recursion for elements after mid index
}

/*********************************
 ****     COUNT_DUPLICATE     ****
 *********************************/

int countDuplicate(int ar[],int i,int n,int key)
{
    int temp=i+1,count=1;                               //count is 1 because i index element is already included
    while(temp<n && ar[temp]==key)                      //finding duplicate element on the right side
    {
        count++;                                        //increment the count
        temp++;
    }
    temp=i-1;
    while(temp>=0 && ar[temp]==key)                     //finding duplicate element on the left side
    {
        count++;                                        //increment the count
        temp--;
    }
    return count;                                       //return the total duplicate count
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
        int key;
        cin>>key;                                       //input the key element to search
        int index=bs(arr,0,num-1,key);                  //finding the index of key element using BINARY_SEARCH
        if(index<0)                                     //if key element is not present
        {
            cout<<"Key not present";                    //key element is NOT PRESENT
            continue;                                   //continue to next test case
        }
        int count=countDuplicate(arr,index,num,key);    //count the duplicate elements
        cout<<key<<"=>"<<count;                         //key element is present and the duplicate count
    }
}