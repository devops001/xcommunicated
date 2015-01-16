#include <iostream>
#include <fstream>
#include <sstream>

#include "rapidxml/rapidxml_utils.hpp"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

int main(int argc, char* argv[]) {

	std::stringstream json;

	rapidxml::file<char> xmlFile("data/wired_feed.xml");
	rapidxml::xml_document<char> doc;
	doc.parse<0>(xmlFile.data());

	rapidxml::xml_node<char>* node = doc.first_node();

	json << "{ \"node\":\"" << std::string(node->name()) << "\",\n";

	for (rapidxml::xml_attribute<char>* attr=node->first_attribute(); attr; attr=attr->next_attribute()) {
		json << "  \"" << attr->name() << "\":\"" << attr->value() << "\"";
		if (attr->next_attribute()) {
			json << ",\n";
		} else {
			json << "\n";
		}		
	}

	json << "}";

	std::cout << json.str() << std::endl;

	return 0;
}

