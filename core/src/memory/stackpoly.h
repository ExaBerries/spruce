#pragma once
#include <types.h>

namespace spruce {
	template <typename TYPE, uint64 SIZE>
	struct alignas(alignof(TYPE)) stackpoly {
		static_assert(SIZE >= sizeof(TYPE));
		using Type = TYPE;
		uint8 data[SIZE];
		bool null = true;

		stackpoly() noexcept = default;
		stackpoly(const stackpoly&) noexcept = default;
		stackpoly(stackpoly&&) noexcept = default;
		~stackpoly() noexcept;

		template <typename POLYTYPE, typename ... CONSTYPES>
		void cons(CONSTYPES&& ... args) noexcept;
		void desc() noexcept;

		[[nodiscard]] operator TYPE*() noexcept;
		[[nodiscard]] operator const TYPE*() const noexcept;
		template <typename OTHERTYPE>
		[[nodiscard]] explicit operator OTHERTYPE*() noexcept;
		template <typename OTHERTYPE>
		[[nodiscard]] explicit operator const OTHERTYPE*() const noexcept;

		[[nodiscard]] TYPE& operator*() noexcept;
		[[nodiscard]] const TYPE& operator*() const noexcept;
		TYPE* operator->() noexcept;
		const TYPE* operator->() const noexcept;

		stackpoly& operator=(const stackpoly&) noexcept = default;
		stackpoly& operator=(stackpoly&&) noexcept = default;
	};

	template <typename TYPE, uint64 SIZE>
	[[nodiscard]] bool operator==(const stackpoly<TYPE, SIZE>& stackPoly, std::nullptr_t) noexcept;

	template <typename TYPE, uint64 SIZE>
	[[nodiscard]] bool operator!=(const stackpoly<TYPE, SIZE>& stackPoly, std::nullptr_t) noexcept;
}

#include <memory/stackpolyImpl.h>
