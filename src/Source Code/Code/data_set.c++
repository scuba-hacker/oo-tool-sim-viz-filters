/************************************************************************************** * CODE FILE: data_set.c++ * PURPOSE	: define members of data_set class **************************************************************************************/#include "data_set.h"// Define default constructordata_set::data_set(){	record_name="";	length=0;	width=0;	data_array=NULL;	fields=NULL;}// Define constructor using record_object and integer to initialisedata_set::data_set(record_object record_obj, const int array_length){	width=0;	length=array_length;	ulist<string_object> field_list=record_obj.get_data();		// get copy of record fields	record_name=record_obj.get_index();							// store name of record_obj in data_set	if (field_list.reset_transverse()==ERROR)		cout << "Warning: generation of data_set with null fields list\n";		do																// find out how many objects are in the records list	{ width++; }	while (field_list.progress_transverse()==SUCCESS);		fields=new string_class[width];										// Create array to hold field names	string_object temp_string_object;	field_list.reset_transverse();										// Reset to first string_object	for (int i=0; i<width; i++)												// Build look-up array:	{																									// - maps element number->field name		field_list.get_transverse(temp_string_object);	// Get current string_object		fields[i]=temp_string_object.get_data();		field_list.progress_transverse();								// Progress to next string_object	}	data_array=new complex[length*width];							// Dynamically create data_array 																											clear_data_array();																// Initialise all elements to 0+0j}// Define copy constructordata_set::data_set(const data_set &original){ *this=original; }// Define assignment of data_set objects by data_set objectsdata_set& data_set::operator=(const data_set &original){	// Copy across all non-dynamic data...	record_name=original.record_name;	length=original.length;	width=original.width;		// Now deal with dynamically allocated data...	if (original.fields!=NULL)								// Copy piecewise dynamic field strings array	{		fields=new string_class[width];					// Array maps element index->field name		for (int i=0; i<width; i++)							// Copy across all elements of original array			fields[i]=original.fields[i];	}	else		fields=NULL;														// No field array defined		if (original.data_array!=NULL)						// Copy piecewise dynamic data_array	{		data_array=new complex[length*width];		// Dynamically allocate large enough array		for (int i=0; i<length*width; i++)			data_array[i]=original.data_array[i];	}	else		data_array=NULL;												// No data_array defined	return *this;}// Define destructordata_set::~data_set(){	delete [] data_array;											// Deallocate two dimensional data array	delete [] fields;													// Deallocate single dimensional fields array}// Define method of reading data_array associatively on field name and index integerstatus data_set::get_element_assoc(complex &result, const int index,																	 const string_class field){	if (data_array!=NULL)																// Refuse non-defined array access	{		int field_index=-1;																// Set field_index to invalid value		for (int i=0; i<width; i++)												// Find out index for 'field'			if (fields[i]==field)														// Matching field name found...			{				field_index=i;																// Record corresponding index, and				break;																				// exit loop.			}		if (field_index==-1 || index<0 || index>=length)	// Index(s) invalid...		{			result=complex(0,0);														// Nullify result			return ERROR;		}		result=*(data_array+width*index+field_index);			// Get requested element of array		return SUCCESS;	}	else																								// Data_array is not defined...	{		result=complex(0,0);															// Nullify result		return ERROR;	}	}// Define method of reading data_array (non-associative: indexed field/indexed integer)status data_set::get_element(complex &result, const int index, const int field_index){	if (data_array!=NULL)																// Refuse non-defined array access	{	// Check both indexes for valid range		if (field_index<0 || field_index>=width || index<0 || index>=length)		{			result=complex(0,0);														// Nullify result			return ERROR;		}		result=*(data_array+width*index+field_index);			// Return array mapped result		return SUCCESS;	}	else																								// Data_array is not defined...	{		result=complex(0,0);															// Nullify result		return ERROR;	}	}// Define method of writing data_array associatively on field name and index integerstatus data_set::set_element_assoc(const complex new_value, const int index,																	 const string_class field){	if (data_array!=NULL)																// Refuse non-defined array access	{		int field_index=-1;																// Set field_index to invalid value		for (int i=0; i<width; i++)												// Find out index for 'field'			if (fields[i]==field)														// Matching field name found...			{				field_index=i;																// Record corresponding index, and				break;																				// exit loop.			}		if (field_index==-1 || index<0 || index>=length)	// Index(s) invalid...			return ERROR;					*(data_array+width*index+field_index)=new_value;	// Set requested element of array 		return SUCCESS;	}	else																								// Data_array is not defined...		return ERROR;}// Define method of writing data_array associatively on field name and index integerstatus data_set::set_element(const complex new_value, const int index,														 const int field_index){	if (data_array!=NULL)																// Refuse non-defined array access	{	// Check both indexes for valid range		if (field_index<0 || field_index>=width || index<0 || index>=length)			return ERROR;						*(data_array+width*index+field_index)=new_value;	// Set requested element of array		return SUCCESS;	}	else																								// Data_array is not defined...		return ERROR;}// Define method to set all elements in data array to 0+0jstatus data_set::clear_data_array(){	if (data_array!=NULL)																// If data array is defined	{		for (int i=0; i<width*length; i++)								// Initialise all complex elements			data_array[i]=complex (0,0);			return SUCCESS;	}	else	{		cout << "ERROR: can't clear_data_array as data array is not set\n";		return ERROR;	}}// Define overloaded output operator for data_set objectostream& operator<<(ostream& output_stream, data_set output_set){	complex number;		if (output_set.data_array!=NULL)												// If data array is initialised	{		output_stream << "Record Base: " << output_set.record_name << "\n";		output_stream << "Dimensions: " << output_set.length << "x";		output_stream <<  output_set.width << "\n";		output_stream << "Field Names: (" << output_set.width << ")\n\t\t";		for (int i=0; i<output_set.width; i++)											// Output all field names			output_stream << output_set.fields[i] << '\t';		output_stream << "\n";				for (int i=0; i<output_set.length; i++)		{			output_stream.width(3);																// Use character field width			output_stream << 'i' << '=' << i << ")\t";						// Output all elements of			for (int j=0; j<output_set.width; j++)								// data_array			{				output_set.get_element(number, i, j);				output_stream << number << "\t\t";			}			output_stream << "\n";		}				}	else		output_stream << "data_set not initialised\n";	return output_stream;}// Provide read-access to private data membersint data_set::get_length(){ return length; }int data_set::get_width(){	return width; }string_class data_set::get_record_name(){ return record_name; }void data_set::get_fields(string_class *storage){	if (data_array!=NULL)																// Refuse non-defined array access	{		for (int i=0; i<width; i++)			storage[i]=fields[i];	}}