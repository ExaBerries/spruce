#pragma once
#include <types.h>
#include <memory/stackpoly.h>

namespace spruce {
	template <typename TYPE>
	struct alignas(alignof(TYPE)) stackown {
		using Type = TYPE;
		uint8 data[sizeof(TYPE)];
		bool null = true;

		stackown() noexcept = default;
		stackown(const stackown&) noexcept = default;
		stackown(stackown&&) noexcept = default;
		~stackown() noexcept;

		template <typename ... CONSTYPES>
		void cons(CONSTYPES&& ... args) noexcept;
		void desc() noexcept;

		[[nodiscard]] operator TYPE*() noexcept;
		[[nodiscard]] operator const TYPE*() const noexcept;
		template <typename OTHERTYPE>
		[[nodiscard]] explicit operator OTHERTYPE*() noexcept;
		template <typename OTHERTYPE>
		[[nodiscard]] explicit operator const OTHERTYPE*() const noexcept;

		TYPE& operator*() noexcept;
		const TYPE& operator*() const noexcept;
		TYPE* operator->() noexcept;
		const TYPE* operator->() const noexcept;

		[[nodiscard]] bool operator==(std::nullptr_t) const noexcept;
		[[nodiscard]] bool operator!=(std::nullptr_t) const noexcept;

		stackown& operator=(const stackown&) noexcept = default;
		stackown& operator=(stackown&&) noexcept = default;
	};
}

#include <memory/stackownImpl.h>
