// CSE240 Fall 2022 HW5
// Sara Schultz
// Write the compiler used: Visual studio

// READ BEFORE YOU START:
// You are given a partially completed program that creates a list of students, like student's record.
// Each record has this information: student's name, id, department of the student, home country.
// The struct 'studentRecord' holds information of one student. Department is enum type.
// An array of structs called 'list' is made to hold the list of students.
// To begin, you should trace through the given code and understand how it works.
// Please read the instructions above each required function and follow the directions carefully.
// You should not modify any of the given code, the return types, or the parameters, you will risk of getting compilation error.
// You are not allowed to modify main ().
// You can use string library functions.

// WRITE COMMENTS FOR IMPORTANT STEPS IN YOUR CODE.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996) // for Visual Studio Only

#define MAX_STUDENTS 20
#define MAX_NAME_LENGTH 30
#define MAX_HOME_COUNTRY_NAME_LENGTH 30

typedef enum { Physics = 0, Mathematics, CS } departmentType;	// enum type

struct studentRecord {									// struct for student details
    char studentName[MAX_NAME_LENGTH];
    departmentType department;
    unsigned int idNumber;
    char homeCountry[MAX_HOME_COUNTRY_NAME_LENGTH];
};

struct studentRecord list[MAX_STUDENTS];				// declare the list of students
int count = 0;											// the number of students currently stored in the list (initialized to 0) //count is tail I think

// functions already implemented
void flushStdIn();
void executeAction(char);
void save(char* fileName);

// functions that need to be implemented by you
int add(char* studentName_input,
    unsigned int idNumber_input,
    char* department_input,
    char* homeCountry_input);		// 20 points
void sort();								// 10 points
int delete(unsigned int idNumber_input);	// 10 points
void load(char* fileName);					// 10 points
void display();								// given


int main()
{
    char* fileName = "Student_List.txt";
    load(fileName);							// load list of students from file (if it exists). Initially there will be no file.
    char choice = 'i';						// initialized to a dummy value
    do
    {
        printf("\nEnter your selection:\n");
        printf("\t a: add a new student\n");
        printf("\t d: display student list\n");
        printf("\t r: remove an student from list\n");
        printf("\t s: sort student list by ID in descending order\n");
        printf("\t q: quit\n");
        choice = getchar();
        flushStdIn();
        executeAction(choice);
    } while (choice != 'q');

    save(fileName);							// save list of students to file (overwrites file, if it exists)
    return 0;
}

// flush out leftover '\n' characters
void flushStdIn()
{
    char c;
    do c = getchar();
    while (c != '\n' && c != EOF);
}

// ask for details from user for the given selection and perform that action
void executeAction(char c)
{
    char studentName_input[MAX_NAME_LENGTH], homeCountry_input[MAX_NAME_LENGTH];
    unsigned int idNumber_input, add_result = 0;
    char department_input[20];
    switch (c)
    {
    case 'a':
        // input student record from user
        printf("\nEnter student name: ");
        fgets(studentName_input, sizeof(studentName_input), stdin);
        studentName_input[strlen(studentName_input) - 1] = '\0';				// discard the trailing '\n' char

        printf("Enter whether student is in 'Physics' or 'Mathematics' or 'CS': ");
        fgets(department_input, sizeof(department_input), stdin);
        department_input[strlen(department_input) - 1] = '\0';					// discard the trailing '\n' char

        printf("Enter Home Country: ");
        fgets(homeCountry_input, sizeof(homeCountry_input), stdin);
        homeCountry_input[strlen(homeCountry_input) - 1] = '\0';			// discard the trailing '\n' char

        printf("Please enter student ID number: ");
        scanf("%d", &idNumber_input);
        flushStdIn();

        // add the student to the list
        add_result = add(studentName_input, idNumber_input, department_input, homeCountry_input);
        if (add_result == 0)
            printf("\nStudent is already on the list! \n\n");
        else if (add_result == 1)
            printf("\nStudent successfully added to the list! \n\n");
        else
            printf("\nUnable to add. Student list is full! \n\n");

        break;
    case 'r':
        printf("Please enter ID number of student to be deleted: ");
        scanf("%d", &idNumber_input);
        flushStdIn();
        int delete_result = delete(idNumber_input);
        if (delete_result == 0)
            printf("\nStudent not found in the list! \n\n");
        else
            printf("\nStudent deleted successfully! \n\n");
        break;
    case 'd': display();	break;
    case 's': sort();		break;

    case 'q': break;
    default: printf("%c is invalid input!\n", c);
    }
}

