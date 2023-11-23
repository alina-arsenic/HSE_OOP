all:
	g++ *.cpp lab.h

style:
	cppcheck --language=c++ *.cpp *.h
	clang-format -n *.cpp *.h

clean:
	rm -rf a.out *.gch