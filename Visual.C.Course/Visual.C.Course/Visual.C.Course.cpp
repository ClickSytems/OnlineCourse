// Visual.C.Course.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Visual.C.Course.h"
//It is needed to include the reference
#include "Person.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

//Error
//Heap
char* GetName1()
{
	//Stack - Is clean up when returned
	return "John";
}

//In C# and Java you pass the address of the object
//In c++ you need to explicitilly pass the address of the object
//Or convert to string, for example

//Right
//Stack - Return by value
string GetName2()
{
	//Stack
	return "John";
}

//Do not work - Pass a local copy of person
void ProcessPerson1(Person p)
{
	p.Name = "abc";
}

//Works - Pass person by reference
void ProcessPerson2(Person *p)
{
	p->Name = "abc";
}

//Returning a stack object
//Do not work, may be cleaned after returned
Person CreatePerson1(string name) 
{
	//Instanciate in the stack memory
	Person p;
	p.Name = name;
	return p;
}

//Returning a converted stack to heap object
//Do not work, may be cleaned after returned
//Return a pointer of a local or temporary variable
//Person* CreatePerson2(string name)
//{
//	//Instanciate in the stack memory
//	Person p;
//	p.Name = name;
//	return &p;
//}

//Returning a heap object
//Works - Return a pointer to heap memory
Person* CreatePerson3(string name)
{
	//Instanciate in the stack memory
	Person* p = new Person;
	p->Name = name;
	return p;
}

//Returning a smart pointer object
//Works - Return a smart pointer to heap memory
//unique_ptr is a special class that is cleaned up when exit the application
//Non copiaple pointer (single owner)
//Guarantee is cleaned up
unique_ptr<Person> CreatePerson4(string name)
{
	//Instanciate in the stack memory
	unique_ptr<Person> p = make_unique<Person>();
	p->Name = name;
	return p;
}


//Arguments to use c++
//1. Speed and performance
//2. Portability - if you write nice and clean code, 
//c++ is portable. 
//3. Custom device support - many devices support
//Main language used for new devices
//Has lambda, smart pointers, 
//get access to assembly using high level language, etc
//c++ evolves, old programmers evolve togheter
//Cientific computation

//Primarly fields to use c++
//1. Quant Finance
//2. Game Dev
//3. Embedded

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // initialize MFC and print and error on failure
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: change error code to suit your needs
            wprintf(L"Fatal Error: MFC initialization failed\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: code your application's behavior here.

			//Two types of allcationg in memory

			//1 - This way constructor will be called
			//and we will have an instance
			//Stack memory (is cleaned automaticaly)
			Person p;
			p.Name = "Dmitri";

			//2 - Heap memory (Pointer)(Address of the memory)
			//Be carefull not to create memory leaks
			Person *pp = new Person;
			pp->Name = "Dmitri";
			
			//Function test 1
			char* name1 = GetName1();
			string name2 = GetName2();

			//console

			//Pass stack - Does not work
			ProcessPerson1(p);

			//Convert stack to heap (reference) 
			ProcessPerson2(&p);

			//Pass heap (reference)
			ProcessPerson2(pp);

			//Stack Object
			Person p1 = CreatePerson1("Marcelo1");
			
			//Person* p2 = CreatePerson2("Marcelo2");
			
			//Pointer (heap) object
			Person* p3 = CreatePerson3("Marcelo3");
			cout << p3->Name << endl;
			//Call destructor
			//To avoid memory leaks
			delete p3;


			//Smart Pointers - Next evolution in pointers
			//Because is not clear when to delete normal pointers
			//Can have copy of pointer be used and delete
			//Include iostream and memory to stdafx.h

			//auto = var in c#
			auto p4 = CreatePerson4("Marcelo4");
			//delete p4;

			//Unicode (character type, string type)
			char c; // one character
			wchar_t c_t; //unicode character
			string str; //string
			wchar_t str_t; //unicode string
			
			/**************8*/
			//Set character set in the project properties

			auto z = new int[16];
			//does not work even compiles
			//delete z;
			//Works
			delete[] z;

			//*Example to simulate property
			uint32_t ageProperty = p4->AgeProperty;




        }
    }
    else
    {
        // TODO: change error code to suit your needs
        wprintf(L"Fatal Error: GetModuleHandle failed\n");
        nRetCode = 1;
    }

    return nRetCode;
}
