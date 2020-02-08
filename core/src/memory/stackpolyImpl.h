#pragma once

namespace spruce {
	template <typename TYPE, uint64 SIZE>
	stackpoly<TYPE, SIZE>::~stackpoly() noexcept {
		desc();
	}

	template <typename TYPE, uint64 SIZE>
	template <typename POLYTYPE, typename ... CONSTYPES>
	void stackpoly<TYPE, SIZE>::cons(CONSTYPES&& ... args) noexcept {
		static_assert(std::is_constructible_v<POLYTYPE, CONSTYPES...>);
		new (data) POLYTYPE(args...);
		null = false;
	}

	template <typename TYPE, uint64 SIZE>
	void stackpoly<TYPE, SIZE>::desc() noexcept {
		static_assert(std::is_destructible_v<TYPE>);
		reinterpret_cast<TYPE*>(data)->~TYPE();
		null = true;
	}

	template <typename TYPE, uint64 SIZE>
	stackpoly<TYPE, SIZE>::operator TYPE*() noexcept {
		return reinterpret_cast<TYPE*>(data);
	}

	template <typename TYPE, uint64 SIZE>
	stackpoly<TYPE, SIZE>::operator const TYPE*() const noexcept {
		return reinterpret_cast<const TYPE*>(data);
	}

	template <typename TYPE, uint64 SIZE>
	template <typename OTHERTYPE>
	stackpoly<TYPE, SIZE>::operator OTHERTYPE*() noexcept {
		static_assert(sizeof(OTHERTYPE) % sizeof(TYPE) == 0);
		return reinterpret_cast<OTHERTYPE*>(data);
	}

	template <typename TYPE, uint64 SIZE>
	template <typename OTHERTYPE>
	stackpoly<TYPE, SIZE>::operator const OTHERTYPE*() const noexcept {
		static_assert(sizeof(OTHERTYPE) % sizeof(TYPE) == 0);
		return reinterpret_cast<const OTHERTYPE*>(data);
	}

	template <typename TYPE, uint64 SIZE>
	TYPE& stackpoly<TYPE, SIZE>::operator*() noexcept {
		return *reinterpret_cast<TYPE*>(data);
	}

	template <typename TYPE, uint64 SIZE>
	const TYPE& stackpoly<TYPE, SIZE>::operator*() const noexcept {
		return *reinterpret_cast<const TYPE*>(data);
	}

	template <typename TYPE, uint64 SIZE>
	TYPE* stackpoly<TYPE, SIZE>::operator->() noexcept {
		return reinterpret_cast<TYPE*>(data);
	}

	template <typename TYPE, uint64 SIZE>
	const TYPE* stackpoly<TYPE, SIZE>::operator->() const noexcept {
		return reinterpret_cast<const TYPE*>(data);
	}

	template <typename TYPE, uint64 SIZE>
	bool operator==(const stackpoly<TYPE, SIZE>& stackPoly, std::nullptr_t) noexcept {
		return stackPoly.null;
	}

	template <typename TYPE, uint64 SIZE>
	bool operator!=(const stackpoly<TYPE, SIZE>& stackPoly, std::nullptr_t) noexcept {
		return !stackPoly.null;
	}
}
