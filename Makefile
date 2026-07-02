#CS480 2026 Summer Term
#Assignment 3 - Disk Arm Makefile

#Team Members:
#1. Aayush Talati, class account: cssc3161
#2. Sparsh Mody, class account: cssc3001

#Account used for testing:
#cssc3161

CC = g++
CFLAGS = -Wall -Wextra -std=c++11
TARGET = simarm

all: $(TARGET)

$(TARGET): simarm.cpp
	$(CC) $(CFLAGS) simarm.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)
