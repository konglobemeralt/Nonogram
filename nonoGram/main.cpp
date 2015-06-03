
#include<iostream>
#include<vector>
#include <fstream>
#include <string>

using namespace std;
int main()
{
std::vector<int>row;
std::vector<int>column;

bool rowBool = true;

ifstream textData;
textData.open ("test.txt");
string line;

if (textData.is_open())
  {
    while ( getline (textData,line) )
    {
     // cout << line << '\n';
		if (!line.compare(""))
			{
				rowBool = false;
			}

		if (line.compare(""))
			{
			
		if(rowBool == true)
			{
				row.push_back(atoi( line.c_str() ) );
			}
		
		if(rowBool == false)
			{
				column.push_back(atoi( line.c_str() ) );
			}
		}
		}
    textData.close();
  }


  else cout << "Unable to open file"; 


  cout << "ROW" << std::endl;
 for(int i = 0; i < row.size(); i++)
{
	cout << row.at(i) << std::endl;
}
 getchar();
  cout << "COLUMN" << std::endl;
 for(int i = 0; i < column.size(); i++)
{
	cout << column.at(i)<< std::endl;
}

 	getchar();
  
  return 0;
}