#ifndef PROFILER_H
#define PROFILER_H

#include <string>
#include <sys/time.h>
#include <fstream>
#include <sstream>

class Profiler
{
public:
    Profiler(const std::string function);

    void Start();
    void End();

    void Profile();
    void LogProfile();
    void PrintProfile(std::string message);

    double GetTimeInMicrosSeconds(void) const;
    double GetTimeInMilliSeconds(void) const;
    double GetTimeInSeconds(void) const;

    std::string GetFunctionName(void) const;

    static void WriteProfileToFile(std::string fileName = "FVR");

private:
    struct timeval _start;
    struct timeval _end;

    double _timeMicroSeconds;
    double _timeMilliSeconds;
    double _timeSeconds;

    std::string _functionName;

private:
    void SetFunctionName(std::string functionName);
};

#define START_PROFILING( )                                                  \
    Profiler profile( __FUNCTION__ )


#define END_PROFILING( )                                                    \
    profile.End()

#endif // PROFILER_H
