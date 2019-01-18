#include <benchmark/benchmark.h>
#include <math/vec/vec3f.h>

using namespace spruce;

static void vec3fConstruct(benchmark::State& state) {
	for (auto _ : state) {
		vec3f v;
	}
}
BENCHMARK(vec3fConstruct);

static void vec3fScale(benchmark::State& state) {
	vec3f a(4, 4, 4);
	float scale = 2;
	for (auto _ : state) {
		vec3f b = a * scale;
	}
}
BENCHMARK(vec3fScale);

static void vec3fAddVec(benchmark::State& state) {
	vec3f a(1, 0, 0);
	vec3f b(0, 1, 1);
	for (auto _ : state) {
		vec3f c = a + b;
	}
}
BENCHMARK(vec3fAddVec);

static void vec3fScaleMulti(benchmark::State& state) {
	constexpr uint64 NUM = 100000;
	vec3f vecs[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		vecs[i].set(i, i, i);
	}
	float scales[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		scales[i] = i;
	}
	for (auto _ : state) {
		for (uint64 i = 0; i < NUM; i++) {
			vec3f vec = vecs[i] * scales[i];
		}
	}
	state.SetBytesProcessed(state.iterations() * (sizeof(vecs) + sizeof(scales)));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(vec3fScaleMulti);

static void vec3fAddMulti(benchmark::State& state) {
	constexpr uint64 NUM = 100000;
	vec3f vecsa[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		vecsa[i].set(i, i, i);
	}
	vec3f vecsb[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		vecsb[i] = i;
	}
	for (auto _ : state) {
		for (uint64 i = 0; i < NUM; i++) {
			vec3f vec = vecsa[i] + vecsb[i];
		}
	}
	state.SetBytesProcessed(state.iterations() * (sizeof(vecsa) + sizeof(vecsb)));
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
