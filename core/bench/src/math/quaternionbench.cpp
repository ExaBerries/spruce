#include <benchmark/benchmark.h>
#include <math/quaternion.h>

using namespace spruce;

static void quatConstructEuler(benchmark::State& state) {
	for (auto _ : state) { // NOLINT(clang-analyzer-deadcode.DeadStores)
		quaternion q(0.121, 0.145, 0.891);
		benchmark::DoNotOptimize(q);
	}
}
BENCHMARK(quatConstructEuler);

static void quatConstructAxisAngle(benchmark::State& state) {
	for (auto _ : state) { // NOLINT(clang-analyzer-deadcode.DeadStores)
		quaternion q({0, 1, 0}, M_PI / 4);
		benchmark::DoNotOptimize(q);
	}
}
BENCHMARK(quatConstructAxisAngle);
