# KonyFinal

Q5
Initial Code

#include <iostream>
using namespace std;

class G {
public:
	G() { cout << "in G::G()\n"; }
	G(int i) { cout << "in G::G(int)\n"; }
};

class F : public G {
public:
	F() { cout << "in F::F()\n"; }
	F(int i) : G(i){ cout << "in F::F(int)\n"; }
};

class E : public G {
public:
	E() { cout << "in E::E()\n"; }
	E(int i) : G(i){ cout << "in E::E(int)\n"; }
};

class D : public E, F {
public:
	D() { cout << "in D::D()\n"; }
	D(int i) : E(i), F(i) { cout << "in D::D(int)\n"; }
};

class C : public D {
public:
	C() { cout << "in C::C()\n"; };
	C(int i) : D(i) { cout << "in C::C(int)\n"; }
};

class B : public D {
public:
	B(){ cout << "in B::B()\n"; };
	B(int i) : D(i) { cout << "in B::B(int)\n"; }
};

class A : public B, C {
public:
	A(){ cout << "in A::A()\n"; };
	A(int i) : B(i), C(i) { cout << "in A::A(int)\n"; }
};



int main()
{
	A e1(2);
	A e2;
	int i; cin >> i;
	return 0;
}*/



Part 1

#include <iostream>
using namespace std;

class G {
public:
	G() { cout << "in G::G()\n"; }
	G(int i) { cout << "in G::G(int)\n"; }
};

class F : public virtual G {
public:
	F() { cout << "in F::F()\n"; }
	F(int i) : G(i) { cout << "in F::F(int)\n"; }
};

class E : public virtual G {
public:
	E() { cout << "in E::E()\n"; }
	E(int i) : G(i) { cout << "in E::E(int)\n"; }
};

class D : public E, F {
public:
	D() { cout << "in D::D()\n"; }
	D(int i) : E(i), F(i) { cout << "in D::D(int)\n"; }
};

class C : public D {
public:
	C() { cout << "in C::C()\n"; };
	C(int i) : D(i) { cout << "in C::C(int)\n"; }
};

class B : public D {
public:
	B() { cout << "in B::B()\n"; };
	B(int i) : D(i) { cout << "in B::B(int)\n"; }
};

class A : public B, C {
public:
	A() { cout << "in A::A()\n"; };
	A(int i) : G(i), B(i), C(i) { cout << "in A::A(int)\n"; }
};


int main()
{
	A e1(2);
	A e2;
	int i; cin >> i;
	return 0;
}



Part 2

#include <iostream>
using namespace std;

class G {
public:
	G() { cout << "in G::G()\n"; }
	G(int i) { cout << "in G::G(int)\n"; }
};

class F : public G {
public:
	F() { cout << "in F::F()\n"; }
	F(int i) :G(i){ cout << "in F::F(int)\n"; }
};

class E : public  G {
public:
	E() { cout << "in E::E()\n"; }
	E(int i) : G(i){ cout << "in E::E(int)\n"; }
};

class D : public E, F{
public:
	D() { cout << "in D::D()\n"; }
	D(int i) :  E(i), F(i) { cout << "in D::D(int)\n"; }
};

class C : public virtual D {
public:
	C() { cout << "in C::C()\n"; };
	C(int i) : D(i) { cout << "in C::C(int)\n"; }
};

class B : public virtual D {
public:
	B(){ cout << "in B::B()\n"; };
	B(int i): D(i) { cout << "in B::B(int)\n"; }
};

class A : public B, C {
public:
	A(){ cout << "in A::A()\n"; };
	A(int i): D(i), B(i), C(i) { cout << "in A::A(int)\n"; }
};



int main()
{
	A e1(2);
	A e2;
	int i; cin >> i;
	return 0;
}



Part 3

#include <iostream>
using namespace std;

class G {
public:
	G() { cout << "in G::G()\n"; }
	G(int i) { cout << "in G::G(int)\n"; }
};

class F : public virtual G {
public:
	F() { cout << "in F::F()\n"; }
	F(int i) : G(i){ cout << "in F::F(int)\n"; }
};

class E : public virtual G {
public:
	E() { cout << "in E::E()\n"; }
	E(int i) : G(i){ cout << "in E::E(int)\n"; }
};

class D : public  E, F {
public:
	D() { cout << "in D::D()\n"; }
	D(int i) : E(i), F(i) { cout << "in D::D(int)\n"; }
};

