#include "ring_tests.h"

bool ring::test::ring_tests::test() const
{
	return this->test_capacity_constructor() &&
		this->test_iterator_constructor() &&
		this->test_il_constructor() &&
		this->test_copy_constructor() &&
		this->test_move_constructor() &&
		this->test_advance() &&
		this->test_retreat();
}

bool ring::test::ring_tests::test_capacity_constructor() const
{
	return false;
}

bool ring::test::ring_tests::test_iterator_constructor() const
{
	return false;
}

bool ring::test::ring_tests::test_il_constructor() const
{
	return false;
}

bool ring::test::ring_tests::test_copy_constructor() const
{
	return false;
}

bool ring::test::ring_tests::test_move_constructor() const
{
	return false;
}

bool ring::test::ring_tests::test_advance() const
{
	return false;
}

bool ring::test::ring_tests::test_retreat() const
{
	return false;
}
