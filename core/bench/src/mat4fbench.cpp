#include <benchmark/benchmark.h>
#include <math/mat/mat4f.h>

using namespace spruce;

static void mat4fConstruct(benchmark::State& state) {
	for (auto _ : state) {
		mat4f m;
	}
}
BENCHMARK(mat4fConstruct);

static void mat4fConstructArr(benchmark::State& state) {
	const float values[16] = {
		0, 1, 1, 1,
		1, 0, 1, 1,
		1, 1, 0, 1,
		1, 1, 1, 0
	};
	for (auto _ : state) {
		mat4f m(values);
	}
}
BENCHMARK(mat4fConstructArr);
