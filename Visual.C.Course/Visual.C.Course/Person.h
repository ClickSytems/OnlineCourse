#pragma once
//Header (definition)

class Person
{
	//*Example to simulate property
	//Private member 
	int _ageMember;

public:
	//Constructor
	Person();
	//Destructor
	~Person();

	string Name;
	//Has different types from many platform.
	//Not standardized as int, long, etc
	int32_t AgeInt32_t;
	int Age;


	//*Example to simulate property
	//Public property 
	__declspec(property(get = GetAgeProperty)) int32_t AgeProperty;
	int32_t GetAgeProperty() 
	{
		return _ageMember;
	}


	/*
	Example stdint.h

	ypedef signed char        int8_t;
	typedef short              int16_t;
	typedef int                int32_t;
	typedef long long          int64_t;
	typedef unsigned char      uint8_t;
	typedef unsigned short     uint16_t;
	typedef unsigned int       uint32_t;
	typedef unsigned long long uint64_t;

	typedef signed char        int_least8_t;
	typedef short              int_least16_t;
	typedef int                int_least32_t;
	typedef long long          int_least64_t;
	typedef unsigned char      uint_least8_t;
	typedef unsigned short     uint_least16_t;
	typedef unsigned int       uint_least32_t;
	typedef unsigned long long uint_least64_t;

	typedef signed char        int_fast8_t;
	typedef int                int_fast16_t;
	typedef int                int_fast32_t;
	typedef long long          int_fast64_t;
	typedef unsigned char      uint_fast8_t;
	typedef unsigned int       uint_fast16_t;
	typedef unsigned int       uint_fast32_t;
	typedef unsigned long long uint_fast64_t;

	typedef long long          intmax_t;
	typedef unsigned long long uintmax_t;
	
	*/
};

