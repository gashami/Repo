#include<iostream>

#include<ctime>
using namespace std;
/*
  void daytime(){
    time_t ti;
    struct tm *tt;
    time(&ti);
    tt = localtime(&ti);
    cout<< tt->tm_sec <<endl;
    cout<< tt->tm_min <<endl;
    cout<< tt->tm_hour <<endl;
    cout<< tt->tm_mday <<endl;
    cout<< tt->tm_mon <<endl;
    cout<< tt->tm_year + 1900 <<endl;
    cout<< tt->tm_wday <<endl;
    cout<< tt->tm_yday <<endl;
    cout<< tt->tm_isdst <<endl;
  }
*/

void getCurrentTime(){
  time_t now = time(nullptr);
  struct tm *gm_time = gmtime(&now);
  struct tm *loc_time = localtime(&now);
  string string_now = ctime(&now);
  cout<<"String day-time\t" <<string_now <<endl<<endl;
 cout<<"tm_sec :"<<gm_time->tm_sec <<endl;
 cout<<"tm_min :"<<gm_time->tm_min <<endl;
 cout<<"tm_hour :"<<gm_time->tm_hour <<endl;
 cout<<"tm_mday :"<<gm_time->tm_mday <<endl;
 cout<<"tm_mon :"<<gm_time->tm_mon <<endl;
 cout<<"tm_year :"<<gm_time->tm_year <<endl;
 cout<<"tm_wday :"<<gm_time->tm_wday <<endl;
 cout<<"tm_yday :"<<gm_time->tm_yday <<endl;
 cout<<"tm_isdst :"<<gm_time->tm_isdst <<endl<<endl;

 cout<<"tm_sec :"<<loc_time->tm_sec <<endl;
 cout<<"tm_min :"<<loc_time->tm_min <<endl;
 cout<<"tm_hour :"<<loc_time->tm_hour <<endl;
 cout<<"tm_mday :"<<loc_time->tm_mday <<endl;
 cout<<"tm_mon :"<<loc_time->tm_mon <<endl;
 cout<<"tm_year :"<<loc_time->tm_year <<endl;
 cout<<"tm_wday :"<<loc_time->tm_wday <<endl;
 cout<<"tm_yday :"<<loc_time->tm_yday <<endl;
 cout<<"tm_isdst :"<<loc_time->tm_isdst <<endl;

}
  int main(){
      getCurrentTime();
  }

