#pragma once

namespace spruce {
	template <typename TYPE, typename DELETER>
	owner<TYPE, DELETER>::owner(TYPE* ptr) noexcept : ptr(ptr) {
	}

	template <typename TYPE, typename DELETER>
	void owner<TYPE, DELETER>::free() noexcept {
		static_assert(std::is_destructible_v<TYPE>);
		DELETER()(ptr);
		this->ptr = nullptr;
	}

	template <typename TYPE, typename DELETER>
	owner<TYPE, DELETER>::operator TYPE*() noexcept {
		return ptr;
	}

	template <typename TYPE, typename DELETER>
	owner<TYPE, DELETER>::operator const TYPE*() const noexcept {
		return ptr;
	}

	template <typename TYPE, typename DELETER>
	template <typename OTHERTYPE>
	owner<TYPE, DELETER>::operator OTHERTYPE*() noexcept {
		static_assert(sizeof(OTHERTYPE) % sizeof(TYPE) == 0);
		return reinterpret_cast<OTHERTYPE*>(ptr);
	}

	template <typename TYPE, typename DELETER>
	template <typename OTHERTYPE>
	owner<TYPE, DELETER>::operator const OTHERTYPE*() const noexcept {
		static_assert(sizeof(OTHERTYPE) % sizeof(TYPE) == 0);
		return reinterpret_cast<const OTHERTYPE*>(ptr);
	}

	template <typename TYPE, typename DELETER>
	TYPE& owner<TYPE, DELETER>::operator*() noexcept {
		return *ptr;
	}

	template <typename TYPE, typename DELETER>
	const TYPE& owner<TYPE, DELETER>::operator*() const noexcept {
		return *ptr;
	}

	template <typename TYPE, typename DELETER>
	TYPE* owner<TYPE, DELETER>::operator->() noexcept {
		return ptr;
	}

	template <typename TYPE, typename DELETER>
	const TYPE* owner<TYPE, DELETER>::operator->() const noexcept {
		return ptr;
	}

	template <typename TYPE, typename DELETER>
	bool owner<TYPE, DELETER>::operator==(void* otherPtr) const noexcept {
		return ptr == otherPtr;
	}

	template <typename TYPE, typename DELETER>
	bool owner<TYPE, DELETER>::operator!=(void* otherPtr) const noexcept {
		return ptr != otherPtr;
	}

	template <typename TYPE, typename DELETER>
	template <typename OTHERTYPE, typename OTHERDELETER>
	owner<TYPE, DELETER>& owner<TYPE, DELETER>::operator=(owner<OTHERTYPE, OTHERDELETER>&& newOwner) noexcept {
		static_assert(std::is_base_of_v<TYPE, OTHERTYPE>);
		this->ptr = newOwner.ptr;
		return *this;
	}
}
