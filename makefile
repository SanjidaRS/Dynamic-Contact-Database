myContacts: contacts.o createContacts.o readContacts.o searchContacts.o
	gcc -Wall -std=c99 contacts.o createContacts.o readContacts.o searchContacts.o -o bin/myContacts

contacts.o: src/contacts.c include/given.h
	gcc -Wall -std=c99 -c src/contacts.c -Iinclude

createContacts.o: src/createContacts.c include/given.h
	gcc -Wall -std=c99 -c src/createContacts.c -Iinclude

readContacts.o: src/readContacts.c include/given.h
	gcc -Wall -std=c99 -c src/readContacts.c -Iinclude

searchContacts.o: src/searchContacts.c include/given.h
	gcc -Wall -std=c99 -c src/searchContacts.c -Iinclude

clean:
	rm -f *.o bin/myContacts
