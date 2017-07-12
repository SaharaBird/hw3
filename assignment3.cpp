#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct lineWithCharCount {
	string line;
	int charInLine;
};

// Desc: openFile function opens a file and read the binary data from the file.
// Input: file name as a string
// Output: function returns void
// Error conditions: If file doesn't exist, output an error message then terminates the program

void openFile(string f1) {
	if ( ifstream(f1) ) { //f1 = "file.txt";
		cout << "file exist. begin computing." << endl;
	}
	else {
		cout << "file doesn't exist. Terminate the program." << endl;
		exit(-1);
	}
}

// Desc: readFile function takes a string input (pass by value), which is the file name and return
// the entire file as a string
// Input: A filename as a string
// Output: entire file as a type string
// Error conditions: none

string readFile(string f1 ) {
	ifstream myfile(f1);
	lineWithCharCount fileLine;
	int lineCounter = 0;
	int storeNumOfCharInOneLine;
	string storeFileContent = "";

	while (getline(myfile, fileLine.line)) { // while !end of the file
		if ( lineCounter == 0 ) {
			storeNumOfCharInOneLine = fileLine.line.length(); // string concatnetion
		}
		storeFileContent = storeFileContent + fileLine.line;
		lineCounter = lineCounter + 1; // total number of lines from the file
	}
	myfile.close();
	return storeFileContent;
}

// Desc: outputFile takes input file, output file name, the entire string input as paramenter
// and creates the compliment file that has the opposite value in it. Meaning
// For every A, output T; for every T, output A; for every G, output C; for every C, output G
// Input: input filename, output file name, then the entire string from the file
// Output: The functions number of lines from each file as a return value
// The function also creates the complement.txt file in the path you are at
// Error conditions: none
int outputFile(string fun_fileName, string outputFileName, string fun_fileString) {
	ifstream myfile(fun_fileName);
	ofstream outputFile(outputFileName);
	cout << outputFileName << " has been created in local path" << endl;
	int lineBreakCounter = 0;
	int lineCounter = 0;
	int storeNumOfCharInOneLine;
	lineWithCharCount fileLine;
	while( getline(myfile, fileLine.line) ) {
		if (lineCounter == 0) {
			storeNumOfCharInOneLine = fileLine.line.length(); // storeNumOfCharInOneLine stores number of character in the variable
		}
		lineCounter = lineCounter + 1;

	}

	for (int i = 0; i < fun_fileString.length(); i ++ ) {
		if (lineBreakCounter < storeNumOfCharInOneLine ) { // this is to create the output file mimic with the input file style. meaning creating a line break at certain number of characters
			if ( fun_fileString.at(i) == 'A' ) {
				outputFile << 'T';
				lineBreakCounter = lineBreakCounter + 1;
			}
			if ( fun_fileString.at(i) == 'T' ) {
				outputFile << 'A';
				lineBreakCounter = lineBreakCounter + 1;
			}
			if ( fun_fileString.at(i) == 'G' ) {
				outputFile << 'C';
				lineBreakCounter = lineBreakCounter + 1;
			}
			if ( fun_fileString.at(i) == 'C' ) {
				outputFile << 'G';
				lineBreakCounter = lineBreakCounter + 1;
			}
		}
		else { 
			outputFile << endl; // when reached at the end of the line, create a new line
			lineBreakCounter = 0;
			if ( fun_fileString.at(i) == 'A' ) {
				outputFile << 'T';
				lineBreakCounter = lineBreakCounter + 1;
			}
			if ( fun_fileString.at(i) == 'T' ) {
				outputFile << 'A';
				lineBreakCounter = lineBreakCounter + 1;
			}
			if ( fun_fileString.at(i) == 'G' ) {
				outputFile << 'C';
				lineBreakCounter = lineBreakCounter + 1;
			}
			if ( fun_fileString.at(i) == 'C' ) {
				outputFile << 'G';
				lineBreakCounter = lineBreakCounter + 1;
			}
		}
	}

	return lineCounter; // returns total number of lines in one file
}

