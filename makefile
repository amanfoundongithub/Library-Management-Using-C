# Compiler and flags
CC = gcc
CFLAGS = -g

# Directories
BOOK_DIR = ./book
USER_DIR = ./user
UTILS_DIR = ./utils

# Source and object files
SRC_FILES = main.c \
            $(BOOK_DIR)/book.c $(BOOK_DIR)/book_def.c $(BOOK_DIR)/print_book.c ${BOOK_DIR}/book_db.c\
            $(USER_DIR)/print_user.c $(USER_DIR)/user.c $(USER_DIR)/user_db.c $(USER_DIR)/userdef.c $(USER_DIR)/user_operations.c \
            $(UTILS_DIR)/utils.c

OBJ_FILES = $(SRC_FILES:.c=.o)

# Executable name
TARGET = main

# Default rule
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(TARGET)

# Pattern rule to compile each .c file to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ_FILES) $(TARGET)

.PHONY: all clean
