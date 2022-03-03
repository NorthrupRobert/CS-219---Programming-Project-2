/**
	-CS219 PP2, HexOperations File-
    Houses multiple processes for hexidecimal numbers
	and conversion to and from such (to decimal).
    @file driver.cpp
    @author Robb Northrup
    @version 1.0 3/3/2022
*/

#include <string>
#include <cmath>
#include <iostream>
#include "hexoperations.h"

/**
    Converts hexidecimal number to decimal.
    @param hexFig - hexidecimal figure, saved as a std::string
    @return num - hex conversion to decimal
*/

uint32_t ConvertHexToDecimal(std::string hexFig) {
	uint32_t num = 0;
	int i;
	char temp;

	for (i = 2; i < hexFig.size(); i++) {
		temp = hexFig.at(i);

		switch(temp) { //converts to decimal by adding proper power to hex characters
			case 'A':
				num += (10 * pow(16, (hexFig.size() - i - 1)));
				break;
			case 'B':
				num += (11 * pow(16, (hexFig.size() - i - 1)));
				break;
			case 'C':
				num += (12 * pow(16, (hexFig.size() - i - 1)));
				break;
			case 'D':
				num += (13 * pow(16, (hexFig.size() - i - 1)));
				break;
			case 'E':
				num += (14 * pow(16, (hexFig.size() - i - 1)));
				break;
			case 'F':
				num += (15 * pow(16, (hexFig.size() - i - 1)));
				break;
			default:
				num += ((temp - 48) * pow(16, (hexFig.size() - i - 1)));
				break;
		}
	}

	return num;//returns decimal num
}

/**
    Converts decimal number to hexidecimal.
    @param decimalFig - decimal figure saved as a uint32_t
    @return hexNum - decimal conversion to hex
*/

std::string ConvertDecimalToHex(uint32_t decimalFig) {
	std::string hexNum;
	int remainder;

	for (int i = 0; (remainder != 0) || (decimalFig != 0); i++){
		remainder = decimalFig % 16;
		decimalFig = (decimalFig - remainder) / 16;
		if(remainder < 10)
			hexNum.insert(0, std::to_string(remainder)); //shifts remainder character to front should it be 0-9
		else if(remainder == 10)
			hexNum.insert(0, "A"); //shifts remainder character to front should it be A (10)
		else if(remainder == 11)
			hexNum.insert(0, "B"); //. . .
		else if(remainder == 12)
			hexNum.insert(0, "C"); //. . .
		else if(remainder == 13)
			hexNum.insert(0, "D"); //. . .
		else if(remainder == 14)
			hexNum.insert(0, "E"); //. . .
		else if(remainder == 15)
			hexNum.insert(0, "F"); //. . .
		remainder = 0;
	}

	hexNum.insert(0, "0x");

	return hexNum;
}

/**
    Adds two uint32_t figures
    @param num1
	@param num2
    @return (num1 + num2) - sum of both numbers
*/

uint32_t Add(uint32_t num1, uint32_t num2) {
	if ((static_cast<long long>(num1) + static_cast<long long>(num1)) > 4,294,967,295)
		return 0;
	return (num1 + num2);
}