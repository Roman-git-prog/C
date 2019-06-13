#include <stdio.h>
          
extern int n, menu_item;  
 
struct phonebook 
{
    char name [10] ;
    char surname [10];
    char phone [10];
}*PB, temp_PB;

FILE *file;

void Read_file_phonebook();

void print_menu();

int input_menu();

void Add_sub();

void Remove_sub();

void Bring_sub();

void Search_sub();

void Save_file_phonebook();

