#include<stdio.h>
#include<windows.h>
#define RED 12		// color definitions
#define GREEN 10
#define YELLOW 14
#define WHITE 15

int main(void){
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, YELLOW);
	
	
	
	
	
	system("pause");
	return 0;
}