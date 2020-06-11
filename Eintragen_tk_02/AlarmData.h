#pragma once
#include <iostream>
#include <string>

using namespace std;


class AlarmData {

private:
    
    string trigger, action, description;

public:

    AlarmData() {};
    AlarmData(string trigger, string action, string description) {
        this->trigger = trigger;
        this->action = action;
        this->description = description;
    }

    string getTrigger() { return trigger; }
    void setTrigger(string trigger) { this->trigger = trigger; }

    string getAction() { return action; }
    void setAction(string action) { this->action = action; }

    string getDescription() { return description; }
    void setDescription(string description) { this->description = description; }
};


