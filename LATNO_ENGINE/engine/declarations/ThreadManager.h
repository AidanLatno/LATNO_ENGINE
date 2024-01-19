#pragma once
#include "Definitions.h"

namespace Latno
{
    class ThreadManager {
    public:
        // Static method to create and manage a thread
        static void CreateThread(std::function<void()> task) {
            // Create a thread that runs the provided task
            std::thread t(task);

            // Detach the thread if it's joinable to ensure it runs independently
            if (t.joinable()) {
                std::cout << "DETACH" << std::endl;
                t.detach();
            }
        }
    private:
        // Private constructor to prevent instantiation
        ThreadManager() {}
    };
}