#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Read_file_phonebook()
{
    PB = malloc((n+1)*sizeof(struct phonebook));
    file = fopen("phonebook.txt", "r");
    if (file == NULL)
    {
        printf("\nPhonebook is not found\n");
        system("touch phonebook.txt");
        file = fopen("phonebook.txt", "r");
        printf("Phonebook is created and open\n");
    }
    else printf("\nPhonebook is open\n");

    do
    {
        n++;
        PB = realloc(PB, (n+1)*sizeof(struct phonebook));
    }while(fscanf(file, "%s%s%s", PB[n].name, PB[n].surname, PB[n].phone)  != EOF);

    fclose(file);

    strcpy(PB->name, "Name");
    strcpy(PB->surname, "Surname");
    strcpy(PB->phone ,"Phone");
}
//////////////////////////////////////////////////////////////////////////////////////////

void print_menu()
{
    printf("\n1. Add the subscriber \n2. Remove the subscriber \n3. Bring subscribers"); 
    printf("\n4. Search of the subscriber by name \n5. Save \n6. Exit\n\n");
}
//////////////////////////////////////////////////////////////////////////////////////////

int input_menu()
{
    int temp;
    printf("Enter point menu: ");
    scanf("%d", &temp);
    return temp;
}
//////////////////////////////////////////////////////////////////////////////////////////

void Add_sub()
{
    printf("\nAdd the subscriber: \n");
    n++;
    PB = realloc(PB, (n)*sizeof(struct phonebook));
    printf("\nName: ");
    scanf("%s", PB[n-1].name);
    printf("Surname: ");
    scanf("%s", PB[n-1].surname);
    printf("Phone: ");
    scanf("%s", PB[n-1].phone);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Remove_sub()
{
    PB = realloc(PB, (n+1)*sizeof(struct phonebook));

    int count_name_remove = 0;
    char remove_name[10];

    scanf("%s", remove_name);
                 
    for (int i=1; i < n; i++)
    {
        if (strcmp (PB[i].name, remove_name)==0)
        {
            strcpy(temp_PB.name, PB[i].name);
            strcpy(temp_PB.surname,PB[i].surname);
            strcpy(temp_PB.phone , PB[i].phone);
              
            strcpy(PB[i].name, PB[i+1].name);
            strcpy(PB[i].surname,PB[i+1].surname);
            strcpy(PB[i].phone , PB[i+1].phone);

            strcpy(PB[i+1].name, temp_PB.name);
            strcpy(PB[i+1].surname,temp_PB.surname);
            strcpy(PB[i+1].phone , temp_PB.phone);

            count_name_remove++;
        }
    }

    if (count_name_remove == 0)
    {
        printf("\nSubscriber is absent\n");
    }
    else 
    {
        n--;
        PB = realloc(PB, (n)*sizeof(struct phonebook));
    }  
}
//////////////////////////////////////////////////////////////////////////////////////////

void Bring_sub()
{
    printf("\nAll subscribers:\n");
    for (int i=0; i < n; i++)
    {
        printf("%s %s %s\r\n", PB[i].name, PB[i].surname, PB[i].phone);
    }  
}
//////////////////////////////////////////////////////////////////////////////////////////

void Search_sub()
{
    printf("\nSearch of the subscriber by name\n");

    int count_name_search = 0;
    char search_name[10];
    int count = 0;

    scanf("%s", search_name);

    for (int i=0; i <= n; i++)
    {
        if (strcmp (PB[i].name, search_name)==0)
           {count++;
            printf("%s %s %s\n", PB[i].name, PB[i].surname, PB[i].phone);
           }
        else 
            count_name_search = count_name_search + count;
    }

    if (count_name_search == 0)
    printf("\nSubscriber is absent\n");
}
//////////////////////////////////////////////////////////////////////////////////////////

void Save_file_phonebook()
{
    printf("\nSave phonebook\n");
    file = fopen("phonebook.txt", "w");


    for (int i=1; i < n; i++)
    {
        fprintf(file, "%s  %s  %s\n", PB[i].name, PB[i].surname, PB[i].phone);
    }
    fclose(file);
}
//////////////////////////////////////////////////////////////////////////////////////////              
