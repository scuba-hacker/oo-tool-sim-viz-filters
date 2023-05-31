/************************************************************************************** * HEADER FILE: newstring.h * PURPOSE		: declare string_class class **************************************************************************************/#ifndef _newstring_h#define _newstring_h#include <iostream.h>#include <string.h>#include <ctype.h>#include "define_vars.h"const int MAX_INPUT_STRING_LENGTH=256;											// Input stream buffer sizeclass string_class{	private:		char *letters;																					// char array holding string		int string_length;																			// length of string inc. NULL				public:		string_class();																						// default constructor		string_class(const char *source);													// char array constructor		string_class(const string_class &original);								// copy constructor		~string_class();																					// destructor		status string_copy(char *target);													// copy letters into target		string_class& operator=(const string_class &source); 			// string_class=string_class		string_class& operator=(const char *source);							// string_class=char array		string_class& operator=(const char &source);							// string_class=char				char& operator[](const int index);												// string_class[]		char& operator[](const int index) const;									// const string_class []				// overloaded stream input/output operations		friend ostream& operator<<(ostream& output_stream, const string_class output_string);		friend istream& operator>>(istream& input_stream, string_class& input_string);		// overloaded comparison operations between char arrays and string_class objects		friend int operator==(const string_class &string1, const string_class &string2);		friend int operator==(const string_class &string1, const char *string2);		friend int operator==(const char *string1, const string_class &string2);		friend int operator!=(const string_class &string1, const string_class &string2);		friend int operator!=(const string_class &string1, const char *string2);		friend int operator!=(const char *string1, const string_class &string2);		friend int operator>=(const string_class &string1, const string_class &string2);		friend int operator<=(const string_class &string1, const string_class &string2);		friend int operator>(const string_class &string1, const string_class &string2);		friend int operator<(const string_class &string1, const string_class &string2);		// overloaded append operations for char arrays and string_class objects		friend string_class operator+(const string_class source1, const string_class source2);		friend string_class operator+(const string_class source1, const char *source2);		friend string_class operator+(const char *source1, const string_class source2);		friend string_class operator+(const string_class source1, const char input_char);		// append source to target, and append a single ASCII 32 to resulting string		friend void append_name(string_class &target, const string_class &source);				// search for an occurrence of target+' ' within source string		friend status search_string(const string_class &source, const string_class &target);				int length();																							// return string_length};#endif