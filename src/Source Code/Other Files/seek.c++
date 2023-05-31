#include <iostream>
#include <strstream>
/* 
const int size = 100;
char buf[size];char arr[size] = 
"Metrowerks CodeWarrior - Software at work";  
main()
{   
  ostrstream ostr(buf, size);
  ostr << arr;
  
     // associate buffer
  strstreambuf *strbuf(ostr.rdbuf());  
  
     // do some manipulations
  strbuf->pubseekoff(10,ios::beg); 
  strbuf->sputc('\0');
  strbuf->pubseekoff(0, ios::beg);
  
  cout << "The original array was\n" << arr << "\n\n";
  cout << "The strstreambuf array is\n" << strbuf->str() <<
"\n\n";
  cout << "The ostrstream array is now\n" << buf;
  
  return 0;
}
*/

#include "string.h"
char input_string[100]="This is a test for streams.\n";
char buf_string[100]="";
main()
{
	istrstream input_stream(input_string, strlen(input_string)+1);
	streampos curr_pos;
	streamoff pos_to_set;
	long offset;

	while (input_stream.rdstate()==ios::goodbit)
	{
		// to get current position in string
		curr_pos=input_stream.rdbuf()->pubseekoff(0, ios::cur, ios::in);
		offset=curr_pos.offset();
		cout << "Reading char " << offset << "\n";
		input_stream >> buf_string;
		cout << buf_string << '\n';
	}

	cout << input_stream.rdstate();

	// now lets do it once more
	
	input_stream.rdbuf()->pubseekoff(5, ios::beg, ios::in);
	
	// read in one word
	
	input_stream >> buf_string;
	cout << "repeated is " << buf_string << "\n";
/*
	while (input_stream)
	{
		// to get current position in string
		curr_pos=input_stream.rdbuf()->pubseekoff(0, ios::cur, ios::in);
		offset=curr_pos.offset();
		cout << "Reading char " << offset << "\n";
		input_stream >> buf_string;
		cout << buf_string << '\n';
	}
*/


	
/*	// input_stream.rdbuf()->pubseekoff(5, ios::beg);
	offset=input_stream.rdbuf()->pubseekoff(5, ios::beg, ios::in);
	cout << offset.offset();
	input_stream >> buf_string;
	cout << buf_string << '\n';
	offset=input_stream.rdbuf()->pubseekoff(0, ios::cur, ios::in);
	cout << offset.offset();


	input_stream >> buf_string;
	cout << buf_string << '\n';

*/

return 1;
}





