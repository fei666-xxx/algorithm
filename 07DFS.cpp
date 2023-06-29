#include<iostream>
#include<vector>

/*
深度优先搜索

题目1：给定N个整数，从中选择K个数，使得这K个数之和恰好等于一个给定的整数X；如果有多种方案，选择它们中元素平方和最大的那一个，输出选择方案

*/

int N=4,K=2,X=6;
int a[] = {2,3,3,4};

std::vector<int> temp, ans;
int maxSumSqu=-1;

void DFS(int index, int sum, int sumSqu, int nowK)
{  

    if(sum==X && nowK==K)
    {
        if(sumSqu>maxSumSqu)
        {
            maxSumSqu = sumSqu;
            ans = temp;
        }
        return;
    }

    if(index==N || nowK>K) return;

    DFS(index+1, sum, sumSqu, nowK);
    temp.push_back(a[index]);
    DFS(index+1, sum+a[index], sumSqu+a[index]*a[index], nowK+1);
    temp.pop_back();
}

int main()
{
    DFS(0,0,0,0);
    for(int i=0;i<ans.size();i++) std::cout << ans[i] << " ";
    std::cout << std::endl << maxSumSqu << std::endl;
    return 0;
}