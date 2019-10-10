#pragma once
#include <types.h>

namespace spruce {
	template <typename TYPE, uint64 SIZE>
	struct alignas(alignof(TYPE)) stackpoly {
		uint8 data[SIZE];
		bool null = true;

		stackpoly() = default;
		stackpoly(const stackpoly&) = default;
		stackpoly(stackpoly&&) noexcept = default;
		~stackpoly();

		template <typename POLYTYPE, typename ... CONSTYPES>
		void cons(CONSTYPES&& ... args);
		void desc();

		operator TYPE*();
		operator const TYPE*() const;
		template <typename OTHERTYPE>
		explicit operator OTHERTYPE*();
		template <typename OTHERTYPE>
		explicit operator const OTHERTYPE*() const;

		TYPE& operator*() noexcept;
		const TYPE& operator*() const noexcept;
		TYPE* operator->() noexcept;
		const TYPE* operator->() const noexcept;

		bool operator==(std::nullptr_t);
		bool operator!=(std::nullptr_t);

		stackpoly& operator=(const stackpoly&) = default;
		stackpoly& operator=(stackpoly&&) noexcept = default;
	};
}

#include <memory/stackpolyImpl.h>
