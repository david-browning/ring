#pragma once
#include "..\itest_apparatus.h"

namespace ring::test
{
	/*
	 Tests the ring's constructors.
	 */
	class ring_tests : public itest_appartatus
	{
		public:
		virtual void test() const;

		private:
		/*
		 Tests creating an empty ring and checking that the size is correct.
		 */
		void test_capacity_constructor() const;

		/*
		 Tests creating a ring from an initializer list.
		 Checks the size.
		 Iterates through the ring to ensure the order is the same as the
		 initializer list.
		 This implicitly tests advancing the ring pointer and that the pointer is
		 correct.
		 */
		void test_il_constructor() const;

		/*
		 Tests the deep copy constructor.
		 Checks that all fields are the same after creating a copy.
		 This implicitly tests advancing the ring pointer and that the pointer is
		 correct.
		 */
		void test_copy_constructor() const;

		/*
		 Tests moving a ring.
		 Checks that no fields have changed after the move.
		 This implicitly tests advancing the ring pointer and that the pointer is
		 correct.
		 */
		void test_move_constructor() const;

		/*
		 Tests that advancing the ring pointer repeatedly will keep the pointer
		 pointing to the correct item.
		 Tests that the ring pointer will eventually loop around.
		 */
		void test_advance() const;

		/*
		 Tests that retreating the ring pointer repeatedly will keep the pointer
		 pointing to the correct item.
		 Tests that the ring pointer will eventually loop around.
		 */
		void test_retreat() const;
	};
}