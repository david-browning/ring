#pragma once

namespace ring::test
{
	/*
	 Abstract class used to organize tests.
	 Override "test" to implement tests. Return true if the tests
	 pass. False if a test does not pass.
	 */
	class itest_appartatus
	{
		public:
		virtual bool test() const = 0;
	};
}