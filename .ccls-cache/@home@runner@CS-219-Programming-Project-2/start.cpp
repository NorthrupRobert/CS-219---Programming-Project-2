/**
	-CS219 PP1, Start File-
    Will process the "operations.txt" file using the processes from
	the hexoperations.cpp file and basic file I/O.  Title screen
	included.
    @file start.cpp
    @author Robb Northrup
    @version 1.0 1/28/2022
*/

#include <iostream>
#include <fstream>
#include <string>
#include "start.h"
#include "hexoperations.h"

/**
    Converts hexidecimal number to decimal.
    @param fileName - given by Start() function when called
    @return inFile - file to be decoded and perform the 
					 appropriate functions
*/

std::ifstream LoadFile(std::string fileName) {
	std::ifstream inFile;
	std::string temp;
	int numLines;
	int numObjects;

	inFile.open(fileName);
	if (inFile.fail()) { //throw if fails to open the file
		throw ("FAILED TO OPEN \"" + fileName + "\"!");
	}
	for (numLines = 0; !inFile.eof(); numLines++) { //checks to ensure there are three objects per line: one operator followed by two arguments
		getline(inFile, temp);
	}

	inFile.close();
	inFile.open(fileName);

	for (numObjects = 0; !inFile.eof(); numObjects++) { //continues the above-mentioned check . . .
		inFile >> temp;
		if ((numObjects % 3 == 0) && temp != "ADD")
			throw ("\"" + fileName + "\" FORMATED INCORRECTLY!"); //uses operators?
		else if ((numObjects % 3 != 0) && (temp.substr(0,2) != "0x")) {
			throw ("\"" + fileName + "\" FORMATED INCORRECTLY!  HEX NUMBERS MUST HAVE 0x PREFIX"); //hex prefix present?
			for (int i = 0; i < temp.size(); i++) { //hex numbers formatted correctly?
				if (!isdigit(temp.at(i)) || temp.at(i) != 'A' || temp.at(i) != 'B' ||
				temp.at(i) != 'C' || temp.at(i) != 'D' || temp.at(i) != 'E' ||
				temp.at(i) != 'F')
					throw ("HEX NUMBERS ARE NOT FORMATTED CORRECTLY, ENSURE\nALPHA CHARACTERS ARE A-F AND UPPERCASE!");
			}
		}
	}

	if ((numObjects % numLines) != 0) { //correct number of objects?
		throw ("\"" + fileName + "\" FORMATED INCORRECTLY!");
	}

	inFile.close();
	inFile.open(fileName); //continues after format checking, opens last time for program use

	return inFile;
}

/**
    Writes file to the console
    @param inFile
*/

void DisplayFile(std::ifstream &inFile) {
	while(!inFile.eof()) {
			std::string temp;
			inFile >> temp;
			std::cout << temp << std::endl;
		} //doesn't display the doc with tabs, only spaces . . . so far
}

/**
    Converts hexidecimal number to decimal.
    @param inFile - file with commands to perform the functions
					already designated to the program.
*/

void Processor(std::ifstream inFile) {
	std::string op;
	std::string arg1;
	std::string arg2;

	do {
		inFile >> op;
		inFile >> arg1;
		inFile >> arg2;
		if (op == "ADD") //should the operator be "ADD", will add the two hex numbers and spew an answer also in hex
			std::cout << "SUM OF " << arg1 << " AND " << arg2 << " -> " << ConvertDecimalToHex(Add(ConvertHexToDecimal(arg1), ConvertHexToDecimal(arg2))) << std::endl;
	} while(!inFile.eof()); //until end of doc
}

/**
    Displays title
*/

void TitleScreen() {
	std::cout << "================================" << std::endl;
	std::cout << "----PROGRAMMING ASSIGNMENT 1----" << std::endl;
	std::cout << "================================" << std::endl; //yup
}