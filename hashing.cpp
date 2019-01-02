#include<iostream>
#include "hashtable.h"

using namespace std;

int main(){
	Hashtable h;
	h.insert("Mango",100);
	h.insert("Mang",20);
	h.insert("Mago",150);
	h.insert("Mao",90);
	h.insert("ango",120);

	h.print();

	return 0;
}