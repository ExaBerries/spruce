#pragma once
#include <types.h>
#include <memory/owner.h>

namespace spruce {
	template <typename TYPE>
	struct aowner : public owner<TYPE> {
		aowner() = default;
		aowner(TYPE* ptr);
		aowner(const aowner& other) = delete;
		aowner(aowner&& other) noexcept;
		~aowner();

		void free();

		template <typename OTHERTYPE>
		aowner& operator=(aowner<OTHERTYPE>&& newOwner) noexcept;

		aowner& operator=(const aowner& other) = delete;
		aowner& operator=(aowner&& other) noexcept;
	};

	template <typename TYPE, typename ... CONSTYPES>
	aowner<TYPE> newaown(CONSTYPES&& ... args);
}

#include <memory/aownerImpl.h>
