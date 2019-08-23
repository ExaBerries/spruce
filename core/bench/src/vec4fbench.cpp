#include <benchmark/benchmark.h>
#include <math/vec/vec4f.h>

using namespace spruce;

static void vec4fConstruct(benchmark::State& state) {
	for (auto _ : state) {
		vec4f v;
		benchmark::DoNotOptimize(v);
	}
}
BENCHMARK(vec4fConstruct);

static void vec4fScale(benchmark::State& state) {
	vec4f a(4, 4, 4, 4);
	float scale = 2;
	for (auto _ : state) {
		vec4f b = a * scale;
		benchmark::DoNotOptimize(b);
	}
}
BENCHMARK(vec4fScale);

static void vec4fAddVec(benchmark::State& state) {
	vec4f a(1, 0, 0, 1);
	vec4f b(0, 1, 1, 0);
	for (auto _ : state) {
		vec4f c = a + b;
		benchmark::DoNotOptimize(c);
	}
}
BENCHMARK(vec4fAddVec);

static void vec4fScaleMulti(benchmark::State& state) {
	constexpr uint64 NUM = 100000;
	struct TestData {
		vec4f vector;
		float scale;
	};
	TestData data[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		data[i].vector.set(i, i, i, i);
		data[i].scale = i;
	}
	for (auto _ : state) {
		for (uint64 i = 0; i < NUM; i++) {
			vec4f vec = data[i].vector * data[i].scale;
			benchmark::DoNotOptimize(vec);
		}
	}
	state.SetBytesProcessed(state.iterations() * sizeof(data));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(vec4fScaleMulti);

static void vec4fAddMulti(benchmark::State& state) {
	constexpr uint64 NUM = 100000;
	struct TestData {
		vec4f a;
		vec4f b;
	};
	TestData data[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		data[i].a.set(i, i, i, i);
		data[i].b = i;
	}
	for (auto _ : state) {
		for (uint64 i = 0; i < NUM; i++) {
			vec4f vec = data[i].a + data[i].b;
			benchmark::DoNotOptimize(vec);
		}
	}
	state.SetBytesProcessed(state.iterations() * sizeof(data));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(vec4fAddMulti);

static void vec4fSubMulti(benchmark::State& state) {
	constexpr uint64 NUM = 100000;
	struct TestData {
		vec4f a;
		vec4f b;
	};
	TestData data[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		data[i].a.set(i, i, i, i);
		data[i].b = i;
	}
	for (auto _ : state) {
		for (uint64 i = 0; i < NUM; i++) {
			vec4f vec = data[i].a - data[i].b;
			benchmark::DoNotOptimize(vec);
		}
	}
	state.SetBytesProcessed(state.iterations() * sizeof(data));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(vec4fSubMulti);

#ifdef __APPLE__
#include <simd/simd.h>

static void vec4fAddMultiMacSys(benchmark::State& state) {
	constexpr uint64 NUM = 100000;
	struct TestData {
		vector_float4 a;
		vector_float4 b;
	};
	TestData data[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		data[i].a = {(float)i, (float)i, (float)i, (float)i};
		data[i].b = {(float)i, (float)i, (float)i, (float)i};
	}
	for (auto _ : state) {
		for (uint64 i = 0; i < NUM; i++) {
			volatile vector_float4 vec = data[i].a + data[i].b;
		}
	}
	state.SetBytesProcessed(state.iterations() * sizeof(data));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(vec4fAddMultiMacSys);
#endif
