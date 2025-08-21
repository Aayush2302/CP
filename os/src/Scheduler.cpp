#include "Scheduler.h"
#include <iostream>

void Scheduler::printMetrics(const std::vector<Process> &processes)
{
    std::cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for (const auto &p : processes)
    {
        std::cout << p.pid << "\t" << p.arrivalTime << "\t" << p.burstTime << "\t"
                  << p.completionTime << "\t" << p.turnAroundTime << "\t"
                  << p.waitingTime << "\n";
    }
}