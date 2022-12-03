all: day1 day2 day2-2 day3 day3-2
day1: day1.cc
	g++ -g day1.cc -o day1
	./day1
day2: day2.cc
	g++ -g day2.cc -o day2
	./day2
day2-2: day2-2.cc
	g++ -g day2-2.cc -o day2-2
	./day2-2
day3: day3.cc
	g++ -g day3.cc -o day3
	./day3
day3-2: day3-2.cc
	g++ -g day3-2.cc -o day3-2
	./day3-2
.PHONY: all
