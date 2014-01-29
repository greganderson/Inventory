#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cstdlib>
#include "fooditem.h"

using namespace std;

void parse_txt(string filename);
void parse_by_line(string filename);

int main()
{

  parse_txt("data3.txt");
  parse_by_line("data3.txt");

  fooditem item1;

  item1.upc("84404");
  item1.s_life(8);
  item1.Name("nutella");

  return 0;

}


void parse_txt(string filename)
{

  fooditem item;

  ifstream in(filename.c_str());

  // Loop for reading the file.  Note that it is controlled
  //   from within the loop (see the 'break').
    
  while (true)
	{
		string word;
		in >> word;

		// If the read failed, we're probably at end of file
		//   (or else the disk went bad).  Exit the loop.
		if (in.fail())
			break;

		// Word successfully read.  Add it to both sets.
		if(word == "FoodItem")
		{
			string nextWord;
			in >> word;
			in >> word;

			in >> nextWord;
			
			if(word == "UPC" && nextWord == "Code:")
			{
				string upcCode;
				in >> upcCode;
				item.upc(upcCode);

				//Advance to the next word.
				in >> word;
			}
			if(word == "Shelf")
			{
				in >> nextWord;
				if(nextWord == "life:")
				{
					string shelfLife;
					in >> shelfLife;

					item.s_life(atoi(shelfLife.c_str()));

					//Advance to the next word.
					in >> word;
				}
			}
			if(word == "Name:")
			{
				string Name;

				getline(in, Name);
				
				item.Name(Name);
			}
		}
	}
  // Close the file.
  in.close();

  cout << "UPC Code: " << item.getUPC() << endl;
  cout << "Shelf Life: " << item.getSLife() << endl;
  cout << "Name: " << item.getName() << endl;
  cout << endl;

}

/**
 *Reading the txt by line.
 *
 */
void parse_by_line(string filename)
{

  ifstream inFile (filename.c_str());

  string line;

  //ofstream outFile("note_new.txt");
  int count = 0;
  while( getline(inFile, line) ) 
    {
      count++;
    }
  cout << "Theres " << count << " lines in the file " << filename << endl;
}
