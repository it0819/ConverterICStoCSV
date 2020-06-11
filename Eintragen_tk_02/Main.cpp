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
#include "Datenmanager.h"

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
	Datenmanager dt;
	string strCsv;
	KalenderDaten* kd;
	bool fertig;


	string newName = file + "_" + currentDateTime() + ".csv";
	dt.eintragen(file, newName);


	return 0;
}