class C : public virtual D {
public:
	C() { cout << "in C::C()\n"; };
	C(int i) : D(i) { cout << "in C::C(int)\n"; }
};

class B : public virtual D {
public:
	B(){ cout << "in B::B()\n"; };
	B(int i) : D(i) { cout << "in B::B(int)\n"; }
};

class A : public B, C {
public:
	A(){ cout << "in A::A()\n"; };
	A(int i) : G(i), D(i), B(i), C(i) { cout << "in A::A(int)\n"; }
};


int main()
{
	A e1(2);
	A e2;
	int i; cin >> i;
	return 0;
}






Q9

Driver

#include <iostream>
#include <string>
#include "Animal.h"
#include "Cat.h"
#include "Duck.h"
#include "Beaver.h"
#include "Platypus.h"

using namespace std;

int main()
{
	//create animal objects
	//Animal *duck = new Duck();
	//Animal *cat = new Cat();
	//Animal *beaver = new Beaver();
	//Animal *platypus = new Platypus();
	 Duck *duck = new Duck();
    Cat *cat = new Cat();
    Beaver *beaver = new Beaver();
    Platypus *platypus = new Platypus();


	//intial testing
	/*cout << endl << duck->talk();
	cout << endl << cat->talk();
	cout << endl << beaver->talk();
	cout << endl << platypus->talk();*/

	// Part 4 [5 marks]: main function
	// Write a main function that creates an array of four Animals and then iterates over the elements of the array to call each of the 
	// array's elements' talk() method using polymorphism. In doing so, when the program is run, it should output: 
	// quack!splat!meow!grrr!

	Animal* animals[4];
	animals[0] = duck;
	animals[1] = beaver;
	animals[2] = cat;
	animals[3] = platypus;

	for (int i = 0; i < 4; i++)
	{
		cout << animals[i]->talk();
	}
duck = NULL;
	delete duck;
	cat = NULL;
	delete cat; 
	beaver = NULL;
	delete beaver;
	platypus = NULL;
	delete platypus;

	for (int i = 0; i < 4; i++)
	{
		animals[i] = NULL;
		delete animals[i];
	}

	system("pause");
	return 0;

}


Platypus.h

#pragma once
#include "Beaver.h"
#include "Duck.h"

class Platypus : public virtual Beaver, Duck
{
public:
	Platypus();
	string talk();
	~Platypus();
};



Platypus.cpp

#include "Platypus.h"


Platypus::Platypus()
{
}

// Part 3 [5 marks]: Platypus: subclass of Duck and Beaver
// 
// Create a subclass of Duck and Beaver (using multiple inheritance) called Platypus, whose talk() method returns the string "grrr!". 
//
string Platypus::talk()
{
	return "grrr!";
}

Platypus::~Platypus()
{
}


Cat.h 

#pragma once
#include "Animal.h"
class Cat : public Animal
{
public:
	Cat();
	string talk();
	~Cat();
};

Cat.cpp

#include "Cat.h"

Cat::Cat()
{
}

// PART 2 [5 marks]: Subclasses of Animal
// 
// Create 3 subclasses of Animal named Duck, Beaver and Cat that implement the talk() method that behave as the following:
// - Duck::talk() returns the string "quack!".
// - Beaver::talk() returns the string "splat!".
// - Cat::talk() returns the string "meow!". 
string Cat::talk()
{
	return "meow!";
}

Cat::~Cat()
{
}


Beaver.h

#pragma once
#include "Animal.h"

class Beaver : public virtual Animal
{
public:
	Beaver();
	virtual string talk();
	~Beaver();
};


Beaver.cpp

#include "Beaver.h"

Beaver::Beaver()
{
}

// PART 2 [5 marks]: Subclasses of Animal
// 
// Create 3 subclasses of Animal named Duck, Beaver and Cat that implement the talk() method that behave as the following:
// - Duck::talk() returns the string "quack!".
// - Beaver::talk() returns the string "splat!".
// - Cat::talk() returns the string "meow!". 
string Beaver::talk()
{
	return "splat!";
}

Beaver::~Beaver()
{
}


Duck.h

#pragma once
#include <string>
#include "Animal.h"

class Duck : public virtual Animal
{
public:
	Duck();
	virtual string talk();
	~Duck();
};


Duck.cpp

#include "Duck.h"

Duck::Duck()
{
}

