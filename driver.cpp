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

int main() {
	TitleScreen();
	try {
		Processor(LoadFile("Programming-Project-1.txt"));
	}
	catch (const char* msg) {
		std::cerr << msg << std::endl;
	}
	std::cout << "================================" << std::endl;
	std::cout << std::endl;

	return 0;
}