// Desc: compareFile function takes two string from the file concatenation and find the global aligmnent for 2 files
// Input: this function takes 4 parameters. String concatnation from first and second file; then total number of lines from 2 files
// Output: compareFile returns the smaller lines from whichever file it is. 
// Error conditions: none
int compareFile (string fun_firstFileString, string fun_secondFileString, int fun_totalLineInFileOne, int fun_totalLineInFileTwo ) {
	int minLineCounter;
	if (fun_totalLineInFileOne < fun_totalLineInFileTwo) {
		minLineCounter = fun_totalLineInFileOne;
	}
	if (fun_totalLineInFileOne > fun_totalLineInFileTwo ) {
		minLineCounter = fun_totalLineInFileTwo;
	}
	if ( fun_totalLineInFileOne == fun_totalLineInFileTwo ) {
		minLineCounter = fun_totalLineInFileOne;
	}

	int minStringLength;
	if ( fun_firstFileString.length() < fun_secondFileString.length() ) {
		minStringLength = fun_firstFileString.length();
	}
	if ( fun_firstFileString.length() > fun_secondFileString.length() ) {
		minStringLength = fun_secondFileString.length();
	}
	if ( fun_firstFileString.length() == fun_secondFileString.length() ) {
		minStringLength = fun_firstFileString.length();
	}

	int matchScore = 0;
	// this for loop counts the file matches up till the small file from the minStringlength variable
	for ( int i = 0; i < minStringLength; i++ ) {
		if (fun_firstFileString.at(i) == fun_secondFileString.at(i) ) {
			matchScore = matchScore + 1;
		}
	}
	cout << "The global alighment of s1 and s2 is: " << matchScore << endl;
	return minLineCounter;

}

// Desc: count_score function takes file name and calculates the total value of stop condons
// Input: file name as a string input
// Output: returns an integer total_Score which is total score of stop codons to countAminoAcid function
// Error conditions: none
int count_score( string fileString ) {
	int TAA_Score = 0;
	int TAG_Score = 0;
	int TGA_Score = 0;
	int total_Score;

	for ( int i = 0; i < fileString.length(); i++ ) {
		if ( fileString.substr(i, 3) == "TAA" ) {
			TAA_Score = TAA_Score + 1;
		}
	}

	for ( int i = 0; i < fileString.length(); i++ ) {
		if ( fileString.substr(i, 3) == "TAG" ) {
			TAG_Score = TAG_Score + 1;
		}
	}

	for ( int i = 0; i < fileString.length(); i++ ) {
		if ( fileString.substr(i, 3) == "TGA" ) {
			TGA_Score = TGA_Score + 1;
		}
	}

	total_Score = TAA_Score + TAG_Score + TGA_Score;

	return total_Score;
}

// Desc: countAminoAcid function takes 2 file concatenate strings and outputs number of stop codons from each file
// Input: takes 2 file from the string concatenation format
// Output: cout the number of stop codons from each file
// Error conditions: none
void countAminoAcid( string fun_firstFileString, string fun_secondFileString ) {
	int firstFile_Score = count_score(fun_firstFileString);
	int secondFile_Score = count_score(fun_secondFileString);

	cout << "Stop codons found for s1 is: " << firstFile_Score << endl;
	cout << "Stop codons found for s2 is: " << secondFile_Score << endl;
}



int main () {
	string firstFile, secondFile;
	cout << "enter your fileName:" << endl;
	cin >> firstFile;
	openFile( firstFile );
	// stores entire file as string to string variable called firstFile
	string firstFileString = readFile (firstFile); 

	cout << "enter your second file name:" << endl;
	cin >> secondFile;
	openFile( secondFile );
	string secondFileString = readFile (secondFile);

	string outputFile1 = "s1_compliment.txt";
	int totalLineInFileOne = outputFile(firstFile, outputFile1, firstFileString);

	string outputFile2 = "s2_compliment.txt";
	int totalLineInFileTwo = outputFile(secondFile, outputFile2, secondFileString );

	int main_minLineInFile = compareFile(firstFileString, secondFileString, totalLineInFileOne, totalLineInFileTwo );

	countAminoAcid(firstFileString, secondFileString);

	return 0;

}
