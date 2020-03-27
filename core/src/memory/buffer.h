#pragma once
#include <types.h>
#include <log.h>
#include <memory>

namespace spruce {
	template <typename TYPE, typename ALLOCATOR = std::allocator<TYPE>>
	struct buffer {
		using ElementType = TYPE;
		using AllocatorType = ALLOCATOR;
		uint64 size = 0;
		TYPE* data = nullptr;

		buffer() noexcept = default;
		buffer(uint64 size) noexcept;
		buffer(uint64 size, TYPE* data) noexcept;
		buffer(std::nullptr_t) noexcept;
		buffer(const buffer&) noexcept = default;
		buffer(buffer&&) noexcept = default;
		~buffer() = default;

		void realloc(uint64 newSize) noexcept;
		void free() noexcept;

		[[nodiscard]] constexpr TYPE* begin() noexcept;
		[[nodiscard]] constexpr const TYPE* begin() const noexcept;
		[[nodiscard]] constexpr TYPE* end() noexcept;
		[[nodiscard]] constexpr const TYPE* end() const noexcept;

		[[nodiscard]] TYPE& operator[](std::size_t idx) noexcept;
		[[nodiscard]] const TYPE& operator[](std::size_t idx) const noexcept;

		template <typename OTHERTYPE, typename OTHERALLOCATOR>
		[[nodiscard]] explicit operator buffer<OTHERTYPE, OTHERALLOCATOR>() noexcept;
		template <typename OTHERTYPE, typename OTHERALLOCATOR>
		[[nodiscard]] explicit operator buffer<OTHERTYPE, OTHERALLOCATOR>() const noexcept;
		[[nodiscard]] operator TYPE*() noexcept;
		[[nodiscard]] operator const TYPE*() const noexcept;
		template <typename OTHERTYPE>
		[[nodiscard]] explicit operator OTHERTYPE*() noexcept;
		template <typename OTHERTYPE>
		[[nodiscard]] explicit operator const OTHERTYPE*() noexcept;

		buffer& operator=(std::nullptr_t) noexcept;
		buffer& operator=(const buffer&) = default;
		buffer& operator=(buffer&&) noexcept = default;
	};

	template <typename TYPE, typename ALLOCATOR>
	[[nodiscard]] bool operator==(buffer<TYPE, ALLOCATOR>& buffer, const void* ptr) noexcept;

	template <typename TYPE, typename ALLOCATOR>
	[[nodiscard]] bool operator!=(buffer<TYPE, ALLOCATOR>& buffer, const void* ptr) noexcept;

	template <typename TYPE, typename ALLOCATOR>
	std::ostream& operator<<(std::ostream& stream, const buffer<TYPE, ALLOCATOR>& buffer) noexcept;
}

#include <memory/bufferImpl.h>
