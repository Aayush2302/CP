#ifndef SJF_p_H
#define SJF_p_H

#include "Scheduler.h"
#include "Process.h"
#include <thread>
#include <chrono>
#include <algorithm>

class SJF_p : public Scheduler{
    public: 
    void scheduleProcesses(std::vector<Process>& processes) override;
    void printMetrics(const std::vector<Process>& processes) override;
};

#endif