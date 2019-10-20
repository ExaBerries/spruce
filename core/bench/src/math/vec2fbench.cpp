#include <benchmark/benchmark.h>
#include <math/vec/vec2f.h>

using namespace spruce;

static void vec2fConstruct(benchmark::State& state) {
	for (auto _ : state) { // NOLINT(clang-analyzer-deadcode.DeadStores)
		vec2f v;
		benchmark::DoNotOptimize(v);
	}
}
BENCHMARK(vec2fConstruct);

static void vec2fScale(benchmark::State& state) {
	vec2f a(4, 4);
	float scale = 2;
	for (auto _ : state) { // NOLINT(clang-analyzer-deadcode.DeadStores)
		vec2f b = a * scale;
		benchmark::DoNotOptimize(b);
	}
}
BENCHMARK(vec2fScale);

static void vec2fAddVec(benchmark::State& state) {
	vec2f a(1, 0);
	vec2f b(0, 1);
	for (auto _ : state) { // NOLINT(clang-analyzer-deadcode.DeadStores)
		vec2f c = a + b;
		benchmark::DoNotOptimize(c);
	}
}
BENCHMARK(vec2fAddVec);

static void vec2fScaleMulti(benchmark::State& state) {
	constexpr uint64 NUM = 100000;
	struct TestData {
		vec2f vector;
		float scale;
	};
	TestData data[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		data[i].vector.set(i, i);
		data[i].scale = i;
	}
	for (auto _ : state) { // NOLINT(clang-analyzer-deadcode.DeadStores)
		for (uint64 i = 0; i < NUM; i++) {
			vec2f vec = data[i].vector * data[i].scale;
			benchmark::DoNotOptimize(vec);
		}
	}
	state.SetBytesProcessed(state.iterations() * sizeof(data));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(vec2fScaleMulti);

static void vec2fAddMulti(benchmark::State& state) {
	constexpr uint64 NUM = 100000;
	struct TestData {
		vec2f a;
		vec2f b;
	};
	TestData data[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		data[i].a.set(i, i);
		data[i].b = i;
	}
	for (auto _ : state) { // NOLINT(clang-analyzer-deadcode.DeadStores)
		for (uint64 i = 0; i < NUM; i++) {
			vec2f vec = data[i].a + data[i].b;
			benchmark::DoNotOptimize(vec);
		}
	}
	state.SetBytesProcessed(state.iterations() * sizeof(data));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(vec2fAddMulti);

static void vec2fSubMulti(benchmark::State& state) {
	constexpr uint64 NUM = 100000;
	struct TestData {
		vec2f a;
		vec2f b;
	};
	TestData data[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		data[i].a.set(i, i);
		data[i].b = i;
	}
	for (auto _ : state) { // NOLINT(clang-analyzer-deadcode.DeadStores)
		for (uint64 i = 0; i < NUM; i++) {
			vec2f vec = data[i].a - data[i].b;
			benchmark::DoNotOptimize(vec);
		}
	}
	state.SetBytesProcessed(state.iterations() * sizeof(data));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(vec2fSubMulti);

#ifdef __APPLE__
#include <simd/simd.h>

static void vec2fAddMultiMacSys(benchmark::State& state) {
	constexpr uint64 NUM = 100000;
	struct TestData {
		vector_float2 a;
		vector_float2 b;
	};
	TestData data[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		float fi = i;
		data[i].a = {fi, fi};
		data[i].b = {fi, fi};
	}
	for (auto _ : state) { // NOLINT(clang-analyzer-deadcode.DeadStores)
		for (uint64 i = 0; i < NUM; i++) {
			volatile vector_float2 vec = data[i].a + data[i].b; // NOLINT(clang-analyzer-deadcode.DeadStores)
		}
	}
	state.SetBytesProcessed(state.iterations() * sizeof(data));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(vec2fAddMultiMacSys);
#endif
