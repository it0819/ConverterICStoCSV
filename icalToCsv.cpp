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
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

int main( int argc, char *argv[]){
	string file = argv[1];
	string myText;
	string strCsv;

    string newName = file + "_" + currentDateTime() + ".csv";
	ofstream MyWriteFile(newName);
	ifstream MyReadFile(file);
	
	if(MyReadFile.is_open()){
		
		while (getline (MyReadFile, myText)) {
			MyWriteFile << myText + ";";
		}
	MyReadFile.close();
	MyWriteFile.close();
	}
	
	return 0;
}

