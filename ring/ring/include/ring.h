#pragma once
#include <vector>

namespace std
{
	/*
	 A ring holds a fixed number of elements and uses a pointer to indicate the
	 current item. A ring must contain at least 1 element. Constructors check 
	 this requirement and throws std::length_error if there are 0 elements.
	 The pointer can be advanced to access the next element in a clockwise
	 order. A ring has does not have a first or last element. Continually 
	 advancing the ring pointer will bring the pointer back to where is 
	 originally was.
	 The pointer can be retreated to access the previous element in a 
	 counter-clockwise order.
	 Accessing the current element and advancing and retreating the pointer are
	 constant operations.
	 */
	template<class T, class Alloc = allocator<T>>
	class ring
	{
		using value_type = T;
		using allocator_type = Alloc;

		public:
		/*
		 Construct an empty ring with "capacity" slots.
		 */
		ring(size_t capacity);

		/*
		 Construct a ring using an iterator.
		 */
		template<class InputIterator>
		ring(InputIterator first,
			 InputIterator last,
			 const allocator_type& alloc = allocator_type());

		/*
		 Construct a ring using an initializer list.
		 */
		ring(initializer_list<value_type> il,
			 const allocator_type& alloc = allocator_type());

		/*
		 Copy Constructor
		 */
		ring(const ring& x) = default;

		/*
		 Move Constructor
		 */
		ring(ring&& x) = default;

		/*
		 Destructor
		 */
		~ring() = default;

		/*
		 Advances the ring pointer to the next item in the ring.
		 Complexity: Constant
		 */
		void advance();

		/*
		 Advances the ring pointer to the previous item in the ring.
		 Complexity: Constant
		 */
		void retreat();

		/*
		 Returns the number of elements in the ring.
		 Complexity: Constant
		 */
		size_t size() const noexcept;

		/*
		 Returns a reference to the current element pointed to in the ring.
		 Complexity: Constant
		 */
		value_type& current();

		/*
		 Returns a const-reference to the current element pointed to in the ring.
		 Complexity: Constant
		 */
		const value_type& current() const;

		private:
		/*
		 Index of the current item.
		 */
		size_t m_current;

		/*
		 Underlying container.
		 */
		std::vector<value_type, allocator_type> m_container;
	};
}