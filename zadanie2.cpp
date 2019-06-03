//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																				//
// Author               : pt206																													//
// Day 				    : 03.06.2019																											//
// file name            : main.cpp																												//
//																																				//
// ---------------------------------------------------------------------------------------------------------------------------------------------//		
// A																																			//
//              _____           _      _     _ _																								//
//             /  __ \         | |    | |   (_) |																								//
//             | /  \/ ___   __| | ___| |    _| |_ ___																							//
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )																							//
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/																							//
//              \____/\___/ \__,_|\___\_____/_|\__\___|																							//
//																																				//
//                                                  F i l e																						//
//																																				//
//  Написать программу для работы с классом String, демонстрирующую его возможности.															//			
//																																				//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class String {
	
	char * value;
	int len;
	
public:
	String():value(new char[1]{}), len(0) {};
	
	String(const String& s) { 
		len = s.len;
		value = new char[len + 1];
		for (int i = 0; i <= len; i++)
			value[i] = s.value[i];
	}
	
	ostream& operator<<(ostream& outputStream, const String & s) {
		return outputStream << s.value; 
	}
	
	~String() {
		delete[] value;
	}
	
};


int main()
{
	String str = “Test”;
	String str2(str);
	cout << str2 << endl;
	return 0;
}