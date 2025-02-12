// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <algorithm>
#include <cmath>
#include <functional>
#include <random>
#include <vector>

#include <benchmark/benchmark.h>
#include "bench/utils.h"

#include <xnnpack/aligned-allocator.h>
#include <xnnpack/common.h>
#include <xnnpack/microfnptr.h>
#include <xnnpack/vunary.h>


static void f32_vrelu(
  benchmark::State& state,
  xnn_f32_vrelu_ukernel_fn f32_vrelu,
  benchmark::utils::IsaCheckFunction isa_check = nullptr)
{
  if (isa_check != nullptr && !isa_check(state)) {
    return;
  }

  const size_t num_elements = state.range(0);

  std::random_device random_device;
  auto rng = std::mt19937(random_device());
  auto f32rng = std::bind(std::uniform_real_distribution<float>(-10.0f, 10.0f), std::ref(rng));

  std::vector<float, AlignedAllocator<float, 64>> x(num_elements);
  std::generate(x.begin(), x.end(), std::ref(f32rng));
  std::vector<float, AlignedAllocator<float, 64>> y(num_elements);
  std::generate(x.begin(), x.end(), std::ref(f32rng));

  for (auto _ : state) {
    f32_vrelu(num_elements * sizeof(float), x.data(), y.data(), nullptr);
  }

  const uint64_t cpu_frequency = benchmark::utils::GetCurrentCpuFrequency();
  if (cpu_frequency != 0) {
    state.counters["cpufreq"] = cpu_frequency;
  }

  const size_t elements_per_iteration = num_elements;
  state.counters["elements"] =
    benchmark::Counter(uint64_t(state.iterations()) * elements_per_iteration, benchmark::Counter::kIsRate);

  const size_t bytes_per_iteration = 2 * num_elements * sizeof(float);
  state.counters["bytes"] =
    benchmark::Counter(uint64_t(state.iterations()) * bytes_per_iteration, benchmark::Counter::kIsRate);
}

#if (XNN_ARCH_WASM || XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD) && XNN_PLATFORM_JIT
static void f32_vrelu(
  benchmark::State& state,
  xnn_vrelu_generator_fn generator,
  int k_unroll,
  bool use_local,
  benchmark::utils::IsaCheckFunction isa_check = nullptr)
{
  xnn_code_buffer b;
  xnn_allocate_code_memory(&b, XNN_DEFAULT_CODE_BUFFER_SIZE);
  generator(&b, k_unroll, use_local);
  xnn_finalize_code_memory(&b);
  auto kernel = (xnn_f32_vrelu_ukernel_fn)(xnn_first_function_ptr(&b));
  f32_vrelu(state, kernel, isa_check);
  xnn_release_code_memory(&b);
}
#endif  // (XNN_ARCH_WASM || XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD) && XNN_PLATFORM_JIT

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  BENCHMARK_CAPTURE(f32_vrelu, sse_x4,
                    xnn_f32_vrelu_ukernel__sse_x4)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

  BENCHMARK_CAPTURE(f32_vrelu, sse_x8,
                    xnn_f32_vrelu_ukernel__sse_x8)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

  BENCHMARK_CAPTURE(f32_vrelu, avx_x8,
                    xnn_f32_vrelu_ukernel__avx_x8,
                    benchmark::utils::CheckAVX)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

  BENCHMARK_CAPTURE(f32_vrelu, avx_x16,
                    xnn_f32_vrelu_ukernel__avx_x16,
                    benchmark::utils::CheckAVX)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

  BENCHMARK_CAPTURE(f32_vrelu, avx512f_x16,
                    xnn_f32_vrelu_ukernel__avx512f_x16,
                    benchmark::utils::CheckAVX512F)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

  BENCHMARK_CAPTURE(f32_vrelu, avx512f_x32,
                    xnn_f32_vrelu_ukernel__avx512f_x32,
                    benchmark::utils::CheckAVX512F)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  BENCHMARK_CAPTURE(f32_vrelu, neon_x4,
                    xnn_f32_vrelu_ukernel__neon_x4,
                    benchmark::utils::CheckNEON)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
  BENCHMARK_CAPTURE(f32_vrelu, neon_x8,
                    xnn_f32_vrelu_ukernel__neon_x8,
                    benchmark::utils::CheckNEON)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64


