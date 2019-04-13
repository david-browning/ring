#pragma once
#include <vector>

namespace std
{
	/*
	 A ring holds a fixed number of elements and uses a pointer to indicate the
	 current item. A ring must contain at least 1 element. Constructors check
	 this requirement and throws std::invalid_argument if there are 0 elements.
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
		ring(size_t capacity,
			 const allocator_type& alloc = allocator_type()) :
			m_current(0),
			m_container(capacity, alloc)
		{
			if (capacity == 0)
			{
				throw std::invalid_argument("Ring size cannot be zero.");
			}
		}

		/*
		 Construct a ring using an iterator.
		 */
		template<class InputIterator>
		ring(InputIterator first,
			 InputIterator last,
			 const allocator_type& alloc = allocator_type()) :
			m_current(0),
			m_container(first, last)
		{
			if (first == last)
			{
				throw std::invalid_argument(
					"The input iterator must have at least 1 item.");
			}
		}

		/*
		 Construct a ring using an initializer list.
		 */
		ring(initializer_list<value_type> il,
			 const allocator_type& alloc = allocator_type()) :
			m_current(0),
			m_container(il)
		{
			if (il.size() == 0)
			{
				throw std::invalid_argument("The initializer list cannot be empty.");
			}
		}

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
		void advance()
		{
			m_current = (m_current + 1) % m_container.size();
		}

		/*
		 Advances the ring pointer to the previous item in the ring.
		 Complexity: Constant
		 */
		void retreat()
		{
			if (m_current == 0)
			{
				m_current = m_container.size() - 1;
			}
			else
			{
				m_current--;
			}
		}

		/*
		 Returns the number of elements in the ring.
		 Complexity: Constant
		 */
		size_t size() const noexcept
		{
			return m_container.size();
		}

		/*
		 Returns a reference to the current element pointed to in the ring.
		 Complexity: Constant
		 */
		value_type& current()
		{
			return m_container[m_current];
		}

		/*
		 Returns a const-reference to the current element pointed to in the ring.
		 Complexity: Constant
		 */
		const value_type& current() const
		{
			return m_container[m_current];
		}

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