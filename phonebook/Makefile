all: phonebook
#	rm -rf *.o

test_1.o: phonebook.c
		gcc -c phonebook.c

menu.o: menu.c
		gcc -c menu.c

phonebook: phonebook.o menu.o
		gcc -o phonebook phonebook.o menu.o

clean:
	rm -rf *o phonebook

clean_txt:
	rm -rf *txt phonebook