#pragma once

namespace spruce {
	template <typename TYPE, typename DELETER>
	aowner<TYPE, DELETER>::aowner(TYPE* ptr) noexcept : owner<TYPE, DELETER>(ptr) {
	}

	template <typename TYPE, typename DELETER>
	aowner<TYPE, DELETER>::aowner(aowner<TYPE, DELETER>&& other) noexcept : owner<TYPE, DELETER>(other.ptr) {
		other.ptr = nullptr;
	}

	template <typename TYPE, typename DELETER>
	aowner<TYPE, DELETER>::~aowner() noexcept {
		owner<TYPE, DELETER>::free();
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
