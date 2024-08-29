#include <iostream>

using namespace std;
#include "Person.h"



int main(int argc, char** argv){
	// Class Person object using default constructor
	Person foivos;
	
	foivos.setAge(22);
	foivos.setName("Foivos");
	foivos.printPersonInfo();
	
	// Class Person object using constructor
	Person m(60,"Jim");
	m.printPersonInfo();
	return 0;
	
	
}
