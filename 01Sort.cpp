#include<iostream>
#include<algorithm>


/*
题目1：实现常见排序算法，包括冒泡排序、选择排序、插入排序、归并排序(递归实现)、归并排序(非递归实现)、快速排序

题目2：在一个无序的数组中求出第K大的数(假设数组中的数各不相同) 提示:利用快速排序
*/


void Swap(int& a, int& b)
{
    int temp=a;
    a=b;
    b=temp;
}

void BubbleSort(int a[], int L, int R)
{
    for(int i=L;i<R;i++)
    {
        for(int j=L;j<R-i+L;j++)
        {
            if(a[j]>a[j+1])
                Swap(a[j],a[j+1]);
        }
    }
}

void SelectSort(int a[], int L, int R)
{
    for(int i=L;i<R;i++)
    {
        int index=i;
        for(int j=i+1;j<=R;j++)
        {
            if(a[j]<a[index])
                index = j;
        }
        Swap(a[index],a[i]);
    }
}

void InsertSort(int a[], int L, int R)
{
    for(int i=L+1; i<=R; i++)
    {
        int temp=a[i];
        int j=i;
        while(j>0&&a[j-1]>temp)
        {
            a[j] = a[j-1];
            j--;
        }
        a[j] = temp;
    }
}

void Merge(int a[], int L1, int R1, int L2, int R2)
{
    int temp[20];
    int i=L1, j=L2, index=0;
    while(i<=R1 && j<=R2)
    {
        if(a[i]<a[j]) temp[index++]=a[i++];
        else temp[index++]=a[j++];
    }
    while(i<=R1) temp[index++]=a[i++];
    while(j<=R2) temp[index++]=a[j++];

    for(int k=0;k<index;k++) a[L1+k]=temp[k];
}

void MergetSort1(int a[], int L, int R)
{
    if(L<R)
    {
        int mid = (L+R)/2;
        MergetSort1(a, L, mid);
        MergetSort1(a, mid+1, R);
        Merge(a,L,mid,mid+1,R);
    }
}

void MergetSort2(int a[], int L, int R)
{
    int num=R-L+1;
    for(int step=2; step/2<=num; step*=2)
    {
        for(int i=L;i<=R;i+=step)
        {
            int mid=i+step/2-1;
            if(mid+1<=R)
            {
                Merge(a,i,mid,mid+1,std::min(i+step-1,R));
            }
        }
    }
}

int Partition(int a[], int L, int R)
{
    int temp=a[L];
    while(L<R)
    {
        while(L<R && a[R]>temp) R--;
        a[L]=a[R];
        while(L<R && a[L]<=temp) L++;
        a[R]=a[L];
    }
    a[L]=temp;
    return L;
}

void QuickSort(int a[], int L, int R)
{
    if(L<R)
    {
        int p=Partition(a,L,R);
        QuickSort(a,L,p-1);
        QuickSort(a,p+1,R);
    }
}

bool cmp(int a, int b)
{
    return a<b;
}

int Select(int a[], int L, int R, int K)
{
    if(L==R) return a[L];
    int p=Partition(a,L,R);
    int M=p-L+1;
    if(K==M) return a[p];
    else if(K<M) 
    {
        return Select(a,L,p-1,K);
    }
    else
    {
        return Select(a,p+1,R,K-M);
    }
    
}

int main()
{
    int a[10] = {1,3,5,2,4,7,9,8,6,0};

    //BubbleSort(a,0,9);
    //SelectSort(a,0,9);
    //InsertSort(a,0,9);
    //MergetSort1(a,0,9);
    //MergetSort2(a,0,9);
    //QuickSort(a,0,9);
    //std::sort(a,a+10,cmp);
    
    //std::cout << Select(a,0,9,7) << std::endl;

    for(int i=0;i<10;i++)
        std::cout << a[i] << " "; 
    return 0;
}