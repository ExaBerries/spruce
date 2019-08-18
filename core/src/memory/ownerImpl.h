#pragma once

namespace spruce {
	template <typename TYPE>
	owner<TYPE>::owner(TYPE* ptr) : ptr(ptr) {
	}

	template <typename TYPE>
	owner<TYPE>::operator TYPE*() {
		return ptr;
	}

	template <typename TYPE>
	owner<TYPE>::operator const TYPE*() const {
		return ptr;
	}

	template <typename TYPE>
	template <typename OTHERTYPE>
	owner<TYPE>::operator OTHERTYPE*() {
		return (OTHERTYPE*) ptr;
	}

	template <typename TYPE>
	template <typename OTHERTYPE>
	owner<TYPE>::operator const OTHERTYPE*() const {
		return (const OTHERTYPE*) ptr;
	}

	template <typename TYPE>
	TYPE& owner<TYPE>::operator*() noexcept {
		return *ptr;
	}

	template <typename TYPE>
	const TYPE& owner<TYPE>::operator*() const noexcept {
		return *ptr;
	}

	template <typename TYPE>
	TYPE* owner<TYPE>::operator->() noexcept {
		return ptr;
	}

	template <typename TYPE>
	const TYPE* owner<TYPE>::operator->() const noexcept {
		return ptr;
	}

	template <typename TYPE>
	bool owner<TYPE>::operator==(void* otherPtr) {
		return ptr == otherPtr;
	}

	template <typename TYPE>
	bool owner<TYPE>::operator!=(void* otherPtr) {
		return ptr != otherPtr;
	}

	template <typename TYPE>
	owner<TYPE>& owner<TYPE>::operator=(TYPE* newPtr) {
		this->ptr = newPtr;
		return *this;
	}
}
