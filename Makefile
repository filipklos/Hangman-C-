build:
	clang++ -std=c++11 draw.cpp functions.cpp game.cpp picker.cpp playerInserts.cpp writeToFile.cpp main.cpp -o wisielec

run:
	./wisielec