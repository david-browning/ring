#include <iostream>
#include "tests/ring_tests.h"
#include <cassert>

int main(int argc, char** argv)
{
	ring::test::ring_tests tests;
	tests.test();

	return 0;
}
