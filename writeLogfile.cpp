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
