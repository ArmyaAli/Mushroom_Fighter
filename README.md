# Mushroom_Fighter
Just a small little game I'm working on in my spare time.
## Project Setup
## Prerequisites
- MinGW GCC Compiler https://www.mingw-w64.org/downloads/, ensure you install mingw32-make.exe with the tooling
- Git source control  https://www.mingw-w64.org/downloads/

## Setup
1. Clone the source code and setup project folders
2. Setup your directory structure as follows

                ├───build
                ├───include
                │   └───raylib
                ├───lib
                ├───log
                ├───scripts
                └───src

3. Download latest release of Raylib for raylib-4.5.0_win64_mingw-w64.zip https://github.com/raysan5/raylib/releases/tag/4.5.0
4. Move libraylib.a into lib folder and the files raylib.h, raymath.h and rlgl.h into our include/raylib folder
5. Build & Run the project. I like to setup an alias for my shell to for minfw32-make.exe to make so then I can run

                make # or without aliasing that executable you may run mingw32-make
 