#include "Profiler.h"
#include <iostream>

static std::stringstream logStream;

/**
 * @brief Profiler::Profiler
 * @param function
 */
Profiler::Profiler(const std::string function)
{
    // Set the function name
    SetFunctionName(function);

    // Start the timer
    Start();
}


/**
 * @brief Profiler::Start
 */
void Profiler::Start()
{
    gettimeofday(&this->_start, NULL);
}


/**
 * @brief Profiler::Profile
 */
void Profiler::Profile()
{
    // Time in seconds, milli-seconds and micro-seconds
    this->_timeMicroSeconds = this->_end.tv_usec - this->_start.tv_usec;
    this->_timeSeconds  = this->_end.tv_sec - this->_start.tv_sec;
    this->_timeMilliSeconds =
            (this->_timeMicroSeconds * 1e-3) + (this->_timeSeconds * 1e3);
}


/**
 * @brief Profiler::End
 */
void Profiler::End()
{
    // End the timer
    gettimeofday(&this->_end, NULL);

    // Profile
    Profile();

    // Add profiling data to the log
    LogProfile();
}


/**
 * @brief Profiler::LogProfile
 */
void Profiler::LogProfile()
{
    /*
    logStream << GetFunctionName() << " " << this->_timeMilliSeconds
              << " ms " << std::endl; */
}


/**
 * @brief Profiler::PrintProfile
 */
void Profiler::PrintProfile (std::string message)
{
    std::cout << GetFunctionName() << " : " << message
              << " [" << this->_timeMilliSeconds << " ms] " << std::endl;
}


/**
 * @brief Profiler::GetTimeInMicrosSeconds
 * @return
 */
double Profiler::GetTimeInMicrosSeconds(void) const
{
    return this->_timeMicroSeconds;
}


/**
 * @brief Profiler::GetTimeInMilliSeconds
 * @return
 */
double Profiler::GetTimeInMilliSeconds(void) const
{
    return this->_timeMilliSeconds;
}


/**
 * @brief Profiler::GetTimeInSeconds
 * @return
 */
double Profiler::GetTimeInSeconds(void) const
{
    return this->_timeSeconds;
}


/**
 * @brief Profiler::GetFunctionName
 * @return
 */
std::string Profiler::GetFunctionName(void) const
{
    return this->_functionName;
}


/**
 * @brief Profiler::WriteProfileToFile
 * @param fileName
 */
void Profiler::WriteProfileToFile(std::string fileName)
{
    std::ofstream fileStream;
    std::string filePath = fileName + std::string(".profile");

    fileStream.open(filePath.c_str ());
    fileStream << logStream.rdbuf();
    fileStream.close();
}


/**
 * @brief Profiler::SetFunctionName
 * @param functionName
 */
void Profiler::SetFunctionName(std::string functionName)
{
    this->_functionName = functionName;
}
