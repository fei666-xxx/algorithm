#include<iostream>


/*
全排列和八皇后问题

题目1：输出1-n的n个整数能形成的所有排列

题目2：在n*n的国际棋盘上放置n个皇后，使得这n个皇后两两均不在同一行、同一列、同一对角线上，求合法的方案数
*/


void FullPermutation(int index, int n, bool hashTable[], int p[])
{
    if(index>n)
    {
        for(int i=1;i<=n;i++)
            std::cout << p[i] << " ";
        std::cout << std::endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(hashTable[i]==false)
        {
            p[index] = i;
            hashTable[i] = true;
            FullPermutation(index+1,n,hashTable,p);
            hashTable[i] = false;
        }
    }
}

void EightQueens(int index, int n, bool hashTable[], int p[], int& count)
{
    if(index>n)
    {
        count++;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(hashTable[i]==false)
        {

            bool flag = true;//第index行放入第i列不冲突
            for(int pre=1; pre<index; pre++)
            {
                if(abs(pre-index)==abs(p[pre]-i))
                {
                    flag=false;
                    break;
                }
            }

            if(flag)
            {
                p[index] = i;
                hashTable[i] = true;
                EightQueens(index+1,n,hashTable,p,count);
                hashTable[i] = false;
            }
        }
    }
}


int main()
{
    bool hashTable[9]= {false};
    int p[9]={0};


    //FullPermutation(1,4,hashTable,p);

    int count=0;
    EightQueens(1,8,hashTable,p,count);
    std::cout << count <<std::endl;

    return 0;
}