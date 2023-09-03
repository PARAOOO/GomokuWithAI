  # include <stdio.h>
# include <Windows.h>
# include <conio.h>  
# include <stdlib.h>
# include <time.h>

int rboard[15][15];

int board[15][15]={0,};

int point_board[15][15]={0,};

int d;

int x[5]={0,};
int y[5]={0,};
//int x1,x2,x3,x4,x5,y1,y2,y3,y4,y5;

int a=7;
int b=7;
int t;
int arrow;
int victory_count=0;
int reset_count=0;
int ai_count=0;  

void setFontSize(int X, int Y)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = X;
	cfi.dwFontSize.Y = Y;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void setWindowConsole(int cols, int lines)
{
	SetWindowLong(GetConsoleWindow(), GWL_STYLE, WS_CAPTION | WS_SYSMENU);
	SetWindowPos(GetConsoleWindow(), 0, 0, 0, 0, 0, SWP_NOMOVE | SWP_SHOWWINDOW);
	char cmd[100];
	sprintf(cmd, "mode con:cols=%d lines=%d", cols, lines);
	system(cmd);
	system("color 0f");


}

void cursorHide() {

	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

}

void print_board(){
	
	system("cls");
	
	printf("\n               < 오목 >\n\n");
	
	if (board[0][0]==0){
		printf("     ┌ ");
	}
	else if (board[0][0]==1){
		printf("     ○");
	}
	else if (board[0][0]==2){
		printf("     ●");
	}
	else if (board[0][0]==3){
		printf("     ◎");
	}
	
	for (int i=1;i<14;i++){
		if (board[0][i]==0){
			printf("┬ ");
		}
		else if (board[0][i]==1){
			printf("○");
		}
		else if (board[0][i]==2){
			printf("●");
		}
		else if (board[0][i]==3){
			printf("◎");
		}
	}
	
	if (board[0][14]==0){
		printf("┐\n");
	}
	else if (board[0][10]==1){
		printf("○\n");
	}
	else if (board[0][10]==2){
		printf("●\n");
	}
	else if (board[0][10]==3){
		printf("◎\n");
	}
	
	for (int i=1;i<14;i++){
		if (board[i][0]==0){
			printf("     ├ ");
		}
		else if (board[i][0]==1){
			printf("     ○");
		}
		else if (board[i][0]==2){
			printf("     ●");
		}
		else if (board[i][0]==3){
			printf("     ◎");
		}
		
		for (int j=1;j<14;j++){
			if (board[i][j]==0){
				printf("┼ ");
			}
			else if (board[i][j]==1){
				printf("○");
			}
			else if (board[i][j]==2){
				printf("●");
			}
			else if (board[i][j]==3){
				printf("◎");
			}
			
		}
		if (board[i][14]==0){
			printf("┤ \n");
		}
		else if (board[i][14]==1){
			printf("○\n");
		}
		else if (board[i][14]==2){
			printf("●\n");
		}
		else if (board[i][14]==3){
			printf("◎\n");
		}

	}
	
	if (board[14][0]==0){
		printf("     └ ");
	}
	else if (board[14][0]==1){
		printf("     ○");
	}
	else if (board[14][0]==2){
		printf("     ●");
	}
	else if (board[14][0]==3){
		printf("     ◎");
	}
	
	for (int i=1;i<14;i++){
		if (board[14][i]==0){
			printf("┴ ");
		}
		else if (board[14][i]==1){
			printf("○");
		}
		else if (board[14][i]==2){
			printf("●");		
		}
		else if (board[14][i]==3){
			printf("◎");
		}
	}
	
	if (board[14][14]==0){
		printf("┘ \n\n");
	}
	else if (board[14][14]==1){
		printf("○\n\n");
	}
	else if (board[14][14]==2){
		printf("●\n\n");
	}
	else if (board[14][14]==3){
		printf("◎\n\n");
	}
	
return;
	
	
}

void print_point_board(){
	
	for (int i=0;i<15;i++){
		for (int j=0;j<15;j++){
			
			if (point_board[i][j]==100000) printf("  B ");
			else if (point_board[i][j]==200000) printf("  W ");
			else printf("%3d ",point_board[i][j]);
		}
		printf("\n\n");
	}
}

