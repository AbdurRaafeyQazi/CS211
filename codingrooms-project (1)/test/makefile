CC = gcc
CFLAGS = -g
TARGET = test
EXEC = $(TARGET).exe

# Build the executable
build:
	rm -f $(EXEC)
	$(CC) $(TARGET).c -o $(EXEC)

# Run the program
run:
	./$(EXEC)

# Valgrind for memory checking
valgrind:
	rm -f $(EXEC)
	$(CC) $(CFLAGS) $(TARGET).c -o $(EXEC)
	valgrind -s --tool=memcheck --leak-check=yes --track-origins=yes ./$(EXEC) -f

# Debug using GDB
debug:
	rm -f $(EXEC)
	$(CC) $(CFLAGS) $(TARGET).c -o $(EXEC)
	gdb ./$(EXEC)

# Clean up generated files
clean:
	rm -f $(EXEC)
