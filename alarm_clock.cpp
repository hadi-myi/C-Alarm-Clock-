#include "alarm_clock.h"

// setting the alarmclock time to 12:00 AM as instructed
AlarmClock::AlarmClock(){
  // time to default value
  AlarmClock::hours_ = 12;
  AlarmClock::minutes_ = 00;
  AlarmClock::period_ = "AM";

  // alarm to default value
  AlarmClock::alarm_hours_ = 12;
  AlarmClock::alarm_minutes_ = 00;
  AlarmClock::alarm_period_ = "AM";
  AlarmClock::alarm_on_ = false;

  // all modes to default value
  AlarmClock::time_mode_ = false;
  AlarmClock::alarm_mode_ = false;
  AlarmClock::no_mode_ = true;
  AlarmClock::alarm_active_ = false;
}

// second constructor which will set the time according to parameters
AlarmClock::AlarmClock(int hour, int minute, bool period){
  AlarmClock::hours_ = hour;
  AlarmClock::minutes_ = minute;
  if (period){
    AlarmClock::period_ = "PM";
  }
  else{
    AlarmClock::period_ = "AM";
  }
  
  // alarm to default value
  AlarmClock::alarm_hours_ = 12;
  AlarmClock::alarm_minutes_ = 00;
  AlarmClock::alarm_period_ = "AM";

  // mode to default value
  AlarmClock::time_mode_ = false;
  AlarmClock::alarm_mode_ = false;
  AlarmClock::no_mode_ = true;
  AlarmClock::alarm_on_ = false;
  AlarmClock::alarm_active_ = false;
}

// third constructor that also sets alarm time according to parameters
 AlarmClock::AlarmClock(int hour, int minute, bool period, int alarm_hour, int alarm_minute, bool alarm_period){

  // for main clock time
  AlarmClock::hours_ = hour;
  AlarmClock::minutes_ = minute;
  if (period){
    AlarmClock::period_ = "PM";
   }
  else{
    AlarmClock::period_ = "AM";
  }

  //for alarm time
  AlarmClock::alarm_hours_ = alarm_hour;
  AlarmClock::alarm_minutes_ = alarm_minute;
  if (alarm_period){
    AlarmClock::alarm_period_ = "PM";
  }
  else{
    AlarmClock::alarm_period_ = "AM";
  }

  // default mode
  AlarmClock::time_mode_ = false;
  AlarmClock::alarm_mode_ = false;
  AlarmClock::no_mode_ = true;
  AlarmClock::alarm_on_ = false;
  AlarmClock::alarm_active_ = false;
 }

//deconstructor for Alarmclock
AlarmClock::~AlarmClock(){
  
}



// setting the alarmclock to time setting mode
void AlarmClock::TimeButton(){
  // checking to see if clock is in 
  // time mode already, if so set to default
  if (AlarmClock::time_mode_){
    AlarmClock::time_mode_ = false;
    AlarmClock::alarm_mode_ = false;
    AlarmClock::no_mode_ = true;
  }
  // else set it in time mode
  else{
    AlarmClock::time_mode_ = true;
    AlarmClock::alarm_mode_ = false;
    AlarmClock::no_mode_ = false;
  }
}

// setting alarmclock to alarm setting mode
void AlarmClock::AlarmButton(){
   // checking to see if clock is in 
  // alarm mode already, if so set to default
  if (AlarmClock::alarm_mode_){
    AlarmClock::time_mode_ = false;
    AlarmClock::alarm_mode_ = false;
    AlarmClock::no_mode_ = true;
  }
  //else set to alarm mode
  else{
    AlarmClock::time_mode_ = false;
    AlarmClock::alarm_mode_ = true;
    AlarmClock::no_mode_ = false;
  }
}
// toggles the alarm switch on or off 
void AlarmClock::AlarmSwitch(){
  if (AlarmClock::alarm_on_){
    AlarmClock::alarm_on_ = false;
  }
  else{
    AlarmClock::alarm_on_ = true;
  }
  // turn off alarm if active
  if (AlarmClock::alarm_active_){
    AlarmClock::alarm_active_ = false;
  }
}

// advcances the minutes by 1
void AlarmClock::MinButton(){

  // advances min by 1 in time
  if (AlarmClock::time_mode_){
    AlarmClock::minutes_++;
    // if min = 60, reset
    if (AlarmClock::minutes_ == 60){
      AlarmClock::minutes_= 0;
    }
  }
  // do the same for alarm time
  else if(AlarmClock::alarm_mode_){
      AlarmClock::alarm_minutes_++;
      if (AlarmClock::alarm_minutes_ == 60){
        AlarmClock::alarm_minutes_= 0;
    }
  }
  // return nothing if no mode
  else if (AlarmClock::no_mode_){
    return;
  }
}

