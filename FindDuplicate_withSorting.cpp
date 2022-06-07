//Given an array of nonnegative integers, design an algorithm and a program to count 
//the number of pairs of integers such that their difference is equal to a given key, K.

#include<iostream>
#define fori(m,n) for(int i=m;i<n;i++)              //macro
#define forj(m,n) for(int j=m;j<n;j++)              //macro
using namespace std;


/*********************************
 ****      SORTING_ARRAY      ****
 *********************************/
void merge(int arr[],int b,int mid,int h)
{
    int l=mid-b+1,r=h-mid;                              //number of elemens in left part and right part
    
    int left[l];                                        
    int right[r];

    fori(0,l)
    {
        left[i]=arr[b+i];                               //collect the left part of the array
    }
    fori(0,r)
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
        fori(0,num)
        {
            cin>>arr[i];                                //input the element in the array
        }
        
        sort(arr,0,num-1);                              //sorting in ascending order

        int f=0,temp=arr[0];
        forj(1,num)
        {
            if(temp==arr[j])
            {
                f++;
                break;
            }
            else
            {
                temp=arr[j];
            }
        }

        if(f)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;

    }
    return 0;
}