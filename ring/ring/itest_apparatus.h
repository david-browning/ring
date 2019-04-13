#pragma once

namespace ring::test
{
	/*
	 Abstract class used to organize tests.
	 Override "test" to implement tests. Throw an exception
	 if the tests do not pass.
	 */
	class itest_appartatus
	{
		public:
		virtual void test() const = 0;
	};
}