#######################################################################################################
#                                                                                                     #
# Author: Ali Umar                                                                                    #
# Date: July 8, 2023                                                                                  # 
# Some build scripts & utilities for this Mushroom Fighter game.							          # 
# Please note I am a windows user and don't intend on switching to linux fully.                       # 
# lol. Default shell will be cmd.exe. I will be primarily using Raylib for                            # 
# graphics.                                                                                           #	
#                                                                                                     #
#######################################################################################################

SHELL       :=  cmd

BUILD_DIR   :=  build
SRC_DIR     :=  src

COMPILER    :=  gcc 
OS_LIBS     := -lgdi32 -lwinmm -lopengl32
INC_DIR     := -Iinclude -Iinclude\raylib
LIB_DIR     := -Llib
STATIC_LIBS := -static -lraylib

SRC_FILES   :=   src\main.c    $\
				 src\logger.c 

run : build
	@build\main

build : setup
	@gcc $(SRC_FILES) $(LIB_DIR) $(STATIC_LIBS) $(OS_LIBS) $(INC_DIR) -o $(BUILD_DIR)\main.exe 

setup : 
	@IF NOT EXIST $(BUILD_DIR) ( MKDIR $(BUILD_DIR) ) 
	@IF NOT EXIST log ( MKDIR log ) 

clean :
	@IF NOT EXIST $(BUILD_DIR) ( ECHO Nothing to clean. ) 
	@IF EXIST $(BUILD_DIR) ( RMDIR /s /q $(BUILD_DIR) & ECHO Successfully deleted build directory. ) 
	
