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
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            cin>>sud[i][j];
        }
    }
    cout<<"BEFORE SOLVING-->"<<endl;
    for(i=0;i<9;i++){
        if(i%3==0 && i!=0){
            cout<<"------------------------"<<endl;
        }
        for(j=0;j<9;j++){
            cout<<sud[i][j]<<" ";
            if(j%3==2 && j!=8){
                cout<<" | ";
            }
        }
        cout<<endl;
    }
    cout<<"AFTER SOLVING-->"<<endl;
    if(solve())
    {
      for(i=0;i<9;i++){
        if(i%3==0 && i!=0){
            cout<<"------------------------"<<endl;
        }
        for(j=0;j<9;j++){
            cout<<sud[i][j]<<" ";
            if(j%3==2 && j!=8){
                cout<<" | ";
            }
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

/*
SAMPLE INPUT--
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0
*/