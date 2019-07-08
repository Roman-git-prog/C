all: phonebook
#	rm -rf *.o

phonebook.o: phonebook.c
	gcc -c phonebook.c

menu.o: menu.c
	gcc -c menu.c

phonebook: phonebook.o menu.o
	gcc -o phonebook phonebook.o menu.o

start:
	./phonebook

clean:
	rm -rf *o phonebook

clean_txt:
	rm -rf *txt phonebook
