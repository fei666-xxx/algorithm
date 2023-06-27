#include<iostream>
#include<algorithm>


/*
简单贪心和区间贪心算法

题目1：给出N个开区间(x,y),从中选择尽可能多的开区间，使得这些开区间两两没有交集
*/


struct Interval
{
    int x,y;
    Interval():x(0),y(0){}
    Interval(int x_, int y_):x(x_),y(y_){}
};

bool cmp(Interval a, Interval b)
{
    if(a.y != b.y) return a.y < b.y;
    else return a.x > b.x;
}

int main()
{
    Interval data[4];
    data[0] = Interval(1,3);
    data[1] = Interval(2,4);
    data[2] = Interval(3,5);
    data[3] = Interval(6,7);

    std::sort(data, data+4, cmp);

    int ans=0, lastY=data[0].y;
    for(int i=1;i<4;i++)
    {
        if(data[i].x>=lastY)
        {
            ans++;
            lastY = data[i].y;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}