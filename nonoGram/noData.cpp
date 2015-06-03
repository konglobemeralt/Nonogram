#include "noData.h"

noData::noData()
{
}

noData::~noData()
{
}

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
		

		if (textData.is_open())
		{
			std::cout << filePath << std::endl;
			while (getline(textData, line))
			{
				// cout << line << '\n';
				if (!line.compare(""))
				{
					rowBool = false;
				}

				if (line.compare(""))
				{
					
					if (rowBool == true)
					{
						std::cout << atoi(line.c_str()) << std::endl;
						//noDataList_to_fill.at(i).row.push_back(atoi(line.c_str()));
					}

					if (rowBool == false)
					{
						std::cout << atoi(line.c_str()) << std::endl;
						//noDataList_to_fill.at(i).column.push_back(atoi(line.c_str()));
					}
				}
			}
			textData.close();

			

		}

		
		else std::cout << "Unable to open file" << std::endl;
	
		getchar();
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