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
		volatile mat4f matr = ma + mb;
		benchmark::DoNotOptimize(matr);
	}
}
BENCHMARK(mat4fAdd);

static void mat4fMul(benchmark::State& state) {
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
		volatile mat4f matr = ma * mb;
		benchmark::DoNotOptimize(matr);
	}
}
BENCHMARK(mat4fMul);

static void mat4fDeterminant(benchmark::State& state) {
	mat4f m;
	for (auto _ : state) {
		volatile float det = m.determinant();
		benchmark::DoNotOptimize(det);
	}
}
BENCHMARK(mat4fDeterminant);

static void mat4fInvert(benchmark::State& state) {
	mat4f m;
	for (auto _ : state) {
		mat4f inv = m.invert();
	}
}
BENCHMARK(mat4fInvert);

static void mat4fTranspose(benchmark::State& state) {
	mat4f m;
	for (auto _ : state) {
		mat4f det = m.transpose();
	}
}
BENCHMARK(mat4fTranspose);

static void mat4fAddMulti(benchmark::State& state) {
	const float values[16] = {
		0, 1, 1, 1,
		1, 0, 1, 1,
		1, 1, 0, 1,
		1, 1, 1, 0
	};
	struct TestData {
		mat4f a;
		mat4f b;
	};
	constexpr uint64 NUM = 10000;
	TestData data[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		data[i].a.set(values);
		data[i].b.set(values);
	}
	for (auto _ : state) {
		for (uint64 i = 0; i < NUM; i++) {
			volatile mat4f matr = data[i].a + data[i].b;
			benchmark::DoNotOptimize(matr);
		}
	}
	state.SetBytesProcessed(state.iterations() * sizeof(data));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(mat4fAddMulti);

static void mat4fMulMulti(benchmark::State& state) {
	const float values[16] = {
		0, 1, 1, 1,
		1, 0, 1, 1,
		1, 1, 0, 1,
		1, 1, 1, 0
	};
	struct TestData {
		mat4f a;
		mat4f b;
	};
	constexpr uint64 NUM = 10000;
	TestData data[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		data[i].a.set(values);
		data[i].b.set(values);
	}
	for (auto _ : state) {
		for (uint64 i = 0; i < NUM; i++) {
			volatile mat4f matr = data[i].a * data[i].b;
			benchmark::DoNotOptimize(matr);
		}
	}
	state.SetBytesProcessed(state.iterations() * sizeof(data));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(mat4fMulMulti);

static void mat4fMulVec3fMulti(benchmark::State& state) {
	const float values[16] = {
		0, 1, 1, 1,
		1, 0, 1, 1,
		1, 1, 0, 1,
		1, 1, 1, 0
	};
	struct TestData {
		mat4f a;
		vec3f b;
	};
	constexpr uint64 NUM = 10000;
	TestData data[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		data[i].a.set(values);
		data[i].b.set(1, 1, 1);
	}
	for (auto _ : state) {
		for (uint64 i = 0; i < NUM; i++) {
			volatile vec3f vecr = data[i].a * data[i].b;
			benchmark::DoNotOptimize(vecr);
		}
	}
	state.SetBytesProcessed(state.iterations() * sizeof(data));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(mat4fMulVec3fMulti);

#ifdef __APPLE__
#include <simd/simd.h>

static void mat4fAddMultiMacSys(benchmark::State& state) {
	constexpr uint64 NUM = 10000;
	struct TestData {
		matrix_float4x4 a;
		matrix_float4x4 b;
	};
	TestData data[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		vector_float4 r0 = {(float)i,(float)i,(float)i,(float)i};
		vector_float4 r1 = {(float)i,(float)i,(float)i,(float)i};
		vector_float4 r2 = {(float)i,(float)i,(float)i,(float)i};
		vector_float4 r3 = {(float)i,(float)i,(float)i,(float)i};
		matrix_float4x4 mat = matrix_from_rows(r0,r1,r2,r3);
		data[i].a = mat;
		data[i].b = mat;
	}
	for (auto _ : state) {
		for (uint64 i = 0; i < NUM; i++) {
			volatile matrix_float4x4 matr = simd_add(data[i].a, data[i].b);
			benchmark::DoNotOptimize(matr);
		}
	}
	state.SetBytesProcessed(state.iterations() * sizeof(data));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(mat4fAddMultiMacSys);

static void mat4fMulMultiMacSys(benchmark::State& state) {
	constexpr uint64 NUM = 10000;
	struct TestData {
		matrix_float4x4 a;
		matrix_float4x4 b;
	};
	TestData data[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		vector_float4 r0 = {(float)i,(float)i,(float)i,(float)i};
		vector_float4 r1 = {(float)i,(float)i,(float)i,(float)i};
		vector_float4 r2 = {(float)i,(float)i,(float)i,(float)i};
		vector_float4 r3 = {(float)i,(float)i,(float)i,(float)i};
		matrix_float4x4 mat = matrix_from_rows(r0,r1,r2,r3);
		data[i].a = mat;
		data[i].b = mat;
	}
	for (auto _ : state) {
		for (uint64 i = 0; i < NUM; i++) {
			volatile matrix_float4x4 matr = simd_mul(data[i].a, data[i].b);
			benchmark::DoNotOptimize(matr);
		}
	}
	state.SetBytesProcessed(state.iterations() * sizeof(data));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(mat4fMulMultiMacSys);

static void mat4fMulVec3fMultiMacSys(benchmark::State& state) {
	constexpr uint64 NUM = 10000;
	struct TestData {
		matrix_float4x4 a;
		vector_float4 b;
	};
	TestData data[NUM];
	for (uint64 i = 0; i < NUM; i++) {
		vector_float4 r0 = {(float)i,(float)i,(float)i,(float)i};
		vector_float4 r1 = {(float)i,(float)i,(float)i,(float)i};
		vector_float4 r2 = {(float)i,(float)i,(float)i,(float)i};
		vector_float4 r3 = {(float)i,(float)i,(float)i,(float)i};
		matrix_float4x4 mat = matrix_from_rows(r0,r1,r2,r3);
		data[i].a = mat;
		data[i].b = {(float)i, (float)i, (float)i, 1};
	}
	for (auto _ : state) {
		for (uint64 i = 0; i < NUM; i++) {
			volatile vector_float4 vecr = simd_mul(data[i].a, data[i].b);
			benchmark::DoNotOptimize(vecr);
		}
	}
	state.SetBytesProcessed(state.iterations() * sizeof(data));
	state.SetItemsProcessed(state.iterations() * NUM);
}
BENCHMARK(mat4fMulVec3fMultiMacSys);
#endif
