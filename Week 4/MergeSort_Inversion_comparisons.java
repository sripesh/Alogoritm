//Given an unsorted array of integers, design an algorithm and implement it using a 
//program to sort an array of elements by dividing the array into two subarrays and  
//combining these subarrays after sorting each one of them. Your program should also 
//find number of comparisons and inversions during sorting the array.


import java.util.*;


/*********************************
 ****      SORTING_ARRAY      ****
 *********************************/
class sorting
{   
    static int arr[];
    static int comparison,inversion;


    sorting(int arr[])                                      //initialization
    {
        sorting.arr=arr;                                    
        sorting.comparison=sorting.inversion=0;
    }
    static void merge(int b,int mid,int h)
    {
        int l=mid-b+1,r=h-mid;                              //number of elemens in left part and right part
        
        int left[]=new int[l];                                        
        int right[]=new int[r];

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
            sorting.comparison++;                           //count the comparisons

            if(left[i]<right[j])                            //condition for sorting in ascending order
            {
                arr[b++]=left[i++];
            }
            else
            {
                arr[b++]=right[j++];
                sorting.inversion=sorting.inversion+(l-i);  //count the number of inversions
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
    static void sort(int l,int r)
    {
        if(l>=r)                                            //base condition that lower bound should not exceed upper bound
            return;
        int mid=l+(r-l)/2;                                  //calculate mid
        sort(l,mid);                                        //recursion of left part of the divided array
        sort(mid+1,r);                                      //recursion of right part of the divided array
        merge(l,mid,r);                                     //merge the divided array while sorting

    }
    static void disp()
    {
        for(int i=0;i<sorting.arr.length;i++)
        {
            System.out.print(sorting.arr[i]+" ");           //display the array
        }
        System.out.println();
        System.out.println("Comparisons= "
                    +sorting.comparison);                   //number of comparisons
        System.out.println("Inversion= "
                    +sorting.inversion);                    //number of inversions        
    }


}

    /********************************
     ****          MAIN          ****
    ********************************/
public class MergeSort_Inversion_comparisons {
    public static void main(String[] args) 
    {   
        Scanner o=new Scanner(System.in);
        int ca;
        ca=o.nextInt();                                     //input for number of test cases
        while((ca--)!=0)                                    //loop for the number of test cases
        {
            int num;                                    
            num=o.nextInt();                                //input the size of array

            int arr[]=new int[num];
            for(int i=0;i<num;i++)
            {
                arr[i]=o.nextInt();                         //input the element in the array
            }
            
            new sorting(arr);                               //create object of sorting
            sorting.sort(0,num-1);                          //sorting in ascending order
            
            sorting.disp();                                 //display the results
        }
        o.close();
        return;
    }
}
