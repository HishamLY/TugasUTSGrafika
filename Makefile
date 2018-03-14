build:
	g++ -o main main.cpp ./lib/warna.cpp ./lib/matriks.cpp ./lib/word.cpp ./lib/point.cpp ./lib/framebuffer.cpp -Wno-narrowing --std=c++11 -pthread -lncurses
	# g++ -o main main.cpp -Wno-narrowing --std=c++11 -pthread -lncurses
run:
	sudo ./main
clean:
	rm main
