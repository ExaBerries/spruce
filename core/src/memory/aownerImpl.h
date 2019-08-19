#pragma once

namespace spruce {
	template <typename TYPE>
	aowner<TYPE>::aowner(TYPE* ptr) : owner<TYPE>(ptr) {
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

	template <typename TYPE, typename ... CONSTYPES>
	aowner<TYPE> newaown(CONSTYPES&& ... args) {
		return new TYPE(args...);
	}

	template <typename TYPE>
	template <typename OTHERTYPE>
	aowner<TYPE>& aowner<TYPE>::operator=(aowner<OTHERTYPE>&& newOwner) noexcept {
		this->ptr = newOwner.ptr;
	}
}
