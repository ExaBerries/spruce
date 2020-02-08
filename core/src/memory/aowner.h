#pragma once
#include <types.h>
#include <memory/owner.h>

namespace spruce {
	template <typename TYPE, typename DELETER = std::default_delete<TYPE>>
	struct aowner {
		using Type = TYPE;
		using DeleterType = DELETER;
		TYPE* ptr = nullptr;

		aowner() noexcept = default;
		explicit aowner(TYPE* ptr) noexcept;
		aowner(const aowner& other) noexcept = delete;
		aowner(aowner&& other) noexcept;
		~aowner() noexcept;

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
		aowner& operator=(aowner<OTHERTYPE, OTHERDELETER>&& newOwner) noexcept;

		aowner& operator=(const aowner& other) noexcept = delete;
		aowner& operator=(aowner&& other) noexcept;
	};

	template <typename TYPE, typename ... CONSTYPES>
	[[nodiscard]] aowner<TYPE> newaown(CONSTYPES&& ... args) noexcept;
}

#include <memory/aownerImpl.h>
