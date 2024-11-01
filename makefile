# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Directories
SRC_DIR = .
BOOK_DIR = ./book
USER_DIR = ./user
UTILS_DIR = ./utils

# Source and object files
SRC_FILES = $(SRC_DIR)/main.c \
            $(BOOK_DIR)/book.c $(BOOK_DIR)/book_def.c \
            $(USER_DIR)/print_user.c $(USER_DIR)/user.c $(USER_DIR)/userdef.c $(USER_DIR)/user_operations.c \
            $(UTILS_DIR)/utils.c

OBJ_FILES = $(SRC_FILES:.c=.o)

# Executable name
TARGET = main

# Default rule
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(TARGET)

# Compile each .c file to .o
$(SRC_DIR)/main.o: $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o $(SRC_DIR)/main.o

$(BOOK_DIR)/book.o: $(BOOK_DIR)/book.c $(BOOK_DIR)/book.h
	$(CC) $(CFLAGS) -c $(BOOK_DIR)/book.c -o $(BOOK_DIR)/book.o

$(BOOK_DIR)/book_def.o: $(BOOK_DIR)/book_def.c $(BOOK_DIR)/book.h
	$(CC) $(CFLAGS) -c $(BOOK_DIR)/book_def.c -o $(BOOK_DIR)/book_def.o

$(USER_DIR)/print_user.o: $(USER_DIR)/print_user.c $(USER_DIR)/user.h
	$(CC) $(CFLAGS) -c $(USER_DIR)/print_user.c -o $(USER_DIR)/print_user.o

$(USER_DIR)/user.o: $(USER_DIR)/user.c $(USER_DIR)/user.h
	$(CC) $(CFLAGS) -c $(USER_DIR)/user.c -o $(USER_DIR)/user.o

$(USER_DIR)/userdef.o: $(USER_DIR)/userdef.c $(USER_DIR)/user.h
	$(CC) $(CFLAGS) -c $(USER_DIR)/userdef.c -o $(USER_DIR)/userdef.o

$(USER_DIR)/user_operations.o: $(USER_DIR)/user_operations.c $(USER_DIR)/user.h
	$(CC) $(CFLAGS) -c $(USER_DIR)/user_operations.c -o $(USER_DIR)/user_operations.o

$(UTILS_DIR)/utils.o: $(UTILS_DIR)/utils.c $(UTILS_DIR)/utils.h
	$(CC) $(CFLAGS) -c $(UTILS_DIR)/utils.c -o $(UTILS_DIR)/utils.o

# Clean up build files
clean:
	rm -f $(OBJ_FILES) $(TARGET)

.PHONY: all clean
