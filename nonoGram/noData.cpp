#include "noData.h"
#include <sstream>

noData::noData()
{
}

noData::~noData()
{
}

noData::noData(const noData& other)
{}

void noData::getData(std::vector<noData> &noDataList_to_fill, std::vector<std::string> &TextFileList)
{
	noData tmp;
	for (int i = 0; i < TextFileList.size(); i++)
	{	
		bool rowBool = true;

		std::string filePath = "../textFiles/";
		filePath += TextFileList.at(i);
		textData.open(filePath);
		std::string line;
		
		int lineCount = 0;
		int rows = 0;
		int columns = 0;

		if (textData.is_open())
		{
			std::cout << filePath << std::endl;
			while (getline(textData, line))
			{
				std::cout << line << '\n';
				if (lineCount == 2)
				{
					std::istringstream is(line);

					int n;
					while (is >> n) {
						if (rows == 0)
						{
							rows = n;
						}

						if (rows != 0)
						{
							columns = n;
						}


					}
				}
			
			//if (!line.compare(""))
			//{
			//	rowBool = false;
			//}
			//
			//if (line.compare(""))
			//{
			//	
			//	if (rowBool == true)
			//	{
			//		std::cout << atoi(line.c_str()) << std::endl;
			//		tmp.row.push_back(atoi(line.c_str()));
			//	
			//	}
			//
			//	if (rowBool == false)
			//	{
			//		std::cout << atoi(line.c_str()) << std::endl;
			//		tmp.column.push_back(atoi(line.c_str()));
			//	}
			//}
				lineCount++;
			}
			textData.close();

			

		}
		else std::cout << "Unable to open file" << std::endl;
		
		noDataList_to_fill.push_back(tmp);
		
	
		getchar();
	}
};

bool noData::getTextFiles(char *folder_path, std::vector<std::string> &list_to_fill)
{
	WIN32_FIND_DATA fdata;
	HANDLE dhandle;

	// m�ste l�gga till \* till genv�gen
	//hitta alla txt filer.
	{
		char buf[MAX_PATH];
		sprintf_s(buf, sizeof(buf), "%s\\*.txt", folder_path);
		if ((dhandle = FindFirstFile(buf, &fdata)) == INVALID_HANDLE_VALUE) {
			return false;
		}
	}
	while (true)
	{
		if (FindNextFile(dhandle, &fdata))
		{
//			// vi vill endast ha ".txt"-filer
//			if (strlen(fdata.cFileName) > 4)
//			{
//				if (strcmp(&fdata.cFileName[strlen(fdata.cFileName) - 3], ".txt") == true)
//				{
			//L�gg i listan
					list_to_fill.push_back(fdata.cFileName);
//				}
//			}
		}
		else
		{
			if (GetLastError() == ERROR_NO_MORE_FILES)
			{
				break;
			}
			else
			{
				FindClose(dhandle);
				return false;
			}
		}
	}
	if (!FindClose(dhandle))
	{
		return false;
	}
	return true;
}