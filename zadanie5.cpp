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
//  Добавить к реализации класса перегруженные операторы присваивания и унарного минуса. 														//
//	Модифицировать программу для демонстрации возможностей операторов.																			//
//																																				//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream> 
#include <cstring> 
#include <cmath> 

using namespace std;

class String
{
	char * value;
	int len;

public:
	String():value(new char[1]{}), len(0) {};
	String(int size) :value(new char[size + 1]), len(size) {}

	String(const String& s) {
		len = s.len;
		value = new char[len + 1];
		for (int i = 0; i <= len; i++)
			value[i] = s.value[i];
	}

	String(const char * s) {
		len = 0;
		while (s[len] != 0) len++;
		value = new char[len + 1];
		for (int i = 0; i <= len; i++)
			value[i] = s[i];
	}

	String operator-() const {
		String ret(len);
		for (int i=0; i<len; i++) {
			ret.value[i] = value[len-i-1];
		}
		ret.value[len] = 0;
		return ret;
	}

	String& operator=(const String& other) { 
		if (this != &other) { 
			delete[] value;
			len = other.len;
			value = new char[len + 1];
			for (int i = 0; i <= len; i++) {
				value[i] = other.value[i];
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& outputStream, const String & s) {
		return outputStream << s.value; 
	}
	~String() { 
		delete[] value;
	}
};
int main()
{
	String str = "Hello World";
	String str2 = str;
	cout << str2 << endl;
	cout << -str2 << endl;
	return 0;
}