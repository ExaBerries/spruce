#pragma once
#include <types.h>
#include <memory/owner.h>

namespace spruce {
	template <typename TYPE>
	struct aowner : public owner<TYPE> {
		aowner() = default;
		aowner(TYPE* ptr);
		aowner(const aowner &other) = default;
		aowner(aowner &&other) noexcept = default;
		~aowner();

		void free();

		aowner& operator=(const aowner &other) = default;
		aowner& operator=(aowner &&other) noexcept = default;
	};

	template <typename TYPE, typename ... CONSTYPES>
	aowner<TYPE> newaown(CONSTYPES&& ... args);
}

#include <memory/aownerImpl.h>
