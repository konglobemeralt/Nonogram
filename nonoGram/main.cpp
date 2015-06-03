#include<iostream>
#include<vector>
#include <fstream>
#include <string>
#include "noData.h"

using namespace std;
int main()
{
	std::vector<std::string> textFileList;
	std::vector<noData> noDataList;


	noData inputData;

	inputData.getTextFiles("../textFiles/", textFileList);
	
	inputData.getData(noDataList, textFileList);
	
	for (int i = 0; i < noDataList.size(); i++)
	{
		std::cout << "Hej!";
	}
  
  return 0;
}