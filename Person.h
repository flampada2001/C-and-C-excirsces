# include <iostream>
 using namespace std;

class Person{
	
private:
	string name;
	int age;
	
	public:
		// Default constructor
	Person(){

	}
// Constructor
    Person(int n , string s){
		age=n;
		name=s;
    } 
		void setAge(int y);
		int getAge();
		void setName(string ph);
		string getName();
	
		
		void printPersonInfo(){
			cout << "Name: "<< getName()<<endl;
			cout << "Age: "<< getAge()<<endl;
}
};

void Person::setAge(int y){
	
	age=y;
}
int Person::getAge(){
	
	return age;
}

void Person::setName(string ph){
	
	name=ph;
}
string Person::getName(){
	
	return name;
}