// PART 2 [5 marks]: Subclasses of Animal
// 
// Create 3 subclasses of Animal named Duck, Beaver and Cat that implement the talk() method that behave as the following:
// - Duck::talk() returns the string "quack!".
// - Beaver::talk() returns the string "splat!".
// - Cat::talk() returns the string "meow!". 

string Duck::talk()
{
	return "quack!";
}

Duck::~Duck()
{
}


Animal.h

#pragma once
#include <string>
using namespace std;

// PART 1 [5 marks]: Abstract Animal class
// 
// Create a C++ abstract class "Animal" that has only one method named Animal::talk() that 
// returns a string. 
class Animal
{
public:
	Animal();
	virtual string talk() = 0;
	~Animal();

};

Animal.cpp

#include "Animal.h"



Animal::Animal()
{
}


Animal::~Animal()
{
}



Q2

List.cpp

// Original code from the web: 
// https://github.com/kamal-choudhary/singly-linked-list
// https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr



#include <iostream>
#include <list>
using namespace std;
struct Node {
	int data;
	Node *next;
};



class List {
	// PART 1: [5 marks]
	// Implement a stream output operator (<<) that prints out to an output stream all the values contained in a List object.

	friend ostream& operator<<(ostream& output, const List &a)
	{
		Node *p;
		for (p = a.head; p != 0; p = p->next)
		{
			output << p->data << "\t";
		}
		return output;
	}

	// PART 2: [5 marks]
	// Implement a stream input operator (>>) that allows the user to input an integer value on the keyboard, 
	// which is then added at then end of an existing List object. 

	friend istream& operator>>(istream& input, List &a)
	{
		int in;
		input >> in;
		a.createnode(in);
		return input;
	

	}

	// PART 3: [5 marks]
// Using operator overloading, implement an addition operator (operator+) that implements the addition of two List objects. 
// The operator must be implemented as a free operator (i.e. not a member of the List class).  
// It must be able to add two lists of different lengths, in which case it stops when it reaches the end 
// of the shortest of the two Lists. 

	friend const List operator+(const List& a, const List& b)
	{
		int aCounter = 0;
		int bCounter = 0;
		Node *ap;
		Node *bp;
		for (ap = a.head; ap != 0; ap = ap->next)
		{
			aCounter++;
		}
		for (bp = b.head; bp != 0; bp = bp->next)
		{
			bCounter++;
		}
		
		if ((aCounter == bCounter) || (aCounter < bCounter))
		{
			for (ap = a.head, bp = b.head; ap != 0; ap = ap->next, bp = bp->next)
			{
				ap->data = ap->data + bp->data;
			}
			
			return a;
		}
		else if (aCounter > bCounter)
		{
			for (bp = b.head, ap = a.head; bp != 0; bp = bp->next, ap = ap->next)
			{
				bp->data = ap->data + bp->data;
			}
			return b;
		}
	}

private:
	Node *head, *tail;
public:
	List() {
		head = NULL;
		tail = NULL;
	}
	// PART 4: [5 marks]
// Implement an assignment operator that implements a proper assignment of one List object into another List object. 

	const List& operator=(const List &a)
	{
		if (this != &a)
		{
			delete head;
			delete tail;
			head = a.head;
			tail = a.tail;
			
			return *this;
		}
	}

	// PART 5: [5 marks]
	// Implement a copy constructor for the List class that performs a deep copy operation from an existing List object 
	// to create another List object. 

	List(const List &a)
	{
		head = a.head;
		tail = a.tail;
	}

