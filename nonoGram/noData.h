#ifndef _NODATA_H_
#define _NODATA_H_

#include<vector>
#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>

class noData
{

public:
	
	//Const och Destr
	noData();
	~noData();
	noData(const noData& other);

	void getData(std::vector<noData> &noDataList_to_fill, std::vector<std::string> &TextFileList);
	bool getTextFiles(char *folder_path, std::vector<std::string> &list_to_fill);

public:
	//actual data
	std::vector<int>size;
	std::vector<int>row;
	std::vector<int>column;

	

	//check variables
	bool rowBool = true;
	//data stream
	std::ifstream textData;
	



};

#endif