#include "noData.h"

noData::noData()
{
}

noData::~noData()
{
}

void noData::getData()
{

	bool rowBool = true;
	textData.open("test.txt");
	std::string line;

	if (textData.is_open())
	{
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
					row.push_back(atoi(line.c_str()));
				}

				if (rowBool == false)
				{
					column.push_back(atoi(line.c_str()));
				}
			}
		}
		textData.close();
	}


	else std::cout << "Unable to open file" << std::endl;;


	std::cout << "ROW" << std::endl;
	for (int i = 0; i < row.size(); i++)
	{
		std::cout << row.at(i) << std::endl;
	}
	getchar();
	std::cout << "COLUMN" << std::endl;
	for (int i = 0; i < column.size(); i++)
	{
		std::cout << column.at(i) << std::endl;
	}

	getchar();

};

bool noData::getTextFiles(char *folder_path, std::vector<std::string> &list_to_fill)
{
	WIN32_FIND_DATA fdata;
	HANDLE dhandle;
	// måste lägga till \* till genvägen
	{
		char buf[MAX_PATH];
		sprintf_s(buf, sizeof(buf), "%s\\*", folder_path);
		if ((dhandle = FindFirstFile(buf, &fdata)) == INVALID_HANDLE_VALUE) {
			return false;
		}
	}
	while (true)
	{
		if (FindNextFile(dhandle, &fdata))
		{
			// vi vill endast ha ".bin"-filer
			if (strlen(fdata.cFileName) > 4)
			{
				if (strcmp(&fdata.cFileName[strlen(fdata.cFileName) - 3], ".txt") == true)
				{
					list_to_fill.push_back(fdata.cFileName);
				}
			}
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