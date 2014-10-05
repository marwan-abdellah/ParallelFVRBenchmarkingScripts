#ifndef PROFILER_H
#define PROFILER_H

#include <string>
#include <sys/time.h>
#include <fstream>
#include <sstream>

/**
 * @brief The Profiler class
 */
class Profiler
{
public:
    /**
     * @brief Profiler
     * @param function
     */
    Profiler(const std::string function);

    /**
     * @brief Start
     */
    void Start();

    /**
     * @brief End
     */
    void End();

    /**
     * @brief Profile
     */
    void Profile();

    /**
     * @brief LogProfile
     */

    void LogProfile();
    /**
     * @brief PrintProfile
     * @param message
     */
    void PrintProfile(std::string message);

    /**
     * @brief GetTimeInMicrosSeconds
     * @return
     */
    double GetTimeInMicrosSeconds(void) const;

    /**
     * @brief GetTimeInMilliSeconds
     * @return
     */
    double GetTimeInMilliSeconds(void) const;

    /**
     * @brief GetTimeInSeconds
     * @return
     */
    double GetTimeInSeconds(void) const;

    /**
     * @brief GetFunctionName
     * @return
     */
    std::string GetFunctionName(void) const;

    /**
     * @brief WriteProfileToFile
     * @param fileName
     */
    static void WriteProfileToFile(std::string fileName = "FVR");

private:
    struct timeval _start;
    struct timeval _end;

    double _timeMicroSeconds;
    double _timeMilliSeconds;
    double _timeSeconds;

    std::string _functionName;

private:
    /**
     * @brief SetFunctionName
     * @param functionName
     */
    void SetFunctionName(std::string functionName);
};

#define START_PROFILING( )                                                  \
    Profiler profile( __FUNCTION__ )


#define END_PROFILING( )                                                    \
    profile.End()

#endif // PROFILER_H
