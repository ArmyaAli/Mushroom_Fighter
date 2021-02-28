COMPILER=gcc
C_STANDARD= -std=c99
WINDOWS_LIBS= -lopengl32 -lgdi32 -lwinmm -luser32 -lkernel32
INCLUDES= -Iraylib/include/
COMPILER_WARNINGS= -Wno-missing-braces -Wall
SOURCE_FILES= src/main.c src/menu.c src/player.c src/game.c src/lifecycle.c

build:
	$(COMPILER) $(SOURCE_FILES) -o output/main.exe -O1 $(C_STANDARD) $(COMPILER_WARNINGS) $(INCLUDES) -L raylib/lib/ -lraylib $(WINDOWS_LIBS)
run: build
	./output/main.exe
clean:
	rm -rf output/*.exe output/*.o *.exe *.o