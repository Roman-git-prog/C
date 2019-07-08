#include <ncurses.h>
//#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <termios.h>
//#include <sys/types.h>
//#include <sys/ioctl.h>
//#include <curses.h>

#include <locale.h>

#define min_x 0
#define max_x 79
#define min_y 1
#define max_y 23

#define STRLEN 80             //максимальная длина строки

int n = 1;                   // номер строки на которой стоит курсор

char str[STRLEN];           //строка, которая читается из файла

int top_line_screen = 0;
int lower_line_screen = 24;

int l= 0;
int c = 0;



struct Ed 
{
 char str [80];
 int len;
 
 }  *Nstr; 

FILE *file;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{

setlocale(LC_ALL,"rus");


    int line = 0;          //количество считаных строк из файла

    initscr();
    cbreak();
    raw();
    noecho();
    keypad(stdscr, TRUE);

    getmaxyx(stdscr, l, c); 

/*
struct Ed 
{
 char str [c] ; 
 int len;
 
 }  *Nstr; 

FILE *file;
*/



    Nstr = malloc((n+1)*sizeof(struct Ed));




    if (argc >= 2)
    {
        file = fopen(argv[1], "r");
        while(!feof(file))
        {
        fgets(Nstr[line].str,STRLEN,file);  //читаем из файла по STRLEN байт
        //fgets(Nstr[line].str,c,file);  
        Nstr[line].len = strlen(Nstr[line].str)-1;
        ++line;                            
        Nstr = realloc(Nstr,sizeof(struct Ed)*(line+1));               
        //strcpy(Nstr[i].str, str);
        }
        fclose(file);
//// сюда остальной main
    }
    else
        //if (file == NULL)  a file name at start
    {
        move(11,33); 
        printw("Press F9 for an exit");
        move(12,30); 
        printw("Enter a file name at start");
        //system("touch test_0.txt");
        //file = fopen("test_0.txt", "r+");
        //file = fopen("main.c", "r");

    }










    int x = 0;
    int y = 1;

    //refresh();

    move(y,x);

    for(int j=0; j<23; j++)
    { 
        addstr(Nstr[j].str);
    }
    refresh();

    int temp = 23; // номер строки в файле, соответствующий 
                  // выведеной нижней строке в терминале

    char buf_tmp[81];

    while(1)
    {
               

        move(0,0); 
        printw("EDITORv1.0. (exit F9, save F8)");

        move(0,72);
        printw("col %d  ", x+1);

        move(0,60);
        printw("ln %d/%d  ", n,line-1);
 
        move(0,45);
        printw("long_ln %d  ", Nstr[n-1].len);//temp);
        refresh();

//        move(0,30);
        //strcpy(buf_tmp, Nstr[n-1].str);
//       printw("X %c ", 'a');
//        refresh();

        move(1,0);
        for(int j= temp-23; j< temp; j++)
        { 
            addstr(Nstr[j].str);
        }
        refresh();

        

        int ch = mvgetch(y, x);
        if (ch == KEY_F(9)) break;

        switch (ch) 
        {

            case KEY_DOWN:
                y++;
                n++;
                if (n >= line-1)
                {
                    n = line-1;
                }

                if (y > max_y )
                {
                    y = max_y;
                }
                    
                if (n > temp)
                    {   
                        temp++;
//                        move(1,0);
//                        for(int j= temp-23; j< temp; j++)
//                        { 
//                            addstr(Nstr[j].str);
//                        }
                    }
//                refresh();
            break;
            ///////////////////////////////////////////////

            case KEY_UP:
                y--;
                n--;

                if (n < min_y)
                {
                    n = min_y;
                }

                if (y < min_y)
                {
                    y = min_y;
                }

                if (n <= temp-23)
                    {   
                        temp--;
//                        move(1,0);
//                        for(int j= temp-23; j< temp; j++)
//                        { 
//                            addstr(Nstr[j].str);
//                        }
                    }
//                refresh();
            break;
            ///////////////////////////////////////////////

            case KEY_LEFT:
                x--;
                if (x < min_x)
                {
                    x = max_x;
                }

            break;

            case KEY_RIGHT:
                x++;
                if (x > max_x)
                {
                    x = min_x;
                    
                }

            break;
            ///////////////////////////////////////////////

            case KEY_BACKSPACE:    

                if (Nstr[n-1].len >= x && 0 < x)
                {
                    char temp_symbol;

                    for(int i= x-1; i < Nstr[n-1].len + 1 ; i++)
                    {
                        Nstr[n-1].str[i] = Nstr[n-1].str[i+1];

                    }
                    Nstr[n-1].len = Nstr[n-1].len -1 ;


 //                       move(1,0);
 //                       for(int j= temp-23; j< temp; j++)
 //                       { 
 //                           addstr(Nstr[j].str);
 //                       }

 //                   refresh();
                }
            break;
            /////////////////////////////////////////////////////

            case KEY_F(8):    
                //file = fopen(argv[1], "r");

                file = fopen(argv[1], "w");


                for (int i=0; i < line-1 ; i++)
                {
                    fprintf(file, "%s", Nstr[i].str);
                }
                fclose(file);               

            break;
            ///////////////////////////////////////////////

            default: ;

        }




    }


        
    echo(); 
    keypad(stdscr, FALSE); 
    cbreak(); 
    endwin();
 }