#ifndef _graph_spec_obj_h#define _graph_spec_obj_h#include "newstring.h"#include "graph_spec.h"#include "define_vars.h"class graph_spec_obj{	private:		string_class name;							// Indexing method - ensures no two names are the same		graph_spec spec;						// Name containing string, graph		graph_spec_obj *next_graph_spec_obj;			// Pointer to next graph_spec_obj node in list	public:			static string_class undefined_index;			// functions required by list				// for the first two constructors - data must be set by using set_data - only allowed to do this once!		graph_spec_obj(); 															// ******DEFAULT CONSTRUCTOR******		graph_spec_obj(string_class name);		// as all data has been given - set_data is now deactivated.		graph_spec_obj(string_class name, graph_spec new_spec);		graph_spec_obj(graph_spec_obj &original);		graph_spec_obj& operator=( graph_spec_obj &original);		string_class get_index();													// Return value of index field		void set_to_next_index(const string_class ref);					// Given index of ref, set index of		status set_index(const string_class setting);					// Set value of index field 				void set_to_first_index();		compare compare_index(const string_class index1, const string_class index2);		graph_spec get_data();																// Return value of data field	 	status set_data(const graph_spec setting);											// Set value of data field		compare compare_data(const graph_spec name1, const graph_spec name2);		void set_pointer_to(graph_spec_obj *p);						// Set next_graph_spec_obj pointer to the		graph_spec_obj* get_pointer();																	// Return value of		void print_node();																			// Print Node info				friend ostream& operator<<(ostream& output_stream, const graph_spec_obj a);};#endif