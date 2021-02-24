COMPILER=gcc
C_STANDARD= -std=c99
WINDOWS_LIBS= -lopengl32 -lgdi32 -lwinmm -luser32 -lkernel32
INCLUDES= -Isrc/include/ -Iraylib/include/
COMPILER_WARNINGS= -Wno-missing-braces -Wall

build:
	$(COMPILER) src/main.c -o output/main.exe -O1 $(C_STANDARD) $(COMPILER_WARNINGS) $(INCLUDES) -L raylib/lib/ -lraylib $(WINDOWS_LIBS)
run: build
	./output/main.exe
clean:
	rm -rf output/*.exe output/*.o *.exe *.o