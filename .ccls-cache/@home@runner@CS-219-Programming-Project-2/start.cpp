/**
	-CS219 PP2, Start File-
    Will process the "operations.txt" file using the processes from
	the hexoperations.cpp file and basic file I/O.  Title screen
	included.
    @file start.cpp
    @author Robb Northrup
    @version 1.0 3/3/2022
*/

#include <iostream>
#include <fstream>
#include <string>
#include "start.h"
#include "hexoperations.h"

using std::endl, std::cout;

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

	//cout << "ABOUT TO OPEN FILE" << endl;
	inFile.open(fileName);
	if (inFile.fail()) { //throw if fails to open the file
		throw ("FAILED TO OPEN \"" + fileName + "\"!");
	}
	//cout << "OPENED FILE" << endl;
	for (numLines = 0; !inFile.eof(); numLines++) { //checks to ensure there are three objects per line: one operator followed by two arguments
		getline(inFile, temp);
	}
	//cout << "CHECKED NUM OBJECTS AND LINES" << endl;

	// inFile.close();
	// inFile.open(fileName);

	// cout << "REOPENING FILE" << endl;
	// cout << "CHECKING OPERATORS" << endl;
	
	// for (numObjects = 0; !inFile.eof(); numObjects++) { //continues the above-mentioned check . . .
	// 	inFile >> temp;
	// 	if ((numObjects % 3 == 0) && ((temp != "ADD") || (temp != "AND") ||(temp != "ASR") || (temp != "LSR") || (temp != "LSL") || (temp != "NOT") || (temp != "ORR") || (temp != "SUB") || (temp != "XOR")))
	// 		throw ("\"" + fileName + "\" FORMATED INCORRECTLY!"); //uses operators?
	// 	else if ((numObjects % 3 != 0) && (temp.substr(0,2) != "0x")) {
	// 		throw ("\"" + fileName + "\" FORMATED INCORRECTLY!  HEX NUMBERS MUST HAVE 0x PREFIX"); //hex prefix present?
	// 		for (int i = 0; i < temp.size(); i++) { //hex numbers formatted correctly?
	// 			if (!isdigit(temp.at(i)) || temp.at(i) != 'A' || temp.at(i) != 'B' ||
	// 			temp.at(i) != 'C' || temp.at(i) != 'D' || temp.at(i) != 'E' ||
	// 			temp.at(i) != 'F')
	// 				throw ("HEX NUMBERS ARE NOT FORMATTED CORRECTLY, ENSURE\nALPHA CHARACTERS ARE A-F AND UPPERCASE!");
	// 		}
	// 	}
	// }

	// cout << "FORMATTED CORRECTLY" << endl;
	
	// if ((numObjects % numLines) != 0) { //correct number of objects?
	// 	throw ("\"" + fileName + "\" FORMATED INCORRECTLY!");
	// }

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

	//std::cout << "IN PROCESSOR" << std::endl;
	int i = 1;
	do {
		//std::cout << "reading line " << i << std::endl;
		inFile >> op;
		if (op == "ADD" || op == "ORR" || op == "SUB" || op == "XOR") { //operations that require 2 operators
			inFile >> arg1;
			inFile >> arg2;

			if (arg1.substr(0,2) != "0x" && arg2.substr(0,2) != "0x")
				throw ("THE FILE IS FORMATED INCORRECTLY!");
			
			if (op == "ADD") {//should the operator be "ADD", will add the two hex numbers and spew an answer also in hex
				std::cout << "SUM OF " << arg1 << " AND " << arg2 << " -> " << ConvertDecimalToHex(ADD(ConvertHexToDecimal(arg1), ConvertHexToDecimal(arg2))) << std::endl;
			}
			else if (op == "AND") {//bitwise "AND" on both operands
				std::cout << "AND BITWISE OPERATION ON " << arg1 << " AND " << arg2 << " -> " << ConvertDecimalToHex(AND(ConvertHexToDecimal(arg1), ConvertHexToDecimal(arg2))) << std::endl;
			}
			else if (op == "ORR") {//bitwise "AND" on both operands
				std::cout << "ORR BITWISE OPERATION ON " << arg1 << " AND " << arg2 << " -> " << ConvertDecimalToHex(ORR(ConvertHexToDecimal(arg1), ConvertHexToDecimal(arg2))) << std::endl;
			}
			else if (op == "SUB") {//bitwise "AND" on both operands
				std::cout << "DIFFERENCE OF " << arg1 << " AND " << arg2 << " -> " << ConvertDecimalToHex(SUB(ConvertHexToDecimal(arg1), ConvertHexToDecimal(arg2))) << std::endl;
			}
			else if (op == "XOR") {//bitwise "AND" on both operands
				std::cout << "XOR BITWISE OPERATION ON " << arg1 << " AND " << arg2 << " -> " << ConvertDecimalToHex(XOR(ConvertHexToDecimal(arg1), ConvertHexToDecimal(arg2))) << std::endl;
			}
		}
		else if (op == "ASR" || op == "LSR" || op == "LSL" || op == "NOT") { // if operator that only utilizes one operand
			inFile >> arg1;
			if (arg1.substr(0,2) != "0x")
				throw ("THE FILE IS FORMATTED INCORRECTLY 1!");
			if (op == "ASR") {
				std::cout << "ARITHMETIC SHIFT RIGHT OF " << arg1 << " -> " << ConvertDecimalToHex(ASR(ConvertHexToDecimal(arg1))) << std::endl;
			}
			else if (op == "LSR") {
				std::cout << "LOGICAL SHIFT RIGHT OF " << arg1 << " -> " << ConvertDecimalToHex(LSR(ConvertHexToDecimal(arg1))) << std::endl;
			}
			else if (op == "LSL") {
				std::cout << "LOGICAL SHIFT LEFT OF " << arg1 << " -> " << ConvertDecimalToHex(LSL(ConvertHexToDecimal(arg1))) << std::endl;
			}
			else if (op == "NOT") {
				std::cout << "NOT OF " << arg1 << " -> " << ConvertDecimalToHex(NOT(ConvertHexToDecimal(arg1))) << std::endl;
			}
		}
		else { //operator doesn't exist?
			throw ("THE FILE IS FORMATTED INCORRECTLY 2!");
		}
	} while(!inFile.eof()); //until end of doc
}

/**
    Displays title
*/

void TitleScreen() {
	std::cout << "================================" << std::endl;
	std::cout << "----PROGRAMMING ASSIGNMENT 2----" << std::endl;
	std::cout << "================================" << std::endl; //yup
}