// Q1 : add (20 points)
// This function is used to add a student into the list. You can simply add the new student to the end of list (array of structs).
// Do not allow the student to be added to the list if it already exists in the list. You can do that by checking student names OR IDs already in the list.
// If the student already exists then return 0 without adding it to the list. If the student does not exist in the list then add the student at the end of the list and return 1.
// If student list is full, then do not add new student to the list and return 2.
// NOTE: Notice how return type of add() is checked in case 'a' of executeAction()
// NOTE: You must convert the string 'department_input' to an enum type and store it in the list because the department has enum type (not string type).
// The list should be case sensitive. For instance, 'Case' and 'case' should be considered two different names.
// Hint: the global variable 'count' holds the number of students currently in the list

int add(char* studentName_input, unsigned int idNumber_input, char* department_input, char* homeCountry_input)
{
    // Write the code below.
    // //return 2 if the list is full
    if (count == MAX_STUDENTS) {
        return 2;
    }

    //check if student is in list by ID number
    int i;
    for (i = 0; i < count; i++) {
        if (list[i].idNumber == idNumber_input) {
            return 0;			//return 0 if student is already on the list
        }
    }

    //add new student
    //*list[count].studentName = *studentName_input;
    strcpy(list[count].studentName, studentName_input);
    list[count].idNumber = idNumber_input;
    //make char* department_input into a departmentType type
    if (tolower(*department_input) == "Physics") {
        list[count].department = Physics;
    }
    else if (tolower(*department_input) == "Mathematics") {
        list[count].department = Mathematics;
    }
    else if (tolower(*department_input) == "CS") {
        list[count].department = CS;
    }
    //*list[count].homeCountry = *homeCountry_input;
    strcpy(list[count].homeCountry, homeCountry_input);
    count++;    //change count/tail once student is added
    return 1;   //return 1 once student is added
    
}



// This function displays the student list with the details (struct elements) of each student.
void display()
{
    char* departmentString = "Physics";									// dummy init

    for (int i = 0; i < count; i++)									// iterate through the list
    {
        printf("\nStudent name: %s", list[i].studentName);		// display student's name

        if (list[i].department == Physics)								// find what to display for department
            departmentString = "Physics";
        else if (list[i].department == Mathematics)
            departmentString = "Mathematics";
        else
            departmentString = "CS";
        printf("\nDepartment: %s", departmentString);				// display department
        printf("\nID Number: %d", list[i].idNumber);				// display student's ID
        printf("\nHome Country: %s", list[i].homeCountry);			// display student's room number
        printf("\n");
    }

}

// Q2 : sort (10 points)
// This function is used to sort the list(array of structs) numerically by student's ID in descending order.
// Parse the list and compare the student IDs to check which one should appear before the other in the list.
// Sorting should happen within the list. That is, you should not create a new array of structs having sorted students.
// Hint: Use a temp struct (already declared) if you need to swap two structs in your logic
void sort()
{
    struct studentRecord studentTemp;	// needed for swapping structs. Not absolutely necessary to use.
    // Write the code below.
    int i, j;
    for (i = 0; i < count; ++i)
    {
        for (j = i + 1; j < count; ++j)
        {
            if (list[i].idNumber < list[j].idNumber)
            {
                studentTemp = list[i];
                list[i] = list[j];
                list[j] = studentTemp;
            }
        }
    }

    // display message for user to check the result of sorting.
    printf("\nStudent list sorted! Use display option 'd' to view sorted list.\n");
}

// save() is called at the end of main()
// This function saves the array of structures to file. It is already implemented.
// You should read and understand how this code works. It will help you with 'load()' function.
// save() is called at end of main() to save the student list to a file.
// The file is saved at the same place as your C file.
// You can simply delete the file to 'reset the list' or to avoid loading from it.
void save(char* fileName)
{
    FILE* file;
    int i, departmentValue = 0;
    file = fopen(fileName, "wb");		// open file for writing

    fwrite(&count, sizeof(count), 1, file);		// First, store the number of students in the list

    // Parse the list and write student record to file
    //
    for (i = 0; i < count; i++)
    {
        fwrite(list[i].studentName, sizeof(list[i].studentName), 1, file);
        fwrite(&list[i].idNumber, sizeof(list[i].idNumber), 1, file);
        // convert enum to a number for storing
        if (list[i].department == Physics)
            departmentValue = 0;		// 0 for Physics
        else if (list[i].department == Mathematics)
            departmentValue = 1;		// 1 for Mathematics
        else
            departmentValue = 2;
        fwrite(&departmentValue, sizeof(departmentValue), 1, file);	// 2 for CS

        fwrite(&list[i].homeCountry, sizeof(list[i].homeCountry), 1, file);
    }

    fclose(file);			// close the file after writing
}

