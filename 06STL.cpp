#include<iostream>
#include<stack>
#include<string>
#include<queue>
#include<map>

/*
数据结构--栈、队列、映射

题目1：读入一个只包含+、-、*、/ 的非负整数计算表达式，计算该表达式的值

*/


std::map<char,int> priority;
struct node
{
    double num;
    char op;
    bool flag;//true为num, false为op
};

std::queue<node> Change(std::string& ss)
{
    std::queue<node> exp;
    std::stack<node> op;
    node temp;

    for(int i=0; i<ss.length();)
    {
        if(ss[i]>='0' && ss[i]<='9')
        {
            int num=0;
            while(i<ss.length() && ss[i]>='0' && ss[i]<='9')
            {
                num = num*10+ss[i]-'0';
                i++;
            }
            temp.num=num, temp.flag=true;
            exp.push(temp);
        }
        else
        {
            temp.flag=false;

            while(!op.empty() && priority[op.top().op]>=priority[ss[i]])
            {
                exp.push(op.top());
                op.pop();
            }

            temp.op=ss[i];
            op.push(temp);
            i++;
        }
    }
    while(!op.empty())
    {
        exp.push(op.top());
        op.pop();
    }
    return exp;
}

double Cal(std::queue<node>& exp)
{
    std::stack<node> num;
    double temp1,temp2;
    char op;

    while(!exp.empty())
    {
        node temp=exp.front();
        exp.pop();
        if(temp.flag) num.push(temp);
        else
        {
            op = temp.op;
            temp.flag=true;
            temp2 = num.top().num;
            num.pop();
            temp1 = num.top().num;
            num.pop();

            if(op=='+') temp.num=temp1+temp2;
            else if(op=='-') temp.num=temp1-temp2;
            else if(op=='*') temp.num=temp1*temp2;
            else if(op=='/') temp.num=temp1/temp2;

            num.push(temp);
        }
    }
    return num.top().num;
}

int main()
{
    std::string ss="30/90-26+97-5-6-13/88*6+51/29+79*87+57*92";

    priority['+'] = priority['-'] = 0;
    priority['*'] = priority['/'] = 1;

    std::queue<node> exp = Change(ss);
    double res = Cal(exp);
    std::cout << res << std::endl;

    return 0;
}