
#include "Converter.h"

#include <fstream>
#include <sstream>

Converter::Converter(std::string xmlFileName) : mXmlFile(xmlFileName.c_str()), mXmlDoc() {
	mXmlDoc.parse<0>(mXmlFile.data());
}

Converter::~Converter() {
}

std::string Converter::to_json() {
	rapidxml::xml_node<char>* node = mXmlDoc.first_node();
	std::stringstream json;
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
	return json.str();
}

