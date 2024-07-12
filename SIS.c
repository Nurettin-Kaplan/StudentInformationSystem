#include<stdio.h>
#include<windows.h>
#include<string.h>
#define RED 12		// color definitions
#define GREEN 10
#define YELLOW 14
#define WHITE 15

void Menu();
void Add();
void Update();
void Delete();
void ViewAll();
void Search();

int main(void){
	
	char choice;
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	
	printf("\t\tWelcome To Student Information System\n\n");
	
	do{
		Menu(&choice);
		system("cls");
		switch(choice){
			case '1': Add();			break;
			case '2': Update();			break;
			case '3': Delete();			break;
			case '4': ViewAll();		break;
			case '5': Search();			break;
			case '6': continue;			break;
			default: printf("You have entered an invalid option. Please try again.\n"); break;
		}
		
	}while(choice != '6');
	
	system("pause");
	return 0;
}

void Menu(char* choice){
	printf(	"1- Add student\n"
			"2- Update student information\n"
			"3- Delete student\n"
			"4- View all students\n"
			"5- Search student by number\n"
			"6- Exit the program\n"
			"Select the operation you want to perform: ");
	scanf("%s", choice);
}

void Add(){
	//
}

void Update(){
	//
}

void Delete(){
	//
}

void ViewAll(){
	//
}

void Search(){
	//
}