#pragma once
#include <types.h>
#include <log.h>
#include <backend/memory/memorymanager.h>

namespace spruce {
	template <typename TYPE>
	struct buffer {
		uint64 size;
		TYPE* data;

		buffer(uint64 size) {
			this->size = size;
			this->data = (TYPE*) mem::allocBuffer(size * sizeof(TYPE));
			new (data) TYPE[size];
		}

		buffer(uint64 size, TYPE* data) {
			this->size = size;
			this->data = data;
		}

		buffer(std::nullptr_t) {
			size = 0;
			data = nullptr;
		}

		buffer(const buffer<TYPE>& buffer) {
			this->size = buffer.size;
			this->data = buffer.data;
		}

		~buffer() {
		}

		void realloc(uint64 newSize) {
			this->~buffer();
			this->size = newSize;
			this->data = (TYPE*) mem::allocBuffer(newSize * sizeof(TYPE));
		}

		void free() {
			if (data == nullptr) {
				return;
			}
			for (uint64 i = 0; i < size; i++) {
				(((TYPE*)data) + i)->~TYPE();
			}
			mem::freeBuffer(size, (void*) data);
			data = nullptr;
		}

		TYPE& operator[](std::size_t idx) {
			#ifdef DEBUG
			#ifdef BUFFER_BOUNDS_CHECK
			if (idx >= size) {
				slog("buffer[] bounds check fail index=", idx, " size=", size);
			}
			#endif
			#endif
			return data[idx];
		}

		bool operator==(const void* ptr) const {
			return data == ptr;
		}

		bool operator!=(const void* ptr) const {
			return data != ptr;
		}

		template <typename OTHERTYPE>
		explicit operator buffer<OTHERTYPE>() const {
			buffer<OTHERTYPE> buff(size * sizeof(TYPE) / sizeof(OTHERTYPE), (OTHERTYPE*) data);
			return buff;
		}

		operator TYPE*() {
			return data;
		}

		buffer<TYPE>& operator=(std::nullptr_t) {
			size = 0;
			data = nullptr;
			return *this;
		}

		TYPE* begin() {
			return data;
		}

		const TYPE* begin() const {
			return data;
		}

		TYPE* end() {
			return data + size;
		}

		const TYPE* end() const {
			return data + size;
		}
	};

	template <typename TYPE>
	std::ostream& operator<<(std::ostream& stream, const buffer<TYPE> buffer) {
		stream << "buffer(" << buffer.size << ", " << (void*)buffer.data << ")";
		return stream;
	}
}
