#include <iostream.h>class B;class A{	public:		B* parent;		void operate_on_parent(void);/*		friend void B::operate_on_list(void);*/};class B{	public:		A list;		void operate_on_list(void);		int c;/*		friend void A::operate_on_parent(void);*/};void B::operate_on_list(void){	cout << list.parent; // output address of parent}void A::operate_on_parent(void){	parent->c=10;}void main(){	A test1;	B test2;}