#include <stdio.h>
#include <string.h>




        struct phonebook 
    {
          char name [10] ;
          char surname [10];
          char phone [10];
    };






////////////////////////////////////////////////////////////////////////////////////////
                           // MAIN//
////////////////////////////////////////////////////////////////////////////////////////

void main()
{

    int menu_item = 0;
    int namber_subscribers = 1;
    int n = 0;
    int m = 255;

    struct phonebook PB[m], temp_PB;

///////////////////////////////////////////////////////////////////
    void print_menu()
    {
    	
		printf("\n1. Add the subscriber \n2. Remove the subscriber \n3. Bring subscribers \n4. Search of the subscriber by name \n5. Exit\n\n");

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


    void remov_sub (struct phonebook *p)
    {
    	strcpy(p->name, "");
        strcpy(p->surname, "");
        strcpy(p->phone ,"");
     }
//////////////////////////////////////////////////////////


    int name (struct phonebook *p, char name_input[])
    {   
    	int count = 0;
              
    	if (strcmp (p->name, name_input)==0)
           {count++;
    	    printf("%s %s %s\n", p->name, p->surname, p->phone); 
    	   }
        else ;
        
        return count;
     }
/////////////////////////////////////////////////////////////////////
  


    add(&PB[0]);


   

    do
    {

        print_menu ();
        menu_item=input_menu();

       switch(menu_item)
       {
           ///////////////////////////////////////////////////////Add the subscriber 
           case 1:                                               
                 printf("\nAdd the subscriber: \n");
                 n++;
                 add_subscriber(&PB[n]);

            break;


           //////////////////////////////////////////////////////Remove the subscriber
           case 2:                                               
                 printf("\nRemove the subscriber\n");

                 int count_name_remove = 0;

                 char remove_name[10];

                 scanf("%s", remove_name);

                 
                 for (int i=0; i <= n; i++)
                 {
                 	 if (strcmp (PB[i].name, remove_name)==0)
    	             {

    	             	temp_PB = PB[i];
    	             	PB[i] = PB[i+1];
    	             	PB[i+1] = temp_PB;
                        count_name_remove++;

    	             };

    	         }


    	         if (count_name_remove == 0)
    	         {
    	             printf("\nSubscriber is absent\n");
    	         }
    	         else 
    	         {   remov_sub (&PB[n+1]);
    	             n--;
    	         }

            break;


            ///////////////////////////////////////////////////////////Bring subscribers
            case 3:                                               
                 printf("\nAll subscribers:\n");
                 for (int i=0; i <= n; i++)
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


            ////////////////////////////////////////////////////////////////////////////Exit
            case 5:                                               
                 printf("\nExit\n");

            break;

            default:
                 printf("\nincorrect menu item\n");
        }
    }
    while (menu_item != 5);


    return ;
}
