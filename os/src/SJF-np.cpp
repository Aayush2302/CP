#include <iostream>
#include <vector>
#include <algorithm>
#include "Process.h"
#include "Scheduler.h"
#include "SJF-np.h"


    void SJF_np :: scheduleProcesses(std::vector<Process> &processes)
    {
        std::sort(processes.begin(), processes.end(),
                  [](const Process &a, const Process &b)
                  {
                      return a.burstTime < b.burstTime;
                  });

        int currentTime = 0;

        for(auto &p : processes)
        {
            currentTime = std::max(currentTime, p.arrivalTime);
            p.completionTime = currentTime + p.burstTime;
            p.turnAroundTime = p.completionTime - p.arrivalTime;
            p.waitingTime = p.turnAroundTime - p.burstTime;
            currentTime = p.completionTime;
        }
    }

    void SJF_np :: printMetrics(const std::vector<Process> &processes){
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

