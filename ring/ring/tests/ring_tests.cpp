#include "ring_tests.h"
#include "..\include\ring.h"

bool ring::test::ring_tests::test() const
{
	return this->test_capacity_constructor() &&
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
	//Create a ring.
	std::vector<int> ringInput{ 0, 1, 2, 3, 4, 5, 6 };
	std::ring<int> r{ ringInput.begin(), ringInput.end() };
	for (auto expectedValue : ringInput)
	{
		auto actualValue = r.current();
		if (actualValue != expectedValue)
		{
			return false;
		}

		r.advance();
	}

	if (r.current() != ringInput.front())
	{
		return false;
	}

	return true;
}

bool ring::test::ring_tests::test_retreat() const
{
	//Create a ring.
	std::vector<int> ringInput{ 0, 1, 2, 3, 4, 5, 6 };
	std::ring<int> r{ ringInput.begin(), ringInput.end() };

	//Use retreat to iterate through the ring backwards.
	for (auto inputIt = ringInput.rbegin(); 
		 inputIt != ringInput.rend(); 
		 ++inputIt)
	{
		r.retreat();

		auto expectedValue = *inputIt;
		auto actualValue = r.current();

		if (expectedValue != actualValue)
		{
			return false;
		}

	}

	return true;
}
