#include<iostream>
#include<queue>

/*
广度优先搜索

题目1：给定一个n*m大小的迷宫，"*"代表不可通过的墙壁，"."代表平地，S表示起点，T表示终点。只能在上下左右四个方向移动，求从起点S到终点T的最少步数

*/

const int N=5;
const int M=5;
char maze[N][M]={'.','.','.','.','.',
                 '.','*','.','*','.',
                 '.','*','S','*','.',
                 '.','*','*','*','.',
                 '.','.','.','T','*'};
struct Node
{
    int x;
    int y;
    int step;

} S, T, node;



int inq[N][M] = {0};
int X[4] = {-1,0,0,1};
int Y[4] = {0,1,-1,0};

bool Judge(int x, int y)
{
    if(x<0 || x>=N || y<0 || y>=M) return false;
    if(inq[x][y]) return false;
    if(maze[x][y]=='*') return false;
    return true;
}

int BFS()
{
    std::queue<Node> q;
    q.push(S);
    inq[S.x][S.y]=1;
    while(!q.empty())
    {
        Node top = q.front();
        q.pop();

        if(top.x==T.x && top.y==T.y) return top.step;

        for(int i=0;i<4;i++)
        {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if(Judge(newX,newY))
            {
                node.x = newX;
                node.y = newY;
                node.step = top.step+1;
                q.push(node);
                inq[newX][newY]=1;
            }
        }

    }
    return -1;
}

int main()
{
    S.x = 2, S.y=2, S.step=0;
    T.x = 4, T.y=3;
    int res=BFS();
    std::cout << res << std::endl;
    return 0;
}