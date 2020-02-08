#pragma once

namespace spruce {
	template <typename TYPE, typename DELETER>
	aowner<TYPE, DELETER>::aowner(TYPE* ptr) noexcept : ptr(ptr) {
	}

	template <typename TYPE, typename DELETER>
	aowner<TYPE, DELETER>::aowner(aowner<TYPE, DELETER>&& other) noexcept : ptr(ptr) {
		other.ptr = nullptr;
	}

	template <typename TYPE, typename DELETER>
	aowner<TYPE, DELETER>::~aowner() noexcept {
		free();
	}

	template <typename TYPE, typename DELETER>
	void aowner<TYPE, DELETER>::free() noexcept {
		static_assert(std::is_destructible_v<TYPE>);
		DELETER()(ptr);
		this->ptr = nullptr;
	}

	template <typename TYPE, typename DELETER>
	aowner<TYPE, DELETER>::operator TYPE*() noexcept {
		return ptr;
	}

	template <typename TYPE, typename DELETER>
	aowner<TYPE, DELETER>::operator const TYPE*() const noexcept {
		return ptr;
	}

	template <typename TYPE, typename DELETER>
	template <typename OTHERTYPE>
	aowner<TYPE, DELETER>::operator OTHERTYPE*() noexcept {
		static_assert(sizeof(OTHERTYPE) % sizeof(TYPE) == 0);
		return reinterpret_cast<OTHERTYPE*>(ptr);
	}

	template <typename TYPE, typename DELETER>
	template <typename OTHERTYPE>
	aowner<TYPE, DELETER>::operator const OTHERTYPE*() const noexcept {
		static_assert(sizeof(OTHERTYPE) % sizeof(TYPE) == 0);
		return reinterpret_cast<const OTHERTYPE*>(ptr);
	}

	template <typename TYPE, typename DELETER>
	TYPE& aowner<TYPE, DELETER>::operator*() noexcept {
		return *ptr;
	}

	template <typename TYPE, typename DELETER>
	const TYPE& aowner<TYPE, DELETER>::operator*() const noexcept {
		return *ptr;
	}

	template <typename TYPE, typename DELETER>
	TYPE* aowner<TYPE, DELETER>::operator->() noexcept {
		return ptr;
	}

	template <typename TYPE, typename DELETER>
	const TYPE* aowner<TYPE, DELETER>::operator->() const noexcept {
		return ptr;
	}

	template <typename TYPE, typename DELETER>
	bool aowner<TYPE, DELETER>::operator==(void* otherPtr) const noexcept {
		return ptr == otherPtr;
	}

	template <typename TYPE, typename DELETER>
	bool aowner<TYPE, DELETER>::operator!=(void* otherPtr) const noexcept {
		return ptr != otherPtr;
	}

	template <typename TYPE, typename DELETER>
	template <typename OTHERTYPE, typename OTHERDELETER>
	aowner<TYPE, DELETER>& aowner<TYPE, DELETER>::operator=(aowner<OTHERTYPE, OTHERDELETER>&& newOwner) noexcept {
		static_assert(std::is_base_of_v<TYPE, OTHERTYPE>);
		this->ptr = newOwner.ptr;
		newOwner.ptr = nullptr;
		return *this;
	}

	template <typename TYPE, typename DELETER>
	aowner<TYPE, DELETER>& aowner<TYPE, DELETER>::operator=(aowner<TYPE, DELETER>&& other) noexcept {
		this->ptr = other.ptr;
		other.ptr = nullptr;
		return *this;
	}

	template <typename TYPE, typename ... CONSTYPES>
	[[nodiscard]] aowner<TYPE> newaown(CONSTYPES&& ... args) noexcept {
		static_assert(std::is_constructible_v<TYPE, CONSTYPES...>);
		return aowner{new TYPE(args...)};
	}
}
