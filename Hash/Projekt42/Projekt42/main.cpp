#include "H.h"




int main()
{
	H* p = new H;
	p->add_open();
	p->add_open();
	p->add_open();
	p->del_open();
	p->add_open();
	p->add_open();

	system("PAUSE");
	return 0;
}