void reset_board(){
	
	for (int i=0;i<15;i++){
		for (int j=0;j<15;j++){
			board[i][j]=0;
			
		}
	}
	
}

void reset_point_board(){
	
	for (int i=0;i<15;i++){
		for (int j=0;j<15;j++){
			
			point_board[i][j]=0;
			
		}
	}
	
}

void game_reset(){
	
	reset_board();

	a=7;
	b=7;
	
	victory_count=0;
	reset_count=0;
	ai_count=0;
	
}

void get_input(){

	t = board[a][b]; //t=0

	board[a][b] = 3; // 9,9 = 3

	print_board();
		
	arrow = _getch();  //input 
		
	if (arrow== 224){
			
		arrow = _getch();
		if (arrow == 75){
			board[a][b] = t;
			b == 0 ? b = b : b--;
		}
		else if (arrow == 77){
			board[a][b] = t;
			b == 14 ? b = b : b++;
		}
		else if (arrow == 80){
			board[a][b] = t;
			a == 14 ? a = a : a++;
		}
		else if (arrow == 72){
			board[a][b] = t;
			a == 0 ? a = a : a--;
		}
			
	}
		
	else {
		if (arrow==32){
			if (t == 1 || t == 2) {
				board[a][b]=t;
		    } 
		    else {
		    	board[a][b] = 1;
		    	ai_count++;
				return;
			}		
		}
		else if (arrow==114){
			reset_count++;
			return;
		}
		else {
			board[a][b]=t;
		}
	}
} 

