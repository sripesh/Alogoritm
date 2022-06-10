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

void insertion(int ar[],int n,int *s,int*c)
{
    fori(1,n)
    {
        int j=i-1,temp=ar[i];
        while(j>=0 && ar[j]>temp)           //finding the larger element before the selected element and shifting it to it's original place
        {
            ar[j+1]=ar[j];
            ++*c;                           //count the comparisons
            ++*s;                           //count the shift
            j--;
        }
        ar[j+1]=temp;                       //positioning the selected element in correct position  
        ++*s;                               //count the shift
    }
}


/********************************
 ****          MAIN          ****
 ********************************/

int main()
{
    int ca;
    cin>>ca;                                //input the number of test case

    while(ca--)                             //loop for the number of test cases
    {
        int num;
        cin>>num;                           //input the size of array

        int arr[num];
        fori(0,num)
        {
            cin>>arr[i];                    //input the element in the array
        }
        int shift=0,comp=0;

        insertion(arr,num,&shift,&comp);    //sort the array

        fori(0,num)
        cout<<arr[i]<<" ";                  //the sorted array
        cout<<endl;

        cout<<"Comparisons="<<comp<<endl;   //total number of comparisons
        cout<<"Shift="<<shift<<endl;        //total number of shifts

    }

    return 0;
}