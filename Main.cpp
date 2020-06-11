/*#include <fstream>
#include <iostream>
#include <ctime>
#include <sstream>
using namespace std;
#define MAX_DATE 12

int main() {

	
	time_t lsec = time(0);
	string filename;
	char the_date[MAX_DATE];

	the_date[0] = '\0';
	tm* ltm = localtime_s(&lsec);


	ostringstream fileNameStream(filename);
	fileNameStream << ltm->tm_mon << ltm->tm_year << ltm->tm_hour << ltm->tm_min << ltm->tm_sec << ".txt";
	string  fileName = fileNameStream.str();

	ofstream myfile(fileName);
	myfile << "Write this to a file. \n";
	myfile.close();
	return 0;


}*/

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdio.h>
#include "KalenderDaten.h"

using namespace std;

const string currentDateTime() {
		time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
	return buf;
}

int main(int argc, char* argv[]) {
	string file = argv[1];
	string myText;
	string strCsv;
	KalenderDaten* kd;
	bool fertig;


	string newName = file + "_" + currentDateTime() + ".csv";
	ofstream MyWriteFile(newName);

	ifstream MyReadFile(file);

	if (MyReadFile.is_open()) {

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

			if (subStr1 == "DTSTAMP") {
				kd[count].setDtStamp(subStr2);
			}
			else if (subStr1 == "SUMMARY") {
				kd[count].setSummary(subStr2);
			}
			else if (subStr1 == "DESCRIPTION") {
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
			if (myText == "END:TODO") {
				count++;
			}
			

			//MyWriteFile << myText + ";";

		}

		MyReadFile.close();
		MyWriteFile.close();
	

	


	return 0;
}