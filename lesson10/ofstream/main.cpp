#include <iostream>
#include "FileWriter.hpp"

using std::cout;
using std::endl;

enum Flags
{
	Read =   0b001,
	Write =  0b010,
	Append = 0b100
};

int main()
{
	// Flags flg = Flags::Write | Flags::Append; // 0b110

	// // ...
	// if (flg & Flags::Read) ;
	// 	// ...
	// if (flg & Flags::Write) ;
	// 	// ...
	// if (flg & Flags::Append) ;
	// 	// ...

	FileWriter fw("file.txt");
	fw << "You are still just a mortal! Every bit as weak as that day you begged"
		  " me to save your life\n";
}