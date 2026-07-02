//CS480 2026 Summer Term
//Assignment 3 - Disk Arm -sim arm.cpp file 

//Team Members:
//1. Aayush Talati, class account: cssc3161
//2. Sparsh Mody, class account: cssc3001

//Account used for testing:
//cssc3161

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

const int MIN_CYLINDER = 0;
const int MAX_CYLINDER = 999;
const int START_CYLINDER = 0;

/*
 * First-Come, First-Served disk scheduling.
 * Services requests in the same order they arrive.
 */
int fcfs(const vector<int>& requests) {
    int totalDistance = 0;
    int current = START_CYLINDER;

    for (int request : requests) {
        totalDistance += abs(request - current);
        current = request;
    }

    return totalDistance;
}

/*
 * Shortest Seek First disk scheduling.
 * Always services the closest pending request.
 */
int ssf(const vector<int>& requests) {
    vector<int> pending = requests;
    int totalDistance = 0;
    int current = START_CYLINDER;

    while (!pending.empty()) {
        int closestIndex = 0;
        int closestDistance = abs(pending[0] - current);

        for (int i = 1; i < (int)pending.size(); i++) {
            int distance = abs(pending[i] - current);

            if (distance < closestDistance) {
                closestDistance = distance;
                closestIndex = i;
            }
        }

        totalDistance += closestDistance;
        current = pending[closestIndex];

        pending.erase(pending.begin() + closestIndex);
    }

    return totalDistance;
}

/*
 * Elevator / SCAN disk scheduling.
 * Starts moving upward, services all requests above the current position,
 * then reverses direction and services lower requests.
 */
int elevator(const vector<int>& requests) {
    vector<int> sorted = requests;
    sort(sorted.begin(), sorted.end());

    int totalDistance = 0;
    int current = START_CYLINDER;

    vector<int> lower;
    vector<int> higher;

    for (int request : sorted) {
        if (request >= current) {
            higher.push_back(request);
        } else {
            lower.push_back(request);
        }
    }

    // Move upward first
    for (int request : higher) {
        totalDistance += abs(request - current);
        current = request;
    }

    // Then move downward
    for (int i = (int)lower.size() - 1; i >= 0; i--) {
        totalDistance += abs(lower[i] - current);
        current = lower[i];
    }

    return totalDistance;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: simarm <sequence_length>" << endl;
        return 1;
    }

    int length = atoi(argv[1]);

    if (length <= 0) {
        cerr << "Error: sequence_length must be a positive integer." << endl;
        return 1;
    }

    srand(time(nullptr));

    vector<int> requests;

    for (int i = 0; i < length; i++) {
        int cylinder = rand() % (MAX_CYLINDER + 1);
        requests.push_back(cylinder);
    }

    cout << "Generated sequence:" << endl;
    for (int request : requests) {
        cout << request << " ";
    }
    cout << endl << endl;

    cout << "FCFS total distance: " << fcfs(requests) << endl;
    cout << "SSF total distance: " << ssf(requests) << endl;
    cout << "Elevator total distance: " << elevator(requests) << endl;

    return 0;
}
