/************************************************************************************** * CODE FILE: set_input.c++ * PURPOSE	: define members of set_input class **************************************************************************************/#include "set_input.h"// Define default constructorset_input::set_input(){ lower_index=upper_index=start_value=incrementer=0; }// Define parameterized constructorset_input::set_input(int lower_i, int upper_i, double start_val, double inc){ set_parameters(lower_i, upper_i, start_val, inc); }// Define destructorset_input::~set_input(){	// do nothing as there is no dynamic allocation}// Define copy constructorset_input::set_input(set_input &original){ *this=original; }// Define assignment of set_input objects by set_input objectsset_input& set_input::operator=( set_input &original){	lower_index=original.lower_index;	upper_index=original.upper_index;	start_value=original.start_value;	incrementer=original.incrementer;	return *this;}// Define overloaded output operator for set_inputostream& operator<<(ostream& output_stream, const set_input output_set){	output_stream << "lower index=" << output_set.lower_index << "\n";	output_stream << "upper index=" << output_set.upper_index << "\n";	output_stream << "start value=" << output_set.start_value << "\n";	output_stream << "incrementer=" << output_set.incrementer << "\n";		output_stream << "\n";		return output_stream;}// define method for setting private data membersvoid set_input::set_parameters(int lower_i, int upper_i, double start_val, double inc){	if (lower_index>upper_index)								// swap over the indexes	{			int temp=upper_index;		upper_index=lower_index;		lower_index=temp;	}	lower_index=lower_i;	upper_index=upper_i;	start_value=start_val;	incrementer=inc;}// define method for extracting private data membersvoid set_input::get_parameters(int &lower_i, int &upper_i, double &start_val, double &inc){	lower_i=lower_index;	upper_i=upper_index;	start_val=start_value;	inc=incrementer;}