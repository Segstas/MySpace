#pragma once
#include"Utilities.h"
#include <fstream>
#include <iostream>
#include <cstdarg>
#include <string>
using namespace std;


class CLogger                                                            //Singleton Logger Class.
{
public:
	 template<typename T> void Log(T const & logMessage);                   // logMessage - �� ��� ����� ������������ .
	template<typename T>CLogger& operator<<(T const & logMessage);         // ���������� <<
	static CLogger* GetLogger();                                         // ������� ��������� ��������� ������ Logger. ���������� �������������� ������ ������ CLogger 
private:
	CLogger();                                                           // ����������� �� ���������. Private �.�. Singltone
	CLogger(const CLogger&) {};                                          // ����������� �����������. Private �.�. Singltone
	CLogger& operator=(const CLogger&) { return *this; };                // �������� ������������ ��� ������ Logger. Private �.�. Singltone
	static const std::string fileName;                                   // Log file name.	
	static CLogger* lThis;                                             // Singleton ��������� �� ������ ������ �������.
	static ofstream logfile;                                           // Stream obj
};




const string CLogger::fileName = "Log.txt";
CLogger* CLogger::lThis = NULL;
ofstream CLogger::logfile;
CLogger::CLogger()
{

}
CLogger* CLogger::GetLogger() {
	if (lThis == NULL) {
		lThis = new CLogger();
		logfile.open(fileName.c_str(), ios::out | ios::app);
	}
	return lThis;
}


template<typename T> void CLogger::Log(T const & logMessage)

{
	(const string&)logMessage;
	logfile << Util::CurrentDateTime() << ":\t";
	logfile << logMessage << "\n";

}

template<typename T>CLogger& CLogger::operator<<(T const & logMessage)
{
	(const string&)logMessage;
	logfile << "\n" << Util::CurrentDateTime() << ":\t";
	logfile << logMessage << "\n";
	return *this;
}




