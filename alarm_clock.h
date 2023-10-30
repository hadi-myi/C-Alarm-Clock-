#ifndef TIME_H_
#define TIME_H_
#include <iostream>
#include <string.h>

class AlarmClock{
  public:
    // 1st constructor with no parameters
    AlarmClock();

    //2nd constructor
    AlarmClock(int hour, int minute, bool period);
    
    //third constructor
    AlarmClock(int hour, int minute, bool period, int alarm_hour, int alarm_minute, bool alarm_period);

    // deconstructor
    ~AlarmClock();

    // all methods from lab 6 doc
    void AlarmSwitch();
    void TimeButton();
    void AlarmButton();
    void MinButton();
    void HourButton();
    //void SnoozeButton();
    void DisplayTime();
    void DisplayAmPm();
    void DisplayAlarmSet();
    void AdvanceMinute();

    // Methods I came up with
    // checks if the alarm should run
    void AlarmCheck();
    
    




  private:

    // for clock
    int hours_;
    int minutes_;
    std::string period_;

    // for buttons
    bool time_mode_;
    bool alarm_mode_;
    bool no_mode_;

    // for alarm clock
    int alarm_hours_;
    int alarm_minutes_;
    std::string alarm_period_;
   
    // for alarm switch
    bool alarm_on_;
    bool alarm_active_;
   
    

};

//void AlarmClock_Main();

#endif