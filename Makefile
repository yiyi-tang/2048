FLAGS = -pedantic-errors -std=c++11

printTiles.o: printTiles.cpp printTiles.h
	g++ $(FLAGS) -c $<

random.o: random.cpp random.h
	g++ $(FLAGS) -c $<

store.o: store.cpp store.h node.h
	g++ $(FLAGS) -c $<

slide.o: slide.cpp slide.h
	g++ $(FLAGS) -c $<

equal.o: equal.cpp equal.h node.h
	g++ $(FLAGS) -c $<

merge.o: merge.cpp merge.h
	g++ $(FLAGS) -c $<

undo.o: undo.cpp node.h undo.h printTiles.h
	g++ $(FLAGS) -c $<

fail.o: fail.cpp fail.h
	g++ $(FLAGS) -c $<

main.o: main.cpp node.h printTiles.h random.h store.h slide.h equal.h merge.h undo.h fail.h
	g++ $(FLAGS) -c $<

main: main.o printTiles.o random.o store.o slide.o equal.o merge.o undo.o fail.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -rf *.o main

tar:
	tar -czvf main.zip *.cpp *.h

.PHONY: clean tar
