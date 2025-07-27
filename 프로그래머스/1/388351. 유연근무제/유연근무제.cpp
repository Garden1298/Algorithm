#include <string>
#include <vector>

using namespace std;

vector<vector<int>> GetTimeLog(vector<vector<int>>& timelogs, int startday)
{
    vector<int> dayIndex;
    vector<vector<int>> log;
    
    for(int i = 0; i<7; i++)
    {
        int day = (startday + i - 1) % 7 + 1;
        if(day >= 1 && day <= 5)
        {
            dayIndex.push_back(i);
        }
    }
    
    for(int i = 0; i<timelogs.size(); i++)
    {
        vector<int> workerlog;
        for(int day : dayIndex)
        {
            workerlog.push_back(timelogs[i][day]);
        }
        log.push_back(workerlog);
    }
    
    return log;
}

int GetPromisedTime(int time)
{
    int hour = time / 100;
    int minute = time % 100 + 10;
    
    if(minute >= 60)
    {
        minute -= 60;
        hour += 1;
    }
    
    return hour * 100 + minute;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int workerCount = schedules.size();
    vector<vector<int>> weekDayTimeLog = GetTimeLog(timelogs, startday);
    
    for(int worker = 0; worker< workerCount; worker++)
    {
        int promisedTime = GetPromisedTime(schedules[worker]);
        bool safe = true;
        for(int time : weekDayTimeLog[worker])
        {
            if(time > promisedTime)
            {
                safe = false;
                break;
            }
        }
        
        if(safe)
        {
            answer++;
        }
    }
    
    return answer;
}