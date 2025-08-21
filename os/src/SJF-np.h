#ifndef SJF_np_H
#define SJF_np_H

#include "Scheduler.h"
#include <thread>
#include <chrono>
#include <algorithm>

class SJF_np : public Scheduler{
    public:
        void scheduleProcesses(std::vector<Process> &processes) override;
        void printMetrics(const std::vector<Process> &processes) override;
};

#endif