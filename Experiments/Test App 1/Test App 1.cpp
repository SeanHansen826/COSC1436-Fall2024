#include <iostream>

int main()
{
	std::string userName;
	std::cout << "Whats your name?\n";
	std::cin >> userName;
	std::cout << "Thank you, " << userName << ".\n";

	//how can I get it to read cin: y/n as cin 0 or 1?
	// 
	//creating the response seperately from the variable allows us to have a response other than "0" or "1"

	char response;
	bool goodAtMath;

	//how can I get it to read cin: y/n as cin 0 or 1? or even true or false?

	std::cout << "I'd like to know something about you, " << userName << ". Are you good at math?\n";
	std::cout << "y/n: ";
	std::cin >> response;

	goodAtMath = (response == 'y' || response == 'Y'); // bool goodAtMath = the value of response, which is synonymous with y or Y
	std::cout << userName << " is good at math: " << std::boolalpha << goodAtMath; // boolalpha displays the 1 or 0 as true or false respectively
	std::cout << std::endl;

	//now I want to display some text depending on the value:
	//think of the (==) meaning a variable is equal to a variable, if it were just an = it would be equal a value, like an expression;

	//not necessary to create a new block, but usefule if you want to return here for any reason
	if (goodAtMath == true) {
		std::cout << "That's great to know, me too!\n";
	}

	if (goodAtMath == false) {
		std::cout << "Damn, sometimes knowledge is a burden anyways!\n";
	}

	//can also be written as::
	//
	//if (goodAtMath) ... if (true)
	//
	//if (!goodAtMath) ... if (NOT true)
	//
	//therefore ! is equivalent to NOT, can be used to exress the NOT of any value or variable.
}