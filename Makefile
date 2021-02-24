build:
	gcc src/main.c -o output/main.exe -O1 -Wall -std=c99 -Wno-missing-braces -I src/include/ -I raylib/include/ -L raylib/lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
run: build
	./output/main.exe
clean:
	rm -rf output/*.exe output/*.o *.exe *.o