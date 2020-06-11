#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdio.h>
using namespace std;

const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d_%X", &tstruct);
    return buf;
}

void writeLogfile(string notiz, string icsName) {
	string logName = icsName + "_logfile.log";
	
	ofstream WriteLog(logName, ios::app);
	WriteLog << currentDateTime() + " " + notiz + "\n";
	WriteLog.close();
}


int main( int argc, char *argv[]){
	string file = argv[1];
	string myText;
	string strCsvHeader;
	string strCsv;

	writeLogfile("Program gestartet", file);

    string newName = file + "_" + currentDateTime() + ".csv";
	ofstream MyWriteFile(newName);
	ifstream MyReadFile(file);
	
	writeLogfile("Filestreams geoeffnet", file);

	if(MyReadFile.is_open()){
		while (getline (MyReadFile, myText)) {
			cout << myText << endl; //DryTest
			size_t find = myText.find(":");
			int pos = find;
			if (myText.substr(0,pos).compare("BEGIN") > 1 || myText.substr(0,pos).compare("END") > 1)
			{
				strCsvHeader.append(myText.substr(0,pos) + ";");
				strCsv.append(myText.substr(pos+1) + ";");
			}
		}

		writeLogfile("Datei gearbeitet", file);

		MyWriteFile << strCsvHeader + "\n" + strCsv;

		writeLogfile("Neue Datei erzeugen", file);

		MyReadFile.close();
		MyWriteFile.close();
		writeLogfile("Filestreams Closed", file);
	}

	writeLogfile("Program beendet", file);
	return 0;
}
