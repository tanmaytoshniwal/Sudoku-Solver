#include<bits/stdc++.h>
using namespace std;
int sud[9][9];

bool valid(int row,int col,int num)
{
    int i,j;
    for(i=0;i<9;i++)
    {
        if(sud[row][i] == num)
            return false;
        if(sud[i][col] == num)
            return false;
    }
    int rowS=row-row%3;
    int colS=col-col%3;
    for(i=rowS;i<rowS+3;i++)
    {
        for(j=colS;j<colS+3;j++)
        {
            if(sud[i][j] == num)
                return false;
        }
    }
    return true;
}

bool solve()
{
    int row,col;
    bool flag=false;
    for(row=0;row<9;row++)
    {
        for(col=0;col<9;col++)
        {
            if(sud[row][col] == 0)
            {
                flag=true;
                break;
            }
        }
        if(flag)
            break;
    }
    if(!flag)
        return true;
    int num;
    for(num = 1;num<10;num++)
    {
        if(valid(row,col,num))
        {
            sud[row][col]=num;
            if(solve())
                return true;
            sud[row][col]=0;
        }
    }
    return false;
}


int main()
{
    int i,j;
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
            cin>>sud[i][j];
    if(solve())
    {
        for(i=0;i<9;i++)
        {
            if(i%3==0 && i!=0)
                cout<<"------------------------"<<endl;
            for(j=0;j<9;j++){
                cout<<sud[i][j]<<" ";
                if(j%3==2 && j!=8)
                    cout<<" | ";
            }
            cout<<endl; 
        }
    }
    else
    {
        cout<<"No";
    }
    return 0;
}