int check(int x,int y,int n,int board[][15]){
	
	
	// 돌 한개를 두었을 때 오목이 되는지로 가중치 판단 + 그 돌이 상대 돌일 경우도 생각            
	int m;
	if (n==1) m=2;
	else if (n==2) m=1;
	
	int sboard[15][15];
	
	for (int i=0;i<15;i++){
		for (int j=0;j<15;j++){
			sboard[i][j]=board[i][j];
		}
	}
	
	sboard[x][y]=n;
	
	// 위 아래  
	
	int line_count=0;
	int empty_count=0;
	int balance=0;
	int value=0;
	 
	
	for (int i=1;i<5;i++){
		
		if (sboard[x+i][y]==n&&x+i<15) line_count++;
		
		else {
			
			if (sboard[x+i][y]==0&&x+i<15) {
				balance++;
				empty_count++;
			}
			if (sboard[x+i+1][y]==0&&x+i+1<15) empty_count++;
			
			break;
		}
		
	}
	
	for (int i=1;i<5;i++){
	
		if (sboard[x-i][y]==n&&x-i>=0) line_count++;
		else {
			
			if (sboard[x-i][y]==0&&x-i>=0) {
				balance++;
				empty_count++;
			}
			if (sboard[x-i-1][y]==0&&x-i-1>=0) empty_count++;
			
			break;
		}
		
	}
	
	// line_count = 몇개가 이어져 있는지 한개 더해야댐  
	// empty_count = 양 옆에 몇개 비어 있는지
	// balance = empty_count가 양쪽에 있는지 
	// 돌을 두었을 때를 기준으로 함  
	
	if (line_count>3) value+=800; // 22222
	else if (line_count>2&&empty_count>1&&balance>1) value+=500; // 022220
	else if (line_count>1&&empty_count>2&&balance>1) value+=100; // 022200
    else if (line_count>2&&empty_count>0) value+=80; // 22220 
    else if (line_count>0&&empty_count>3&&balance>1) value+=10; // 002200
    
    
    // 좌 우  
    
    line_count=0;
	empty_count=0;
	balance=0;
	
	
	for (int i=1;i<5;i++){
	
		if (sboard[x][y+i]==n&&y+i<15) line_count++;
		else {
			
			if (sboard[x][y+i]==0&&y+i<15) {
				balance++;
				empty_count++;
			}
			if (sboard[x][y+i+1]==0&&y+i+1<15) empty_count++;
			
			break;
		}
		
	}
	
	for (int i=1;i<5;i++){
	
		if (sboard[x][y-i]==n&&y-i>=0) line_count++;
		else {
			
			if (sboard[x][y-i]==0&&y-i>=0) {
				balance++;
				empty_count++;
			}
			if (sboard[x][y-i-1]==0&&y-i-1>=0) empty_count++;
			
			break;
		}
		
	}
	
	// line_count = 몇개가 이어져 있는지 한개 더해야댐  
	// empty_count = 양 옆에 몇개 비어 있는지
	// balance = empty_count가 양쪽에 있는지 
	// 돌을 두었을 때를 기준으로 함  
	
	if (line_count>3) value+=800; // 22222
	else if (line_count>2&&empty_count>1&&balance>1) value+=500; // 022220
	else if (line_count>1&&empty_count>2&&balance>1) value+=100; // 022200
    else if (line_count>2&&empty_count>0) value+=80; // 22220 
    else if (line_count>0&&empty_count>3&&balance>1) value+=10; // 002200
    
    
    // 우하단 대각선  
    
    line_count=0;
	empty_count=0;
	balance=0;
	
	 
	for (int i=1;i<5;i++){
	
		if (sboard[x+i][y+i]==n&&x+i<15&&y+i<15) line_count++;
		else {
			
			if (sboard[x+i][y+i]==0&&x+i<15&&y+i<15) {
				balance++;
				empty_count++;
			}
			if (sboard[x+i+1][y+i+1]==0&&x+i+1<15&&y+i+1<15) empty_count++;
			
			break;
		}
		
	}
	
	for (int i=1;i<5;i++){
	
		if (sboard[x-i][y-i]==n&&x-i>=0&&y-i>=0) line_count++;
		else {
			
			if (sboard[x-i][y-i]==0&&x-i>=0&&y-i>=0) {
				balance++;
				empty_count++;
			}
			if (sboard[x-i-1][y-i-1]==0&&x-i-1>=0&&y-i-1>=0) empty_count++;
			
			break;
		}
		
	}
	
	// line_count = 몇개가 이어져 있는지 한개 더해야댐  
	// empty_count = 양 옆에 몇개 비어 있는지
	// balance = empty_count가 양쪽에 있는지 
	// 돌을 두었을 때를 기준으로 함  
	
	if (line_count>3) value+=800; // 22222
	else if (line_count>2&&empty_count>1&&balance>1) value+=500; // 022220
	else if (line_count>1&&empty_count>2&&balance>1) value+=100; // 022200
    else if (line_count>2&&empty_count>0) value+=80; // 22220 
    else if (line_count>0&&empty_count>3&&balance>1) value+=10; // 002200
		
	// 좌하단 대각선 	
		
	line_count=0;
	empty_count=0;
	balance=0;
	
	for (int i=1;i<5;i++){
	
		if (sboard[x+i][y-i]==n&&x+i<15&&y-i>=0) line_count++;
		else {
			
			if (sboard[x+i][y-i]==0&&x+i<15&&y-i>=0) {
				balance++;
				empty_count++;
			}
			if (sboard[x+i+1][y-i-1]==0&&x+i+1<15&&y-i-1>=0) empty_count++;
			
			break;
		}
		
	}
	
	for (int i=1;i<5;i++){
	
		if (sboard[x-i][y+i]==n&&x-i>=0&&y+i<15) line_count++;
		else {
			
			if (sboard[x-i][y+i]==0&&x-i>=0&&y+i<15) {
				balance++;
				empty_count++;
			}
			if (sboard[x-i-1][y+i+1]==0&&x-i-1>=0&&y+i+1<15) empty_count++;
			
			break;
		}
		
	}
	
	// line_count = 몇개가 이어져 있는지 한개 더해야댐  
	// empty_count = 양 옆에 몇개 비어 있는지
	// balance = empty_count가 양쪽에 있는지 
	// 돌을 두었을 때를 기준으로 함  
	
	if (line_count>3) value+=800; // 22222
	else if (line_count>2&&empty_count>1&&balance>1) value+=500; // 022220
	else if (line_count>1&&empty_count>2&&balance>1) value+=100; // 022200
    else if (line_count>2&&empty_count>0) value+=80; // 22220 
    else if (line_count>0&&empty_count>3&&balance>1) value+=10; // 002200
    
    
    //-----------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------
    
    
    
    sboard[x][y]=1;
	
	// 위 아래  
	
	line_count=0;
	empty_count=0;
	balance=0;
	 
	
	for (int i=1;i<5;i++){
		
		if (sboard[x+i][y]==m&&x+i<15) line_count++;
		
		else {
			
			if (sboard[x+i][y]==0&&x+i<15) {
				balance++;
				empty_count++;
			}
			if (sboard[x+i+1][y]==0&&x+i+1<15) empty_count++;
			
			break;
		}
		
	}
	
	for (int i=1;i<5;i++){
	
		if (sboard[x-i][y]==m&&x-i>=0) line_count++;
		else {
			
			if (sboard[x-i][y]==0&&x-i>=0) {
				balance++;
				empty_count++;
			}
			if (sboard[x-i-1][y]==0&&x-i-1>=0) empty_count++;
			
			break;
		}
		
	}
	
	// line_count = 몇개가 이어져 있는지 한개 더해야댐  
	// empty_count = 양 옆에 몇개 비어 있는지
	// balance = empty_count가 양쪽에 있는지 
	// 돌을 두었을 때를 기준으로 함  
	
	if (line_count>3) value+=700; // 22222
	else if (line_count>2&&empty_count>1&&balance>1) value+=450; // 022220
	else if (line_count>1&&empty_count>2&&balance>1) value+=90; // 022200
    else if (line_count>2&&empty_count>0) value+=70; // 22220 
    else if (line_count>0&&empty_count>3&&balance>1) value+=8; // 002200
    
    
    // 좌 우  
    
    line_count=0;
	empty_count=0;
	balance=0;
	
	
	for (int i=1;i<5;i++){
	
		if (sboard[x][y+i]==m&&y+i<15) line_count++;
		else {
			
			if (sboard[x][y+i]==0&&y+i<15) {
				balance++;
				empty_count++;
			}
			if (sboard[x][y+i+1]==0&&y+i+1<15) empty_count++;
			
			break;
		}
		
	}
	
	for (int i=1;i<5;i++){
	
		if (sboard[x][y-i]==m&&y-i>=0) line_count++;
		else {
			
			if (sboard[x][y-i]==0&&y-i>=0) {
				balance++;
				empty_count++;
			}
			if (sboard[x][y-i-1]==0&&y-i-1>=0) empty_count++;
			
			break;
		}
		
	}
	
	// line_count = 몇개가 이어져 있는지 한개 더해야댐  
	// empty_count = 양 옆에 몇개 비어 있는지
	// balance = empty_count가 양쪽에 있는지 
	// 돌을 두었을 때를 기준으로 함  
	
	if (line_count>3) value+=700; // 22222
	else if (line_count>2&&empty_count>1&&balance>1) value+=450; // 022220
	else if (line_count>1&&empty_count>2&&balance>1) value+=90; // 022200
    else if (line_count>2&&empty_count>0) value+=70; // 22220 
    else if (line_count>0&&empty_count>3&&balance>1) value+=8; // 002200
    
    
    // 우하단 대각선  
    
    line_count=0;
	empty_count=0;
	balance=0;
	
	 
	for (int i=1;i<5;i++){
	
		if (sboard[x+i][y+i]==m&&x+i<15&&y+i<15) line_count++;
		else {
			
			if (sboard[x+i][y+i]==0&&x+i<15&&y+i<15) {
				balance++;
				empty_count++;
			}
			if (sboard[x+i+1][y+i+1]==0&&x+i+1<15&&y+i+1<15) empty_count++;
			
			break;
		}
		
	}
	
	for (int i=1;i<5;i++){
	
		if (sboard[x-i][y-i]==m&&x-i>=0&&y-i>=0) line_count++;
		else {
			
			if (sboard[x-i][y-i]==0&&x-i>=0&&y-i>=0) {
				balance++;
				empty_count++;
			}
			if (sboard[x-i-1][y-i-1]==0&&x-i-1>=0&&y-i-1>=0) empty_count++;
			
			break;
		}
		
	}
	
	// line_count = 몇개가 이어져 있는지 한개 더해야댐  
	// empty_count = 양 옆에 몇개 비어 있는지
	// balance = empty_count가 양쪽에 있는지 
	// 돌을 두었을 때를 기준으로 함  
	
	if (line_count>3) value+=700; // 22222
	else if (line_count>2&&empty_count>1&&balance>1) value+=450; // 022220
	else if (line_count>1&&empty_count>2&&balance>1) value+=90; // 022200
    else if (line_count>2&&empty_count>0) value+=70; // 22220 
    else if (line_count>0&&empty_count>3&&balance>1) value+=8; // 002200
		
	// 좌하단 대각선 	
		
	line_count=0;
	empty_count=0;
	balance=0;
	
	for (int i=1;i<5;i++){
	
		if (sboard[x+i][y-i]==m&&x+i<15&&y-i>=0) line_count++;
		else {
			
			if (sboard[x+i][y-i]==0&&x+i<15&&y-i>=0) {
				balance++;
				empty_count++;
			}
			if (sboard[x+i+1][y-i-1]==0&&x+i+1<15&&y-i-1>=0) empty_count++;
			
			break;
		}
		
	}
	
	for (int i=1;i<5;i++){
	
		if (sboard[x-i][y+i]==m&&x-i>=0&&y+i<15) line_count++;
		else {
			
			if (sboard[x-i][y+i]==0&&x-i>=0&&y+i<15) {
				balance++;
				empty_count++;
			}
			if (sboard[x-i-1][y+i+1]==0&&x-i-1>=0&&y+i+1<15) empty_count++;
			
			break;
		}
		
	}
	
	// line_count = 몇개가 이어져 있는지 한개 더해야댐  
	// empty_count = 양 옆에 몇개 비어 있는지
	// balance = empty_count가 양쪽에 있는지 
	// 돌을 두었을 때를 기준으로 함  
	
	if (line_count>3) value+=700; // 22222
	else if (line_count>2&&empty_count>1&&balance>1) value+=450; // 022220
	else if (line_count>1&&empty_count>2&&balance>1) value+=90; // 022200
    else if (line_count>2&&empty_count>0) value+=70; // 22220 
    else if (line_count>0&&empty_count>3&&balance>1) value+=8; // 002200
		

	
	return value;	
		
}

