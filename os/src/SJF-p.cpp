#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "Process.h"
#include "Scheduler.h"
#include "SJF-p.h"
#ifndef INT_MAX
#define INT_MAX 2147483647
#endif
void SJF_p::scheduleProcesses(std::vector<Process> &processes)
{
    int currentTime = 0;
    int n = processes.size();
    std::unordered_map<int, int> remainingTime;
    std::unordered_map<int, bool> isCompleted;
    int completed = 0;

    for (auto &p : processes)
    {
        remainingTime[p.pid] = p.burstTime;
        isCompleted[p.pid] = false;
    }

    // Sort by arrival time
    std::sort(processes.begin(), processes.end(), [](const Process &a, const Process &b)
              { return a.arrivalTime < b.arrivalTime; });

    while (completed < n)
    {
        std::vector<Process *> readyQueue;

        // Get all processes that have arrived and are not completed
        for (auto &p : processes)
        {
            if (p.arrivalTime <= currentTime && !isCompleted[p.pid])
            {
                readyQueue.push_back(&p);
            }
        }

        int minRemaining = INT_MAX;
        Process *currentProcess = nullptr;

        for (auto *p : readyQueue)
        {
            if (remainingTime[p->pid] < minRemaining)
            {
                minRemaining = remainingTime[p->pid];
                currentProcess = p;
            }
        }

        if (currentProcess == nullptr)
        {
            currentTime++;
            continue;
        }

        remainingTime[currentProcess->pid]--;
        currentTime++;

        if (remainingTime[currentProcess->pid] == 0)
        {
            isCompleted[currentProcess->pid] = true;
            completed++;

            currentProcess->completionTime = currentTime;
            currentProcess->turnAroundTime = currentProcess->completionTime - currentProcess->arrivalTime;
            currentProcess->waitingTime = currentProcess->turnAroundTime - currentProcess->burstTime;
        }
    }
}

void SJF_p :: printMetrics(const std::vector<Process> &processes){
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
