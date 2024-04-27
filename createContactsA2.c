/*
Student Name: Sanjida Rahman Supti
Student ID: 1215651
Due Date: 10th March 2024
Course: CIS*2500
I have exclusive control over this submission via my password.
By including this header comment, I certify that:
1) I have read and understood the policy on academic integrity.
2) I have completed Moodle's module on academic integrity.
3) I have achieved at least 80% on the academic integrity quiz
I assert that this work is my own. I have appropriate acknowledged
any and all material that I have used, be it directly quoted or
paraphrased. Furthermore, I certify that this assignment was written
by me in its entirety.
*/

#include "givenA2.h"

void createContacts (char * fileName)
{
    typedef struct contact con;
    con labelsPtr;

    FILE * fptr = fopen(fileName, "a+");  //opened in append and read/write mode. If the file does not exist, it will be created.
    if (fptr == NULL)
    {
        printf("Could not open the file!");
        return;
    }


    fseek(fptr, 0, SEEK_END);

    int empId;
    printf("Employee Id: ");
    scanf("%d", &empId);  //id read from user and stored in 'empIdPosn' field of the dynamically allocated 'labelsPtr'
    labelsPtr.empIdPosn = ftell(fptr) + sizeof (struct contact);

    char firstName[30];
    printf("First Name:");
    scanf("%s", firstName);
    labelsPtr.firstNamePosn =  labelsPtr.empIdPosn + sizeof (int);

    char lastName[30];
    printf("Last Name:");
    scanf("%s", lastName);
    labelsPtr.lastNamePosn =  labelsPtr.firstNamePosn + sizeof (char) * (strlen (firstName) + 1);

    char email[30];
    printf("Email:");
    scanf("%s", email);
    labelsPtr.emailPosn =  labelsPtr.lastNamePosn + sizeof (char) * (strlen (lastName) + 1);

    labelsPtr.next =  labelsPtr.emailPosn + sizeof (char) * (strlen (email) + 1);

    fwrite(&labelsPtr, sizeof(con), 1, fptr);  //writes the entire contact record, including all the positions and data, to the file
    fwrite(&empId, sizeof(int), 1, fptr);
    fwrite(firstName, sizeof(char), strlen(firstName)+1, fptr);  // writes the string stored in 'firstNamePosn' which includes the null character as well
    fwrite(lastName, sizeof(char), strlen(lastName)+1, fptr);
    fwrite(email, sizeof(char), strlen(email)+1, fptr);

    fclose(fptr);
}