void remember_board(){
	
	for (int i=0;i<15;i++){
		for (int j=0;j<15;j++){
			rboard[i][j]=board[i][j];
		}
	}
	
}

void return_rboard(){
	
	for (int i=0;i<15;i++){
		for (int j=0;j<15;j++){
			board[i][j]=rboard[i][j];
		}
	}
}

int victory(int x,int y,int n){
	
	int line_count=0;
	int blank=0;
	
	
	
	for (int i=0;i<5;i++){
		if (board[x+i][y]==n&&blank==0) line_count++;	
		else blank++;	
	}
	
	blank=0;
	for (int i=1;i<5;i++){
		if (board[x-i][y]==n&&blank==0) line_count++;
		else blank++;		
	}
	
	if (line_count>4) return 1;
	
	//_________________________________________________
	//_________________________________________________
	
	
	line_count=0;
	blank=0;
	
	for (int i=0;i<5;i++){
		if (board[x][y+i]==n&&blank==0) line_count++;
		else blank++;		
	}
	blank=0;
	for (int i=1;i<5;i++){
		if (board[x][y-i]==n&&blank==0) line_count++;		
		else blank++;
	}
	
	if (line_count>4) return 1;
	
	//_________________________________________________
	//_________________________________________________
	
	line_count=0;
	blank=0;
	
	for (int i=0;i<5;i++){
		if (board[x+i][y+i]==n&&blank==0) line_count++;	
		else blank++;	
	}
	blank=0;
	for (int i=1;i<5;i++){
		if (board[x-i][y-i]==n&&blank==0) line_count++;	
		else blank++;	
	}
	
	if (line_count>4) return 1;
	
	//_________________________________________________
	//_________________________________________________
	
	line_count=0;
	blank=0;
	
	for (int i=0;i<5;i++){
		if (board[x-i][y+i]==n&&blank==0) line_count++;	
		else blank++;	
	}
	blank=0;
	for (int i=1;i<5;i++){
		if (board[x+i][y-i]==n&&blank==0) line_count++;	
		else blank++;	
	}
	
	if (line_count>4) return 1;
	
	
	
	return 0;
	
	
}

