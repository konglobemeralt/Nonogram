#include "noData.h"
#include <sstream>

noData::noData()
{
	maxRow = 0;
	maxColumn = 0;
}

noData::~noData()
{
}

noData::noData(const noData& other)
{
	size = other.size;
	row = other.row;
	column = other.column;
	picture = other.picture;
	maxRow = other.maxRow;
	maxColumn = other.maxColumn;
}

void noData::getData(std::vector<noData> &noDataList_to_fill, std::vector<std::string> &TextFileList)
{
		int rows = 0;
		int columns = 0;
		bool rowBool = true;
	
		
		int lineCount = 0;
		int lineCount2 = 0;

	for (int i = 0; i < TextFileList.size(); i++)
	{	
		noData tmp;
		
		//reset all counts
		rows = 0;
		columns = 0;
		rowBool = true;
		lineCount = 0;
		lineCount2 = 0;
		
		std::string filePath = "../textFiles/";
		filePath += TextFileList.at(i);
		textData.open(filePath);
		std::string line;
		
		if (textData.is_open())
		{
			//std::cout << filePath << std::endl;
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
					//The array Size
					tmp.size.push_back(rows);
					tmp.size.push_back(columns);
				}
				
				if ((line.find('#') != std::string::npos || line.find('?') != std::string::npos))
					{


						char ch;
						
						//if (line.find('#') != std::string::npos)
						//{
							for (int a = 0; a < line.size(); a++)
							{
								ch = line.at(a);
								if (ch != ' ')
								{
									tmp.picture.push_back(ch);
								}
						//	}
						}


						//tmp.picture.push_back(line);
						lineCount++;
						continue;
					}
			
			else 
			{
				//beacause we get the size in the beginning
				if (lineCount2 > rows+1  && lineCount > 2)
				{
					rowBool = false;
				}

				//To get rid of lines without data
				if (rowBool == true && lineCount > 5)
				{
					int n;
					int count = 0;

					std::istringstream iss(line);
					while (iss >> n)
					{
						tmp.row.push_back(n);
						count++;
						if (count > tmp.maxRow)
						{
							tmp.maxRow = count;
						}


					}
					    tmp.row.push_back(-1);
						lineCount2++;
					
				}
			
				if (rowBool == false && lineCount > 2)
				{
					int n;
					int count = 0;

					std::istringstream iss(line);
					while (iss >> n)
					{
						tmp.column.push_back(n);
						count++;
						if (count > tmp.maxColumn)
						{
							tmp.maxColumn = count;
						}
					}
					tmp.column.push_back(-1);
				
					
				}
				lineCount++;
			}
			
			
			}
			textData.close();

			//getRidofExtre -1
			tmp.column.pop_back();
			tmp.row.pop_back();

			noDataList_to_fill.push_back(tmp);

		}
		else std::cout << "Unable to open file" << std::endl;
		
		}
};

bool noData::getTextFiles(std::vector<std::string> &list_to_fill)
{

	WIN32_FIND_DATA search_data;

	memset(&search_data, 0, sizeof(WIN32_FIND_DATA));

	HANDLE handle = FindFirstFile("..\\TextFiles\\*.txt", &search_data);

	int count = 0;

	std::cout << "\n";

	while (handle != INVALID_HANDLE_VALUE)
	{
		std::cout << "   " << ++count << ". " << search_data.cFileName << std::endl;

		/* Here, you append another found file to the end of the vector.
		* However, unlike arrays, you do NOT have to worry about resizing.
		* The vector is resized for you!
		*/
		list_to_fill.push_back(std::string(search_data.cFileName));

		if (FindNextFile(handle, &search_data) == FALSE)
			break;
	}

	

	return true;
}