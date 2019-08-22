#include <benchmark/benchmark.h>
#include <math/vec/vec3d.h>

using namespace spruce;

static void vec3dConstruct(benchmark::State& state) {
	for (auto _ : state) {
		vec3d v;
		benchmark::DoNotOptimize(v);
	}
}
BENCHMARK(vec3dConstruct);

static void vec3dScale(benchmark::State& state) {
	vec3d a(4, 4, 4);
	double scale = 2;
	for (auto _ : state) {
		vec3d b = a * scale;
		benchmark::DoNotOptimize(b);
	}
}
BENCHMARK(vec3dScale);

static void vec3dAddVec(benchmark::State& state) {
	vec3d a(1, 0, 0);
	vec3d b(0, 1, 1);
	for (auto _ : state) {
		vec3d c = a + b;
		benchmark::DoNotOptimize(c);
	}
}
BENCHMARK(vec3dAddVec);

static void vec3dScaleMulti(benchmark::State& state) {
	constexpr uint64 NUM = 100000;
	struct TestData {
		vec3d vector;
		double scale;
	};
	TestData data[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		data[i].vector.set(i, i, i);
		data[i].scale = i;
	}
	for (auto _ : state) {
		for (uint64 i = 0; i < NUM; i++) {
			vec3d vec = data[i].vector * data[i].scale;
			benchmark::DoNotOptimize(vec);
		}
	}
	state.SetBytesProcessed(state.iterations() * sizeof(data));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(vec3dScaleMulti);

static void vec3dAddMulti(benchmark::State& state) {
	constexpr uint64 NUM = 100000;
	struct TestData {
		vec3d a;
		vec3d b;
	};
	TestData data[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		data[i].a.set(i, i, i);
		data[i].b = i;
	}
	for (auto _ : state) {
		for (uint64 i = 0; i < NUM; i++) {
			vec3d vec = data[i].a + data[i].b;
			benchmark::DoNotOptimize(vec);
		}
	}
	state.SetBytesProcessed(state.iterations() * sizeof(data));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(vec3dAddMulti);

static void vec3dSubMulti(benchmark::State& state) {
	constexpr uint64 NUM = 100000;
	struct TestData {
		vec3d a;
		vec3d b;
	};
	TestData data[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		data[i].a.set(i, i, i);
		data[i].b = i;
	}
	for (auto _ : state) {
		for (uint64 i = 0; i < NUM; i++) {
			vec3d vec = data[i].a - data[i].b;
			benchmark::DoNotOptimize(vec);
		}
	}
	state.SetBytesProcessed(state.iterations() * sizeof(data));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(vec3dSubMulti);

static void vec3dCrs(benchmark::State& state) {
	for (auto _ : state) {
		vec3d vec(1, 0, 0);
		vec3d crs = vec.crs(vec3d(0, 1, 0));
	}
}
BENCHMARK(vec3dCrs);

#ifdef __APPLE__
#include <simd/simd.h>

static void vec3dAddMultiSIMD(benchmark::State& state) {
	constexpr uint64 NUM = 100000;
	struct TestData {
		vector_double3 a;
		vector_double3 b;
	};
	TestData data[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		data[i].a = {(double)i, (double)i, (double)i};
		data[i].b = {(double)i, (double)i, (double)i};
	}
	for (auto _ : state) {
		for (uint64 i = 0; i < NUM; i++) {
			volatile vector_double3 vec = data[i].a + data[i].b;
		}
	}
	state.SetBytesProcessed(state.iterations() * sizeof(data));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(vec3dAddMultiSIMD);
#endif
