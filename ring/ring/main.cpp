#include <iostream>
#include "tests/ring_tests.h"
#include <cassert>

int main(int argc, char** argv)
{
	ring::test::ring_tests tests;
	assert(tests.test() == true);

	return 0;
}
