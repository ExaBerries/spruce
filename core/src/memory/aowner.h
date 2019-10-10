#pragma once
#include <types.h>
#include <memory/owner.h>

namespace spruce {
	template <typename TYPE>
	struct aowner {
		TYPE* ptr = nullptr;

		aowner() = default;
		aowner(TYPE* ptr);
		aowner(const aowner& other) = delete;
		aowner(aowner&& other) noexcept;
		~aowner();

		void free();

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

		template <typename OTHERTYPE>
		aowner& operator=(aowner<OTHERTYPE>&& newOwner) noexcept;

		aowner& operator=(const aowner& other) = delete;
		aowner& operator=(aowner&& other) noexcept;
	};

	template <typename TYPE, typename ... CONSTYPES>
	aowner<TYPE> newaown(CONSTYPES&& ... args);
}

#include <memory/aownerImpl.h>
