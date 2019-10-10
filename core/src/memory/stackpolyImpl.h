#pragma once

namespace spruce {
	template <typename TYPE, uint64 SIZE>
	stackpoly<TYPE, SIZE>::~stackpoly() {
		desc();
	}

	template <typename TYPE, uint64 SIZE>
	template <typename POLYTYPE, typename ... CONSTYPES>
	void stackpoly<TYPE, SIZE>::cons(CONSTYPES&& ... args) {
		new (data) POLYTYPE(args...);
	}

	template <typename TYPE, uint64 SIZE>
	void stackpoly<TYPE, SIZE>::desc() {
		static_cast<TYPE*>(data)->~TYPE();
	}

	template <typename TYPE, uint64 SIZE>
	stackpoly<TYPE, SIZE>::operator TYPE*() {
		return static_cast<TYPE*>(data);
	}

	template <typename TYPE, uint64 SIZE>
	stackpoly<TYPE, SIZE>::operator const TYPE*() const {
		return static_cast<const TYPE*>(data);
	}

	template <typename TYPE, uint64 SIZE>
	template <typename OTHERTYPE>
	stackpoly<TYPE, SIZE>::operator OTHERTYPE*() {
		return static_cast<OTHERTYPE*>(data);
	}

	template <typename TYPE, uint64 SIZE>
	template <typename OTHERTYPE>
	stackpoly<TYPE, SIZE>::operator const OTHERTYPE*() const {
		return static_cast<const OTHERTYPE*>(data);
	}

	template <typename TYPE, uint64 SIZE>
	TYPE& stackpoly<TYPE, SIZE>::operator*() noexcept {
		return *static_cast<TYPE*>(data);
	}

	template <typename TYPE, uint64 SIZE>
	const TYPE& stackpoly<TYPE, SIZE>::operator*() const noexcept {
		return *static_cast<const TYPE*>(data);
	}

	template <typename TYPE, uint64 SIZE>
	TYPE* stackpoly<TYPE, SIZE>::operator->() noexcept {
		return static_cast<TYPE*>(data);
	}

	template <typename TYPE, uint64 SIZE>
	const TYPE* stackpoly<TYPE, SIZE>::operator->() const noexcept {
		return static_cast<const TYPE*>(data);
	}

	template <typename TYPE, uint64 SIZE>
	bool stackpoly<TYPE, SIZE>::operator==(std::nullptr_t) {
		return null;
	}

	template <typename TYPE, uint64 SIZE>
	bool stackpoly<TYPE, SIZE>::operator!=(std::nullptr_t) {
		return !null;
	}
}
