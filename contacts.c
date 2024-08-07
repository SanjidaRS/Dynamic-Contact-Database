#include "given.h"

int main ()
{

    char ans[3];
    int choice;

    while (1)    //prompting the user for a specific input until 'break' statement is encountered
    {
        printf("Do you wish to enter a new contact (Yes or No)? ");
        scanf("%s", ans);

        if (ans[0] == 'Y' && ans[1] == 'e' && ans[2] == 's' && ans[3] =='\0')    //input is "Yes"
        {
            createContacts("contactListA2.db");   //function 1 call

        }
        else if (ans[0] == 'N' && ans[1] == 'o' && ans[2] == '\0')      //if input is "No"
        {
            break;

        }
        else
        {
            printf("Invalid input. Please enter 'Yes' or 'No'.\n");
        }
    }

    while (1)
    {
        printf("\nEnter a choice:\n");
        printf("1 to print, 2 to search, 3 to create more, -1 to exit:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            readContacts("contactListA2.db");
            break;

        case 2:
            int keyId;
            do
            {
                printf("Search for Employee Id?");
                scanf("%d", &keyId);
            }
            while (keyId < 1 || keyId > 9999);
            if (searchContacts("contactListA2.db", keyId))
            {
                printf("Contact found at index %d.\n", keyId);
            }
            else
            {
                printf("Contact not found.\n");
            }
            break;

        case 3:
            createContacts("contactListA2.db");
            break;

        case -1:
            printf("Exiting\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

        if (choice == -1)
        {
            break;
        }
    }
    return 0;
}

