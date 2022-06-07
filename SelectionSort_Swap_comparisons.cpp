//Given an unsorted array of integers, design an algorithm and a program to sort the array using
//insertion sort. Your program should be able to find number of comparisons and shifts(shifts - total
//number of times the array elements are shifted from their place) required for sorting the array.

#include<iostream>
#define fori(m,n) for(int i=m;i<n;i++)              //macro
#define forj(m,n) for(int j=m;j<n;j++)              //macro
using namespace std;


/*********************************
 ****      SORTING_ARRAY      ****
 *********************************/

void selection(int ar[],int n,int *s,int*c)
{
    fori(0,n-1)
    {
        int j=i-1,temp=ar[i],temp_index=i;
        forj(i+1,n)           
        {
            ++*c;                                   //count the comparisons

            if(ar[j]<temp)                          //finding the smallest number after the selected element
            {
                temp_index=j;                       //store the index of the smallest element
                temp=ar[j];                         //store the smallest element after the selected element
            }

        }
        ar[temp_index]=ar[i];                       //swaping the smallest element with the selected element
        ar[i]=temp;                                 //swaping the selected element with the smallest element

        ++*s;                                       //count the swaps
    }
}


/********************************
 ****          MAIN          ****
 ********************************/

int main()
{
    int ca;
    cin>>ca;                                        //input the number of test case

    while(ca--)                                     //loop for the number of test cases
    {
        int num;
        cin>>num;                                   //input the size of array

        int arr[num];
        fori(0,num)
        {
            cin>>arr[i];                            //input the element in the array
        }
        int shift=0,comp=0;

        selection(arr,num,&shift,&comp);            //sort the array

        fori(0,num)
        cout<<arr[i]<<" ";                          //the sorted array
        cout<<endl;

        cout<<"Comparisons="<<comp<<endl;           //total number of comparisons
        cout<<"Swaps="<<shift<<endl;                //total number of swaps

    }

    return 0;
}