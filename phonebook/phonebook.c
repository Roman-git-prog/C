#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"

#define ADD_SUB 1
#define REMOVE_SUB 2
#define BRING_SUB 3
#define SEARCH_SUB 4
#define SAVE 5
#define EXIT 6


int menu_item = 0;            // номер пункта меню
int n = 0;                    // количество абонентов  + 1(заголовок таблицы)

//////////////////////////////////////////////////////////////////////////////////////////
                           // MAIN//
//////////////////////////////////////////////////////////////////////////////////////////

void main()
{
    Read_file_phonebook();

    do
    {
        print_menu ();
//        printf("\nN = %d\n", n);
        menu_item=input_menu();

        switch(menu_item)
        {
            case ADD_SUB:
                Add_sub();
            break;

            case REMOVE_SUB:
                Remove_sub();
            break;

            case BRING_SUB:
                Bring_sub();                                     
            break;

            case SEARCH_SUB:
                Search_sub();                                              
            break;

            case SAVE:     
                Save_file_phonebook();                                          
            break;

            case EXIT:                                               
                printf("\nExit\n");
            break;

            default:
                printf("\nincorrect menu item\n");
        }
    }
    while (menu_item != EXIT);

    return ;
}