/**
	-CS219 PP1, Driver-
    Starts titlescreen, processes the txt file, and begins all
	other functions.
    @file driver.cpp
    @author Robb Northrup
    @version 1.0 1/28/2022
*/

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