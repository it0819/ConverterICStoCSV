#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "KalenderDaten.h"
#include "AlarmData.h"
class Datenmanager
{

public: 
	
	void eintragen(string file , string newName) {
		ofstream MyWriteFile(newName);

		ifstream MyReadFile(file);
		
		if (MyReadFile.is_open()) {

			string myText;
			KalenderDaten* kd;
			int count = 0;

			while (getline(MyReadFile, myText)) {

				if (myText == "END:TODO") {
					count++;
				}
			}

			kd = new KalenderDaten[count];

			count = 0;


			while (getline(MyReadFile, myText)) {
				size_t pos1 = myText.find(":") + 1; // position after ":"
				size_t pos2 = myText.find(":");   // position at ":"
				string subStr2 = myText.substr(pos1); // get after ":" to the end   
				string subStr1 = myText.substr(0, pos2); // get from begin to ":" 
				bool valarm = false;

				if (subStr1 == "DTSTAMP") {
					kd[count].setDtStamp(subStr2);
				}
				else if (subStr1 == "SUMMARY") {
					kd[count].setSummary(subStr2);
				}
				else if (subStr1 == "DESCRIPTION" && valarm == false) {
					kd[count].setDescription(subStr2);
				}
				else if (subStr1 == "DTSTART" || subStr1 == "DTSTART;VALUE=DATE") {
					kd[count].setDtStart(subStr2);
				}
				else if (subStr1 == "DUE" || "DUE;VALUE=DATE") {
					kd[count].setDue(subStr2);
				}
				else if (subStr1 == "KLASSE") {
					kd[count].setKlasse(subStr2);
				}
				else if (subStr1 == "STATUS") {
					kd[count].setStatus(subStr2);
				}
				else if (subStr1 == "PERCENTCOMPLETE") {
					kd[count].setPercentComplete(subStr2);
				}
				else if (subStr1 == "PRIORITY") {
					kd[count].setPriority(subStr2);
				}
				else if (subStr1 == "UID") {
					kd[count].setUid(subStr2);
				}
				else if (subStr1 == "CREATED") {
					kd[count].setCreated(subStr2);
				}
				else if (subStr1 == "LASTMODIFIED") {
					kd[count].setLastModified(subStr2);
				}
				else if (subStr1 == "BEGIN:VALARM") {
					valarm = true;
				}
				else if (subStr1 == "TRIGGER;VALUE=DATE-TIME") {
					kd[count].getAd().setTrigger(subStr2);
				}
				else if (subStr1 == "ACTION") {
					kd[count].getAd().setAction(subStr2);
				}
				else if (subStr1 == "DESCRIPTION" && valarm == true) {
					kd[count].getAd().setDescription(subStr2);
					valarm = false;
				}

			
				if (myText == "END:TODO") {
				count++;
				}

			}
			
			for (int i = 0; i < sizeof(kd); i++)
			{
				MyWriteFile << kd[i].getCreated() + ";";
				MyWriteFile << kd[i].getDescription() + ";";
				MyWriteFile << kd[i].getDtStamp() + ";";
				MyWriteFile << kd[i].getDtStart() + ";";
				MyWriteFile << kd[i].getDue() + ";";
				MyWriteFile << kd[i].getKlasse() + ";";
				MyWriteFile << kd[i].getLastModified() + ";";
				MyWriteFile << kd[i].getPercentComplete() + ";";
				MyWriteFile << kd[i].getPriority() + ";";
				MyWriteFile << kd[i].getStatus() + ";";
				MyWriteFile << kd[i].getUid() + ";";
				MyWriteFile << kd[i].getAd().getAction() + ";";
				MyWriteFile << kd[i].getAd().getDescription() + ";";
				MyWriteFile << kd[i].getAd().getTrigger() + ";";
				MyWriteFile << "\n";


			}


		}



		MyReadFile.close();
		MyWriteFile.close();




	}
};

