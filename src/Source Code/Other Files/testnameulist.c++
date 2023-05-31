#include "define_vars.h"#include "name_object.h"#include <SIOUX.h>#include "ulist.c++"// ******* TEST list class using object.h contains only integers ***************// ******* Used in preliminary testing, not required for final system testing **// ******** All code and design MARK JONES *************************************name_ulist test;											// declare one list structureint main(){	complex_container nameitem;	string_class index;	name_object temp;		SIOUXSettings.asktosaveonclose = FALSE;	SIOUXSettings.showstatusline = TRUE;	SIOUXSettings.columns = 150;	SIOUXSettings.rows = 40;	SIOUXSettings.toppixel = 38;	SIOUXSettings.leftpixel = 0;		char command[4];	// Holds two command input characters and the NULL character	cout << "Formatting of input: \n";	cout << "\tcomplex_container:\n";	cout << "\t\t{\n";	cout << "\t\t\tindicator = CONSTANT | VARIABLE | EXPRESSION\n";	cout << "\t\t\tunion { complex_number : re im     (CONSTANT|VARIABLE\n";	cout << "\t\t\t        expression     : re im			(EXPRESSION)\n";	cout << "\n";	cout << "Commands Available :\n";	cout << "add (index sort)          adi : name complex_container direction\n";	cout << "add (data sort)           add : name complex_container direction\n";	cout << "update                    upd : (search_name, search_container) (new_name, new_complex_container) update_field (order direction)\n";	cout << "remove (index search)     rmi : name\n";	cout << "remove (data search)      rmd : complex_container\n";	cout << "print_list...             prn : no parameters\n";	cout << "\n\n";		while (cin >> command)	// While there is standard input data, read in command	{			if (strcmp(command,"prn") == 0)			// Print out entire list.		{			cout << "ADDRESS of test is " << &test << "\n";			test.printlist();		}			if (strcmp(command,"adi") == 0 ||		// Use C function to check command for				strcmp(command,"add") == 0)		{																		// correct add node instruction.			ordering order;			string_class direction_string;			orderproperty direction;			int input_error=0;						if (strcmp(command,"adi") == 0)				order = COUNTER;			else				order = DATA;							cin >> index >> nameitem >> direction_string;					// Read in index and data values.			{				if (direction_string=="ASCENDING")					direction=ASCENDING;				else					if (direction_string=="DESCENDING")						direction=DESCENDING;					else					{						cout << "direction: invalid orderproperty enum value\n";						input_error=1;					}			}						// Load up temp object with the input parameters...			if (input_error==1 || temp.set_index(index)==ERROR || temp.set_data(nameitem) == ERROR)				cout << "Invalid add - Index or nameitem out of range\n";			else			{				if (test.add(temp, order, direction) == ERROR)// Attempt to add the object just defined					cout << "Invalid add - Index match problem\n";				else					{					test.printlist();								// Send list to Standard Output.					cout << "\n";										// Send New-Line to Standard Output				}			}		}							if (strcmp(command,"upd") == 0)	// Use C function to check command for		{																		// correct add node instruction.			string_class search_name_string, new_name_string;							complex_container search_container, new_container;			ordering update_field, order;			orderproperty direction;						string_class update_field_string, order_string, direction_string;			name_object search_node, new_node;						int input_error=0;						cin >> search_name_string >> search_container >> new_name_string >> new_container >> update_field_string >>  order_string >> direction_string;	// Read in index and data values.			cout << "read in all upd parameters\n";			{				if (update_field_string=="COUNTER")					update_field=COUNTER;				else					if (update_field_string=="DATA")						update_field=DATA;					else					{						cout << "search_field: invalid ordering enum value\n";						input_error=1;					}			}			{				if (order_string=="COUNTER")					order=COUNTER;				else					if (order_string=="DATA")						order=DATA;					else					{						cout << "order: invalid ordering enum value\n";						input_error=1;					}			}			{				if (direction_string=="ASCENDING")					direction=ASCENDING;				else					if (direction_string=="DESCENDING")						direction=DESCENDING;					else					{						cout << "direction: invalid orderproperty enum value\n";						input_error=1;					}			}			// Load up temp object with the input parameters...			if (input_error==1 || search_node.set_index(search_name_string)==ERROR || search_node.set_data(search_container) == ERROR ||														new_node.set_index(new_name_string)==ERROR || new_node.set_data(new_container) == ERROR)				cout << "Invalid upd - inputs out of range\n";			else			{				if (update_field==DATA)					cout << "update_field is DATA\n";				if (test.update(search_node, new_node, update_field, order, direction) == ERROR)// Attempt to add the object just defined					cout << "Invalid update\n";				else					{					test.printlist();								// Send list to Standard Output.					cout << "\n";										// Send New-Line to Standard Output				}			}		}			if (strcmp(command,"rmi") == 0)			// Use C function to check command for		{																		// correct remove node instruction.						cin >> index;											// Read in index of node to remove									temp.set_index(index);			if (test.remove(temp, COUNTER) == ERROR)	// Attempt to remove the node with this																				// index				cout << "Invalid remove - Node with index " << index <<" not found\n";							test.printlist();									// Send list to Standard Output.			cout << "\n";											// Send New-Line to Standard Output.		}		if (strcmp(command,"rmd") == 0)			// Use C function to check command for		{																		// correct remove node instruction.			complex_container container;			int input_error=0;						cin >> container;											// Read in index of node to remove									temp.set_data(container);			if (test.remove(temp, DATA) == ERROR)	// Attempt to remove the node with this																				// index				cout << "Invalid remove - Node with complex_container " << container <<" not found\n";							test.printlist();									// Send list to Standard Output.			cout << "\n";											// Send New-Line to Standard Output.		}	}	return 0;}