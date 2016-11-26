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
	 template<typename T> void Log(T const & logMessage);                   // logMessage - то что будет логироваться .
	template<typename T>CLogger& operator<<(T const & logMessage);         // перегрузка <<
	static CLogger* GetLogger();                                         // Функция создающая экземпляр класса Logger. Возвращает одноэлементный объект класса CLogger 
private:
	CLogger();                                                           // Конструктор по умолчанию. Private т.к. Singltone
	CLogger(const CLogger&) {};                                          // Конструктор копирования. Private т.к. Singltone
	CLogger& operator=(const CLogger&) { return *this; };                // Оператор присваивания для класса Logger. Private т.к. Singltone
	static const std::string fileName;                                   // Log file name.	
	static CLogger* lThis;                                             // Singleton указатель на объект класса логгера.
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




