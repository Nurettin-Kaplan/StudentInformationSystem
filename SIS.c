#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#define RED 12		// color definitions
#define GREEN 10
#define YELLOW 14
#define WHITE 15

struct Student{
	char num[10];
	char name[25];
	char surname[25];
	char age[5];
	char department[30];
};

void Menu();
void Add();
void Update();
void Delete();
void ViewAll();
void Search();
void Accept();

int main(void){
	
	static char choice;
	char answer;
	
	printf("\n\t\tWelcome To Student Information System\n\n");
	
	do{
		Menu(&choice);
		Accept(&answer);
		system("cls");
		if(answer == '1'){
			switch(choice){
				case '1': Add();			break;
				case '2': Update();			break;
				case '3': Delete();			break;
				case '4': ViewAll();		break;
				case '5': Search();			break;
				case '6': continue;			break;
				default: printf("You have entered an invalid option. Please try again.\n"); break;
			}	
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
	scanf("%s", &newStudent.num);
	printf("Enter the student's name: ");
	scanf("%s", &newStudent.name);
	printf("Enter the student's surname: ");
	scanf("%s", &newStudent.surname);
	printf("Enter the student's age: ");
	scanf("%s", &newStudent.age);
	printf("Enter the student's department: ");
	scanf("%s", &newStudent.department);
	
	FILE *file = fopen("students.txt", "a+");
	if(file == NULL){
		SetConsoleTextAttribute(hConsole, 12);
		perror("There was an error opening the file.\n");
		exit(1);
	}
	fprintf(file, "%s %s %s %s %s\n", &newStudent.num, &newStudent.name, &newStudent.surname, &newStudent.age, &newStudent.department);
	fclose(file);
	
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n\t\tThe student was successfully added.\n\n");
	SetConsoleTextAttribute(hConsole, 14);
	system("pause");
	system("cls");
}

void Update(){
	//
}

void Delete(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	
	struct Student foundStudent;
	int isFound = 0;
	char number[10];
	
	printf("\nEnter the number of the student you want to delete: ");
	scanf("%s", &number);
	
	FILE *file1 = fopen("students.txt", "r");
	FILE *file2 = fopen("newStudents.txt", "w");
	if(file1 == NULL || file2 == NULL){
		SetConsoleTextAttribute(hConsole, 12);
		perror("There was an error opening the file.\n");
		exit(1);
	}
	while(!feof(file1)){
		fscanf(file1, "%s %s %s %s %s", &foundStudent.num, &foundStudent.name, &foundStudent.surname, &foundStudent.age, &foundStudent.department);
		if(strcmp(number, foundStudent.num) == 0){
			isFound = 1;
			continue;
		}
		fprintf(file2, "%s %s %s %s %s\n", &foundStudent.num, &foundStudent.name, &foundStudent.surname, &foundStudent.age, &foundStudent.department);
	}
	fclose(file1);
	fclose(file2);
	remove("students.txt");
	rename("newStudents.txt", "students.txt");
	
	if(isFound == 1){
		SetConsoleTextAttribute(hConsole, 10);
		printf("\n\t\tDeletion process completed.\n\n");
	}
	else{
		SetConsoleTextAttribute(hConsole, 12);
		printf("\n\t\tThe student to be deleted could not be found.\n\n");	
	}
	
	SetConsoleTextAttribute(hConsole, 14);
	system("pause");
	system("cls");
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
		fscanf(file, "%s %s %s %s %s", &student.num, &student.name, &student.surname, &student.age, &student.department);
		printf("\n%s %s %s %s %s\n", student.num, student.name, student.surname, student.age, student.department);
	}
	fclose(file);
	
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n\t\tAll students listed.\n\n");
	SetConsoleTextAttribute(hConsole, 14);
	system("pause");
	system("cls");
}

void Search(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	
	struct Student foundStudent;
	int isFound = 0;
	char number[10];
	
	printf("\nEnter the number of the student you are searching for: ");
	scanf("%s", &number);
	
	FILE *file = fopen("students.txt", "r");
	if(file == NULL){
		SetConsoleTextAttribute(hConsole, 12);
		perror("There was an error opening the file.\n");
		exit(1);
	}
	while(!feof(file)){
		fscanf(file, "%s %s %s %s %s", &foundStudent.num, &foundStudent.name, &foundStudent.surname, &foundStudent.age, &foundStudent.department);
		if(strcmp(number, foundStudent.num) == 0){
			isFound = 1;
			break;
		}
	}
	fclose(file);
	
	if(isFound == 1){
		SetConsoleTextAttribute(hConsole, 15);
		printf("\nFound student: %s %s %s %s %s\n\n", foundStudent.num, foundStudent.name, foundStudent.surname, foundStudent.age, foundStudent.department);
	}
	else{
		SetConsoleTextAttribute(hConsole, 12);
		printf("\nThe student being searched for could not be found.\n\n");	
	}
	
	SetConsoleTextAttribute(hConsole, 14);
	system("pause");
	system("cls");
}

void Accept(char* answer){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	printf("\nDo you want to continue with the operation?\n");
	SetConsoleTextAttribute(hConsole, 10);
	printf("Continue = 1 ");
	SetConsoleTextAttribute(hConsole, 12);
	printf("Cancel = 0\n");
	SetConsoleTextAttribute(hConsole, 14);
	printf("Answer: ");
	scanf("%s", answer);
}