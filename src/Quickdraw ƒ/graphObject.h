#include "extragraphclasses.h"#include <stdio.h>class graph{	private:		port_info port;		border_info border;		bound_info bound;		scale_info horiz_scale, vert_scale;		range_info horiz_range, vert_range;		tick_info ticks;				int scaleSize;				// scale text size in points				WindowPtr mainPtr;		Rect windRect;		int graph_display;			public:		graph(port_info newport, border_info newborder, scale_info newhoriz_scale, scale_info newvert_scale,			range_info newhoriz_range,  range_info newvert_range, tick_info newticks);				void showGraph();		void hideGraph();		void clear_window();		void blank_graph();		void translate_to_grafport(double &x, double &y);		double translate_x(double x);		double translate_y(double y);		void draw_x_line(double x, long int brightness);		void draw_y_line(double y, long int brightness);		void draw_axes();		void vertical_ticks();		void horizontal_ticks();		void PlaceCross(int Width);		void set_port(port_info newport);		void set_border(border_info newborder);		void set_horiz_scales(scale_info newhoriz_scale);		void set_vert_scales(scale_info newvert_scale);		void set_horiz_range(range_info newhoriz_range);		void set_vert_range(range_info newvert_range);		void set_ticks(tick_info newticks);};