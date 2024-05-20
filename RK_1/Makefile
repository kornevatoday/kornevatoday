all : main.o tests.o test_tasks_rk1.o tasks_rk1.o
	g++ main.cpp tests.cpp test_tasks_rk1.cpp tasks_rk1.cpp -g


main.o : main.cpp
	g++ -c main.cpp -g

tests.o : tests.cpp
	g++ -c tests.cpp -g

test_tasks_rk1.o : test_tasks_rk1.cpp
	g++ -c test_tasks_rk1.cpp -g

tasks_rk1.o : tasks_rk1.cpp
	g++ -c tasks_rk1.cpp -g

clean :
	rm -rf *.o a.out
