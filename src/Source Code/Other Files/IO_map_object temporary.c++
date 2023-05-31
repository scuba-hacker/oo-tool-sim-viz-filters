#include "IO_map_object.h"IO_map_object::IO_map_object()  															// ******DEFAULT CONSTRUCTOR*******{	next_IO_map_object = NULL;									// Initialize internal fields	name="";																	// Default NULL string}IO_map_object::IO_map_object(string_class map_name){	next_IO_map_object = NULL;	name=map_name;} IO_map_object::IO_map_object(string_class name, IO_map new_map){	initialise(new_map);}string_class IO_map_object::get_index()													// Return value of index field{ return name; }// *******THIS FUNCTION DEFINES HOW INDEXING WORKS ACROSS THE LIST *******void IO_map_object::set_to_next_index(const string_class ref)					// Given index of ref, set index of{																				// this IO_map_object to the next	name=ref+"a";											// permissible index. (append 'a')}void IO_map_object::set_to_first_index(){	name="a";}status IO_map_object::set_index(const string_class setting)						// Set value of index field {	name=setting;	return SUCCESS;		// always successful!}// ********THIS FUNCTION DEFINES THE COMPARISON METHOD FOR INDEXES**********compare IO_map_object::compare_index(const string_class index1, const string_class index2){	// cout << "compare IO_map_objects called, result is: ";	if (index1>index2)	{		// cout << "LARGER\n";		return LARGER;	}	else		if (index1==index2)		{			// cout << "EQUAL\n";			return EQUAL;		}		else		{			// cout << "SMALLER\n";			return SMALLER;		}}			IO_map IO_map_object::get_data()																// Return value of map field{ return map; }	status IO_map_object::set_data(const IO_map setting)											// Set value of map field{			return map.initialise(setting);																	// if within valid bounds}	// ********THIS FUNCTION DEFINES THE COMPARISON METHOD FOR DATA************	compare IO_map_object::compare_data(const IO_map name1, const IO_map name2){	return SMALLER; // this is irrelevant as ordering on map isn't going to be used}void IO_map_object::set_pointer_to(IO_map_object *p)						// Set next_IO_map_object pointer to the	{ next_IO_map_object=p; }											// value of pointer pIO_map_object* IO_map_object::get_pointer()																	// Return value of	{ return next_IO_map_object; }															// next_IO_map_object pointer	void IO_map_object::print_node()																			// Print Node info	{cout << name << "-> " << map;}					// on standard outputostream& operator<<(ostream& output_stream, const IO_map_object a){	output_stream << a.name << "->" << a.map;	return output_stream;}string_class get_calc_name(){	return map.get_calc_name();}string_class get_output_field(){	return map.output_field;}string_class IO_map_object::undefined_index="";