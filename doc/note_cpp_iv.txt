#include <chrono>
taskStart = std::chrono::high_resolution_clock::now();
//do something here
taskEnd = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> elapsed_seconds_task = taskEnd - taskStart;
