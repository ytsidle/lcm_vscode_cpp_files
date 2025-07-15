//Windows环境下运行
#include<conio.h>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
const int Dir[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{1,-1},{-1,1},{1,1}};
const int Length=9;
const int Width=9;
const int Number=10;
char user_board[Length+2][Width+2];
short game_board[Length+2][Width+2];
void Initialize_array(){
	if(Number<0||Number>Length*Width){
		printf("错误！");
		system("shutdown -s");
	}
	for(int i=1;i<=Length;i++)
		for(int j=1;j<=Width;j++){
			user_board[i][j]='#';
			game_board[i][j]=0;
		}
	for(int k=1;k<=Number;){
		int x=rand()%Length+1,y=rand()%Width+1;
		if(game_board[x][y]!=1){
			game_board[x][y]=1;
			k++;
		}
	}
}
void Print_array(int x,int y){
	for(int i=0;i<=Length;i++){
		if(i!=0){
			for(int j=0;j<=Width;j++){
				if(j!=0)
					printf("%c",user_board[i][j]);
				printf("%c",i==x&&(j==y-1||j==y)?'@':' ');
			}
			printf("\n");
		}
		for(int j=0;j<=Width;j++)
			printf(" %c",(i==x-1||i==x)&&j==y-1?'@':' ');
		printf("\n");
	}
}
void Print_game_menu(int z,int num){
	printf("WASD/wasd：控制方向\n");
	printf("enter：打开格子/标记格子\n");
	printf("space：切换探索/标记模式\n");
	printf("R/r：返回主菜单");
	if(z==0)
		printf("当前模式：探索模式\n");
	else
		printf("当前模式：标记模式\n");
	printf("剩余雷的数量：%d\n",num);
}
int Count_the_number_of_mines(int x,int y){
	int s=0;
	for(int k=0;k<8;k++)
		s+=game_board[x+Dir[k][0]][y+Dir[k][1]];
	return s;
}
void Extend_board(int x,int y,int &tot){
	if(x<1||x>Length||y<1||y>Width||user_board[x][y]!='#')
		return;
	int c=Count_the_number_of_mines(x,y);
	tot--;
	if(c!=0){
		user_board[x][y]=c+'0';
		return;
	}
	user_board[x][y]=' ';
	for(int k=0;k<8;k++)
		Extend_board(x+Dir[k][0],y+Dir[k][1],tot);
}
void Invalid_operation(){
	printf("操作无效！\n");
	system("pause");
}
void New_game(){
	Initialize_array();
	int x=1,y=1,z=0,tot=Length*Width-Number,num=Number;
	while(tot>=1){
		system("cls");
		Print_array(x,y);
		Print_game_menu(z,num);
		char c=getch();
		if(c=='W'||c=='w')
			x=(x==1?Length:x-1);
		else if(c=='S'||c=='s')
			x=(x==Length?1:x+1);
		else if(c=='A'||c=='a')
			y=(y==1?Width:y-1);
		else if(c=='D'||c=='d')
			y=(y==Width?1:y+1);
		else if(c=='\r')
			if(z==0)
				if(game_board[x][y]==1){
					user_board[x][y]='*';
					break;
				}
				else if(user_board[x][y]=='#')
					Extend_board(x,y,tot);
				else
					Invalid_operation();
			else
				if(user_board[x][y]=='#'){
					user_board[x][y]='!';
					num--;
				}
				else if(user_board[x][y]=='!'){
					user_board[x][y]='#';
					num++;
				}
				else
					Invalid_operation();
		else if(c==' ')
			z=1-z;
		else if(c=='R'||c=='r')
			return;
		else
			Invalid_operation();
	}
	system("cls");
	Print_array(0,0);
	if(tot==0)
		printf("恭喜!您赢了！\n");
	else
		printf("不好意思，您输了。下次走运！\n");
}
int main(){
	srand(time(NULL));
	New_game();
	return 0;
}