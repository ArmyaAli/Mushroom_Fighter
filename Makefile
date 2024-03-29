#######################################################################################################
#                                                                                                     #
#     Author: Ali Umar                                                                                #
#     Date: July 8, 2023                                                                              #
#     Some build scripts & utilities for this Mushroom Fighter game.							      #
#     Please note I am a windows user and don't intend on switching to linux fully.                   #
#     lol. Default shell will be cmd.exe. I will be primarily using Raylib for                        #
#     graphics. Also I don't care about incremental builds. I am gonna compile every src file         #
#     at the same time every time :)                                                                  #
#                                                                                                     #
#######################################################################################################

SHELL       :=  cmd

BUILD_DIR   :=  build
SRC_DIR     :=  src

COMPILER    :=  gcc 
C_STD		:= -std=c99
OS_LIBS     := -lgdi32 -lwinmm -lopengl32
INC_DIR     := -Iinclude -Iinclude\raylib
LIB_DIR     := -Llib
STATIC_LIBS := -static -lraylib
SRC_FILES   :=  src\main.c        $\
				src\logger.c      $\
				src\render.c      $\
				src\animation.c   

run : build
	@build\main

build : setup
	@gcc $(SRC_FILES) $(LIB_DIR) $(STATIC_LIBS) $(OS_LIBS) $(INC_DIR) $(C_STD) -o $(BUILD_DIR)\main.exe 

setup : 
	@IF NOT EXIST $(BUILD_DIR) ( MKDIR $(BUILD_DIR) ) 
	@IF NOT EXIST log ( MKDIR log ) 

clean :
	@IF NOT EXIST $(BUILD_DIR) ( ECHO Nothing to clean. ) 
	@IF EXIST $(BUILD_DIR) ( RMDIR /s /q $(BUILD_DIR) & ECHO Successfully deleted build directory. ) 
	
