#include <stdio.h>
#include <string.h>
#include <stdlib.h>

        struct phonebook 
    {
          char name [10] ;
          char surname [10];
          char phone [10];
    };

    FILE *file;

////////////////////////////////////////////////////////////////////////////////////////
                           // MAIN//
////////////////////////////////////////////////////////////////////////////////////////

void main()
{
    struct phonebook *PB;

    int menu_item = 0;           
    int n = 0;                    // количество абонентов  + 1(заголовок таблицы)

///////////////////////////////////////////////////////////////////
    void print_menu()
    {
        printf("\n1. Add the subscriber \n2. Remove the subscriber \n3. Bring subscribers"); 
        printf("\n4. Search of the subscriber by name \n5. Save \n6. Exit\n\n");
    };
//////////////////////////////////////////////////////////////////

    int input_menu()
    {
        int temp;
        printf("Enter point menu: ");
        scanf("%d", &temp);
        return temp;
    };
 //////////////////////////////////////////////////////////////////// 
   

    void add (struct phonebook *p)
    {
        strcpy(p->name, "Name");
        strcpy(p->surname, "Surname");
        strcpy(p->phone ,"Phone");
    }
///////////////////////////////////////////////////////////


    void add_subscriber (struct phonebook *p)
    {
        printf("\nName: ");
        scanf("%s", p->name);
        printf("Surname: ");
        scanf("%s", p->surname);
        printf("Phone: ");
        scanf("%s", p->phone);

    }
////////////////////////////////////////////////////////////

    void remov_sub (struct phonebook *p0, struct phonebook *p1, char name[])
    {
        struct phonebook p_temp;

     	if (strcmp (p0->name, name)==0)
    	{
            p_temp = *p0;
            *p0 = *p1;
            *p1 = p_temp;
        }
        else{} ;      
    }
//////////////////////////////////////////////////////////


    int name (struct phonebook *p, char name_input[])
    {   
        int count = 0;
              
        if (strcmp (p->name, name_input)==0)
           {count++;
            printf("%s %s %s\n", p->name, p->surname, p->phone); 
           }
        else 
        return count;
     }
/////////////////////////////////////////////////////////////////////

    //PB = malloc(30*(n+1));
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
    add(&PB[0]);



    do
    {

        print_menu ();

      //  printf("\nN = %d\n", n);
        menu_item=input_menu();
        //printf ("%d\n", menu_item);

       switch(menu_item)
       {
           ///////////////////////////////////////////////////////Add the subscriber 
            case 1:                                               
                 printf("\nAdd the subscriber: \n");
                 n++;
                 PB = realloc(PB, (n)*sizeof(struct phonebook));
                 add_subscriber(&PB[n-1]);
            break;

           //////////////////////////////////////////////////////Remove the subscriber
            case 2:                                               
                 printf("\nRemove the subscriber\n");
                 PB = realloc(PB, (n+1)*sizeof(struct phonebook));

                 int count_name_remove = 0;
                 char remove_name[10];

                 scanf("%s", remove_name);
                 
                 for (int i=1; i < n; i++)
                 {
                     remov_sub (&PB[i], &PB[i+1], remove_name);
                     count_name_remove++;
                 }

                 if (count_name_remove == 0)
                 {
                     printf("\nSubscriber is absent\n");
                 }
                 else 
                 {   //remov_sub (&PB[n+1]);
                     n--;
                     PB = realloc(PB, (n)*sizeof(struct phonebook));
                 }
            break;

            ///////////////////////////////////////////////////////////Bring subscribers
            case 3:                                               
                 printf("\nAll subscribers:\n");
                 for (int i=0; i < n; i++)
                 {
                     printf("%s %s %s\r\n", PB[i].name, PB[i].surname, PB[i].phone);
                 }
            break;

            ///////////////////////////////////////////////Search of the subscriber by name
            case 4:                                              
                 printf("\nSearch of the subscriber by name\n");

                 int count_name_search = 0;
                 char search_name[10];

                 scanf("%s", search_name);

                 for (int i=0; i <= n; i++)
                 {
                     count_name_search = count_name_search + name (&PB[i], search_name);
                 }

                 if (count_name_search == 0)
                    printf("\nSubscriber is absent\n");
            break;

            ////////////////////////////////////////////////////////////////////////////Save
            case 5:                                               
                 printf("\nSave phonebook\n");
                 file = fopen("phonebook.txt", "w");


                 for (int i=1; i < n; i++)
                 {
                    fprintf(file, "%s  %s  %s\n", PB[i].name, PB[i].surname, PB[i].phone);
                 }
                 fclose(file);
            break;

            ////////////////////////////////////////////////////////////////////////////Exit
            case 6:                                               
                 printf("\nExit\n");
            break;
            default:
                 printf("\nincorrect menu item\n");
        }
    }
    while (menu_item != 6);

    return ;
}