# Work in Progress
This is a joint project still under development with a limited time frame, so use it at your own risk.

# Discription
Convert Files from ICS-Format to CSV-Format with a CLI C++ Program for Win / Linux / Unix

# How to
Compile the source-code with a c++ compiler for your operating system.

Put the Programm in the same folder where your ICS-File is and run the program from the CLI with an argument for the filename you want to convert.

Example: c:\myfolder\ConverterICStoCSV yourfile.ics

The Programm will then convert the ICS-File to CSV-File.

---------------------------------------------------------------------------------------------------------
# Fuktion Logfile
This is the first version of the function. On June 11th, 2020 the development team received two changes. 
The development team needs additional time to program these changes.


Pseudocode of function writeLogfile:

	function writeLogfile (note: String, icsName: String){
	Beginning of the function logfileWrite
	string logName = icsName + "_logfile.log";
	If (Does the file named logName exist?) {
		yes: open the files with the name logName;
		no: create the file with the name logName;
		    and open this file;}
	write the variable notiz into the file named logName;
	close the file named logName; 
	end of function writeLogfile;
	}

# Comment:

The writeLogfile () function is to be called in the main program if a specific action to be noted in the log file.

When the function writeLogfile () is called, two parameters "notiz" and "icsName" will be passed to. These parameters have the data type string.

The "notiz" parameter contains a note which is to be saved in the log file. This parameter can be, for example, 
"Program starts", "The output file is open", "The data is being read" or "An error has occurred".

The "iscName" parameter contains the name of the source file, for example Tasks.isc. 
The "iscName" parameter is used to generate the name of the log file. For example, "Tasks.isc_logfile.log"

The writeLogfile () function checks whether the logfile already exists. If not, this log file will be created. 
Then the function writeLogfile () writes the contents with the parameter "notiz" into the logfile file and closes this logfile.

The writelogfile() function uses a currentDateTime() function.

----------------------------	
# Muster Ergebnis
The file "Muster_Ergebnisdatei.csv" is an example of the Excel file created by the main program.
This example file was created based on the requirements of June 9th, 2020.
The possible changes to the sample file will be discussed on June 12th, 2020. The development team 
needs additional time to implement the changes.
