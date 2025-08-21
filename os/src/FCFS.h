#ifndef FCFS_H
#define FCFS_H

#include "Scheduler.h"
#include <thread>
#include <chrono>
#include <algorithm>

class FCFS : public Scheduler {
    public:
        void scheduleProcesses(std::vector<Process>& proceeses)override;
        void printMetrics(const std::vector<Process>& processes) override;
};

#endif