	void createnode(int value) {
		Node *temp = new Node;
		temp->data = value;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}
	void display() {
		Node *temp = new Node;
		temp = head;
		while (temp != NULL) {
			cout << temp->data << "\t";
			temp = temp->next;
		}
	}
	void insert_start(int value) {
		Node *temp = new Node;
		temp->data = value;
		temp->next = head;
		head = temp;
	}
	void insert_position(int pos, int value) {
		Node *pre = new Node;
		Node *cur = new Node;
		Node *temp = new Node;
		cur = head;
		for (int i = 1; i < pos; i++) {
			pre = cur;
			cur = cur->next;
		}
		temp->data = value;
		pre->next = temp;
		temp->next = cur;
	}
	void delete_first() {
		Node *temp = new Node;
		temp = head;
		head = head->next;
		delete temp;
	}
	void delete_last() {
		Node *current = new Node;
		Node *previous = new Node;
		current = head;
		while (current->next != NULL) {
			previous = current;
			current = current->next;
		}
		tail = previous;
		previous->next = NULL;
		delete current;
	}
	void delete_position(int pos) {
		Node *current = new Node;
		Node *previous = new Node;
		current = head;
		for (int i = 1; i < pos; i++) {
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
		delete current;
	}
};

// Part 6: [-5 marks for failure to use exact same main function]
// Use the exact following main() function in your resulting code: 
int main() {
	List obj;
	obj.createnode(25);
	obj.createnode(50);
	obj.createnode(90);
	obj.createnode(40);
	cout << "\n--------------------------------------------------\n";
	cout << "---------------Displaying All nodes---------------";
	cout << "\n--------------------------------------------------\n";
	obj.display();
	cout << "\n--------------------------------------------------\n";
	cout << "-----------------Inserting At End-----------------";
	cout << "\n--------------------------------------------------\n";
	obj.createnode(55);
	obj.display();
	cout << "\n--------------------------------------------------\n";
	cout << "----------------Inserting At Start----------------";
	cout << "\n--------------------------------------------------\n";
	obj.insert_start(50);
	obj.display();
	cout << "\n--------------------------------------------------\n";
	cout << "-------------Inserting At Particular--------------";
	cout << "\n--------------------------------------------------\n";
	obj.insert_position(5, 60);
	obj.display();
	cout << "\n--------------------------------------------------\n";
	cout << "----------------Deleting At Start-----------------";
	cout << "\n--------------------------------------------------\n";
	obj.delete_first();
	obj.display();
	cout << "\n--------------------------------------------------\n";
	cout << "-----------------Deleting At End-------------------";
	cout << "\n--------------------------------------------------\n";
	obj.delete_last();
	obj.display();
	cout << "\n--------------------------------------------------\n";
	cout << "--------------Deleting At Particular--------------";
	cout << "\n--------------------------------------------------\n";
	obj.delete_position(4);
	obj.display();

	cout << "\n--------------------------------------------------\n";
	cout << "--------------Using answer code-----------------";
	cout << "\n--------------------------------------------------\n";

	cout << "\n--------------------------------------------------\n";
	cout << "--------------Using copy constructor-----------------";
	cout << "\n--------------------------------------------------\n";
	List obj1(obj);
	cout << obj1 << endl;

	cout << "\n--------------------------------------------------\n";
	cout << "--------------Using assignment operator-----------------";
	cout << "\n--------------------------------------------------\n";
	List obj2;
	obj2 = obj1;
	cout << obj1 << endl;

	cout << "\n--------------------------------------------------\n";
	cout << "--------------Using stream input------------------";
	cout << "\n--------------------------------------------------\n";
	cin >> obj1 >> obj1;
	cout << obj1 << endl;

	cout << "\n--------------------------------------------------\n";
	cout << "--------------Using operator+------------------";
	cout << "\n--------------------------------------------------\n";
	List obj3, obj4;
	obj3.createnode(1);
	obj3.createnode(2);
	obj3.createnode(3);
	obj3.createnode(3);
	obj4.createnode(4);
	obj4.createnode(5);
	obj4.createnode(6);
	cout << "obj3 List: " << endl << obj3 << endl;
	cout << "obj4 List: " << endl << obj4 << endl;
	cout << "obj3 + obj4: " << endl << obj3 + obj4 << endl;

	int x; cin >> x;
	return 0;
}


Q6

MyArray.h

#pragma once
#include <iostream>
const int SIZE_OF_STATIC_ARRAY = 5;
// PART 1 [40 marks]:

class MyArray
{

	//friend ostream& operator<<(ostream& output, MyArray* a);
public:

	// a.[5 marks] a default constructor that initializes theArray to size zero.

	MyArray();

	// b.[5 marks] a constructor that takes a statically allocated array as a parameter and copies it into theArray, while making sure 
	//				that duplicates are removed during the copy(using the isInArray function�see B.i.(e)).

	MyArray(int array[]);

	// c.[5 marks] a copy constructor. 
	MyArray(const MyArray &array);

	// d.[5 marks] an assignment operator.
	MyArray& operator=(const MyArray &array);

	// e.[5 marks] an isInArray non-inline member function that gets an integer value as a parameter and returns true if the value 
	//				received as parameter is in theArray, and false if it is not.
	bool isInArray(int value);

