#pragma once
#include <types.h>
#include <memory/stackpoly.h>

namespace spruce {
	template <typename TYPE>
	struct stackown {
		uint8 data[sizeof(TYPE)];
		bool null = true;

		stackown() = default;
		stackown(const stackown&) = default;
		stackown(stackown&&) noexcept = default;
		~stackown();

		template <typename ... CONSTYPES>
		void cons(CONSTYPES&& ... args);
		void desc();

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

		bool operator==(std::nullptr_t);
		bool operator!=(std::nullptr_t);

		stackown& operator=(const stackown&) = default;
		stackown& operator=(stackown&&) noexcept = default;
	};
}

#include <memory/stackownImpl.h>
