#include <benchmark/benchmark.h>
#include <math/vec/vec3f.h>

using namespace spruce;

static void vec3fConstruct(benchmark::State& state) {
	for (auto _ : state) {
		vec3f v;
		benchmark::DoNotOptimize(v);
	}
}
BENCHMARK(vec3fConstruct);

static void vec3fScale(benchmark::State& state) {
	vec3f a(4, 4, 4);
	float scale = 2;
	for (auto _ : state) {
		vec3f b = a * scale;
		benchmark::DoNotOptimize(b);
	}
}
BENCHMARK(vec3fScale);

static void vec3fAddVec(benchmark::State& state) {
	vec3f a(1, 0, 0);
	vec3f b(0, 1, 1);
	for (auto _ : state) {
		vec3f c = a + b;
		benchmark::DoNotOptimize(c);
	}
}
BENCHMARK(vec3fAddVec);

static void vec3fScaleMulti(benchmark::State& state) {
	constexpr uint64 NUM = 100000;
	struct TestData {
		vec3f vector;
		float scale;
	};
	TestData data[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		data[i].vector.set(i, i, i);
		data[i].scale = i;
	}
	for (auto _ : state) {
		for (uint64 i = 0; i < NUM; i++) {
			vec3f vec = data[i].vector * data[i].scale;
			benchmark::DoNotOptimize(vec);
		}
	}
	state.SetBytesProcessed(state.iterations() * sizeof(data));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(vec3fScaleMulti);

static void vec3fAddMulti(benchmark::State& state) {
	constexpr uint64 NUM = 100000;
	struct TestData {
		vec3f a;
		vec3f b;
	};
	TestData data[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		data[i].a.set(i, i, i);
		data[i].b = i;
	}
	for (auto _ : state) {
		for (uint64 i = 0; i < NUM; i++) {
			vec3f vec = data[i].a + data[i].b;
			benchmark::DoNotOptimize(vec);
		}
	}
	state.SetBytesProcessed(state.iterations() * sizeof(data));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(vec3fAddMulti);

static void vec3fCrs(benchmark::State& state) {
	for (auto _ : state) {
		vec3f vec(1, 0, 0);
		vec3f crs = vec.crs(vec3f(0, 1, 0));
	}
}
BENCHMARK(vec3fCrs);

#ifdef __APPLE__
#include <simd/simd.h>

static void vec3fAddMultiSIMD(benchmark::State& state) {
	constexpr uint64 NUM = 100000;
	struct TestData {
		vector_float3 a;
		vector_float3 b;
	};
	TestData data[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		data[i].a = {(float)i, (float)i, (float)i};
		data[i].b = {(float)i, (float)i, (float)i};
	}
	for (auto _ : state) {
		for (uint64 i = 0; i < NUM; i++) {
			volatile vector_float3 vec = data[i].a + data[i].b;
		}
	}
	state.SetBytesProcessed(state.iterations() * sizeof(data));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(vec3fAddMultiSIMD);
#endif
