all: dequedriver

dequedriver: Deque.cpp dequedriver.cpp
		g++ -std=c++11 -o dequedriver dequedriver.cpp Deque.cpp

run:    dequedriver 
	./dequedriver < test01.in > test01.out
	./dequedriver < test02.in > test02.out
	./dequedriver < test03.in > test03.out
	./dequedriver < test04.in > test04.out

clean:           
	rm  -f dequedriver 