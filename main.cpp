#include <iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>

using namespace std;
class qa
{
    int sno;
    char ques[180];
    char ans[50];
public:
    void getdata()
    {
        cout<<"\n enter sno : "; cin>>sno;
        cout<<"\n enter ques :"; cin.ignore(); gets(ques);
        cout<<"\n enter ans :"; cin.ignore(); gets(ans);
    }
    void showdata()
    {
        cout<<"\n sno is"<<sno;
        cout<<"\n"<<ques;
    }
    char* retans()
    {
        return ans;
    }
};
qa obj;
int pos,counter,eq,mq,hq,coq; char* ans2; fstream file,fp1,fp2; char ans3[30]; //file is for easy. fp1 is medium. fp2 is hard
//--------------------------------------------------------------------------
void posdecide()
{
        system("cls");
        switch(pos)
        {
            case 3 :
            case 5 :
            case 6 :
            case 8 :
            case 11:
            case 13:
            case 14:
                pos=pos-counter;
                cout<<"\n you encountered an obstacle number.";
                break;
            default : cout<<"\n not an obstacle number";
        }
        if(pos<=0)
            pos=1;
        cout<<"\n your position is "<<pos;
        cout<<"\npress any key to go back ";
        getch();
}
//---------------------------------------------------------
void easy()
{
        cout<<"\n";
        file.read((char*)&obj,sizeof(obj));
        obj.showdata();
        ans2=obj.retans();
        cout<<"\n enter ur ans ";
        cin.ignore(); gets(ans3);
        if(strcmpi(ans2,ans3)==0)
        {
            cout<<"\n right ";
            pos=pos+1;
        }
        else
            cout<<"\n wrong";
        cout<<"\n press any key to go back";
        getch();

}
//--------------------------------------------------------
void medium()
{
        cout<<"\n";
        fp1.read((char*)&obj,sizeof(obj));
        obj.showdata();
        ans2=obj.retans(); cout<<"\n enter ur ans ";
        cin.ignore(); gets(ans3);
        if(strcmpi(ans2,ans3)==0)
        {
            cout<<"\n right ";
            pos=pos+2;
        }
        else
            cout<<"\n wrong";
        cout<<"\n press any key to go back";
        getch();
}
//---------------------------------------------------------------------
void hard()
{
        cout<<"\n";
        fp2.read((char*)&obj,sizeof(obj));
        obj.showdata();
        ans2=obj.retans(); cout<<"\n enter ur ans ";
        cin.ignore(); gets(ans3);
        if(strcmpi(ans2,ans3)==0)
            {
                cout<<"\n right ";
                pos=pos+3;
            }
        else
            cout<<"\n wrong";
            cout<<"\n press any key to go back";
            getch();
}
//--------------------------------------------------------------------
int main()
{
    file.open("easy.dat", ios::binary|ios::out|ios::in);
    fp2.open("hard.dat",ios::binary|ios::out|ios::in);
    fp1.open("medium.dat",ios::binary|ios::out|ios::in);
    counter=0; pos=1;
    cout << "Hello.Lets play a game.Now there are numbers 1 to 16.";
    cout<<"\n Some of them are obstacles numbers. And u will start from 1 and you have to reach 16 ";
    cout<<"\n And to reach 16, you need to answer questions. Now there are levels of questions. Easy,medium and hard";
    cout<<"\n Now if u answer easy u move 1 number forward and medium 2 numbers and hard 3 numbers forward ";
    cout<<"\n and if u encounter an obstacle number u will be back by the amount of times u have played and obs no wont change";
    cout<<"\n gear up now!";
    cout<<"\n Copied from the hp quiz in isbf :P";
    cout<<"\n press any key to start "; getch();
    do
    {
        system("cls");
        cout<<"\n 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16";
        cout<<"\n     -   - -   -       -    -   -";
        cout<<"\n Obstacle numbers are: 3,5,6,8,11,13,14 ";
        cout<<"\n Your position is : "<<pos;
        cout<<"\n Now enter your choice :\n 1 Easy\n 2 Medium\n 3 Hard ";
        cin>>coq; counter++;
        switch(coq)
        {
            case 1 :
                    easy();
                    break;
            case 2 :
                    medium();
                    break;
            case 3 :
                    hard();
                    break;
        }
        posdecide();
    }while(pos<16);
    cout<<"\n game over ";
    getch();
    return 0;
}

