#include "given.h"

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
