#include "given.h"

int searchContacts(char *fileName, int keyId) {
    typedef struct contact con;
    con recordPtr;

    FILE *fptr = fopen(fileName, "rb");  // Open in binary read mode
    if (fptr == NULL) {
        printf("Could not open the file!\n");
        return 0;
    }

    int index = 0;
    int empId;
    while (fread(&recordPtr, sizeof(struct contact), 1, fptr) == 1) {  //loop reads each contact record from the file using 'fread'
         fseek (fptr,  recordPtr.empIdPosn, SEEK_SET);
         fread (&empId, sizeof(int), 1, fptr);

        if (empId == keyId) {
         printf ("Employee Id: %d\n", empId);

     //the fseek function used before indicates the positioning of the file pointer at the correct location ('recordPtr->firstNamePosn')
        fseek(fptr, recordPtr.firstNamePosn, SEEK_SET);   // function sets the file position indicator to the position specified by 'recordPtr'
        char* firstName = malloc(sizeof(char) * 20);
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

       index = 1;

       }

        fseek(fptr, recordPtr.next, SEEK_SET);
    }

        fclose(fptr);
        return index;
}
