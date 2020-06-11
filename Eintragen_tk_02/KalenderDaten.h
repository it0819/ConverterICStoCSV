#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include "AlarmData.h"

using namespace std;

class KalenderDaten {

private: 
	string dtStamp, summary, description, dtStart, due, klasse, status, percentComplete, priority, uid, created, lastModified;
    AlarmData ad;
	
public:
        KalenderDaten() { this->ad = AlarmData(); }
        KalenderDaten(string  dtStamp, string  summary, string description, string  dtStart, string  due, string  klasse, string  status, string  percentComplete, string  priority, string  uid, string  created, string  lastModified) {
        this->ad = AlarmData();
        this->dtStamp = dtStamp;
        this->summary = summary;
        this->description = description;
        this->dtStart = dtStart;
        this->due = due;
        this->klasse = klasse;
        this->status = status;
        this->percentComplete = percentComplete;
        this->priority = priority;
        this->uid = uid;
        this->created = created;
        this->lastModified = lastModified;
    }

    
    AlarmData getAd() { return this->ad; }
    void setAd(string trigger, string action, string description) { this->ad = AlarmData(trigger, action, description); }

    string getDtStamp() { return this -> dtStamp; }
    void setDtStamp(string value) { this->dtStamp = value; }

    string getSummary() { return summary; }
    void setSummary(string value) { this->summary = value; }

    string getDescription() { return description; }
    void setDescription(string value) { this->description = value; }

    string getDtStart() { return dtStart; }
    void setDtStart(string value) { this->dtStart = value; }

    string getDue() { return due; }
    void setDue(string value) { this->due = value; }

    string getKlasse() { return klasse; }
    void setKlasse(string value) { this->klasse = value; }

    string getStatus() { return status; }
    void setStatus(string value) { this->status = value; }

    string getPercentComplete() { return percentComplete; }
    void setPercentComplete(string value) { this->percentComplete = value; }

    string getPriority() { return priority; }
    void setPriority(string value) { this->priority = value; }

    string getUid() { return uid; }
    void setUid(string value) { this->uid = value; }

    string getCreated() { return created; }
    void setCreated(string value) { this->created = value; }

    string getLastModified() { return lastModified; }
    void setLastModified(string value) { this->lastModified = value; }
};

