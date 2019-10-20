#include <benchmark/benchmark.h>
#include <math/vec/vec2d.h>

using namespace spruce;

static void vec2dConstruct(benchmark::State& state) {
	for (auto _ : state) { // NOLINT(clang-analyzer-deadcode.DeadStores)
		vec2d v;
		benchmark::DoNotOptimize(v);
	}
}
BENCHMARK(vec2dConstruct);

static void vec2dScale(benchmark::State& state) {
	vec2d a(4, 4);
	float scale = 2;
	for (auto _ : state) { // NOLINT(clang-analyzer-deadcode.DeadStores)
		vec2d b = a * scale;
		benchmark::DoNotOptimize(b);
	}
}
BENCHMARK(vec2dScale);

static void vec2dAddVec(benchmark::State& state) {
	vec2d a(1, 0);
	vec2d b(0, 1);
	for (auto _ : state) { // NOLINT(clang-analyzer-deadcode.DeadStores)
		vec2d c = a + b;
		benchmark::DoNotOptimize(c);
	}
}
BENCHMARK(vec2dAddVec);

static void vec2dScaleMulti(benchmark::State& state) {
	constexpr uint64 NUM = 100000;
	struct TestData {
		vec2d vector;
		float scale;
	};
	TestData data[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		data[i].vector.set(i, i);
		data[i].scale = i;
	}
	for (auto _ : state) { // NOLINT(clang-analyzer-deadcode.DeadStores)
		for (uint64 i = 0; i < NUM; i++) {
			vec2d vec = data[i].vector * data[i].scale;
			benchmark::DoNotOptimize(vec);
		}
	}
	state.SetBytesProcessed(state.iterations() * sizeof(data));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(vec2dScaleMulti);

static void vec2dAddMulti(benchmark::State& state) {
	constexpr uint64 NUM = 100000;
	struct TestData {
		vec2d a;
		vec2d b;
	};
	TestData data[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		data[i].a.set(i, i);
		data[i].b = i;
	}
	for (auto _ : state) { // NOLINT(clang-analyzer-deadcode.DeadStores)
		for (uint64 i = 0; i < NUM; i++) {
			vec2d vec = data[i].a + data[i].b;
			benchmark::DoNotOptimize(vec);
		}
	}
	state.SetBytesProcessed(state.iterations() * sizeof(data));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(vec2dAddMulti);

static void vec2dSubMulti(benchmark::State& state) {
	constexpr uint64 NUM = 100000;
	struct TestData {
		vec2d a;
		vec2d b;
	};
	TestData data[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		data[i].a.set(i, i);
		data[i].b = i;
	}
	for (auto _ : state) { // NOLINT(clang-analyzer-deadcode.DeadStores)
		for (uint64 i = 0; i < NUM; i++) {
			vec2d vec = data[i].a - data[i].b;
			benchmark::DoNotOptimize(vec);
		}
	}
	state.SetBytesProcessed(state.iterations() * sizeof(data));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(vec2dSubMulti);

#ifdef __APPLE__
#include <simd/simd.h>

static void vec2dAddMultiMacSys(benchmark::State& state) {
	constexpr uint64 NUM = 100000;
	struct TestData {
		vector_double2 a;
		vector_double2 b;
	};
	TestData data[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		data[i].a = {(float)i, (float)i};
		data[i].b = {(float)i, (float)i};
	}
	for (auto _ : state) { // NOLINT(clang-analyzer-deadcode.DeadStores)
		for (uint64 i = 0; i < NUM; i++) {
			volatile vector_double2 vec = data[i].a + data[i].b; // NOLINT(clang-analyzer-deadcode.DeadStores)
		}
	}
	state.SetBytesProcessed(state.iterations() * sizeof(data));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(vec2dAddMultiMacSys);
#endif
