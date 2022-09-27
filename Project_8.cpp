// Tic-Tack-Toe (Replacing numbers 1-9)
#include<iostream>
#include<windows.h>
#include <list>
using namespace std;

void Color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main()
{
    int num = 0, pos, def = 0;
    char c[9] = {'1','2','3','4','5','6','7','8','9'};
    char c2;
    for(int i=0;i<9;i++)
    {
        if(i==1||i==4||i==7)
        {
            cout<<"| "; // 1 whitespace
        }
        cout<<" "<<i+1<<"  "; // 1 whitespace + 2 whitespace
        if(i==1||i==4||i==7)
        {
            cout<<"| "; // 1 whitespace
        }
        if(i==2||i==5)
        {
            cout<<endl;
            cout<<"----------------"<<endl; // 16 '-'
        }
    }    
    string name1,name2;
    int win1 = 0, win2 = 0;
    int color1 = 14, color2 = 10, normal = 7;
    cout<<"\nEnter player 1 name: ";
    Color(color1);
    getline(cin,name1);
    Color(normal);
    cout<< "Enter player 2 name: ";
    Color(color2);
    getline(cin,name2);
    Color(normal);
    for(int i=0;i<9;i++)
    {
        if(def==1)
        {
            break;
        }
        num = 0;
        if(i%2==0)
        {
            Color(color1);
            cout<<"\nPLAYER 1'S TURN"<<endl;
            Color(normal);
            win1++;
        }
        else
        {
            Color(color2);
            cout<<"\nPLAYER 2'S TURN"<<endl;
            Color(normal);
            win2++;
        }
        cout<<"Enter position number 1-9: ";
        cin>>pos;
        cout<<"\nEnter X/O: ";
        cin>>c2;
        c[pos-1]=c2;
        for(int j=0;j<9;j++)
        {
            if(j==1||j==4||j==7)
            {
                cout<<"| "; // 1 whitespace
            }
            if((pos-1)==num && i%2==0) // Player 1
            {
                Color(color1);
                cout<<" "<<c[pos-1]<<"  "; // 1 + 2 whitespace
                Color(normal);
                num++;
                goto skip;
            }
            else if((pos-1)==num && (i%2)!=0) // Player 2
            {
                Color(color2);
                cout<<" "<<c[pos-1]<<"  ";
                Color(normal);
                num++;
                goto skip;
            }
            skip:
            {
                if((pos-1)!=(num-1))
                {
                    cout<<" "<<c[j]<<"  "; // 1 whitespace + 2 whitespace
                }
                num++;
                if(j==2||j==5)
                {
                    cout<<endl;
                    cout<<"----------------"<<endl; // 16 '-'
                    continue;
                }
                if(j==1||j==4||j==7)
                {
                    cout<<"| "; // 1 whitespace
                }
            }
            if(j==8 && i==8)
            {
                cout<<"\nTIE!"<<endl;
                exit;
            }
        }
        if(c[0]==c[1] && c[1]==c[2] || c[3]==c[4] && c[4]==c[5] || c[6]==c[7] && c[7]==c[8]
        || c[0]==c[3] && c[3]==c[6] || c[1]==c[4] && c[4]==c[7] || c[2]==c[5] && c[5]==c[8]
        || c[0]==c[4] && c[4]==c[8] || c[2]==c[4] && c[4]==c[6])
        {
            cout<<"\nWinner: ";
            if(win1>win2)
            {
                Color(color1);
                cout<<name1<<endl;
                Color(normal);
                def = 1;
            }
            if(win1==win2)
            {
                Color(color2);
                cout<<name2<<endl;
                Color(normal);
                def = 1;
            }
            break;
        }
    }
    return 0;
}