//Given an unsorted array of integers, design an algorithm and implement it using a program to sort
//an array of elements by partitioning the array into two subarrays based on a pivot element such
//that one of the sub array holds values smaller than the pivot element while another sub array 
//holds values greater than the pivot element. Pivot element should be selected randomly from the 
//array. Your program should also find number of comparisons and swaps required forsorting the array.



import java.util.*;


/*********************************
 ****      SORTING_ARRAY      ****
 *********************************/


 class sorting
{   
    static int arr[];
    static int comparison,swaps;

    sorting(int arr[])                                      //initialization
    {
        sorting.arr=arr;                                    
        sorting.comparison=sorting.swaps=0;
    }
    static void quick(int l,int h)
    {
        if(l>=h)                                            //base condition
        return;
        
        int i=l-1;
        for(int j=l;j<h;j++)                                //loop to positioning larger element on right and smaller element on the left side of the pivot
        {   
            if(arr[j]<arr[h])                               //condition for sorting in ascending order
            {
                i++;
                swap(i,j);
                swaps++;                                    //count the swaps
            }
            comparison++;                                   //count the comparisons
        }
        swap(++i,h);                                        //positioning the pivot to the right place
        swaps++;                                            //count the swaps
        
        quick(l,i-1);                                       //arranging new pivot of left side of the pivot
        quick(i+1,h);                                       //arranging new pivot of right side of the pivot
    }

    static void swap(int i,int j)                           //swap the element of the array with the indeces i & j
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
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
        System.out.println("Swaps= "
                    +sorting.swaps);                        //number of swaps       
    }


}

    
public class QuickSort_Swap_comparisons {


    /********************************
     ****          MAIN          ****
    ********************************/

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
            sorting.quick(0,num-1);                         //sorting in ascending order
            
            sorting.disp();                                 //display the results
        }
        o.close();
        return;
    }
}

