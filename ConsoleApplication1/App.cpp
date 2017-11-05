#include "Manager.h"
int main(int argc, char** argv)
{
	Manager manager("1.avi", "result.avi", "00:00:05");
	manager.make();
	return 0;
}