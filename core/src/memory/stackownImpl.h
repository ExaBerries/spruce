#pragma once

namespace spruce {
	template <typename TYPE>
	stackown<TYPE>::~stackown() {
		desc();
	}

	template <typename TYPE>
	template <typename ... CONSTYPES>
	void stackown<TYPE>::cons(CONSTYPES& ... args) {
		new (data) TYPE(args...);
		null = false;
	}

	template <typename TYPE>
	void stackown<TYPE>::desc() {
		((TYPE*)data)->~TYPE();
		null = true;
	}

	template <typename TYPE>
	stackown<TYPE>::operator TYPE*() {
		return (TYPE*) data;
	}

	template <typename TYPE>
	stackown<TYPE>::operator const TYPE*() const {
		return (const TYPE*) data;
	}

	template <typename TYPE>
	template <typename OTHERTYPE>
	stackown<TYPE>::operator OTHERTYPE*() {
		return (OTHERTYPE*) data;
	}

	template <typename TYPE>
	template <typename OTHERTYPE>
	stackown<TYPE>::operator const OTHERTYPE*() const {
		return (const OTHERTYPE*) data;
	}

	template <typename TYPE>
	TYPE& stackown<TYPE>::operator*() noexcept {
		return *((TYPE*)data);
	}

	template <typename TYPE>
	const TYPE& stackown<TYPE>::operator*() const noexcept {
		return *((const TYPE*)data);
	}

	template <typename TYPE>
	TYPE* stackown<TYPE>::operator->() noexcept {
		return (TYPE*) data;
	}

	template <typename TYPE>
	const TYPE* stackown<TYPE>::operator->() const noexcept {
		return (const TYPE*) data;
	}

	template <typename TYPE>
	bool stackown<TYPE>::operator==(std::nullptr_t) {
		return null;
	}

	template <typename TYPE>
	bool stackown<TYPE>::operator!=(std::nullptr_t) {
		return !null;
	}
}
