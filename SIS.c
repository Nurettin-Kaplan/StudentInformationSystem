#include<stdio.h>
#include<windows.h>
#define RED 12		// color definitions
#define GREEN 10
#define YELLOW 14
#define WHITE 15

void Menu();

int main(void){
	
	int choice;
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	
	printf("\t\tWelcome To Student Information System\n\n");
	
	Menu(&choice);
	
	system("pause");
	return 0;
}

void Menu(int* choice){
	printf("1- Add student\n"
	"2- Update student information\n"
	"3- Delete student\n"
	"4- View all students\n"
	"5- Search student by number\n"
	"Select the operation you want to perform: ");
	scanf("%d", choice);
}