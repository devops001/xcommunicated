#include <iostream>
#include <sstream>

#include "Converter.h"

int main(int argc, char* argv[]) {

	Converter converter("data/wired_feed.xml");

	std::cout << converter.to_json() << std::endl;

	return 0;
}

