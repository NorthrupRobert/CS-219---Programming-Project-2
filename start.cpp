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
    Loads file, ensures it can open.
    @param fileName - given by Start() function when called
    @return inFile - file to be decoded and perform the 
					 appropriate functions
*/

std::ifstream LoadFile(std::string fileName) {
	std::ifstream inFile;
	
	inFile.open(fileName);
	if (inFile.fail()) { //throw if fails to open the file
		throw ("FAILED TO OPEN \"" + fileName + "\"!");
	}
	
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
	std::string temp; //used to store 
	bool useStoredValue = false;

	//std::cout << "IN PROCESSOR" << std::endl;
	int i = 1;
	do {
		//std::cout << "reading line " << i << std::endl;
		if (useStoredValue == false)
			inFile >> op;
		else {
			op = temp;
			useStoredValue = false;
		}
		if (op == "ADD" || op == "AND" || op == "ORR" || op == "SUB" || op == "XOR") { //operations that require 2 operators
			inFile >> arg1;
			inFile >> arg2;

			if (arg1.substr(0,2) != "0x" && arg2.substr(0,2) != "0x")
				throw ("THE FILE IS FORMATTED INCORRECTLY!\nOPERANDS AREN'T IN CORRECT HEX FORM OR NUMBER OF OPERANDS IS INCORRECT");
			
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
				throw ("THE FILE IS FORMATTED INCORRECTLY!\nOPERANDS AREN'T IN CORRECT HEX FORM OR NUMBER OF OPERANDS IS INCORRECT");
			inFile >> temp;
			if (temp.substr(0,2) == "0x") //if two operands for one operand-specific operator
				{ }
			else
				useStoredValue = true;
			
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
			throw ("THE FILE IS FORMATTED INCORRECTLY!\nAN OPERATOR USED DOESN'T EXIST.");
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