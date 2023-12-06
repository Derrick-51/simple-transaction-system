all: test/linked-list-menu-test.out test/linked-list-test.out

test/build/linked-list-menu-test.out: intermediates/linked-list-menu-test.o intermediates/linked-list.o
	gcc -o test/build/linked-list-menu-test.out intermediates/linked-list-menu-test.o intermediates/linked-list.o

test/build/linked-list-test.out: intermediates/linked-list-test.o intermediates/linked-list.o
	gcc -o test/build/linked-list-test.out intermediates/linked-list-test.o intermediates/linked-list.o

intermediates/linked-list-menu-test.o: test/linked-list-menu-test.c
	gcc -c test/linked-list-menu-test.c -o intermediates/linked-list-menu-test.o

intermediates/linked-list-test.o: test/linked-list-test.c
	gcc -c test/linked-list-test.c -o intermediates/linked-list-test.o

intermediates/linked-list.o: src/linked-list.c
	gcc -c src/linked-list.c -o ./intermediates/linked-list.o

test/linked-list-menu-test.c:

test/linked-list-test.c:

src/linked-list.c:
