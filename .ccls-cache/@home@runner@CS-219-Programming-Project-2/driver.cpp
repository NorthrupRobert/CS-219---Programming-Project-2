/**
	-CS219 PP2, Driver-
    Starts titlescreen, processes the txt file, and begins all
	other functions.
    @file driver.cpp
    @author Robb Northrup
    @version 1.0 3/3/2022
*/

#include <iostream>
#include <fstream>
#include <string>
#include "start.h"
#include "hexoperations.h"

using std::endl, std::cout;

int main() {
	TitleScreen();
	//cout << "ABOUT TO PROCESS FILE" << endl;
	try {
		Processor(LoadFile("input.txt"));
		//std::cout << "PROCESSED FILE" << std::endl;
	}
	catch (const char* msg) {
		std::cerr << msg << std::endl;
	}
	std::cout << "================================" << std::endl;
	std::cout << std::endl;

	return 0;
}