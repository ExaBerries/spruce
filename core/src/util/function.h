#pragma once
#include <common.h>
#include <functional>
#include <utility>

namespace spruce {
	namespace util {
		template <typename FUNCTION, typename TUPLE, std::size_t... INDEXES>
		constexpr auto execute_impl(const FUNCTION& function, TUPLE&& args, std::index_sequence<INDEXES...> /*unused*/) {
			return function(std::get<INDEXES>(std::forward<TUPLE>(args))...);
		}

		template <typename FUNCTION, typename TUPLE>
		constexpr auto execute(const FUNCTION& function, TUPLE&& args) {
			return util::execute_impl(function, std::forward<TUPLE>(args), std::make_index_sequence<std::tuple_size<std::remove_reference_t<TUPLE>>::value>{});
		}
	}
}
