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


	else std::cout << "Unable to open file";


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