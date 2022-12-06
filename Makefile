all: day1 day2 day2-2 day3 day3-2 day4
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
day4: day4.cc
	g++ -g day4.cc -o day4
	./day4
day5: day5.cc
	g++ -g day5.cc -o day5
	./day5
day5-2: day5-2.cc
	g++ -g day5-2.cc -o day5-2
	./day5-2
.PHONY: all