int set_point(int n){
	
	reset_point_board();
	
	for (int i=0;i<15;i++){
		for (int j=0;j<15;j++){
			
			if (board[i][j]==0){
				
				point_board[i][j]=check(i,j,n,board);
				
			}
		}
	}
	
	
}

void find(){
	
	int g[5]={0,};
	
	for (int i=0;i<15;i++){
		for (int j=0;j<15;j++){
			
			if (point_board[i][j]>g[0]){
				g[2]=g[1];
				x[2]=x[1]; y[2]=y[1];
				g[1]=g[0];
				x[1]=x[0]; y[1]=y[0];
				g[0]=point_board[i][j];
				x[0]=i; y[0]=j;	
				
			}
			else if (point_board[i][j]>g[1]){
				g[2]=g[1];
				x[2]=x[1]; y[2]=y[1];
				g[1]=point_board[i][j];
				x[1]=i; y[1]=j;	
			
			}
			else if (point_board[i][j]>g[2]){
				g[2]=point_board[i][j];
				x[2]=i; y[2]=j;	
				
			}
			
		}
		
	}	


	
}

int MINMAX(int depth){
	
	int m;
	int max=-10000000;
	int min= 10000000;
	int mx,my;
	
	if (depth%2==0){
		set_point(2);
		find();
	}
	else {
		set_point(1);
		find();
	}

	for (int i=0;i<3;i++){
		
		int X = x[i];
		int Y = y[i];
		
		if (depth%2==0){ // 짝수
		
			if (depth==0){
				
				return check(X,Y,2,board);
			}
			
			board[X][Y]=2;
			
			//print_board();
			
			if (victory(X,Y,2)){
				
				if (depth==d){
					return_rboard();
					board[X][Y]=2;
					a=X;b=Y;
					return 0;
				}
				
				board[X][Y]=0;
				return 10000000*depth;
				
			}
			
			m = MINMAX(depth-1);
			
			board[X][Y]=0;
			
			if (m>max){
				max=m;
				mx=X;
 				my=Y;
			}
			
		}
		
		else {
			
			board[X][Y]=1;
			
			//print_board();
			
			if (victory(X,Y,1)){
			
				board[X][Y]=0;
				
				return -10000000*depth;
				
			}
			
			m = MINMAX(depth-1);
			
			board[X][Y]=0;
			
			if (m<min){
				min=m;
				mx=X;
				my=Y;
			}
			
		}
		
	}
	
	if (depth==d){
		return_rboard();
		board[mx][my]=2;
		return 0;
	}
		
	if (depth%2==0){
		
	
		return max;
		
	}
	
	else {
	
		return min;
	}
	
} 

