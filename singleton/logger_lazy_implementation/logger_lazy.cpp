#include <iostream>
#include <string>
#include <mutex>
#include <memory>
#include <thread>

class Logger {
    
public:

    static std::shared_ptr<Logger> getInstance() 
    {
        std::lock_guard<std::mutex> lock(m_instanceMutex);
        if(!m_instance) {
            m_instance = std::shared_ptr<Logger>(new Logger());
        }
        return m_instance;
    }
    
    void log(const std::string& message) 
    {
        std::lock_guard<std::mutex> lock(m_logMutex);
        std::cout << "[LOG] " << message << std::endl;
    }
    
    ~Logger() {
        std::cout << "Logger destroyed\n";
    }
    
private:

    Logger() {
        std::cout << "Logger created\n";
    }
    
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    
    Logger(Logger&&) = delete;
    Logger& operator=(Logger&&) = delete;
    
    static std::shared_ptr<Logger> m_instance;
    static std::mutex m_instanceMutex;
    std::mutex m_logMutex;
};

std::shared_ptr<Logger> Logger::m_instance = nullptr;
std::mutex Logger::m_instanceMutex;

void worker(int id)
{
    auto logger = Logger::getInstance();
    logger->log("Worker " + std::to_string(id) + " started work");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    logger->log("Worker " + std::to_string(id) + " finished work");
}

int main() {
    std::thread t1(worker, 1);
    std::thread t2(worker, 2);
    std::thread t3(worker, 3);
    
    t1.join();
    t2.join();
    t3.join();
    
    return 0;
}