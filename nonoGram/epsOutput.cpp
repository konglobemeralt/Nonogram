#include "epsOutput.h"

epsOutput::epsOutput()
{
}

epsOutput::~epsOutput()
{
}

void epsOutput::createEPSfiles(std::vector<noData> noDataList, std::vector<std::string> TextFileList)
{

	for (int i=0; i < noDataList.size(); i++)
	{
		std::ofstream fileOutput;
		std::string fileName = TextFileList.at(i);
	

		//Get rid of .txt
		for (int j = 0; j < 4; j++)
		{
			fileName.pop_back();
		}
		//add .eps
		fileName += ".eps";

		fileOutput.open("../outputFiles/" +fileName);

		fileOutput << "%!PS - Adobe - 3.0 EPSF - 3.0 \n";
		

		
		fileOutput << "%%BoundingBox: " << (578 - ((noDataList.at(i).size.at(0)) * 7.370078742)) - noDataList.at(i).maxColumn * (7.4) << " 11 " << "580 " << ((noDataList.at(i).size.at(1) * 7.370078742) + (noDataList.at(i).maxRow + 2) * (7.4)) + 1 << " \n";
		//fileOutput << "%%BoundingBox: " << (579 - ((noDataList.at(i).size.at(0)) * 7.370078742)) - noDataList.at(i).maxColumn * (7.5) << " 0 " << (((noDataList.at(i).size.at(0)) * 7.370078742)) + (575 - ((noDataList.at(i).size.at(0)) * 7.370078742) + (noDataList.at(i).maxColumn * 7.370078742 * 2)) << " " << (((noDataList.at(i).size.at(1)) * 7.370078742)) + (noDataList.at(i).maxRow * 7.370078742 * 2) << " \n";
		


		


	//	//Inramat CLIP SPACE
	//	fileOutput << "newpath \n";
	//	//fileOutput << "10 10 moveto \n";
	//	fileOutput << (579 - ((noDataList.at(i).size.at(0)) * 7.370078742)) - noDataList.at(i).maxColumn * (7.5) << " " << 12 << " moveto \n";
	//	fileOutput << "0 " << (noDataList.at(i).size.at(1) * 7.370078742) + noDataList.at(i).maxRow * (10) << " rlineto \n";
	//	fileOutput << noDataList.at(i).size.at(0) * 7.370078742 + noDataList.at(i).maxColumn * (7.5) << " 0 rlineto \n";
	//	fileOutput << "0 " << (-noDataList.at(i).size.at(1)* 7.370078742) - noDataList.at(i).maxRow * (10) << " rlineto \n";
	//	fileOutput << noDataList.at(i).size.at(0) * 7.370078742 + noDataList.at(i).maxColumn * (7.5) << " 0 rlineto \n";
	//	fileOutput << "closepath \n";
	//	fileOutput << "clip \n";
	//	fileOutput << "1 setlinewidth \n";
	//	fileOutput << "0 setgray \n";
	//	fileOutput << "stroke \n";
		


	//	//CLIP SPACE		
	//	fileOutput << "newpath \n";
	//	fileOutput << "579 12 moveto \n";
	//	fileOutput << "0 " <<noDataList.at(i).size.at(1) << " rlineto \n";
	//	fileOutput << noDataList.at(i).size.at(0) <<" 0 rlineto \n";
	//	fileOutput << "0 " << -noDataList.at(i).size.at(1) << " rlineto \n";
	//	fileOutput << "closepath \n";
	//	fileOutput << "clip \n";

	
		
//	//CLIP SPACE
//	fileOutput << "newpath \n";
//	//fileOutput << "10 10 moveto \n";
//	fileOutput << (579 - ((noDataList.at(i).size.at(0)) * 7.370078742)) - noDataList.at(i).maxColumn * (7.4) << " " << 12 << " moveto \n";
//	fileOutput << "0 " << (noDataList.at(i).size.at(1) * 7.370078742) + noDataList.at(i).maxRow * (7.4) << " rlineto \n";
//	fileOutput << noDataList.at(i).size.at(0) * 7.370078742 + noDataList.at(i).maxColumn * (7.4) << " 0 rlineto \n";
//	fileOutput << "0 " << (-noDataList.at(i).size.at(1)* 7.370078742) - noDataList.at(i).maxRow * (7.4) << " rlineto \n";
//	fileOutput << noDataList.at(i).size.at(0) * 7.370078742 + noDataList.at(i).maxColumn * (7.4) << " 0 rlineto \n";
//	fileOutput << "closepath \n";
//	fileOutput << "clip \n";
//	fileOutput << "0 setlinewidth \n";
//	fileOutput << "1 setgray \n";
//	fileOutput << "stroke \n";
//	fileOutput << "0 setgray \n";

		//595x842

		//mirror and stuff
		//fileOutput << "-1 1 scale \n";
		//fileOutput << "-450 300  translate \n";
		
		fileOutput << "/heol " << (579 - ((noDataList.at(i).size.at(0)) * 7.370078742)) - noDataList.at(i).maxColumn * (7.4)<< " def \n";
		//3.5 offset for lines
		fileOutput << "/veol " <<(noDataList.at(i).size.at(1) * 7.370078742) + (noDataList.at(i).maxRow + 2) * (7.4) << " def \n";

		//definiera linjer
		fileOutput << "/xstart 579 def \n";
		fileOutput << "/ystart 12 def \n";




	//	fileOutput << "1 0 0 setrgbcolor \n";
		
	//	//stödlinjer
	//	//Get lodrät
	//	fileOutput << 100 << "{ xstart ystart moveto heol ystart lineto 0.2 setlinewidth stroke /ystart ystart 7.370078742 add def} repeat \n ";
	//
	//	//restarta linjer
	//	fileOutput << "/xstart 579 def \n";
	//	fileOutput << "/ystart 12 def \n";
	//
	//	//Get vågrät
	//	fileOutput << 100 << "{ xstart ystart moveto xstart veol lineto 0.2 setlinewidth stroke /xstart xstart 7.370078742 sub def} repeat \n ";
	//
	//	//restarta linjer
	//	fileOutput << "/xstart 579 def \n";
	//	fileOutput << "/ystart 12 def \n";
	//
	//	//end stödlinjer



		//Get lodrät
		fileOutput << noDataList.at(i).size.at(1) << "{ xstart ystart moveto heol ystart lineto 0.2 setlinewidth stroke /ystart ystart 7.370078742 add def} repeat \n ";

		//restarta linjer
		fileOutput << "/xstart 579 def \n";
		fileOutput << "/ystart 12 def \n";
		
		//Get vågrät
		fileOutput << noDataList.at(i).size.at(0) << "{ xstart ystart moveto xstart veol lineto 0.2 setlinewidth stroke /xstart xstart 7.370078742 sub def} repeat \n ";

		//restarta linjer
		fileOutput << "/xstart 579 def \n";
		fileOutput << "/ystart 12 def \n";

		//Räkna ut hur många tjocka (add one to get borders)
		int vTj = (noDataList.at(i).size.at(0) / 5) + 1;
		int hTj = (noDataList.at(i).size.at(1) / 5) + 1;
		
		fileOutput << hTj << " { xstart ystart moveto heol ystart lineto 1 setlinewidth stroke /ystart ystart 36.85039371 add def} repeat \n";
		
		//restarta linjer
		
		fileOutput << "/xstart 579 def \n";
		fileOutput << "/ystart 12 def \n";

		fileOutput << vTj << " { xstart ystart moveto xstart veol lineto 1 setlinewidth stroke /xstart xstart 36.85039371 sub def} repeat \n";
		
		//Siffrorna
		fileOutput << "/Courier findfont \n";
		fileOutput << "7.5 scalefont \n";
		fileOutput << "setfont \n";  
		fileOutput << "newpath \n";
		
		fileOutput << "0.75 1 scale \n";


		
		//Kanske för att höger justera: http://www.cs.utsa.edu/~wagner/CS3723/postrecs/justify/just.html

		//reset where numbers start
		float rowX = 0, rowY = 0, columnX = 0, columnY = 0;

		rowX = (595 - ((noDataList.at(i).size.at(0)+3) * 7.370078742));
		rowY = (noDataList.at(i).size.at(1) * 7.370078742) + 6.5;

		rowX = (575.5 * 1.333 - ((noDataList.at(i).size.at(0) * 1.333) * 7.370078742));
		rowY = (noDataList.at(i).size.at(1) * 7.370078742) + 5.7;

		fileOutput << "/xstart " << (rowX) << " def \n";
		fileOutput << "/ystart " << (rowY) << " def \n";
		fileOutput << "/xReset " << (rowX) << " def \n";
		fileOutput << "/yReset " << (rowY) << " def \n";
		
		int minusCounter = 0;

		for (int q = 0; q < noDataList.at(i).column.size(); q++)
		{
			
			fileOutput << "xstart ystart moveto \n";
			if (noDataList.at(i).column.at(q) == -1)
			{
				if (minusCounter == 1)
				{
					fileOutput << "(" << 0 << ") dup stringwidth pop 2 div neg 0 rmoveto show  \n";
				}
				fileOutput << "/ystart ystart 7.37 sub def \n";
				fileOutput << "/xstart xReset def \n";
				minusCounter ++;
			}
			
			//fileOutput << q * 7 << " " << (q * 7) << " moveto  \n"
			
			
			//fileOutput << "/ystart ystart 7.35 add def \n";
			if (noDataList.at(i).column.at(q) != -1)
			{

				fileOutput << "(" << noDataList.at(i).column.at(q) << ") dup stringwidth pop 2 div neg 0 rmoveto show  \n";
				//fileOutput << "show  \n";
				fileOutput << "/xstart xstart 7.370078742 1.333 mul sub def \n";
				minusCounter = 0;

			}
			//fileOutput << "/xstart xstart 7.5 sub def \n";
			//fileOutput << "xstart ystart moveto \n";
		
			
			//fileOutput << "xSaved ystart moveto \n";

			fileOutput << "0.5 setlinewidth \n";
			//fileOutput << "1 setgray \n";
			fileOutput << "stroke \n";
			
		}
		

		//HORIZONTELLA
		//reset where numbers start
		
		rowX = (595 - ((noDataList.at(i).size.at(0) + 3) * 7.370078742));
		rowY = (noDataList.at(i).size.at(1) * 7.370078742) + 6.5;

		rowX = (575.5 * 1.333 - ((noDataList.at(i).size.at(0) * 1.333) * 7.370078742));
		rowY = ((noDataList.at(i).size.at(1)+0.8) * 7.370078742) + 7.5;


		//skala siffrorna
		//fileOutput << "0.75 1 scale \n";

		fileOutput << "/xstart " << (rowX) << " def \n";
		fileOutput << "/ystart " << (rowY) << " def \n";
		fileOutput << "/xReset " << (rowX) << " def \n";
		fileOutput << "/yReset " << (rowY) << " def \n";
	
		minusCounter = 0;

		for (int q = 0; q < noDataList.at(i).row.size(); q++)
		{
		
			fileOutput << "xstart ystart moveto \n";
			if (noDataList.at(i).row.at(q) == -1)
			{
				if (minusCounter == 1)
				{
					fileOutput << "(" << 0 << ") dup stringwidth pop 2 div neg 0 rmoveto show  \n";
				}
				fileOutput << "/xstart xstart 7.370078742 1.333 mul add def \n";
				fileOutput << "/ystart yReset def \n";
				minusCounter++;
			}
	
			//fileOutput << q * 7 << " " << (q * 7) << " moveto  \n"
			//fileOutput << "/ystart ystart 7.35 add def \n";
			if (noDataList.at(i).row.at(q) != -1)
			{
				
				{
					fileOutput << "(" << noDataList.at(i).row.at(q) << ") dup stringwidth pop 2 div neg 0 rmoveto show  \n";
				}
				fileOutput << "/ystart ystart 7.370078742 add def \n";
				minusCounter = 0;
			}
			//fileOutput << "/xstart xstart 7.5 sub def \n";
			//fileOutput << "xstart ystart moveto \n";
	
	
			//fileOutput << "xSaved ystart moveto \n";
	
			fileOutput << "0.5 setlinewidth \n";
			//fileOutput << "1 setgray \n";
			fileOutput << "stroke \n";
	
		}
	

			/// x 450 def % right end of every line
			/// y 680 def % initial height of line

		
		

		


		fileOutput << "showpage \n";
		fileOutput << "%%EOF\n";

		//fileOutput << noDataList.at(i).size.at(0) << " " <<  noDataList.at(i).size.at(1);
		
		fileOutput.close();
	}


}


