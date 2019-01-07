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

struct fcvec3f {
	float x = 0;
	float y = 0;
	float z = 0;

	fcvec3f() = default;
	fcvec3f(const fcvec3f&) = default;
	fcvec3f(float x, float y, float z) : x(x), y(y), z(z) {};
	~fcvec3f() = default;
};

fcvec3f operator+(fcvec3f a, fcvec3f b) {
	return fcvec3f(a.x + b.x, a.y + b.y, a.z + b.z);
}

fcvec3f operator*(const fcvec3f& a, float b) {
	return fcvec3f(a.x * b, a.y * b, a.z * b);
}


static void fcvec3fConstruct(benchmark::State& state) {
	for (auto _ : state) {
		fcvec3f(1, 1, 1);
	}
}
BENCHMARK(fcvec3fConstruct);

static void fcvec3fScale(benchmark::State& state) {
	fcvec3f a(4, 4, 4);
	float scale = 2;
	for (auto _ : state) {
		fcvec3f b = a * scale;
	}
}
BENCHMARK(fcvec3fScale);

static void fcvec3fAddVec(benchmark::State& state) {
	fcvec3f a(1, 0, 0);
	fcvec3f b(0, 1, 1);
	for (auto _ : state) {
		fcvec3f c = a + b;
	}
}
BENCHMARK(fcvec3fAddVec);

static void fcvec3fScaleMulti(benchmark::State& state) {
	constexpr uint64 NUM = 100000;
	fcvec3f vecs[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		vecs[i] = fcvec3f(i, i, i);
	}
	float scales[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		scales[i] = i;
	}
	for (auto _ : state) {
		for (uint64 i = 0; i < NUM; i++) {
			fcvec3f vec = vecs[i] * scales[i];
		}
	}
	state.SetBytesProcessed(state.iterations() * (sizeof(vecs) + sizeof(scales)));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(fcvec3fScaleMulti);

static void fcvec3fAddMulti(benchmark::State& state) {
	constexpr uint64 NUM = 100000;
	fcvec3f vecsa[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		vecsa[i] = fcvec3f(i, i, i);
	}
	fcvec3f vecsb[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		vecsb[i] = fcvec3f(i, i, i);
	}
	for (auto _ : state) {
		for (uint64 i = 0; i < NUM; i++) {
			fcvec3f vec = vecsa[i] + vecsb[i];
		}
	}
	state.SetBytesProcessed(state.iterations() * (sizeof(vecsa) + sizeof(vecsb)));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(fcvec3fAddMulti);

struct fncvec3f {
	float x = 0;
	float y = 0;
	float z = 0;

	fncvec3f() = default;
	fncvec3f(const fncvec3f&) = default;
	fncvec3f(const float& x, const float& y, const float& z) : x(x), y(y), z(z) {};
	~fncvec3f() = default;
};

fncvec3f operator+(const fncvec3f& a, const fncvec3f& b) {
	return fncvec3f(a.x + b.x, a.y + b.y, a.z + b.z);
}

fncvec3f operator*(const fncvec3f& a, const float& b) {
	return fncvec3f(a.x * b, a.y * b, a.z * b);
}

static void fncvec3fConstruct(benchmark::State& state) {
	for (auto _ : state) {
		fncvec3f(1, 1, 1);
	}
}
BENCHMARK(fncvec3fConstruct);

static void fncvec3fScale(benchmark::State& state) {
	fncvec3f a(4, 4, 4);
	float scale = 2;
	for (auto _ : state) {
		fncvec3f b = a * scale;
	}
}
BENCHMARK(fncvec3fScale);

static void fncvec3fAddVec(benchmark::State& state) {
	fncvec3f a(1, 0, 0);
	fncvec3f b(0, 1, 1);
	for (auto _ : state) {
		fncvec3f c = a + b;
	}
}
BENCHMARK(fncvec3fAddVec);

static void fncvec3fScaleMulti(benchmark::State& state) {
	constexpr uint64 NUM = 100000;
	fncvec3f vecs[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		vecs[i] = fncvec3f(i, i, i);
	}
	float scales[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		scales[i] = i;
	}
	for (auto _ : state) {
		for (uint64 i = 0; i < NUM; i++) {
			fncvec3f vec = vecs[i] * scales[i];
		}
	}
	state.SetBytesProcessed(state.iterations() * (sizeof(vecs) + sizeof(scales)));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(fncvec3fScaleMulti);

static void fncvec3fAddMulti(benchmark::State& state) {
	constexpr uint64 NUM = 100000;
	fncvec3f vecsa[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		vecsa[i] = fncvec3f(i, i, i);
	}
	fncvec3f vecsb[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		vecsb[i] = fncvec3f(i, i, i);
	}
	for (auto _ : state) {
		for (uint64 i = 0; i < NUM; i++) {
			fncvec3f vec = vecsa[i] + vecsb[i];
		}
	}
	state.SetBytesProcessed(state.iterations() * (sizeof(vecsa) + sizeof(vecsb)));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(fncvec3fAddMulti);
