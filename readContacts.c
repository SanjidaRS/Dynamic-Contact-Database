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

#include "given.h"

void readContacts(char* fileName)
{
    typedef struct contact con;
    con recordPtr;
    int empId;

    FILE* fptr = fopen(fileName, "rb");  // Open in binary read mode
    if (fptr == NULL)
    {
        printf("Could not open the file!\n");
        return;
    }

    printf("Printing Employee records saved on file:\n***************\n");
    while (fread(&recordPtr, sizeof(struct contact), 1, fptr) == 1) { //reads records from the file using 'fread'
         fseek (fptr,  recordPtr.empIdPosn, SEEK_SET);
         fread (&empId, sizeof (int), 1, fptr);
         printf ("Employee Id: %d\n", empId);

     //the fseek function used before indicates the positioning of the file pointer at the correct location ('recordPtr->firstNmaePosn')
        fseek(fptr, recordPtr.firstNamePosn, SEEK_SET);   // function sets the file position indicator to the position specified by 'recordPtr'
        char *firstName = malloc(sizeof(char) * 20);
        fread(firstName, sizeof(char),  recordPtr.lastNamePosn - recordPtr.firstNamePosn, fptr);  //reads the first name from the file
        printf("First Name: %s\n", firstName);
        free(firstName);

        fseek(fptr, recordPtr.lastNamePosn, SEEK_SET);
        char* lastName = malloc(sizeof(char) * 20);
        fread(lastName, sizeof(char), recordPtr.emailPosn - recordPtr.lastNamePosn, fptr);
        printf("Last Name: %s\n", lastName);
        free(lastName);

        fseek(fptr, recordPtr.emailPosn, SEEK_SET);
        char* email = malloc(sizeof(char) * 20);
        fread(email, sizeof(char), recordPtr.next - recordPtr.emailPosn, fptr);
        printf("Email: %s\n", email);
        free(email);

        printf("******************\n******************\n");

    }

    fseek(fptr, recordPtr.next, SEEK_SET);  //sets the file pointer to the position of the next record in the file
    fclose(fptr);
}
