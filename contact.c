#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on the choosen criteria

}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
void createContact(AddressBook *addressBook)
{
    char name[50];
    int i, count = 0;

    printf("Enter the name: ");
    scanf(" %[^\n]", name);

    for(i = 0; name[i] != '\0'; i++)
    {
        if(name[i] != ' ')
        {
            count++;
        }
    }

    if(count < 2)
    {
        printf("Error: Name must contain at least 2 characters\n");
        return;
    }

    for(i = 0; name[i] != '\0'; i++)
    {
        if(!((name[i] >= 'A' && name[i] <= 'Z') ||
             (name[i] >= 'a' && name[i] <= 'z') ||
             name[i] == ' '))
        {
            printf("Error: Name must contain only alphabets and spaces\n");
            return;
        }
    }
    printf("Name is valid: %s\n", name);
}
    
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
   
}
