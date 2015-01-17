
#ifndef Converter_h
#define Converter_h

#include <string>
#include "rapidxml/rapidxml_utils.hpp"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

class Converter {
public:
    Converter(std::string xmlFileName);
    ~Converter();
		std::string to_json();
protected:
		std::string                  mXmlFileName;
		rapidxml::file<char>         mXmlFile;
		rapidxml::xml_document<char> mXmlDoc;
protected:
		void readXmlFile();
};

#endif

