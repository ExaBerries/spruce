#pragma once
#include <types.h>
#include <log.h>

namespace spruce {
	template <typename TYPE>
	struct buffer {
		uint64 size = 0;
		TYPE* data = nullptr;

		buffer() noexcept = default;
		buffer(uint64 size) noexcept;
		buffer(uint64 size, TYPE* data) noexcept;
		buffer(std::nullptr_t) noexcept;
		buffer(const buffer<TYPE>&) = default;
		buffer(buffer<TYPE>&&) noexcept = default;
		~buffer() = default;

		void realloc(uint64 newSize);
		void free();

		TYPE* begin();
		const TYPE* begin() const;
		TYPE* end();
		const TYPE* end() const;

		TYPE& operator[](std::size_t idx);
		const TYPE& operator[](std::size_t idx) const;

		template <typename OTHERTYPE>
		explicit operator buffer<OTHERTYPE>();
		template <typename OTHERTYPE>
		explicit operator const buffer<OTHERTYPE>() const;
		operator TYPE*();
		operator const TYPE*() const;
		template <typename OTHERTYPE>
		explicit operator OTHERTYPE*();
		template <typename OTHERTYPE>
		explicit operator const OTHERTYPE*();

		buffer<TYPE>& operator=(std::nullptr_t);
		buffer<TYPE>& operator=(const buffer<TYPE>&) = default;
		buffer<TYPE>& operator=(buffer<TYPE>&&) = default;
	};

	template <typename TYPE>
	bool operator==(buffer<TYPE>& buffer, const void* ptr);

	template <typename TYPE>
	bool operator!=(buffer<TYPE>& buffer, const void* ptr);

	template <typename TYPE>
	std::ostream& operator<<(std::ostream& stream, const buffer<TYPE> buffer);
}

#include <memory/bufferImpl.h>
