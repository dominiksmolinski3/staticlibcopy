CC = gcc
AR = ar
CFLAGS = -Wall
LIB_NAME = libcopy.a
SRC_COPY = copy.c
SRC_MAIN = main.c
OBJ_COPY = copy.o
OBJ_MAIN = main.o
HEADERS = copy.h

.PHONY: all clean

all: main

# create static library
$(LIB_NAME): $(OBJ_COPY)
	$(AR) rcs $(LIB_NAME) $(OBJ_COPY)

# compile the copying function
$(OBJ_COPY): $(SRC_COPY) $(HEADERS)
	$(CC) $(CFLAGS) -c $(SRC_COPY)

# compile the main program and link it with the static library
main: $(OBJ_MAIN) $(LIB_NAME)
	$(CC) $(CFLAGS) -o main $(OBJ_MAIN) -L. -lcopy

# compile the main.o file
$(OBJ_MAIN): $(SRC_MAIN) $(HEADERS)
	$(CC) $(CFLAGS) -c $(SRC_MAIN)

# clean the build files
clean:
	rm -f $(OBJ_MAIN) $(OBJ_COPY) $(LIB_NAME) main
