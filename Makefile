CC=gcc
C_STANDARD= -std=c99
WINDOWS_LIBS= -lopengl32 -lgdi32 -lwinmm -luser32 -lkernel32  
INCLUDES= -Iraylib/include/
COMPILER_WARNINGS= -Wno-missing-braces -Wall
# -LDirectory -lFile.a
LINKER_FLAGS= -LC:/Development/mingw32/i686-w64-mingw32/lib -lws2_32 -Lraylib/lib/ -lraylib
# SOURCE_FILES= src/main.c src/menu.c src/player.c src/game.c src/lifecycle.c
SOURCE_FILES= src/main.c 

build:
	$(CC) $(SOURCE_FILES) -o output/main.exe -O1 $(C_STANDARD) $(COMPILER_WARNINGS) $(INCLUDES) $(LINKER_FLAGS) $(WINDOWS_LIBS)
run: build
	./output/main.exe
clean:
	rm -rf output/*.exe output/*.o *.exe *.o