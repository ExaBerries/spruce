#pragma once
#include <types.h>
#include <memory/stackpoly.h>

namespace spruce {
	template <typename TYPE>
	struct alignas(alignof(TYPE)) stackown {
		uint8 data[sizeof(TYPE)];
		bool null = true;

		stackown() = default;
		stackown(const stackown&) = default;
		stackown(stackown&&) noexcept = default;
		~stackown();

		template <typename ... CONSTYPES>
		void cons(CONSTYPES&& ... args);
		void desc();

		[[nodiscard]] operator TYPE*();
		[[nodiscard]] operator const TYPE*() const;
		template <typename OTHERTYPE>
		[[nodiscard]] explicit operator OTHERTYPE*();
		template <typename OTHERTYPE>
		[[nodiscard]] explicit operator const OTHERTYPE*() const;

		TYPE& operator*() noexcept;
		const TYPE& operator*() const noexcept;
		TYPE* operator->() noexcept;
		const TYPE* operator->() const noexcept;

		[[nodiscard]] bool operator==(std::nullptr_t) const noexcept;
		[[nodiscard]] bool operator!=(std::nullptr_t) const noexcept;

		stackown& operator=(const stackown&) = default;
		stackown& operator=(stackown&&) noexcept = default;
	};
}

#include <memory/stackownImpl.h>
