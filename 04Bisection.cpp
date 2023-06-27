#include<iostream>

/*
二分法查找

题目1：在一个严格递增整数序列中给出整数x的下标，没有则返回-1

题目2：在一个递增整数序列中(可能有重复元素), 给出整数x的存在区间[L,R)，没有则返回"假设序列中存在x, x应当在的位置"
*/

int BinarySearch(int a[], int length, int x)
{
    int left=0, right=length-1;
    int mid=0;
    while(left<=right)
    {
        mid = (left+right)/2;
        if(a[mid]==x) return mid;
        if(a[mid]>x) right=mid-1;
        else if(a[mid]<x) left=mid+1;
    }
    return -1;
}

int LowerBound(int a[], int length, int x)
{
    int left=0, right=length;
    int mid=0;
    while(left<right)
    {
        mid = (left+right)/2;
        if(a[mid]>=x) right=mid;
        else left = mid+1;
    }
    return left;
}

int UpperBound(int a[], int length, int x)
{
    int left=0, right=length;
    int mid=0;
    while(left<right)
    {
        mid = (left+right)/2;
        if(a[mid]>x) right=mid;
        else left = mid+1;
    }
    return left;
}

int main()
{
    //int a[10] = {1,3,4,6,7,8,10,11,12,15};
    int a[10] = {1,3,4,6,6,6,9,11,12,12};
    
    //std::cout << BinarySearch(a,10,6) << std::endl;
    //std::cout << BinarySearch(a,10,9) << std::endl;

    std::cout << LowerBound(a,10,12) << std::endl;
    std::cout << UpperBound(a,10,12) << std::endl;

    return 0;
}