#include <benchmark/benchmark.h>
#include <math/vec/vec3f.h>

using namespace spruce;

static void BM_vec3fConstruct(benchmark::State& state) {
	for (auto _ : state) {
		vec3f v;
	}
}
BENCHMARK(BM_vec3fConstruct);

BENCHMARK_MAIN();
