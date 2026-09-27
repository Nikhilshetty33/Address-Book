#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
//#include "populate.h"

void listContacts(AddressBook *addressBook) 
{
    int i;

    printf("\nList of Contacts:\n");

    for(i = 0; i < addressBook->contactCount; i++)
    {
        printf("\nContact %d\n", i + 1);

        printf("Name  : %s\n", addressBook->contacts[i].name);
        printf("Phone : %s\n", addressBook->contacts[i].phone);
        printf("Email : %s\n", addressBook->contacts[i].email);
    }
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
    char name[50];
    char phone[20];
    char email[50];
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
        printf("Name must contain at least 2 characters\n");
        return;
    }

    for(i = 0; name[i] != '\0'; i++)
    {
        if(!((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z') || name[i] == ' '))
        {
            printf("Name must contain only alphabets and spaces\n");
            return;
        }
    }

    printf("Name is valid: %s\n", name);

    printf("Enter phone number: ");
    scanf(" %[^\n]", phone);

    count = 0;

    for(i = 0; phone[i] != '\0'; i++)
    {
        if(phone[i] >= '0' && phone[i] <= '9')
        {
            count++;
        }
        else
        {
            printf("Phone number must contain only digits\n");
            return;
        }
    }

    if(count != 10)
    {
        printf("Phone number must contain exactly 10 digits\n");
        return;
    }

    printf("Phone number is valid: %s\n", phone);

    printf("Enter email: ");
    scanf(" %[^\n]", email);

    int at = 0;
    int dot = 0;

    for(i = 0; email[i] != '\0'; i++)
    {
        if(email[i] == '@')
        {
            at++;
        }

        if(email[i] == '.')
        {
            dot++;
        }
    }

    if(at != 1)
    {
        printf("Email must contain exactly one @\n");
        return;
    }

    if(dot == 0)
    {
        printf("Email must contain a dot\n");
        return;
    }

    printf("Email is valid: %s\n", email);

    strcpy(addressBook->contacts[addressBook->contactCount].name, name);

    strcpy(addressBook->contacts[addressBook->contactCount].phone, phone);

    strcpy(addressBook->contacts[addressBook->contactCount].email, email);

    addressBook->contactCount++;

    printf("Contact added successfully!\n");
}

void searchContact(AddressBook *addressBook) 
{
    //* Define the logic for search */
}
void editContact(AddressBook *addressBook)
{
	//* Define the logic for Editcontact */
}   
void deleteContact(AddressBook *addressBook)
{
	//* Define the logic for deletecontact */
}  

