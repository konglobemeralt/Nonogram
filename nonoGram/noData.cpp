#include "noData.h"
#include <sstream>

noData::noData()
{
}

noData::~noData()
{
}

noData::noData(const noData& other)
{
	size = other.size;
	row = other.row;
	column = other.column;
	

}

void noData::getData(std::vector<noData> &noDataList_to_fill, std::vector<std::string> &TextFileList)
{
	
	for (int i = 0; i < TextFileList.size(); i++)
	{	
		noData tmp;
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
				//std::cout << line << '\n';
				if (lineCount == 2)
				{
					std::istringstream is(line);

					int n;
					while (is >> n) 
					{
						if (rows == 0)
						{
							rows = n;
						}

						if (rows != 0)
						{
							columns = n;
						}


					}
					tmp.size.push_back(rows);
					tmp.size.push_back(columns);
				}
				
				if ((line.find('#') != std::string::npos || line.find('?') != std::string::npos))
					{
						lineCount++;
						continue;
				}
			
			else 
			{
				
				if (rowBool == true)
				{
					std::cout << line << '\n';
					//std::cout << atoi(line.c_str()) << std::endl;
					tmp.row.push_back(atoi(line.c_str()));
				
				}
			
				if (rowBool == false)
				{
					std::cout << line << '\n';
					//std::cout << atoi(line.c_str()) << std::endl;
					tmp.column.push_back(atoi(line.c_str()));
				}
				lineCount++;
			}
				
			}
			textData.close();

			noDataList_to_fill.push_back(tmp);

		}
		else std::cout << "Unable to open file" << std::endl;
		
		
		
	
		
	}
};

bool noData::getTextFiles(char *folder_path, std::vector<std::string> &list_to_fill)
{
	WIN32_FIND_DATA fdata;
	HANDLE dhandle;

	// måste lägga till \* till genvägen
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
			//Lägg i listan
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