CS480 Summer 2026 Term
Assignment 3 - Diskarm 

README

Team Members:
1. Aayush Talati, class account: cssc3161
2. Sparsh Mody, class account: cssc3001

Account used for testing:
cssc3161 - Aayush Talati

File Manifest:
README: contains all the project instructions and the description of it
simarm.cpp: has all the logic for the three disk arm scheduling algorithms (FCFS, SSF, Elevator/SCAN). It is also main source file
Makefile: This contains the build instructions for being able to execute simarm

Compiling Instructions: 
1. use "make" to compile the project
2. "simarm" is the executable that gets created
3. "make clean" removes all of the files generated

Operating Instructions: The program requires one command line argument
1. you can run the program by calling "./simarm <sequence_length>", where sequence_length is a positive integer
2. example: "./simarm 64"
The program will now:
1. Generate a random sequence of "sequence_length" cylinder numbers, each between 0 and 999
2. Print the generated sequence to the console
3. Run the FCFS algorithm on the sequence and print the total seek distance
4. Run the SSF algorithm on the sequence and print the total seek distance
5. Run the Elevator (SCAN) algorithm on the sequence and print the total seek distance
6. The program finishes and exits

Design Decisions:
1. The arm starts the cylinder at 0 for all 3 of the algorithms so you can direcrtly compare the results
2. SSF is implemented by repeatedly scanning remaining pending requests and selecting closest one to the arm's current position. Removes it from the pending list once serviced
3. Elevator is implemented by sorting all requests. Split them into those at or above the current position and those below it, servicing the "above" group in increasing order first, then reversing direction to service the "below" group in decreasing order
4. All three algorithms operate on a copy of the original request vector where needed (SSF, Elevator) so the original generated sequence is left unmodified for consistent reporting

No eextra features that weren't required
We are not aware of any known bugs for this 

Lessons Learned:
1. We learned how different disk scheduling strategies trade off total seek distance versus fairness and starvation risk
2. We learned that SSF can starve requests far from the arm's current position, while Elevator bounds worst-case wait time at the cost of sometimes higher total distance than SSF
3. We practiced structuring a small C++ program with clearly separated, independently testable functions for each algorithm, sharing a single generated dataset for fair comparison
