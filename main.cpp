#include <iostream>
#include <vector>
#include "algorithm.h"

using namespace std;

int main() {
    // Define the input instance
    int n = 3; // Number of jobs
    int K = 2; // Number of machines
    
    // Initialize executionTimes vector
    vector<int> executionTimes = {3, 5, 2}; // Corrected initialization

    // Initialize dependencies vector
    vector<vector<int>> dependencies = {{}, {0}, {0}}; // Corrected initialization

    // Calculate minimum execution time
    int minTime = minExecutionTime(executionTimes, dependencies, K);

    // Output the result
    cout << "Minimum Execution Time: " << minTime << endl;

    return 0;
}
