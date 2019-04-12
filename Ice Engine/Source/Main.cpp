
//Authors: James Bews, Jatin Kumar, Dennis Nguyen

#include "MainMenu.h"
#include "tinyxml2.h"


//#define DIV 1024
// Global variables  
// The main window class name.  
//static TCHAR szWindowClass[] = _T("IceEngine");
// The string that appears in the application's title bar.  
//std::vector<std::string> MusicFile;
//HINSTANCE hInst;
//~~~~Main Window With Console Enabled~~~~~

/*
///For ints and strings
bool example_4()
{
	static const char* xml =
		"<information>"
		"	<ObjectType>"
		"		<Transform>"
		"			<Position>"
		"				<x>10</x>"
		"				<y>1</y>"
		"			</Position>"
		"			<Rotation>"
		"				<rot>1</rot>"
		"			</Rotation>"
		"			<Scale>"
		"				<x>1</x>"
		"				<y>1</y>"
		"			</Scale>"
		"		</Transform>"
		"	</ObjectType>"
		"	<ObjectType>"
		"		<Transform>"
		"			<Position>"
		"				<x>33</x>"
		"				<y>1</y>"
		"			</Position>"
		"			<Rotation>"
		"				<rot>1</rot>"
		"			</Rotation>"
		"			<Scale>"
		"				<x>1</x>"
		"				<y>1</y>"
		"			</Scale>"
		"		</Transform>"
		"	</ObjectType>"
		"</information>";

	tinyxml2::XMLDocument doc;
	doc.Parse(xml);

	int v0 = 0;
	int v1 = 0;
	
	//tinyxml2::XMLElement* attributeApproachElement = doc.FirstChildElement()->FirstChildElement("ObjectType");
	//attributeApproachElement->QueryIntAttribute("v", &v0);
	//if (v0 == 2) {
	//	printf("Yes okay\n");
	//}
	for (tinyxml2::XMLElement* ele = doc.FirstChildElement()->FirstChildElement("ObjectType"); ele != NULL;ele= ele->NextSiblingElement()) {
		//create game object
		int posx = 0;
		tinyxml2::XMLElement* temp = ele->FirstChildElement("Transform");
		temp->FirstChildElement("Position")->FirstChildElement("x")->QueryIntText(&posx);
		
		printf("v1 =%d ", posx);
	}
	tinyxml2::XMLElement* attributeApproachElement2 = doc.FirstChildElement()->FirstChildElement("ObjectType")->FirstChildElement("Transform")->FirstChildElement("Position");
	attributeApproachElement2->FirstChildElement("x")->QueryIntText(&v1);
	if (v1 == 10) {
		printf("v1 =%d " ,v1);
	}
	//tinyxml2::XMLElement* attributeApproachElement3 = doc.FirstChildElement()->FirstChildElement("ObjectType")->;
	//attributeApproachElement3->QueryIntAttribute("v", &v0);
	//tinyxml2:: XMLElement* textApproachElement = doc.FirstChildElement()->FirstChildElement("textApproach");
	//textApproachElement->FirstChildElement("v")->QueryIntText(&v1);

	printf("Both values are the same: %d and %d\n", v0, v1);

	return !doc.Error() && (v0 == v1);
	//return true;
}

int example_3()
{
	tinyxml2::XMLDocument doc;
	const char* name = "Assets/testXML.xml";
	doc.LoadFile(name);
	tinyxml2::XMLElement* titleElement = doc.FirstChildElement("PLAY")->FirstChildElement("TITLE");
	const char* title = titleElement->GetText();
	printf("Name of play (1): %s\n", title);

	tinyxml2::XMLText* textNode = titleElement->FirstChild()->ToText();
	title = textNode->Value();
	printf("Name of play (2): %s\n", title);

	return doc.ErrorID();
}
*/

int main()
{
	MainMenu _MainMenu;
	_MainMenu.Inist();
	return 0;
}

