### Student Information System README

---

#### Overview
The **Student Information System** is a simple console-based application written in C. It allows users to manage student information including adding, updating, deleting, viewing, and searching for students.

---

#### Changes Made

#### Platform Independence

In this project, Windows-specific dependencies have been removed, and the code has been made to work across all platforms.

---

#### Changes Made:

- Removed Windows-specific libraries and code.

---

#### Features
1. **Add Student:** Add new student records.
2. **Update Student Information:** Update existing student records.
3. **Delete Student:** Delete student records.
4. **View All Students:** Display all student records.
5. **Search Student by Number:** Search for a student using their number.
6. **Exit:** Exit the application.

---

#### Installation
1. **Download the repository:** Clone the repository to your local machine using
   ```bash
   git clone https://github.com/Nurettin-Kaplan/StudentInformationSystem.git
   ```
2. **Compile the code:** Use a C compiler to compile the `main.c` file.
   ```sh
   gcc -o SIS SIS.c
   ```
3. **Run the application:** Execute the compiled file.
   ```sh
   ./SIS
   ```

---

#### Usage
1. **Launch the Application:** Run the compiled file to start the application.
2. **Menu Options:**
   - **1:** Add student
   - **2:** Update student information
   - **3:** Delete student
   - **4:** View all students
   - **5:** Search student by number
   - **6:** Exit the program

3. **Add Student:** Enter the student's details when prompted.
4. **Update Student Information:** Enter the student number of the record you want to update and provide new details.
5. **Delete Student:** Enter the student number of the record you want to delete.
6. **View All Students:** Display all student records.
7. **Search Student by Number:** Enter the student number to search for the student.

---

#### File Structure
- **SIS.c:** The main program file containing the code for the Student Information System.
- **students.txt:** A text file where student records are stored.

---

#### Functions
1. `void Menu(char* choice);` - Displays the menu options.
2. `void Add();` - Adds a new student record.
3. `void Update(int lines);` - Updates an existing student record.
4. `void Delete(int lines);` - Deletes a student record.
5. `void ViewAll(int lines);` - Displays all student records.
6. `void Search(int lines);` - Searches for a student record by student number.
7. `void Accept(char* answer);` - Accepts the user's choice to continue or cancel the operation.
8. `int LineCount();` - Counts the number of lines (records) in the students.txt file.

---

#### Dependencies
- **stdio.h:** Standard Input/Output library.
- **string.h:** Library for string handling functions.
- **stdlib.h:** Standard Library for general-purpose functions.

---

#### Contributing
Feel free to fork this repository and contribute by submitting a pull request. For major changes, please open an issue first to discuss what you would like to change.

---

#### License
This project is licensed under the MIT License - see the [LICENSE](https://github.com/Nurettin-Kaplan/StudentInformationSystem/blob/master/LICENSE.txt) file for details.

---

#### Contributors
[Nurettin Kaplan](https://github.com/Nurettin-Kaplan) - Project owner and developer.

---

If you have any questions or feedback, please contact me at [email address](nurettinkaplaan@gmail.com)
