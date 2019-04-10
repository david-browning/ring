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
	std::ring<int> r{ 8 };
	if (r.size() != 8)
	{
		return false;
	}

	//Rings do not allow size 0.
	bool caughtException = false;
	try
	{
		std::ring<int> emptyRing{ 0 };
	}
	catch (std::length_error const&)
	{
		caughtException = true;
	}

	if (!caughtException)
	{
		return false;
	}

	return true;
}

bool ring::test::ring_tests::test_il_constructor() const
{
	//Create a ring using an initializer list.
	std::initializer_list<int> il = { 0, 1, 2, 3, 4, 5, 6 };
	std::ring<int> r{ il };

	//Check its size
	if (r.size() != il.size())
	{
		return false;
	}

	//Check the order
	for (auto expectedValue : il)
	{
		if (r.current() != expectedValue)
		{
			return false;
		}

		r.advance();
	}

	//Create a ring using an empty initializer list.
	std::initializer_list<int> emptyIL = {};
	bool caughtException = false;

	//Catch the exception.
	try
	{
		std::ring<int> emptyRing{ emptyIL };
	}
	catch (std::length_error const&)
	{
		caughtException = true;
	}

	if (!caughtException)
	{
		return false;
	}

	return true;
}

bool ring::test::ring_tests::test_copy_constructor() const
{
	//Create a ring
	std::vector<int> ringInput{ 0, 1, 2, 3, 4, 5, 6 };
	std::ring<int> r{ ringInput.begin(), ringInput.end() };

	//Copy it
	std::ring<int> ringCopied{ r };

	//Check the size.
	if (ringCopied.size() != r.size())
	{
		return false;
	}

	//Iterate through both rings, checking that their order is the same.
	for (auto expectedValue : ringInput)
	{
		if (r.current() != expectedValue || ringCopied.current() != expectedValue)
		{
			return false;
		}

		r.advance();
		ringCopied.advance();
	}

	return true;
}

bool ring::test::ring_tests::test_move_constructor() const
{
	//Create a ring.
	std::vector<int> ringInput{ 0, 1, 2, 3, 4, 5, 6 };
	std::ring<int> r{ ringInput.begin(), ringInput.end() };

	//Move it
	auto ringMoved = std::move(r);

	//As a sanity check, the old ring should have size zero.
	if (r.size() != 0)
	{
		return false;
	}

	//Check the size
	if (ringMoved.size() != ringInput.size())
	{
		return false;
	}

	//Iterate through the ring, checking if the order matches the original.
	for (auto expectedValue : ringInput)
	{
		auto actualValue = ringMoved.current();
		if (actualValue != expectedValue)
		{
			return false;
		}

		ringMoved.advance();
	}

	if (ringMoved.current() != ringInput.front())
	{
		return false;
	}

	return true;
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
