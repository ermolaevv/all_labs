#include <iostream>
#include "HeadRing.h"
#include "Monom.h"

int main(int argc, char** argv) {
	THeadRing<TMonom> list;
	list.InsFirst(new TMonom());
	list.InsFirst(new TMonom());
	list.InsCurrent(new TMonom());
	list.GoNext();
	list.GoNext();
	list.GoNext();
	list.DelFirst();
	list.GoNext();
	list.GoNext();
	list.GoNext();

}