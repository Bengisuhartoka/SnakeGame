#include<iostream>
#include<conio.h>
#include<time.h>
using namespace std;
bool gameover;
const int weidth=20;
const int height=20;
int x,y,fruitx,fruity,score;
enum edrection{STOP=0,LEFT,RÝGHT,UP,DOWN};
edrection dir;
void setup()
{
	srand(time(NULL));
	gameover=false;
	dir=STOP;
	x=weidth/2;
	y=height/2;
	fruitx=rand()%weidth;
	fruitx=rand()%height;
	score=0;

}
void draw()
{
	system("cls");
	srand(time(NULL));
	for(int i=0;i<weidth+2;i++)
	{
		cout<<"#";
	}
	for(int i=0;i<height;i++)
	{	cout<<endl;
		
		for(int j=0;j<weidth;j++)
		{
			if(j==0)
				cout<<"#";
			if(i==y&&j==x)
			{
				cout<<"O";
			}
			else if(i==fruity&&j==fruitx)
			{
				cout<<"f";
			}
			else
			cout<<" ";
			if(j==weidth-1)
				cout<<"#";
		}
	}
	cout<<endl;
	for(int i=0;i<weidth+2;i++)
	{
		cout<<"#";
	}

	cout<<endl<<"SCORE:"<<score;

}
void input()
{
	if(_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir=LEFT;
			break;
			case 's':
				dir=DOWN;
			break;
			case 'd':
				dir=RÝGHT;
			break;
			case 'w':
				dir=UP;
			break;
		}
	}
	

}
void logic()
{

	switch (dir)
	{

	case LEFT:
		x--;
		break;
	case RÝGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if(x>weidth+1||x<-1||y>height+1||y<-1)
	{
		gameover=true;
		cout<<endl<<"GAMEOVER"<<endl;
	}
	if(x==fruitx&&y==fruity)
	{
		score+=10;
		fruitx=rand()%weidth;
	fruity=rand()%height;

		
		
	}
}

void main()
{
	setup();
	while(!gameover)
	{
		draw();
		input();
		logic();

	}
system("pause");
}