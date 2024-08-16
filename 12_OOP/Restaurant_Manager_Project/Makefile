CC=g++

CFLAGS=-g -Wall -I.

HEADER_DIR = Header
SOURCE_DIR = Source

SOURCES=$(wildcard $(SOURCE_DIR)/*.cpp)       
OBJECTS=$(SOURCES:$(SOURCE_DIR)/%.cpp=$(SOURCE_DIR)/%.o) 

EXECUTABLE=program

all: $(EXECUTABLE) run

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(SOURCE_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Quy tắc dọn dẹp
clean:
	rm -f $(SOURCE_DIR)/*.o $(EXECUTABLE).exe

run: $(EXECUTABLE)
	# Executing Program
	./$(EXECUTABLE)
