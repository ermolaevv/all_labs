#include <iostream>
#include "DatList.h"
#include "Monom.h"

int main(int argc, char** argv) {
	TDatList<TMonom> list;
	list.InsFirst(new TMonom());
	list.InsCurrent(new TMonom());
	list.GoNext();
}