int start(){
	
	print_board();
	
	printf("         스페이스 바 : 돌 놓기\n\n             방향키 : 조작 \n");
	
	arrow = _getch();
	
	print_board();
	
	int sun=0;
	int hoo=0;
	
	printf("             선공      후공       ");
	
	while(1){
		
		arrow=_getch();
		
		if (arrow == 32) {
			
			if (sun==0&&hoo==0){
				
			}
			else break;
		} 
		
		if (arrow == 224){
			
			arrow=_getch();
			
			if (arrow == 75) {
				sun=1;
				hoo=0;
			}
		
			else if (arrow == 77){
				
				hoo=1;
				sun=0;
			}
		}
		
		if (sun==1) {
			print_board();
			printf("           < 선공 >    후공       ");
		}
		else if (hoo==1) {
			print_board();
			printf("             선공    < 후공 >      ");
			
		}
		
	}
	
		return sun;
	
}

int main(){
	
	setFontSize(18, 36);
	cursorHide();
	setWindowConsole(40,35);

    int s = start();
    
    if (s != 1) board[7][7]=2; 
    
	while(1){
		
		int X,Y;
		
		print_board();
		
		if (victory(a,b,2)) {
			printf("              Computer Win\n\n");
			break;
		}
		
		while(1){
			
			get_input();
			
			if (ai_count>0) break;
		}
		
		ai_count=0;
		print_board();
		
		if (victory(a,b,1)) {
			printf("                  Player Win");
			break;
		}
		
		d=10;
		remember_board();
		MINMAX(10);
		 
	} 

}

