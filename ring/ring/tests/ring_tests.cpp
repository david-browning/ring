#include "ring_tests.h"
#include "..\include\ring.h"

void ring::test::ring_tests::test() const
{
	test_capacity_constructor();
	test_il_constructor();
	test_copy_constructor();
	test_move_constructor();
	test_advance();
	test_retreat();
}

void ring::test::ring_tests::test_capacity_constructor() const
{
	std::ring<int> r(8);
	if (r.size() != 8)
	{
		throw std::length_error(
			"The ring does not have the correct size.");
	}

	//Rings do not allow size 0.
	bool caughtException = false;
	try
	{
		std::ring<int> emptyRing(0);
	}
	catch (std::invalid_argument const&)
	{
		caughtException = true;
	}

	if (!caughtException)
	{
		throw std::length_error(
			"The ring allowed an invalid size when constructing");
	}
}

void ring::test::ring_tests::test_il_constructor() const
{
	//Create a ring using an initializer list.
	std::initializer_list<int> il = { 0, 1, 2, 3, 4, 5, 6 };
	std::ring<int> r(il);

	//Check its size
	if (r.size() != il.size())
	{
		throw std::length_error(
			"The ring does not have the correct size.");
	}

	//Check the order
	for (auto expectedValue : il)
	{
		if (r.current() != expectedValue)
		{
			throw std::logic_error("The ring is not in the correct order");
		}

		r.advance();
	}

	//Create a ring using an empty initializer list.
	std::initializer_list<int> emptyIL = {};
	bool caughtException = false;

	//Catch the exception.
	try
	{
		std::ring<int> emptyRing(emptyIL);
	}
	catch (std::invalid_argument const&)
	{
		caughtException = true;
	}

	if (!caughtException)
	{
		throw std::length_error(
			"The ring allowed an invalid size when constructing");
	}
}

void ring::test::ring_tests::test_copy_constructor() const
{
	//Create a ring
	std::vector<int> ringInput{ 0, 1, 2, 3, 4, 5, 6 };
	std::ring<int> r(ringInput.begin(), ringInput.end());

	//Copy it
	std::ring<int> ringCopied(r);

	//Check the size.
	if (ringCopied.size() != r.size())
	{
		throw std::length_error(
			"The ring does not have the correct size.");
	}

	//Iterate through both rings, checking that their order is the same.
	for (auto expectedValue : ringInput)
	{
		if (r.current() != expectedValue || ringCopied.current() != expectedValue)
		{
			throw std::logic_error("The ring is not in the correct order");
		}

		r.advance();
		ringCopied.advance();
	}
}

void ring::test::ring_tests::test_move_constructor() const
{
	//Create a ring.
	std::vector<int> ringInput{ 0, 1, 2, 3, 4, 5, 6 };
	std::ring<int> r(ringInput.begin(), ringInput.end());

	//Move it
	auto ringMoved = std::move(r);

	//As a sanity check, the old ring should have size zero.
	if (r.size() != 0)
	{
		throw std::length_error(
			"The old ring should have 0 size.");
	}

	//Check the size
	if (ringMoved.size() != ringInput.size())
	{
		throw std::length_error(
			"The ring does not have the correct size.");
	}

	//Iterate through the ring, checking if the order matches the original.
	for (auto expectedValue : ringInput)
	{
		auto actualValue = ringMoved.current();
		if (actualValue != expectedValue)
		{
			throw std::logic_error("The ring is not in the correct order");
		}

		ringMoved.advance();
	}

	if (ringMoved.current() != ringInput.front())
	{
		throw std::logic_error("The ring is not in the correct order");
	}
}

void ring::test::ring_tests::test_advance() const
{
	//Create a ring.
	std::vector<int> ringInput{ 0, 1, 2, 3, 4, 5, 6 };
	std::ring<int> r(ringInput.begin(), ringInput.end());
	for (auto expectedValue : ringInput)
	{
		auto actualValue = r.current();
		if (actualValue != expectedValue)
		{
			throw std::logic_error("The ring is not in the correct order");
		}

		r.advance();
	}

	if (r.current() != ringInput.front())
	{
		throw std::logic_error("The ring is not in the correct order");
	}
}

void ring::test::ring_tests::test_retreat() const
{
	//Create a ring.
	std::vector<int> ringInput{ 0, 1, 2, 3, 4, 5, 6 };
	std::ring<int> r(ringInput.begin(), ringInput.end());

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
			throw std::logic_error("The ring is not in the correct order");
		}
	}
}