#if XNN_ARCH_WASM || XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  BENCHMARK_CAPTURE(f32_vrelu, wasm_x1,
                    xnn_f32_vrelu_ukernel__wasm_x1)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

  BENCHMARK_CAPTURE(f32_vrelu, wasm_x2,
                    xnn_f32_vrelu_ukernel__wasm_x2)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

  BENCHMARK_CAPTURE(f32_vrelu, wasm_x4,
                    xnn_f32_vrelu_ukernel__wasm_x4)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

  BENCHMARK_CAPTURE(f32_vrelu, wasm_x8,
                    xnn_f32_vrelu_ukernel__wasm_x8)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

  BENCHMARK_CAPTURE(f32_vrelu, wasm32_shr_x1,
                    xnn_f32_vrelu_ukernel__wasm32_shr_x1)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

  BENCHMARK_CAPTURE(f32_vrelu, wasm32_shr_x2,
                    xnn_f32_vrelu_ukernel__wasm32_shr_x2)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

  BENCHMARK_CAPTURE(f32_vrelu, wasm32_shr_x4,
                    xnn_f32_vrelu_ukernel__wasm32_shr_x4)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
#endif  // XNN_ARCH_WASM || XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD

#if (XNN_ARCH_WASM || XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD) && XNN_PLATFORM_JIT
  BENCHMARK_CAPTURE(f32_vrelu, jit_wasm32_shr_x1,
                    xnn_generate_f32_vrelu_ukernel__jit_wasm32_shr, 1, false)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

  BENCHMARK_CAPTURE(f32_vrelu, jit_wasm32_shr_x2,
                    xnn_generate_f32_vrelu_ukernel__jit_wasm32_shr, 2, false)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

  BENCHMARK_CAPTURE(f32_vrelu, jit_wasm32_shr_x4,
                    xnn_generate_f32_vrelu_ukernel__jit_wasm32_shr, 4, false)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

  BENCHMARK_CAPTURE(f32_vrelu, jit_wasm32_shr_x8,
                    xnn_generate_f32_vrelu_ukernel__jit_wasm32_shr, 8, false)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

  BENCHMARK_CAPTURE(f32_vrelu, jit_wasm32_shr_local_x1,
                    xnn_generate_f32_vrelu_ukernel__jit_wasm32_shr, 1, true)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

  BENCHMARK_CAPTURE(f32_vrelu, jit_wasm32_shr_local_x2,
                    xnn_generate_f32_vrelu_ukernel__jit_wasm32_shr, 2, true)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

  BENCHMARK_CAPTURE(f32_vrelu, jit_wasm32_shr_local_x4,
                    xnn_generate_f32_vrelu_ukernel__jit_wasm32_shr, 4, true)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

  BENCHMARK_CAPTURE(f32_vrelu, jit_wasm32_shr_local_x8,
                    xnn_generate_f32_vrelu_ukernel__jit_wasm32_shr, 8, true)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
#endif  // (XNN_ARCH_WASM || XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD) && XNN_PLATFORM_JIT

#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  BENCHMARK_CAPTURE(f32_vrelu, wasmsimd_x4,
                    xnn_f32_vrelu_ukernel__wasmsimd_x4)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

  BENCHMARK_CAPTURE(f32_vrelu, wasmsimd_x8,
                    xnn_f32_vrelu_ukernel__wasmsimd_x8)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();

  BENCHMARK_CAPTURE(f32_vrelu, wasmsimd_x16,
                    xnn_f32_vrelu_ukernel__wasmsimd_x16)
    ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
    ->UseRealTime();
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD

BENCHMARK_CAPTURE(f32_vrelu, scalar_x1,
                  xnn_f32_vrelu_ukernel__scalar_x1)
  ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
  ->UseRealTime();

BENCHMARK_CAPTURE(f32_vrelu, scalar_x2,
                  xnn_f32_vrelu_ukernel__scalar_x2)
  ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
  ->UseRealTime();

BENCHMARK_CAPTURE(f32_vrelu, scalar_x4,
                  xnn_f32_vrelu_ukernel__scalar_x4)
  ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
  ->UseRealTime();

BENCHMARK_CAPTURE(f32_vrelu, scalar_x8,
                  xnn_f32_vrelu_ukernel__scalar_x8)
  ->Apply(benchmark::utils::UnaryElementwiseParameters<float, float>)
  ->UseRealTime();

#ifndef XNNPACK_BENCHMARK_NO_MAIN
BENCHMARK_MAIN();
#endif
