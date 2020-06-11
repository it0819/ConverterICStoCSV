void writeLogfile(string notiz, string icsName) {
	string logName = icsName + "_logfile.log";
	
	ofstream WriteLog(logName, ios::app);
	WriteLog << currentDateTime() + " " + notiz + "\n";
	WriteLog.close();
}
