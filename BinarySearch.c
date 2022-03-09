#include<stdio.h>
int bs(int ar[],int l,int r,int *lo,int key)
{
    int mid=(l+r)/2;
    *lo=*lo+1;
    if(l==r)
    return 0;
    if(ar[mid]==key)
    return 1;
    else if(ar[mid]>key)
    return bs(ar,l,mid-1,lo,key);
    else
    return bs(ar,mid+1,r,lo,key);
}
int main()
{
    int ca;
    scanf("%d",ca);
    while(ca--)
    {
        int num;
        scanf("%d",num);
        int arr[num];
        for(int i=0;i<num;i++)
        {
            scanf("%d",arr[i]);
        }
        int key;
        scanf("%d",key);
        int loop=0;
        if(bs(arr,0,num-1,&loop,key))
        {
            printf("Present %d\n",loop);
        }
        else
        {
            printf("Not Present %d\n",loop);
        }
    }
}