CC = g++
CFLAGS = -Wall -Wextra -std=c++11
TARGET = simarm

all: $(TARGET)

$(TARGET): simarm.cpp
	$(CC) $(CFLAGS) simarm.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)