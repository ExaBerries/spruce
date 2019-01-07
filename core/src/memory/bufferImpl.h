#pragma once

namespace spruce {
	template <typename TYPE>
	buffer<TYPE>::buffer(uint64 size) noexcept {
		#ifdef DEBUG
		if (size == 0) {
			serr("buffer size must be greater than 0");
			return;
		}
		#endif
		this->size = size;
		this->data = (TYPE*) std::malloc(size * sizeof(TYPE));
		new (data) TYPE[size];
	}

	template <typename TYPE>
	buffer<TYPE>::buffer(std::nullptr_t) noexcept {
		size = 0;
		data = nullptr;
	}

	template <typename TYPE>
	buffer<TYPE>::buffer(uint64 size, TYPE* data) noexcept {
		this->size = size;
		this->data = data;
	}

	template <typename TYPE>
	void buffer<TYPE>::realloc(uint64 newSize) {
		#ifdef DEBUG
		if (size == 0) {
			serr("buffer size must be greater than 0");
			return;
		}
		#endif
		free();
		this->size = newSize;
		this->data = (TYPE*) std::malloc(newSize * sizeof(TYPE));
	}

	template <typename TYPE>
	void buffer<TYPE>::free() {
		if (data == nullptr) {
			return;
		}
		for (uint64 i = 0; i < size; i++) {
			(((TYPE*)data) + i)->~TYPE();
		}
		std::free(data);
		data = nullptr;
	}

	template <typename TYPE>
	TYPE* buffer<TYPE>::begin() {
		return data;
	}

	template <typename TYPE>
	const TYPE* buffer<TYPE>::begin() const {
		return data;
	}

	template <typename TYPE>
	TYPE* buffer<TYPE>::end() {
		return data + size;
	}

	template <typename TYPE>
	const TYPE* buffer<TYPE>::end() const {
		return data + size;
	}

	template <typename TYPE>
	TYPE& buffer<TYPE>::operator[](std::size_t idx) {
		#ifdef DEBUG
		#ifdef BUFFER_BOUNDS_CHECK
		if (idx >= size) {
			slog("buffer[] bounds check fail index=", idx, " size=", size);
		}
		#endif
		#endif
		return data[idx];
	}

	template <typename TYPE>
	const TYPE& buffer<TYPE>::operator[](std::size_t idx) const {
		#ifdef DEBUG
		#ifdef BUFFER_BOUNDS_CHECK
		if (idx >= size) {
			slog("buffer[] bounds check fail index=", idx, " size=", size);
		}
		#endif
		#endif
		return data[idx];
	}

	template <typename TYPE>
	template <typename OTHERTYPE>
	buffer<TYPE>::operator buffer<OTHERTYPE>() {
		buffer<OTHERTYPE> buff(size * sizeof(TYPE) / sizeof(OTHERTYPE), (OTHERTYPE*) data);
		return buff;
	}


	template <typename TYPE>
	template <typename OTHERTYPE>
	buffer<TYPE>::operator const buffer<OTHERTYPE>() const {
		const buffer<OTHERTYPE> buff(size * sizeof(TYPE) / sizeof(OTHERTYPE), (OTHERTYPE*) data);
		return buff;
	}

	template <typename TYPE>
	buffer<TYPE>::operator TYPE*() {
		return data;
	}

	template <typename TYPE>
	buffer<TYPE>::operator const TYPE*() const {
		return data;
	}

	template <typename TYPE>
	template <typename OTHERTYPE>
	buffer<TYPE>::operator OTHERTYPE*() {
		return (OTHERTYPE*) data;
	}

	template <typename TYPE>
	template <typename OTHERTYPE>
	buffer<TYPE>::operator const OTHERTYPE*() {
		return (const OTHERTYPE*) data;
	}

	template <typename TYPE>
	buffer<TYPE>& buffer<TYPE>::operator=(std::nullptr_t) {
		size = 0;
		data = nullptr;
		return *this;
	}

	template <typename TYPE>
	bool operator==(buffer<TYPE>& buffer, const void* ptr) {
		return buffer.data == ptr;
	}

	template <typename TYPE>
	bool operator!=(buffer<TYPE>& buffer, const void* ptr) {
		return buffer.data != ptr;
	}

	template <typename TYPE>
	std::ostream& operator<<(std::ostream& stream, const buffer<TYPE> buffer) {
		stream << "buffer(" << buffer.size << ", " << (void*)buffer.data << ")";
		return stream;
	}
}
