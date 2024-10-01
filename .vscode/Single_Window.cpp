#include<iostream>
#include "linkQueue.h"
using namespace std;

struct Time{
    int time;
    int hour;
    int minute;
    void into_time(const int& hour, const int& minute){
        this->time=60*hour+minute;
    }
    void update_time(const int& time){
        this->hour=static_cast<int>(time / double(60));
        this->minute=time%60;
    }
};

struct People{
    Time arrive;
    Time begin;
    int serveType; 
};

int time_needed(int ran){
    switch (ran)
    {
    case 0:
        return 2;
        break;
    case 1:
        return 4;
        break;
    case 2:
        return 10;
        break;
    }
}

int main(){
    srand(static_cast<unsigned int>(time(0)));
    linkQueue<People> queue;
    // Time realtime;
    // realtime.hour=9;
    // realtime.minute=time_needed(rand() % 3);
    People p;
    p.arrive.hour=9;
    p.arrive.minute=rand()%11;
    p.begin=p.arrive;
    p.serveType=rand()%3;
    p.arrive.into_time(p.arrive.hour, p.arrive.minute);
    p.begin.into_time(p.begin.hour, p.begin.minute);
    int cnt=1;
    while (p.arrive.time<=990){
        cout<<p.arrive.hour<<" "<<p.arrive.minute<<" ";
        cout<<p.begin.hour<<" "<<p.begin.minute<<" ";
        cout<<p.serveType<<endl;
        queue.enQueue(p);
        p.arrive.time+=rand()%6;
        p.arrive.update_time(p.arrive.time);
        p.begin.time=max(p.arrive.time, p.begin.time+time_needed(p.serveType));
        p.begin.update_time(p.begin.time);
        p.serveType=rand()%3;
        cnt++;
    }
    cout<<cnt<<endl;
    cout<<queue.length()<<endl;

    return 0;
}