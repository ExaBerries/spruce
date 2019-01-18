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

static void mat4fAdd(benchmark::State& state) {
	const float valuesa[16] = {
		0, 1, 1, 1,
		1, 0, 1, 1,
		1, 1, 0, 1,
		1, 1, 1, 0
	};
	mat4f ma(valuesa);
	const float valuesb[16] = {
		0, 1, 1, 1,
		1, 0, 1, 1,
		1, 1, 0, 1,
		1, 1, 1, 0
	};
	mat4f mb(valuesb);
	for (auto _ : state) {
		ma + mb;
	}
}
BENCHMARK(mat4fAdd);

static void mat4fAddMulti(benchmark::State& state) {
	const float values[16] = {
		0, 1, 1, 1,
		1, 0, 1, 1,
		1, 1, 0, 1,
		1, 1, 1, 0
	};
	constexpr uint64 NUM = 10000;
	mat4f matsa[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		matsa[i].set(values);
	}
	mat4f matsb[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		matsb[i].set(values);
	}
	for (auto _ : state) {
		for (uint64 i = 0; i < NUM; i++) {
			mat4f mat = matsa[i] + matsb[i];
		}
	}
	state.SetBytesProcessed(state.iterations() * (sizeof(matsa) + sizeof(matsb)));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(mat4fAddMulti);