void epsOutput::createSolutionEPSfiles(std::vector<noData> noDataList, std::vector<std::string> TextFileList)
{

	for (int i = 0; i < noDataList.size(); i++)
	{
		std::ofstream fileOutput;
		std::string fileName = TextFileList.at(i);


		//Get rid of .txt
		for (int j = 0; j < 4; j++)
		{
			fileName.pop_back();
		}
		//add .eps
		fileName += "_Solution";
		fileName += ".eps";

		fileOutput.open("../outputFiles/" + fileName);

		fileOutput << "%!PS-Adobe-3.0 \n";
		
		
		
		fileOutput << "%%BoundingBox: " << (578 - ((noDataList.at(i).size.at(0)) * 7.370078742)) << " 11 " << "580 " << ((noDataList.at(i).size.at(1) * 7.370078742)) + 13 << " \n";
		//fileOutput << "%%BoundingBox: " << (579 - ((noDataList.at(i).size.at(0)) * 7.370078742)) - noDataList.at(i).maxColumn * (7.5) << " 0 " << (((noDataList.at(i).size.at(0)) * 7.370078742)) + (575 - ((noDataList.at(i).size.at(0)) * 7.370078742) + (noDataList.at(i).maxColumn * 7.370078742 * 2)) << " " << (((noDataList.at(i).size.at(1)) * 7.370078742)) + (noDataList.at(i).maxRow * 7.370078742 * 2) << " \n";
		
		

	//	//CLIP SPACE
	//	fileOutput << "newpath \n";
	//	//fileOutput << "10 10 moveto \n";
	//	fileOutput << (579 - ((noDataList.at(i).size.at(0)) * 7.370078742)) << " " << 12 << " moveto \n";
	//	fileOutput << "0 " << (noDataList.at(i).size.at(1) * 7.370078742) << " rlineto \n";
	//	fileOutput << noDataList.at(i).size.at(0) * 7.370078742 << " 0 rlineto \n";
	//	fileOutput << "0 " << (-noDataList.at(i).size.at(1)* 7.370078742) << " rlineto \n";
	//	fileOutput << noDataList.at(i).size.at(0) * 7.370078742 << " 0 rlineto \n";
	//	fileOutput << "closepath \n";
	//	fileOutput << "clip \n";
	//	fileOutput << "0 setlinewidth \n";
	//	fileOutput << "1 setgray \n";
	//	fileOutput << "stroke \n";
	//	fileOutput << "0 setgray \n";

		//mirror and stuff
		//fileOutput << "-1 1 scale \n";
		//fileOutput << "-450 300  translate \n";
	//	fileOutput << "/heol 0 def \n";
	//	fileOutput << "/veol 834 def \n";


		fileOutput << "/heol " << (579 - ((noDataList.at(i).size.at(0)) * 7.370078742)) - (0) << " def \n";
		//3.5 offset for lines


		fileOutput << "/veol " << (noDataList.at(i).size.at(1) * 7.370078742) + (12.370078742) << " def \n";

		//definiera linjer
		fileOutput << "/xstart 579 def \n";
		fileOutput << "/ystart 12 def \n";

		//colortemp
		fileOutput << "0 0 0 setrgbcolor \n";

		
		//Get lodr�t
		fileOutput << noDataList.at(i).size.at(1) << "{ xstart ystart moveto heol ystart lineto 0.2 setlinewidth stroke /ystart ystart 7.370078742 add def} repeat \n ";

		//restarta linjer
		fileOutput << "/xstart 579 def \n";
		fileOutput << "/ystart 12 def \n";

		//Get v�gr�t
		fileOutput << noDataList.at(i).size.at(0) << "{ xstart ystart moveto xstart veol lineto 0.2 setlinewidth stroke /xstart xstart 7.370078742 sub def} repeat \n ";

		//restarta linjer
		fileOutput << "/xstart 579 def \n";
		fileOutput << "/ystart 12 def \n";

		//R�kna ut hur m�nga tjocka (add one to get borders)
		int vTj = (noDataList.at(i).size.at(0) / 5) + 1;
		int hTj = (noDataList.at(i).size.at(1) / 5) + 1;

		fileOutput << hTj << " { xstart ystart moveto heol ystart lineto 1 setlinewidth stroke /ystart ystart 36.85039371 add def} repeat \n";

		//restarta linjer

		fileOutput << "/xstart 579 def \n";
		fileOutput << "/ystart 12 def \n";

		fileOutput << vTj << " { xstart ystart moveto xstart veol lineto 1 setlinewidth stroke /xstart xstart 36.85039371 sub def} repeat \n";

		//Siffrorna
		fileOutput << "/Arial-Narrow findfont \n";
		fileOutput << "7.5 scalefont \n";
		fileOutput << "setfont \n";
		fileOutput << "newpath \n";

		fileOutput << "0.75 1 scale \n";
		//skala siffrorna


		//Kanske f�r att h�ger justera: http://www.cs.utsa.edu/~wagner/CS3723/postrecs/justify/just.html

		//reset where numbers start
		float rowX = 0, rowY = 0, columnX = 0, columnY = 0;

		rowX = (575 * 1.333 - ((noDataList.at(i).size.at(0) * 1.333) * 7.370078742));
		rowY = (noDataList.at(i).size.at(1) * 7.370078742) + 5.7;


		fileOutput << "/xstart " << (rowX) << " def \n";
		fileOutput << "/ystart " << (rowY) << " def \n";
		fileOutput << "/xReset " << (rowX) << " def \n";
		fileOutput << "/yReset " << (rowY) << " def \n";

		int minusCounter = 0;


		//HORIZONTELLA
		//reset where numbers start

		rowX = (575 * 1.333 - ((noDataList.at(i).size.at(0) * 1.333) * 7.370078742));
		rowY = ((noDataList.at(i).size.at(1) + 1) * 7.370078742) + 7.5;


		fileOutput << "/xstart " << (rowX) << " def \n";
		fileOutput << "/ystart " << (rowY) << " def \n";
		fileOutput << "/xReset " << (rowX) << " def \n";
		fileOutput << "/yReset " << (rowY) << " def \n";
		//skala siffrorna

		minusCounter = 0;

		fileOutput << "1.33333 1 scale \n";
		/// x 450 def % right end of every line
		/// y 680 def % initial height of line


		rowX = (595 - ((noDataList.at(i).size.at(0) + 2) * 7.370078742));
		rowY = (noDataList.at(i).size.at(1) * 7.340078742) + 6.5;

		rowX = (575 * 1.333 - ((noDataList.at(i).size.at(0) * 1.333) * 7.370078742));
		rowY = ((noDataList.at(i).size.at(1) + 1) * 7.370078742) + 7.5;

		rowX = noDataList.at(i).size.at(1);
		rowY = noDataList.at(i).size.at(0);


	//	fileOutput << "/xstart " << ((593.7 - ((noDataList.at(i).size.at(0) + 2) * 7.370078742))) << " def \n";
	//	fileOutput << "/ystart " << ((noDataList.at(i).size.at(1) * 7.330078742) + 5.5) << " def \n";
	//	fileOutput << "/xReset " << ((593.7 - ((noDataList.at(i).size.at(0) + 2) * 7.370078742))) << " def \n";
	//	fileOutput << "/yReset " << ((noDataList.at(i).size.at(1) * 7.330078742) + 5.5) << " def \n";

		
		
		
		fileOutput << "/xstart " << (579 - ((noDataList.at(i).size.at(0)) * 7.370078742)) - (0) << " def \n";
		fileOutput << "/ystart " << (noDataList.at(i).size.at(1) * 7.370078742) + (4.5) << " def \n";
		fileOutput << "/xReset " << (579 - ((noDataList.at(i).size.at(0)) * 7.370078742)) - (0) << " def \n";
		fileOutput << "/yReset " << (noDataList.at(i).size.at(1) * 7.370078742) + (4.5) << " def \n";



		fileOutput << "/csquare{ \n";
		fileOutput << "newpath \n";
		fileOutput << "0 0 moveto \n";
		fileOutput << "0 7.45 rlineto \n";
		fileOutput << "7.45 0 rlineto \n";
		fileOutput << "0 -7.45 rlineto \n";
		fileOutput << "closepath \n";
		fileOutput << "0 0 0 setrgbcolor \n";
		fileOutput << "fill \n";
		fileOutput << "} def \n\n";

		//PostScriptLoop
		//fileOutput << noDataList.at(i).size.at(0) << "{ xstart ystart moveto 1 0 0 csquare /xstart xstart 7.370078742 sub def} repeat \n";

		//C++ loop

		int row = 0, column = 0, place = 0;

		fileOutput << "xstart ystart translate \n";
		for (int z = 0; z < rowX; z++)
		{
			//fileOutput << "1 0 0 csquare \n";


			for (int w = 0; w < rowY; w++)
			{
				if (noDataList.at(i).picture.at(place) == '#')
				{
					fileOutput << "0 0 0 csquare \n";
				}
				place++;

				fileOutput << 7.370078742 << " " << 0 << " translate \n";
				//fileOutput << 7.370078742 << " " << 0 << " translate \n";
			}
			
				fileOutput << -7.370078742 * (rowY) << " " << -7.370078742 << " translate \n";
			
			


		}


		fileOutput << "showpage \n";
		fileOutput << "%%EOF\n";

		//fileOutput << noDataList.at(i).size.at(0) << " " <<  noDataList.at(i).size.at(1);

		fileOutput.close();
	}


}