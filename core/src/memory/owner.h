#pragma once
#include <types.h>

namespace spruce {
	template <typename TYPE>
	struct owner {
		TYPE* ptr = nullptr;

		owner() = default;
		owner(TYPE* ptr);
		owner(const owner&) = default;
		owner(owner&&) noexcept = default;
		virtual ~owner() = default;

		operator TYPE*();
		operator const TYPE*() const;
		template <typename OTHERTYPE>
		explicit operator OTHERTYPE*();
		template <typename OTHERTYPE>
		explicit operator const OTHERTYPE*() const;

		TYPE& operator*() noexcept;
		const TYPE& operator*() const noexcept;
		TYPE* operator->() noexcept;
		const TYPE* operator->() const noexcept;

		bool operator==(void* otherPtr);
		bool operator!=(void* otherPtr);

		owner& operator=(TYPE* newPtr);

		owner& operator=(const owner&) = default;
		owner& operator=(owner&&) noexcept = default;
	};
}

#include <memory/ownerImpl.h>
