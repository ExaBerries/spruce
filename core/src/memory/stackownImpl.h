#pragma once

namespace spruce {
	template <typename TYPE>
	stackown<TYPE>::~stackown() {
		desc();
	}

	template <typename TYPE>
	template <typename ... CONSTYPES>
	void stackown<TYPE>::cons(CONSTYPES&& ... args) {
		static_assert(std::is_constructible_v<TYPE, CONSTYPES...>);
		new (data) TYPE(args...);
		null = false;
	}

	template <typename TYPE>
	void stackown<TYPE>::desc() {
		static_assert(std::is_destructible_v<TYPE>);
		reinterpret_cast<TYPE*>(data)->~TYPE();
		null = true;
	}

	template <typename TYPE>
	stackown<TYPE>::operator TYPE*() {
		return reinterpret_cast<TYPE*>(data);
	}

	template <typename TYPE>
	stackown<TYPE>::operator const TYPE*() const {
		return reinterpret_cast<const TYPE*>(data);
	}

	template <typename TYPE>
	template <typename OTHERTYPE>
	stackown<TYPE>::operator OTHERTYPE*() {
		static_assert(sizeof(OTHERTYPE) % sizeof(TYPE) == 0);
		return reinterpret_cast<OTHERTYPE*>(data);
	}

	template <typename TYPE>
	template <typename OTHERTYPE>
	stackown<TYPE>::operator const OTHERTYPE*() const {
		static_assert(sizeof(OTHERTYPE) % sizeof(TYPE) == 0);
		return reinterpret_cast<const OTHERTYPE*>(data);
	}

	template <typename TYPE>
	TYPE& stackown<TYPE>::operator*() noexcept {
		return *reinterpret_cast<TYPE*>(data);
	}

	template <typename TYPE>
	const TYPE& stackown<TYPE>::operator*() const noexcept {
		return *reinterpret_cast<const TYPE*>(data);
	}

	template <typename TYPE>
	TYPE* stackown<TYPE>::operator->() noexcept {
		return reinterpret_cast<TYPE*>(data);
	}

	template <typename TYPE>
	const TYPE* stackown<TYPE>::operator->() const noexcept {
		return reinterpret_cast<const TYPE*>(data);
	}

	template <typename TYPE>
	bool stackown<TYPE>::operator==(std::nullptr_t) const noexcept {
		return null;
	}

	template <typename TYPE>
	bool stackown<TYPE>::operator!=(std::nullptr_t) const noexcept {
		return !null;
	}
}
