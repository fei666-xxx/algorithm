#include<iostream>

/*
双指针思想

题目1：给定一个递增的正整数序列和一个正整数M，求序列中的两个不同位置的数a和b，使得它们的和恰好为M，输出所有满足条件的方案

题目2：合并两个递增整数序列A和B
*/

int main()
{
    int a[]={1,3,5,7,9,11};
    int b[]={3,4,5,6,7,8};
    int c[12]={0};

    int i=0,j=5;
    int m=14;
    while(i<j)
    {
        if(a[i]+a[j]==m)
        {
            std::cout << a[i] << " " << a[j] << std::endl;
            i++,j--;
        }
        else if(a[i]+a[j]>m) j--;
        else i++;
    }

    i=0,j=0;
    int index=0;
    while(i<6 && j<6)
    {
        if(a[i]<b[j]) c[index++]=a[i++];
        else c[index++]=b[j++];  
    }

    while(i<6) c[index++]=a[i++];
    while(j<6) c[index++]=b[j++];

    for(int k=0;k<index;k++) std::cout << c[k] << " ";

    return 0;
}