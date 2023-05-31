/************************************************************************************** * CODE FILE: system_process.c++ * PURPOSE	: define members of system_process class **************************************************************************************/#include "system_process.h"// Function for reading list of names from input_stream and storing in one of the listsvoid system_process::load_list(istream &input_stream, int list){	char name_chars[100];														// Buffer to hold individual name	ulist<string_object> names_list;								// List for holding all names	while(input_stream >> name_chars)								// Get names from input_stream	{	// Add each name to list using order found in input_string		names_list.add_to_end(string_object(name_chars));	}	switch (list)	{		case 0:			set_input_names=names_list;												// Copy in set_input_names list			break;		case 1:			set_input_fields=names_list;											// Copy in set_input_fields list			break;		case 2:			map_names=names_list;															// Copy to map_names list			break;	}}// Overloaded output operator for system_process classostream& operator<<(ostream& output_stream, system_process& output_map){	output_stream << "Calculator Name: " << output_map.calc_name << "\n";	output_stream << "Data Set Name: " << output_map.data_set_name << "\n";	output_stream << "Graph Spec Name: " << output_map.graph_spec_name << "\n";	output_stream << "Set Input Names: " << output_map.set_input_names;	output_stream << "Set Input Fields: " << output_map.set_input_fields;	output_stream << "Map Names: " << output_map.map_names;	return output_stream;}