#pragma once

namespace spruce {
	template <typename TYPE>
	aowner<TYPE>::aowner(TYPE* ptr) : ptr(ptr) {
	}

	template <typename TYPE>
	aowner<TYPE>::aowner(aowner<TYPE>&& other) noexcept : ptr(ptr) {
		other.ptr = nullptr;
	}

	template <typename TYPE>
	aowner<TYPE>::~aowner() {
		free();
	}

	template <typename TYPE>
	void aowner<TYPE>::free() {
		static_assert(std::is_destructible_v<TYPE>);
		delete this->ptr;
		this->ptr = nullptr;
	}

	template <typename TYPE>
	aowner<TYPE>::operator TYPE*() {
		return ptr;
	}

	template <typename TYPE>
	aowner<TYPE>::operator const TYPE*() const {
		return ptr;
	}

	template <typename TYPE>
	template <typename OTHERTYPE>
	aowner<TYPE>::operator OTHERTYPE*() {
		static_assert(sizeof(OTHERTYPE) % sizeof(TYPE) == 0);
		return reinterpret_cast<OTHERTYPE*>(ptr);
	}

	template <typename TYPE>
	template <typename OTHERTYPE>
	aowner<TYPE>::operator const OTHERTYPE*() const {
		static_assert(sizeof(OTHERTYPE) % sizeof(TYPE) == 0);
		return reinterpret_cast<const OTHERTYPE*>(ptr);
	}

	template <typename TYPE>
	TYPE& aowner<TYPE>::operator*() noexcept {
		return *ptr;
	}

	template <typename TYPE>
	const TYPE& aowner<TYPE>::operator*() const noexcept {
		return *ptr;
	}

	template <typename TYPE>
	TYPE* aowner<TYPE>::operator->() noexcept {
		return ptr;
	}

	template <typename TYPE>
	const TYPE* aowner<TYPE>::operator->() const noexcept {
		return ptr;
	}

	template <typename TYPE>
	bool aowner<TYPE>::operator==(void* otherPtr) const noexcept {
		return ptr == otherPtr;
	}

	template <typename TYPE>
	bool aowner<TYPE>::operator!=(void* otherPtr) const noexcept {
		return ptr != otherPtr;
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
	[[nodiscard]] aowner<TYPE> newaown(CONSTYPES&& ... args) {
		static_assert(std::is_constructible_v<TYPE, CONSTYPES...>);
		return new TYPE(args...);
	}
}
