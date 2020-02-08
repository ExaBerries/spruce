#pragma once

namespace spruce {
	template <typename TYPE, typename ALLOCATOR>
	buffer<TYPE, ALLOCATOR>::buffer(uint64 size) noexcept {
		static_assert(std::is_default_constructible_v<TYPE>);
		#ifdef DEBUG
		if (size == 0) {
			serr("buffer size must be greater than 0");
			return;
		}
		#endif
		this->size = size;
		this->data = ALLOCATOR().allocate(size);
		std::uninitialized_default_construct_n(this->data, size);
	}

	template <typename TYPE, typename ALLOCATOR>
	buffer<TYPE, ALLOCATOR>::buffer(std::nullptr_t) noexcept {
		size = 0;
		data = nullptr;
	}

	template <typename TYPE, typename ALLOCATOR>
	buffer<TYPE, ALLOCATOR>::buffer(uint64 size, TYPE* data) noexcept {
		this->size = size;
		this->data = data;
	}

	template <typename TYPE, typename ALLOCATOR>
	void buffer<TYPE, ALLOCATOR>::realloc(uint64 newSize) noexcept {
		#ifdef DEBUG
		if (size == 0) {
			serr("buffer size must be greater than 0");
			return;
		}
		#endif
		free();
		this->size = newSize;
		this->data = ALLOCATOR().allocate(size);
		std::uninitialized_default_construct_n(this->data, size);
	}

	template <typename TYPE, typename ALLOCATOR>
	void buffer<TYPE, ALLOCATOR>::free() noexcept {
		static_assert(std::is_destructible_v<TYPE>);
		if (data == nullptr) {
			return;
		}
		for (uint64 i = 0; i < size; i++) {
			(static_cast<TYPE*>(data) + i)->~TYPE();
		}
		ALLOCATOR().deallocate(data, size);
		data = nullptr;
	}

	template <typename TYPE, typename ALLOCATOR>
	constexpr TYPE* buffer<TYPE, ALLOCATOR>::begin() noexcept {
		return data;
	}

	template <typename TYPE, typename ALLOCATOR>
	constexpr const TYPE* buffer<TYPE, ALLOCATOR>::begin() const noexcept {
		return data;
	}

	template <typename TYPE, typename ALLOCATOR>
	constexpr TYPE* buffer<TYPE, ALLOCATOR>::end() noexcept {
		return data + size;
	}

	template <typename TYPE, typename ALLOCATOR>
	constexpr const TYPE* buffer<TYPE, ALLOCATOR>::end() const noexcept {
		return data + size;
	}

	template <typename TYPE, typename ALLOCATOR>
	TYPE& buffer<TYPE, ALLOCATOR>::operator[](std::size_t idx) noexcept {
		#ifdef DEBUG
		#ifdef BUFFER_BOUNDS_CHECK
		if (idx >= size) {
			slog("buffer[] bounds check fail index=", idx, " size=", size);
		}
		#endif
		#endif
		return data[idx];
	}

	template <typename TYPE, typename ALLOCATOR>
	const TYPE& buffer<TYPE, ALLOCATOR>::operator[](std::size_t idx) const noexcept {
		#ifdef DEBUG
		#ifdef BUFFER_BOUNDS_CHECK
		if (idx >= size) {
			slog("buffer[] bounds check fail index=", idx, " size=", size);
		}
		#endif
		#endif
		return data[idx];
	}

	template <typename TYPE, typename ALLOCATOR>
	template <typename OTHERTYPE, typename OTHERALLOCATOR>
	buffer<TYPE, ALLOCATOR>::operator buffer<OTHERTYPE, OTHERALLOCATOR>() noexcept {
		static_assert(sizeof(OTHERTYPE) % sizeof(TYPE) == 0);
		buffer<OTHERTYPE> buff(size * sizeof(TYPE) / sizeof(OTHERTYPE), reinterpret_cast<OTHERTYPE*>(data));
		return buff;
	}


	template <typename TYPE, typename ALLOCATOR>
	template <typename OTHERTYPE, typename OTHERALLOCATOR>
	buffer<TYPE, ALLOCATOR>::operator buffer<OTHERTYPE, OTHERALLOCATOR>() const noexcept {
		static_assert(sizeof(OTHERTYPE) % sizeof(TYPE) == 0);
		const buffer<OTHERTYPE> buff(size * sizeof(TYPE) / sizeof(OTHERTYPE), reinterpret_cast<OTHERTYPE*>(data));
		return buff;
	}

	template <typename TYPE, typename ALLOCATOR>
	buffer<TYPE, ALLOCATOR>::operator TYPE*() noexcept {
		return data;
	}

	template <typename TYPE, typename ALLOCATOR>
	buffer<TYPE, ALLOCATOR>::operator const TYPE*() const noexcept {
		return data;
	}

	template <typename TYPE, typename ALLOCATOR>
	template <typename OTHERTYPE>
	buffer<TYPE, ALLOCATOR>::operator OTHERTYPE*() noexcept {
		static_assert(sizeof(OTHERTYPE) % sizeof(TYPE) == 0);
		return static_cast<OTHERTYPE*>(data);
	}

	template <typename TYPE, typename ALLOCATOR>
	template <typename OTHERTYPE>
	buffer<TYPE, ALLOCATOR>::operator const OTHERTYPE*() noexcept {
		static_assert(sizeof(OTHERTYPE) % sizeof(TYPE) == 0);
		return static_cast<const OTHERTYPE*>(data);
	}

	template <typename TYPE, typename ALLOCATOR>
	buffer<TYPE, ALLOCATOR>& buffer<TYPE, ALLOCATOR>::operator=(std::nullptr_t) noexcept {
		size = 0;
		data = nullptr;
		return *this;
	}

	template <typename TYPE, typename ALLOCATOR>
	bool operator==(buffer<TYPE, ALLOCATOR>& buffer, const void* ptr) noexcept {
		return buffer.data == ptr;
	}

	template <typename TYPE, typename ALLOCATOR>
	bool operator!=(buffer<TYPE, ALLOCATOR>& buffer, const void* ptr) noexcept {
		return buffer.data != ptr;
	}

	template <typename TYPE, typename ALLOCATOR>
	std::ostream& operator<<(std::ostream& stream, const buffer<TYPE, ALLOCATOR>& buffer) noexcept {
		stream << "buffer(" << buffer.size << ", " << reinterpret_cast<void*>(buffer.data) << ")";
		return stream;
	}
}
