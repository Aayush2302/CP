#include <iostream>
#include <vector>
#include <algorithm>
#include "Process.h"
#include "Scheduler.h"
#include "FCFS.h"

void FCFS::scheduleProcesses(std::vector<Process> &processes)
{
    // Sort processes by arrival time
    std::sort(processes.begin(), processes.end(),
              [](const Process &a, const Process &b)
              {
                  return a.arrivalTime < b.arrivalTime;
              });

    int currentTime = 0;

    for (auto &p : processes)
    {
        currentTime = std::max(currentTime, p.arrivalTime);

        std::cout << "[Process " << p.pid << "] Starting at time " << currentTime << "\n";

        p.completionTime = currentTime + p.burstTime;
        p.turnAroundTime = p.completionTime - p.arrivalTime;
        p.waitingTime = p.turnAroundTime - p.burstTime;

        std::cout << "[Process " << p.pid << "] Finished at time " << p.completionTime << "\n";

        currentTime = p.completionTime;
    }
}

void FCFS :: printMetrics(const std::vector<Process> &processes){
    std::cout<<"\nPID\tAT\tBT\tCT\tTAT\tWT\n";

    double totalTAT = 0;
    double totalWT = 0;

    for(const auto &p : processes){
        std::cout << p.pid << "\t" << p.arrivalTime << "\t" << p.burstTime
                  << "\t" << p.completionTime << "\t" << p.turnAroundTime
                  << "\t" << p.waitingTime << "\n";
        
        totalTAT += p.turnAroundTime;
        totalWT += p.waitingTime;
    }
    int n = processes.size();
    std::cout << "\nAverage Turnaround Time: " << totalTAT / n;
    std::cout << "\nAverage Waiting Time: " << totalWT / n;
}
