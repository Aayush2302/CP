#include <bits/stdc++.h>

// Process class
class Process
{
public:
    int pid;
    int arrivalTime;
    int burstTime;
    int priority;
    int completionTime;
    int waitingTime;
    int turnAroundTime;

    Process(int pid, int at, int bt, int p = 0)
        : pid(pid), arrivalTime(at), burstTime(bt), priority(p),
          completionTime(0), waitingTime(0), turnAroundTime(0) {}
};

// Abstract Base Scheduler class
class Scheduler
{
public:
    virtual void scheduleProcesses(std::vector<Process> &processes) = 0;
    virtual void printMetrics(const std::vector<Process> &processes) = 0;
    virtual ~Scheduler() {}
};

// FCFS Scheduler derived class
class FCFS_Scheduler : public Scheduler
{
public:
    void scheduleProcesses(std::vector<Process> &processes) override
    {
        std::sort(processes.begin(), processes.end(),
                  [](const Process &a, const Process &b)
                  {
                      return a.arrivalTime < b.arrivalTime;
                  });

        int currentTime = 0;
        for (auto &p : processes)
        {
            currentTime = std::max(currentTime, p.arrivalTime);
            p.completionTime = currentTime + p.burstTime;
            p.turnAroundTime = p.completionTime - p.arrivalTime;
            p.waitingTime = p.turnAroundTime - p.burstTime;
            currentTime = p.completionTime;
        }
    }

    void printMetrics(const std::vector<Process> &processes) override
    {
        std::cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
        for (const auto &p : processes)
        {
            std::cout << p.pid << "\t" << p.arrivalTime << "\t" << p.burstTime
                      << "\t" << p.completionTime << "\t" << p.turnAroundTime
                      << "\t" << p.waitingTime << "\n";
        }
    }
};

class SJF_non_pre : public Scheduler
{
public:
    void scheduleProcesses(std::vector<Process> &processes) override
    {
        std::sort(processes.begin(), processes.end(),
                  [](const Process &a, const Process &b)
                  {
                      return a.burstTime < b.burstTime;
                  });

        int currentTime = 0;

        for (auto &p : processes)
        {
            currentTime = std::max(currentTime, p.arrivalTime);
            p.completionTime = currentTime + p.burstTime;
            p.turnAroundTime = p.completionTime - p.arrivalTime;
            p.waitingTime = p.turnAroundTime - p.burstTime;
            currentTime = p.completionTime;
        }
    }
    void printMetrics(const std::vector<Process> &processes) override
    {
        std::cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
        for (const auto &p : processes)
        {
            std::cout << p.pid << "\t" << p.arrivalTime << "\t" << p.burstTime
                      << "\t" << p.completionTime << "\t" << p.turnAroundTime
                      << "\t" << p.waitingTime << "\n";
        }
    }
};

class SJF_Preemptive : public Scheduler
{
public:
    int currentTime = 0;

    void scheduleProcesses(std::vector<Process> &processes) override
    {
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

        currentTime = 0;

        while (completed < n)
        {
            std::vector<Process *> readyQueue;

            // Get all processes that have arrived and are not completed
            for (auto &p : processes)
            {
                if (p.arrivalTime <= currentTime && !isCompleted[p.pid])
                {
                    readyQueue.push_back(&p); // push pointer to process
                }
            }

            int minPid = -1;
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

            // 🛠 This part now works because currentProcess is in scope
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
    void printMetrics(const std::vector<Process> &processes) override
    {
        std::cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
        for (const auto &p : processes)
        {
            std::cout << p.pid << "\t" << p.arrivalTime << "\t" << p.burstTime
                      << "\t" << p.completionTime << "\t" << p.turnAroundTime
                      << "\t" << p.waitingTime << "\n";
        }
    };
};


int main()
{
    std::vector<Process> processes = {
        Process(1, 0, 5),
        Process(2, 1, 3),
        Process(3, 2, 8)};

    Scheduler *scheduler = new SJF_Preemptive();
    scheduler->scheduleProcesses(processes);
    scheduler->printMetrics(processes);

    delete scheduler;
    return 0;
}
