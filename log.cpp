//
// Author: Pooja Gupta
// Date: 8/11/17
// Description: Definition for logger.

#include "log.h"
ofstream fout;

void setLogConfiguration(string filename)
{
	fout.open(filename.c_str(),ios::app);
}

void writeToLog(string str, int line)
{
	fout<<line<<"  "<<__TIME__<<"  msg:"<<str<<"  "<<__FILE__<<endl;
}

void EndLogConfiguration()
{
	fout.close();
}