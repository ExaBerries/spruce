#pragma once
#include <common.h>
#include <functional>
#include <utility>

namespace spruce {
	namespace util {
		template <class FUNCTION, class TUPLE, std::size_t... INDEXES>
		constexpr decltype(auto) execute_impl(FUNCTION&& function, TUPLE&& args, std::index_sequence<INDEXES...>) {
			return function(std::get<INDEXES>(std::forward<TUPLE>(args))...);
		}

		template <class FUNCTION, class TUPLE>
		constexpr decltype(auto) execute(FUNCTION&& function, TUPLE&& args) {
			return util::execute_impl(std::forward<FUNCTION>(function), std::forward<TUPLE>(args), std::make_index_sequence<std::tuple_size<std::remove_reference_t<TUPLE>>::value>{});
		}
	}
}