	// f.[5 marks] a getArray inline member function returning theArray.
	inline int* getArray() { return theArray; };

	// g.[5 marks] a getSize inline member function returning the size of the stored array.
	inline int getSize() { return size; };

	// h.[5 marks] a destructor. 
	~MyArray();		
	
	
private:
	//two private data members: a dynamically allocated array of integers named theArray, 
	//and an integer named size that stores the number of elements in theArray.
	int size;
	int *theArray;
	

};


MyArray.cpp

#include "MyArray.h"


// PART 1 [40 marks]:


// a.[5 marks] a default constructor that initializes theArray to size zero.
MyArray::MyArray()
{
	size = 0;
	theArray = new int [0];
}

// b.[5 marks] a constructor that takes a statically allocated array as a parameter and copies it into theArray, while making sure 
//				that duplicates are removed during the copy(using the isInArray function�see B.i.(e)).
MyArray::MyArray(int array[])
{
	int counter = 0;
	int tempArray[SIZE_OF_STATIC_ARRAY];

	size = SIZE_OF_STATIC_ARRAY;
	theArray = new int[SIZE_OF_STATIC_ARRAY];

	for (int i = 0; i < SIZE_OF_STATIC_ARRAY; i++)
	{
		theArray[i] = array[i];
	}

	int j = 0;
	for (int i = 0; i < SIZE_OF_STATIC_ARRAY; i++)
	{
		if (i == 0)
		{
			tempArray[j] = array[i];
			j++;
			counter++;
		}
		else
		{
			if (isInArray(array[i]) == false)
			{
				tempArray[j] = array[i];
				j++;
				counter++;
				
			}
			else if (isInArray(array[i]) == true)
			{
				tempArray[j] = NULL;
				j++;

				
			}


		}
	}
	theArray = NULL;
	delete theArray;
		size = counter - 1;
		theArray = new int[size];
		j = 0;
		for (int i = 0; i < SIZE_OF_STATIC_ARRAY; i++)
		{
			if (tempArray[i] != NULL)
			{
				theArray[i] = tempArray[i];
				
			}
		}
		

}



// c.[5 marks] a copy constructor. 
MyArray::MyArray(const MyArray& array)
{
	size = array.size;
	theArray = array.theArray;
}

// d.[5 marks] an assignment operator.
MyArray& MyArray::operator=(const MyArray &array)
{
	if (&array == this)
	{
		return *this;
	}
	else
	{
		delete theArray;
		size = array.size;
		theArray = array.theArray;
		return *this;
	}

}

// e.[5 marks] an isInArray non-inline member function that gets an integer value as a parameter and returns true if the value 
//				received as parameter is in theArray, and false if it is not.
bool MyArray::isInArray(int value)
{
	for (int i = 0; i < SIZE_OF_STATIC_ARRAY; i++)
	{
		if (theArray[i] == value)
			return true;
		if (theArray[i] != value)
			return false;

	}
}

// h.[5 marks] a destructor. 
MyArray::~MyArray()
{
	theArray = nullptr;
	delete theArray;
	

}


Driver.cpp

#include "MyArray.h"
#include <iostream>
using namespace std;

// Part 2 [10 marks]: 
  

int main()
{
	int array[SIZE_OF_STATIC_ARRAY];
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	array[3] = 1;
	array[4] = 2;


	//default
	/*MyArray a;

	cout << endl << "Default Constructor";
	cout << endl << a.getSize();
	cout << endl << a.getArray();*/

	
	// a.[2 marks] create an object of type pointer to MyArray using the constructor developed in question B.i.(b). 
	MyArray* c =  new MyArray(array);

	cout << endl << endl << endl << "Constructor B.i.(b)";
	cout << endl << c->getSize();
	cout << endl << c->getArray();
	cout << endl;

	int *ptr = c->getArray();
	for (int i = 0; i < c->getSize(); i++)
	{
		cout << endl << ptr[i];
		ptr++;
	}

	// b.[3 marks] use the copy constructor developed in question B.i.(c) to create another object of type MyArray and assign it to a 
	//				variable of type pointer to MyArray named copiedArray.
	
	
	MyArray* copiedArray = new MyArray(*c);
	
	cout << endl << endl << endl << "Copy Constructor B.i.(c)";
	cout << endl << copiedArray->getSize();
	cout << endl << copiedArray->getArray();
	
	// c.[3 marks] print to the screen all elements of the array stored in the copiedArray object. 

	ptr = copiedArray->getArray();
	for (int i = 0; i < copiedArray->getSize(); i++)
	{
		cout << endl << ptr[i];
		ptr++;
	}

	//assignment
	/*a = a;
	cout << endl << endl << endl << "Returning Original Object From Assignment Operator" << endl;
	cout << endl << a.getSize();
	cout << endl << a.getArray();

	a = *c;
	cout << endl << endl << endl << "Returning Assigned Object From Assignment Operator";
	cout << endl << a.getSize();
	cout << endl << a.getArray();*/

	// d.[2 marks] ensure that the main function does not implement a memory leak.
	c = NULL;
	copiedArray = NULL;
	ptr = NULL;
	delete c;
	delete copiedArray;
	delete ptr;

	system("pause");
	return 0;
}


Q4

Exceptions.h

#pragma once

class Exceptions
{
public:
	Exceptions();
	//virtual void exception() = 0;
	~Exceptions();
};

class SensorException : public Exceptions
{
public:
	SensorException();
	virtual void exception() = 0;
	~SensorException();

};

class NegativeSensorException :  public SensorException, Exceptions
{
	NegativeSensorException(int &pVal);
	void exception();
	~NegativeSensorException();
};

class OverloadSensorException :  public SensorException, Exceptions
{
	OverloadSensorException(int & pVal);
	void exception();
	~OverloadSensorException();
};


Exceptions.cpp

#include "Exceptions.h"

Exceptions::Exceptions()
{
}

Exceptions::~Exceptions()
{
}

SensorException::SensorException()
{
}

SensorException::~SensorException()
{
}


NegativeSensorException::NegativeSensorException(int &pVal)
{

}
	
void NegativeSensorException::exception()
{

}

NegativeSensorException::~NegativeSensorException()
{
}

OverloadSensorException::OverloadSensorException(int &pVal)
{

}
	
void OverloadSensorException::exception() 
{

}

OverloadSensorException::~OverloadSensorException()
{
}



CarController.cpp

// CarController.cpp
//THIS FILE SHOULD BE CHANGED, SEE THE CONSTRUCTOR BELOW

#include "CarController.h"
#include "Sensor.h"
#include <iostream>
#include <ctime> 

using namespace std;

CarController::CarController() {
	state = safe;
	wheels.push_back(new Wheel(new Sensor(), WheelId::FR));
	wheels.push_back(new Wheel(new Sensor(), WheelId::FL));
	// THE TWO REAR WHEELS NEED TO BE CONNECTED TO THE NEW SENSORS 
	// USING THE ADAPTER
	wheels.push_back(new Wheel(new Sensor(), WheelId::RR));
	wheels.push_back(new Wheel(new Sensor(), WheelId::RL));
	srand(time(0));
}

void CarController::start() {
	cout << "in CarController::start()" << state << endl;
	int pressure;
	while (state == safe) {
		for (Wheel* w : wheels) {
			pressure = w->pressureSensor->getPressure();
			if (pressure > 240 || pressure < 10) {
				cout << "abnormal pressure: " << pressure << endl;
				state = unsafe;
			}
		}
	}
	cout << "Car usafe to drive!" << endl;
}
CarController::~CarController() {
}

Wheel::Wheel(Sensor* newPressureSensor, WheelId newWid) : pressureSensor(newPressureSensor), wid(newWid) 
{
	
};

SensorExceptionSuppressor.h

#pragma once
#include "Sensor.h" 
#include "SensorV2.h"

class SensorExceptionSuppressor : public Sensor
{
public:
	SensorExceptionSuppressor(SensorV2 sensor);
	void checkPressure(int pressure);
	~SensorExceptionSuppressor();

private: 
	SensorV2 newSensor;
};


SensorExceptionSuppresor.cpp

#include "SensorExceptionSuppressor.h"
#include <ctime> 
#include <iostream>
using namespace std;

SensorExceptionSuppressor::SensorExceptionSuppressor(SensorV2 sensor)
{
	newSensor = sensor;
}
void SensorExceptionSuppressor::checkPressure(int pressure) 
{
	int pressure = this->getPressure();
	try
	{//normal execution
		newSensor.getPsi(pressure);
	}
	catch (NegativeSensorException exc1)
	{
	}
	catch (OverloadSensorException exc2)
	{
	}
	
}

SensorExceptionSuppressor::~SensorExceptionSuppressor()
{
}

