#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	//Assignt hein and out stream 
	ifstream in_stream;
	ofstream out_stream;
	// Open input and output text files
	in_stream.open(" letter.txt");
	out_stream.open("encode.txt ");

	//Check that input file opened
	if (in_stream.fail())
	{
		cout << " Input file opening failed. \n";
		exit(1);
	}

	// Check that output file opened
	if (out_stream.fail())
	{
		cout << " outputfile opening failed. \ n";
		exit(1);
	}

	// set arrays
	char FindWord[14] = { ' t ' , ' T' , ' h' , ' H' , ' j ' , ' J' , ' d' , ' D' , ' a' , ' A' , ' p' , ' P' ,' i ' , ' I ' };
	string ReplaceWord[14] = { " 1Y" , " 1Y" , " 1O" , " 1O" , " 1X" , " 1X" , " 1B" , " 1B" , " 1S" ," 1S" , " 1M" , " 1M" , " 1Q" , " 1Q" };

	//Nested while loop to extract datafrom.dat 
	string line;

	while (getline(in_stream, line)) // Getfile
	{
		for (int i = 0; i <= 14; i++) // iterate
		{
			while (1) // while true change the current iterated value
			{


				int index = line.find(FindWord[i]);

				if (index != -1)
				{
					line.replace(index, 1, ReplaceWord[i]);
				}
				else
				{
					break; // break while loop
				}
			}
		}
		// Display eachiterated value accordingly
			out_stream << line << ' \n';
		cout << line << ' \n';
	}

	in_stream.close();
	out_stream.close();

	system("pause");
	return(0);
}