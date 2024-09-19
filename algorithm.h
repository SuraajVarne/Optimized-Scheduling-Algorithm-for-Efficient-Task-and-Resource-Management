#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>

std::vector<int> topologicalSort(const std::vector<int>& executionTimes, const std::vector<std::vector<int> >& dependencies);

std::vector<std::vector<int> > dynamicProgramming(const std::vector<int>& executionTimes, const std::vector<std::vector<int> >& dependencies, int K);

int backtracking(const std::vector<int>& executionTimes, const std::vector<std::vector<int> >& dp, int n, int K, std::vector<int>& schedule);

int minExecutionTime(const std::vector<int>& executionTimes, const std::vector<std::vector<int> >& dependencies, int K);

#endif // ALGORITHM_H
