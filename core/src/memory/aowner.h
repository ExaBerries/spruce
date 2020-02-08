#pragma once
#include <types.h>
#include <memory/owner.h>

namespace spruce {
	template <typename TYPE, typename DELETER = std::default_delete<TYPE>>
	struct aowner : public owner<TYPE, DELETER> {
		aowner() noexcept = default;
		explicit aowner(TYPE* ptr) noexcept;
		aowner(const aowner& other) noexcept = delete;
		aowner(aowner&& other) noexcept;
		~aowner() noexcept;

		template <typename OTHERTYPE, typename OTHERDELETER>
		aowner& operator=(aowner<OTHERTYPE, OTHERDELETER>&& newOwner) noexcept;

		aowner& operator=(const aowner& other) noexcept = delete;
		aowner& operator=(aowner&& other) noexcept;
	};

	template <typename TYPE, typename ... CONSTYPES>
	[[nodiscard]] aowner<TYPE> newaown(CONSTYPES&& ... args) noexcept;
}

#include <memory/aownerImpl.h>
