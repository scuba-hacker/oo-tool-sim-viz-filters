/************************************************************************************** * CODE FILE: IO_map_object.c++ * PURPOSE	: define members of IO_map_object class **************************************************************************************/#include "IO_map_object.h"// Define default constructorIO_map_object::IO_map_object(){	next_IO_map_object = NULL;	name=IO_map_object::undefined_index;}// Define constructor using string_class to initialiseIO_map_object::IO_map_object(string_class map_name){	next_IO_map_object = NULL;	name=map_name;} // Define constructor using string_class and IO_map to initialiseIO_map_object::IO_map_object(string_class map_name, IO_map new_map){		next_IO_map_object = NULL;	name=map_name;	map=new_map;}// Define copy constructorIO_map_object::IO_map_object(IO_map_object &original){	name=original.name;	map=original.map;	next_IO_map_object=original.next_IO_map_object;}// Define assignment of IO_map_object objects by IO_map_object objectsIO_map_object& IO_map_object::operator=(IO_map_object &original){	name=original.name;	map=original.map;	next_IO_map_object=original.next_IO_map_object;	return *this;}// Define method for extracting index fieldstring_class IO_map_object::get_index(){ return name; }// Define method for setting index fieldstatus IO_map_object::set_index(const string_class setting){	name=setting;	return SUCCESS;}// Define method for defining index of first object in list, if index not specifiedvoid IO_map_object::set_to_first_index(){	name="a"; }// Define method for defining incremental indexing across the list, head->tailvoid IO_map_object::set_to_next_index(const string_class ref)	{	name=ref+"a";	}// Define method for comparing two index objects - lexical comparison of string_classcompare IO_map_object::compare_index(const string_class index1, const string_class index2){	if (index1>index2)		return LARGER;	else		if (index1==index2)			return EQUAL;		else			return SMALLER;}			// Define method for extracting data fieldIO_map IO_map_object::get_data()	{ return map; }	// Define method for setting data fieldstatus IO_map_object::set_data(IO_map setting){			map=setting;	return SUCCESS;}	// Define method for comparing two data objects - comparison complex_containerscompare IO_map_object::compare_data(const IO_map name1, const IO_map name2){	#pragma unused (name1)	#pragma unused (name2)	return SMALLER; 																				// Arbitrary ordering on IO_map}// Define method for setting pointer fieldvoid IO_map_object::set_pointer_to(IO_map_object *p){ next_IO_map_object=p; }	// Define method for extracting pointer fieldIO_map_object* IO_map_object::get_pointer(){ return next_IO_map_object; }	// Define method for outputting name_object contents on standard outputvoid IO_map_object::print_node(){cout << name << "-> " << map;}// Define overloaded output operator for IO_map_objectostream& operator<<(ostream& output_stream, IO_map_object a){	output_stream << a.name << "->" << a.map;	return output_stream;}// Define methods for accessing public data members inside data field (IO_map)void IO_map_object::get_input_fields(string_class *stored_input_fields){ map.get_input_fields(stored_input_fields); }int IO_map_object::get_number_of_input_fields(){	return map.get_number_of_input_fields(); }void IO_map_object::get_output_fields(string_class *stored_output_fields){ map.get_output_fields(stored_output_fields); }int IO_map_object::get_number_of_output_fields(){	return map.get_number_of_output_fields(); }// Define undefined index as empty stringstring_class IO_map_object::undefined_index="";