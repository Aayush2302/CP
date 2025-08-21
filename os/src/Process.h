#ifndef PROCESS_H
#define PROCESS_H

class Process {
public:
    int pid;
    int arrivalTime;
    int burstTime;
    int priority;

    int startTime;
    int completionTime;
    int waitingTime;
    int turnAroundTime;

    Process(int pid, int arrivalTime, int burstTime, int priority = 0)
        : pid(pid), arrivalTime(arrivalTime), burstTime(burstTime), priority(priority),
          startTime(-1), completionTime(0), waitingTime(0), turnAroundTime(0) {}
};

#endif