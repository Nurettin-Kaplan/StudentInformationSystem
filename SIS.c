#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#define RED 12		// color definitions
#define GREEN 10
#define YELLOW 14
#define WHITE 15

struct Student{
	int num;
	char name[20];
	char surname[20];
	int age;
	char department[20];
};

void Menu();
void Add();
void Update();
void Delete();
void ViewAll();
void Search();

int main(void){
	
	char choice;
	
	printf("\n\t\tWelcome To Student Information System\n\n");
	
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
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	printf(	"\n1- Add student\n"
			"2- Update student information\n"
			"3- Delete student\n"
			"4- View all students\n"
			"5- Search student by number\n"
			"6- Exit the program\n"
			"Select the operation you want to perform: ");
	scanf("%s", choice);
}

void Add(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	
	struct Student newStudent;
	
	printf("Enter the student's number: ");
	scanf("%d", &newStudent.num);
	printf("Enter the student's name: ");
	scanf("%s", &newStudent.name);
	printf("Enter the student's surname: ");
	scanf("%s", &newStudent.surname);
	printf("Enter the student's age: ");
	scanf("%d", &newStudent.age);
	printf("Enter the student's department: ");
	scanf("%s", &newStudent.department);
	
	FILE *file = fopen("students.txt", "a+");
	if(file == NULL){
		SetConsoleTextAttribute(hConsole, 12);
		perror("There was an error opening the file.\n");
		exit(1);
	}
	fprintf(file, "%d %s %s %d %s\n", newStudent.num, &newStudent.name, &newStudent.surname, newStudent.age, &newStudent.department);
	fclose(file);
	
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n\t\tThe student was successfully added.\n\n");
}

void Update(){
	//
}

void Delete(){
	//
}

void ViewAll(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	
	struct Student student;
	
	FILE *file = fopen("students.txt", "r");
	if(file == NULL){
		SetConsoleTextAttribute(hConsole, 12);
		perror("There was an error opening the file.\n");
		exit(1);
	}
	while(!feof(file)){
		fscanf(file, "%d %s %s %d %s", &student.num, &student.name, &student.surname, &student.age, &student.department);
		printf("\n%d %s %s %d %s\n", student.num, student.name, student.surname, student.age, student.department);
	}
	fclose(file);
	
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n\t\tAll students listed.\n\n");
	SetConsoleTextAttribute(hConsole, 14);
	system("pause");
	system("cls");
	
}

void Search(){
	//
}