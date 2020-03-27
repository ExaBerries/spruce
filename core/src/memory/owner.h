#pragma once
#include <types.h>
#include <memory>

namespace spruce {
	template <typename TYPE, typename DELETER = std::default_delete<TYPE>>
	struct owner {
		using Type = TYPE;
		using DeleterType = DELETER;
		TYPE* ptr = nullptr;

		owner() noexcept = default;
		owner(TYPE* ptr) noexcept;
		owner(const owner& other) noexcept = default;
		owner(owner&& other) noexcept = default;
		~owner() noexcept = default;

		void free() noexcept;

		[[nodiscard]] operator TYPE*() noexcept;
		[[nodiscard]] operator const TYPE*() const noexcept;
		template <typename OTHERTYPE>
		[[nodiscard]] explicit operator OTHERTYPE*() noexcept;
		template <typename OTHERTYPE>
		[[nodiscard]] explicit operator const OTHERTYPE*() const noexcept;

		[[nodiscard]] TYPE& operator*() noexcept;
		[[nodiscard]] const TYPE& operator*() const noexcept;
		TYPE* operator->() noexcept;
		const TYPE* operator->() const noexcept;

		[[nodiscard]] bool operator==(void* otherPtr) const noexcept;
		[[nodiscard]] bool operator!=(void* otherPtr) const noexcept;

		template <typename OTHERTYPE, typename OTHERDELETER>
		owner& operator=(owner<OTHERTYPE, OTHERDELETER>&& newOwner) noexcept;

		owner& operator=(const owner& other) noexcept = default;
		owner& operator=(owner&& other) noexcept = default;
	};
}

#include <memory/ownerImpl.h>
