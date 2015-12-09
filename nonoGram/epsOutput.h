#ifndef _EPSOUTPUT_H_
#define _EPSOUTPUT_H_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "noData.h"

class epsOutput
{

public:

	//Const och Destr
	epsOutput();
	~epsOutput();
	

	void createEPSfiles(std::vector<noData> noDataList, std::vector<std::string> TextFileList);
	void createSolutionEPSfiles(std::vector<noData> noDataList, std::vector<std::string> TextFileList);

public:




};

#endif