// Q3 : delete (10 points)
// This function is used to delete an student by ID.
// Parse the list and compare the student IDs to check which one should be deleted.
// Restore the array structure after removal of the student record.
// Return 0 if the specified ID was not found. Return 1 upon successful removal of a record.
int delete(unsigned int idNumber_input)
{
    struct studentRecord studentTemp;	// needed for swapping structs. Not absolutely necessary to use.
    // Write the code below
    // list[count].idNumber
    // decrease count when done
    //check if student is in list by ID number
    int i;
    for (i = 0; i < count; i++)
    {
        if (list[i].idNumber == idNumber_input)
        {
        //    *list[i].studentName = '\0';
        //    list[i].idNumber = NULL;
        //    list[i].department = NULL;
        //    *list[i].homeCountry = '\0';
            int j;
            for (j = i; j < count; j++) {
                studentTemp = list[j];
                list[j] = list[(j+1)];
                list[(j+1)] = studentTemp;
            }
            count--;    //change the count
            return 1;   //once record was removed
        }
    }
    return 0; // if specified ID was not found
    
}

// Q4:  load (10 points)
// This function is called in the beginning of main().
// This function reads the student list from the saved file and builds the array of structures 'list'.
// In the first run of the program, there will be no saved file because save() is called at the end of program.
// So at the begining of this function, write code to open the file and check if it exists. If file does not exist, then return from the function.
// (See expected output of add() in homework question file. It displays "Student_List.txt not found" because the file did not exist initially.)
// If the file exists, then parse the student list to read the student details from the file.
// Use the save function given above as an example of how to write this function. Notice the order in which the struct elements are saved in save()
// You need to use the same order to read the list back.
// NOTE: The saved file is not exactly readable because all elements of the struct are not string or char type.
//       So you need to implement load() similar to how save() is implemented. Only then the 'list' will be loaded correctly.
//		You can simply delete the file to 'reset the list' or to avoid loading from it.
void load(char* fileName)
{
    // Write the code below.
    //at the begining of this function, write code to open the file and check if it exists. If file does not exist, then return from the function.
    FILE* fileBuffer;
    fileBuffer = fopen(fileName, "rb"); //open file for reading
    if (fileBuffer != NULL) {
        printf("Students record loaded from %s.\n", fileName);
        fread(&count, sizeof(count), 1, fileBuffer);    //read count
        int i;
        for (i = 0; i < count; i++) {
            fread(list[i].studentName, sizeof(list[i].studentName), 1, fileBuffer);
            fread(&list[i].idNumber, sizeof(list[i].idNumber), 1, fileBuffer);
            fread(&list[i].department, sizeof(list[i].department), 1, fileBuffer);
            fread(list[i].homeCountry, sizeof(list[i].homeCountry), 1, fileBuffer);
        }
        fclose(fileBuffer);
    }
    else {
        printf("%s not found.\n", fileName);
    }
}


//void save(char* fileName)
//{
//    FILE* file;
//    int i, departmentValue = 0;
//    file = fopen(fileName, "wb");		// open file for writing
//
//    fwrite(&count, sizeof(count), 1, file);		// First, store the number of students in the list
//
//    // Parse the list and write student record to file
//    //
//    for (i = 0; i < count; i++)
//    {
//        fwrite(list[i].studentName, sizeof(list[i].studentName), 1, file);
//        fwrite(&list[i].idNumber, sizeof(list[i].idNumber), 1, file);
//        // convert enum to a number for storing
//        if (list[i].department == Physics)
//            departmentValue = 0;		// 0 for Physics
//        else if (list[i].department == Mathematics)
//            departmentValue = 1;		// 1 for Mathematics
//        else
//            departmentValue = 2;
//        fwrite(&departmentValue, sizeof(departmentValue), 1, file);	// 2 for CS
//
//        fwrite(&list[i].homeCountry, sizeof(list[i].homeCountry), 1, file);
//    }
//
//    fclose(file);			// close the file after writing
//}