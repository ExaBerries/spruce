#pragma once

namespace spruce {
	template <typename TYPE>
	aowner<TYPE>::aowner(TYPE* ptr) : owner<TYPE>(ptr) {
	}

	template <typename TYPE>
	aowner<TYPE>::aowner(aowner<TYPE>&& other) noexcept : owner<TYPE>(other.ptr) {
		other.ptr = nullptr;
	}

	template <typename TYPE>
	aowner<TYPE>::~aowner() {
		free();
	}

	template <typename TYPE>
	void aowner<TYPE>::free() {
		delete this->ptr;
		this->ptr = nullptr;
	}

	template <typename TYPE>
	template <typename OTHERTYPE>
	aowner<TYPE>& aowner<TYPE>::operator=(aowner<OTHERTYPE>&& newOwner) noexcept {
		this->ptr = newOwner.ptr;
		newOwner.ptr = nullptr;
		return *this;
	}

	template <typename TYPE>
	aowner<TYPE>& aowner<TYPE>::operator=(aowner<TYPE>&& other) noexcept {
		this->ptr = other.ptr;
		other.ptr = nullptr;
		return *this;
	}

	template <typename TYPE, typename ... CONSTYPES>
	aowner<TYPE> newaown(CONSTYPES&& ... args) {
		return new TYPE(args...);
	}
}