//advances the hour by 1
void AlarmClock::HourButton(){
  // advance time hours
  if (AlarmClock::time_mode_){
    AlarmClock::hours_++;
    // if hours 13, set to 1
    if (AlarmClock::hours_ == 13){
      AlarmClock::hours_= 1;
    }
    // whenever hours hit 12, change period
    if (AlarmClock::hours_ == 12){
      if (AlarmClock::period_ == "AM"){
        AlarmClock::period_ = "PM";
      }
      else{
        AlarmClock::period_ = "AM";
      }
    }
  }
    // do the same for alarm time
  else if(AlarmClock::alarm_mode_){
      AlarmClock::alarm_hours_++;
      if (AlarmClock::alarm_hours_ == 13){
        AlarmClock::alarm_hours_= 1;
      }
      if (AlarmClock::alarm_hours_ == 12){
        if (AlarmClock::alarm_period_ == "AM"){
          AlarmClock::alarm_period_ = "PM";
        }
        else{
          AlarmClock::alarm_period_ = "AM";
        }
      }
    }
    // return nothing if no mode
  else if (AlarmClock::no_mode_){
    return;
  }
}

// displays the alarm time or current time depending on mode
void AlarmClock::DisplayTime(){
  
  // convert all times to strings
  std::string hour = std::to_string(AlarmClock::hours_);
  std::string minute = std::to_string(AlarmClock::minutes_);
  std::string alarmhour = std::to_string(AlarmClock::alarm_hours_);
  std::string alarmmin = std::to_string(AlarmClock::alarm_minutes_);

  // add zeros behind all times if less than 10
  if (AlarmClock::hours_ < 10){
    hour = '0' + hour;
  }
  if (AlarmClock::minutes_ < 10){
    minute = '0' + minute;
  }
  if (AlarmClock::alarm_hours_ < 10){
    alarmhour = '0' + alarmhour;
  }
  if (AlarmClock::alarm_minutes_ < 10){
    alarmmin = '0' + alarmmin;
  }

  // print time or alarm time depending on mode
  if (AlarmClock::time_mode_ || AlarmClock::no_mode_){
    std::cout << hour<< ':' <<  minute<<std::endl;
  }
  else if (AlarmClock::alarm_mode_){
    std::cout << alarmhour << ':' << alarmmin<<std::endl;
  }
  // check if the alarm should run
  AlarmClock::AlarmCheck(); 
}

// display if either alarm or time is in am or pm
void AlarmClock::DisplayAmPm(){
  
  if (alarm_mode_){
    std::cout << AlarmClock::alarm_period_ <<std::endl;
  } else {
    std::cout << AlarmClock::period_ << std::endl;
  }
  // check if the alarm should run
  AlarmClock::AlarmCheck();
}

// display if the alarm is on or not
void AlarmClock::DisplayAlarmSet(){
 
  if (AlarmClock::alarm_on_){
    std::cout<<"alarm is on"<<std::endl;
  }
  else {
    std::cout<<"alarm is off"<<std::endl;
  }
  // check if the alarm should run
  AlarmClock::AlarmCheck();
}

// checks if alarm time is equal to the actual time or not
void AlarmClock::AlarmCheck(){
  // set the boolean alarm active to true if it satisfies all conditions
  if (AlarmClock::alarm_hours_ == AlarmClock::hours_ && AlarmClock::alarm_minutes_ == AlarmClock::minutes_ && AlarmClock::alarm_period_ == AlarmClock::period_ && AlarmClock::alarm_on_){
    AlarmClock::alarm_active_ = true;
  }
  // while alarm active isnt turned off, alarm keeps sounding
  while(AlarmClock::alarm_active_){
      std::cout<<"ALARM: BEEP BEEP BEEP!!"<<std::endl;
      return;
    }
}

// advance minutes like an actual clock
void AlarmClock::AdvanceMinute(){
  // add minutes 
  AlarmClock::minutes_++;
  // if minutes = 60, reset and + hours
  if (AlarmClock::minutes_ == 60){
    AlarmClock::minutes_ = 0;
    AlarmClock::hours_ ++;
    // change the period when hours hit 12
    if (AlarmClock::hours_ == 12){
      if (AlarmClock::period_ == "AM"){
        AlarmClock::period_ = "PM";
      }
      else{
        AlarmClock::period_ = "AM";
      }
    }
    // reset hours to 1 when they hit 13
    if (AlarmClock::hours_ == 13){
      AlarmClock::hours_ = 1;
    }
  }

  // check if the alarm should run
  //AlarmCheck();
}