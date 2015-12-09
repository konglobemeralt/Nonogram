#include<iostream>
#include<vector>
#include <fstream>
#include <string>
#include "noData.h"
#include "epsOutput.h"

using namespace std;
int main()
{
	std::vector<std::string> textFileList;
	std::vector<noData> noDataList;


	noData inputData;
	epsOutput outputData;

	std::cout << "Text files found and converted: \n";

	inputData.getTextFiles(textFileList);
	
	inputData.getData(noDataList, textFileList);
	
	outputData.createEPSfiles(noDataList, textFileList);
	outputData.createSolutionEPSfiles(noDataList, textFileList);

	std::cout << "\n";
	std::cout << "Press any key to Exit...\n";
	
	
  return 0;
}