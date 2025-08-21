#include <iostream>
#include <vector>
#include <fstream>
#include "Process.h"
#include "Scheduler.h"
#include "FCFS.h"
#include "SJF-p.h"
#include "SJF-np.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

int main() {
    try {
        // Open and read input file
        std::ifstream file("web/input.json");
        if (!file.is_open()) {
            std::cerr << "Error: Could not open web/input.json" << std::endl;
            std::cerr << "Make sure the file exists and is readable." << std::endl;
            return 1;
        }

        json input;
        file >> input;
        file.close();

        // Validate input structure
        if (!input.contains("algorithm")) {
            std::cerr << "Error: Missing 'algorithm' field in input.json" << std::endl;
            return 1;
        }

        if (!input.contains("processes") || !input["processes"].is_array()) {
            std::cerr << "Error: Missing or invalid 'processes' field in input.json" << std::endl;
            return 1;
        }

        std::string algo = input["algorithm"];
        std::vector<Process> processes;

        // Parse processes with validation
        for (const auto &p : input["processes"]) {
            if (!p.contains("pid") || !p.contains("arrivalTime") || !p.contains("burstTime")) {
                std::cerr << "Error: Process missing required fields (pid, arrivalTime, burstTime)" << std::endl;
                return 1;
            }

            int pid = p["pid"];
            int arrivalTime = p["arrivalTime"];
            int burstTime = p["burstTime"];

            // Validate process data
            if (burstTime <= 0) {
                std::cerr << "Error: Process " << pid << " has invalid burst time: " << burstTime << std::endl;
                return 1;
            }

            if (arrivalTime < 0) {
                std::cerr << "Error: Process " << pid << " has invalid arrival time: " << arrivalTime << std::endl;
                return 1;
            }

            processes.emplace_back(pid, arrivalTime, burstTime);
        }

        if (processes.empty()) {
            std::cerr << "Error: No valid processes found in input" << std::endl;
            return 1;
        }

        std::cout << "Processing " << processes.size() << " processes with algorithm: " << algo << std::endl;

        // Create scheduler based on algorithm
        Scheduler* scheduler = nullptr;

        if (algo == "FCFS") {
            scheduler = new FCFS();
        } else if (algo == "SJF_np") {
            scheduler = new SJF_np();
        } else if (algo == "SJF_p") {
            scheduler = new SJF_p();
        } else {
            std::cerr << "Error: Unknown algorithm: " << algo << std::endl;
            std::cerr << "Supported algorithms: FCFS, SJF_np, SJF_p" << std::endl;
            return 1;
        }

        // Execute scheduling
        scheduler->scheduleProcesses(processes);
        scheduler->printMetrics(processes);

        // Prepare output JSON
        json output = json::array();
        for (const auto &p : processes) {
            output.push_back({
                {"pid", p.pid},
                {"arrivalTime", p.arrivalTime},
                {"burstTime", p.burstTime},
                {"completionTime", p.completionTime},
                {"waitingTime", p.waitingTime},
                {"turnAroundTime", p.turnAroundTime}
            });
        }

        // Write output to file
        std::ofstream outFile("web/output.json");
        if (!outFile.is_open()) {
            std::cerr << "Error: Could not create web/output.json" << std::endl;
            delete scheduler;
            return 1;
        }

        outFile << output.dump(4);  // 4-space indentation
        outFile.close();

        std::cout << "Output successfully written to web/output.json" << std::endl;

        // Cleanup
        delete scheduler;
        return 0;

    } catch (const json::exception& e) {
        std::cerr << "JSON Error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}