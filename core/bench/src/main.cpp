#include <benchmark/benchmark.h>
#include <types.h>
#include <cstring>

static void syscapCpy(benchmark::State& state) {
	constexpr uint64 SIZE = 1024 * 1024;
	uint8* a = (uint8*) malloc(SIZE);
	memset(a, 2, SIZE);
	uint8* b = (uint8*) malloc(SIZE);
	for (auto _ : state) {
		benchmark::DoNotOptimize(memcpy(b, a, SIZE));
	}
	state.SetBytesProcessed(state.iterations() * SIZE);
	free(a);
	free(b);
}
BENCHMARK(syscapCpy);

static void syscapAdd(benchmark::State& state) {
	constexpr uint64 NUM = 1024 * 1024 / sizeof(float);
	float a0[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		a0[i] = i;
	}
	float a1[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		a1[i] = i;
	}
	for (auto _ : state) {
		for (uint64 i = 0; i < NUM; i++) {
			float v;
			benchmark::DoNotOptimize(v);
			v = a0[i] + a1[i];
		}
	}
	state.SetBytesProcessed(state.iterations() * (sizeof(a0) + sizeof(a1)));
}
BENCHMARK(syscapAdd);

BENCHMARK_MAIN();
