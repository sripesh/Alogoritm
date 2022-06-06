//Given a sorted array of positive integers, design an algorithm and implement it 
//using a program to find three indices i, j, k such that arr[i] + arr[j] = arr[k].

#include<iostream>
using namespace std;

/*********************************
 ****      BINARY_SEARCH      ****
 *********************************/

int bs(int ar[],int l,int r,int key)
{
    int mid=l+(r-l)/2;                                  //calculate the mid
    
    if(l>r)                                             //if lower limit is equal to upper limit
    return -1;                                          //return key element is not present(0)

    if(ar[mid]==key)                                    //if key element is present in mid index
    return mid;                                         //return key element is present(1)

    else if(ar[mid]>key)                                //else if key element is present before mid index
    return bs(ar,l,mid-1,key);                          //recursion for elements before mid index

    else                                                //else if key element is present after mid index
    return bs(ar,mid+1,r,key);                          //recursion for elements after mid index
}


/********************************
 ****          MAIN          ****
 ********************************/

int main()
{
    int ca;
    cin>>ca;                                                    //input for number of test cases
    while(ca--)                                                 //loop for the number of test cases
    {
        int num;                                    
        cin>>num;                                               //input the size of array

        if(num<3)                                               //if size of array is less than 3
        continue;                                               //continue to next test case

        int arr[num];
        for(int i=0;i<num;i++)
        {
            cin>>arr[i];                                        //input the element in the array
        }
        
        for(int i=0;i<num-2;i++)                                //loop for i indexed element
        for(int k=2;k<num;k++)                                  //loop for k indexed element
        {
            int j=bs(arr,i+1,k-1,arr[k]-arr[i]);                //BINARY SEARCH for j indexed element from i+1 index to j-1 index
            if(j!=-1)                                           //if j is present
            cout<<arr[i]<<"+"<<arr[j]<<"="<<arr[k]<<endl;       //element at i , j , k index
        }

    }
}