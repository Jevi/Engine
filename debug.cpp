#include "debug.h"

void Debug::Log(LogLevel level, const char* format, ...)
{
	va_list args;
	va_start(args, format);
	cout << "[" << LogLevelToString(level) << "]\t";
	vprintf(format, args);
	va_end(args);
	cout << endl;
}

string Debug::BoolToString(bool Bool)
{
	if (Bool)
	{
		return string("true");
	}
	return string("false");
}

string Debug::XMLDocumentToString(XMLDocument* doc)
{
	ostringstream os;
	const XMLNode* ParentNode = doc->FirstChild();
	if (ParentNode)
	{
		ProcessElements(ParentNode, os);
	}
	return os.str();
}
;

void Debug::ProcessElements(const XMLNode* ParentNode, ostringstream& os, unsigned int indents)
{
	const XMLElement* CurrElem = ParentNode->ToElement();
	const XMLAttribute* CurrElemAttribute = CurrElem->FirstAttribute();
	bool hasClosingTag = false;

	os << GetIndent(indents) << "<" << CurrElem->Name();
	while (CurrElemAttribute)
	{
		os << " " << CurrElemAttribute->Name() << "=" << "\"" << CurrElemAttribute->Value() << "\"";
		CurrElemAttribute = CurrElemAttribute->Next();
	}

	if (ParentNode->FirstChild())
	{
		os << ">\n";
		hasClosingTag = true;
	}
	else
	{
		os << "/>";
	}

	for (const XMLNode* ChildNode = ParentNode->FirstChild(); ChildNode; ChildNode = ChildNode->NextSibling())
	{
		ProcessElements(ChildNode, os, indents + 1);
	}

	if (hasClosingTag)
	{
		os << GetIndent(indents) << "\n<" << CurrElem->Name() << "/>";
	}
}

const char* Debug::GetIndent(int indents)
{
	const char* pINDENT = "  ";
	const unsigned int LENGTH = strlen(pINDENT);
	unsigned int n = indents * 2;
	if (n > LENGTH)
	{
		n = LENGTH;
	}
	return &pINDENT[LENGTH - n];
}
