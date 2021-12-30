// Copyright 2021 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <stdint.h>
#include <stddef.h>

#include <xnnpack/common.h>
#include <xnnpack/params.h>


#ifdef __cplusplus
extern "C" {
#endif


#define DECLARE_INIT_QU8_CONV_MINMAX_PARAMS_FUNCTION(fn_name)     \
  XNN_INTERNAL void fn_name(                                      \
    union xnn_qu8_conv_minmax_params params[XNN_MIN_ELEMENTS(1)], \
    uint8_t kernel_zero_point,                                    \
    float scale,                                                  \
    uint8_t output_zero_point,                                    \
    uint8_t output_min,                                           \
    uint8_t output_max);

DECLARE_INIT_QU8_CONV_MINMAX_PARAMS_FUNCTION(xnn_init_qu8_conv_minmax_fp32_scalar_lrint_params)
DECLARE_INIT_QU8_CONV_MINMAX_PARAMS_FUNCTION(xnn_init_qu8_conv_minmax_fp32_scalar_magic_params)

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  DECLARE_INIT_QU8_CONV_MINMAX_PARAMS_FUNCTION(xnn_init_qu8_conv_minmax_fp32_neon_params)
  DECLARE_INIT_QU8_CONV_MINMAX_PARAMS_FUNCTION(xnn_init_qu8_conv_minmax_fp32_neonv8_params)
  DECLARE_INIT_QU8_CONV_MINMAX_PARAMS_FUNCTION(xnn_init_qu8_conv_minmax_rndnu_neon_params)
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  DECLARE_INIT_QU8_CONV_MINMAX_PARAMS_FUNCTION(xnn_init_qu8_conv_minmax_fp32_sse2_params)
  DECLARE_INIT_QU8_CONV_MINMAX_PARAMS_FUNCTION(xnn_init_qu8_conv_minmax_fp32_avx2_params)
  DECLARE_INIT_QU8_CONV_MINMAX_PARAMS_FUNCTION(xnn_init_qu8_conv_minmax_fp32_avx512_params)
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  DECLARE_INIT_QU8_CONV_MINMAX_PARAMS_FUNCTION(xnn_init_qu8_conv_minmax_fp32_wasmsimd_params)
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#define DECLARE_INIT_QS8_CONV_MINMAX_PARAMS_FUNCTION(fn_name)     \
  XNN_INTERNAL void fn_name(                                      \
    union xnn_qs8_conv_minmax_params params[XNN_MIN_ELEMENTS(1)], \
    float scale,                                                  \
    int8_t output_zero_point,                                     \
    int8_t output_min,                                            \
    int8_t output_max);

DECLARE_INIT_QS8_CONV_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_conv_minmax_rndnu_scalar_params)
DECLARE_INIT_QS8_CONV_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_conv_minmax_fp32_scalar_lrint_params)
DECLARE_INIT_QS8_CONV_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_conv_minmax_fp32_scalar_magic_params)

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  DECLARE_INIT_QS8_CONV_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_conv_minmax_fp32_neon_params)
  DECLARE_INIT_QS8_CONV_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_conv_minmax_fp32_neonv8_params)
  DECLARE_INIT_QS8_CONV_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_conv_minmax_rndnu_neon_params)
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  DECLARE_INIT_QS8_CONV_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_conv_minmax_fp32_sse2_params)
  DECLARE_INIT_QS8_CONV_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_conv_minmax_fp32_sse4_params)
  DECLARE_INIT_QS8_CONV_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_conv_minmax_fp32_avx2_params)
  DECLARE_INIT_QS8_CONV_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_conv_minmax_fp32_avx512_params)
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  DECLARE_INIT_QS8_CONV_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_conv_minmax_fp32_wasmsimd_params)
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


XNN_INTERNAL void xnn_init_qc8_scale_fp32_params(
  size_t channels,
  size_t channels_tile,
  size_t stride,
  const float scale[XNN_MIN_ELEMENTS(1)],
  void* packed_w);


#define DECLARE_INIT_QS8_MINMAX_PARAMS_FUNCTION(fn_name)     \
  XNN_INTERNAL void fn_name(                                 \
    union xnn_qs8_minmax_params params[XNN_MIN_ELEMENTS(1)], \
    int8_t output_zero_point,                                \
    int8_t output_min,                                       \
    int8_t output_max);

DECLARE_INIT_QS8_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_minmax_scalar_lrint_params)
DECLARE_INIT_QS8_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_minmax_scalar_magic_params)

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  DECLARE_INIT_QS8_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_minmax_neon_params)
  DECLARE_INIT_QS8_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_minmax_neonv8_params)
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  DECLARE_INIT_QS8_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_minmax_sse2_params)
  DECLARE_INIT_QS8_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_minmax_sse4_params)
  DECLARE_INIT_QS8_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_minmax_avx2_params)
  DECLARE_INIT_QS8_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_minmax_avx512_params)
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  DECLARE_INIT_QS8_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_minmax_wasmsimd_params)
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


XNN_INTERNAL void xnn_init_qu8_avgpool_params(
  union xnn_qu8_avgpool_params params[XNN_MIN_ELEMENTS(1)],
  int32_t bias,
  float scale,
  uint8_t output_zero_point,
  uint8_t output_min,
  uint8_t output_max);

XNN_INTERNAL void xnn_init_scalar_qu8_avgpool_params(
  union xnn_qu8_avgpool_params params[XNN_MIN_ELEMENTS(1)],
  int32_t bias,
  float scale,
  uint8_t output_zero_point,
  uint8_t output_min,
  uint8_t output_max);

XNN_INTERNAL void xnn_update_qu8_avgpool_params(
  union xnn_qu8_avgpool_params* params,
  int32_t bias,
  float scale);

XNN_INTERNAL void xnn_init_qs8_avgpool_params(
  union xnn_qs8_avgpool_params params[XNN_MIN_ELEMENTS(1)],
  int32_t bias,
  float scale,
  int8_t output_zero_point,
  int8_t output_min,
  int8_t output_max);

XNN_INTERNAL void xnn_init_scalar_qs8_avgpool_params(
  union xnn_qs8_avgpool_params params[XNN_MIN_ELEMENTS(1)],
  int32_t bias,
  float scale,
  int8_t output_zero_point,
  int8_t output_min,
  int8_t output_max);

XNN_INTERNAL void xnn_update_qs8_avgpool_params(
  union xnn_qs8_avgpool_params* params,
  int32_t bias,
  float scale);

XNN_INTERNAL void xnn_update_f16_scaleminmax_params(
  struct xnn_f16_scaleminmax_params* params,
  uint16_t scale);

XNN_INTERNAL void xnn_update_f32_scaleminmax_params(
  union xnn_f32_scaleminmax_params* params,
  float scale);

XNN_INTERNAL void xnn_init_f16_scaleminmax_params(
  struct xnn_f16_scaleminmax_params params[XNN_MIN_ELEMENTS(1)],
  uint16_t scale,
  uint16_t min,
  uint16_t max);

XNN_INTERNAL void xnn_init_f32_scaleminmax_params(
  union xnn_f32_scaleminmax_params params[XNN_MIN_ELEMENTS(1)],
  float scale,
  float min,
  float max);

XNN_INTERNAL void xnn_init_f32_gavgpool_params(
  union xnn_f32_gavgpool_params params[XNN_MIN_ELEMENTS(1)],
  float multiplier,
  float output_min,
  float output_max,
  uint32_t width);

XNN_INTERNAL void xnn_update_f32_gavgpool_params(
  union xnn_f32_gavgpool_params* params,
  float multiplier,
  uint32_t width);

XNN_INTERNAL void xnn_init_scalar_f32_scaleminmax_params(
  union xnn_f32_scaleminmax_params params[XNN_MIN_ELEMENTS(1)],
  float scale,
  float min,
  float max);

XNN_INTERNAL void xnn_init_scalar_f32_gavgpool_params(
  union xnn_f32_gavgpool_params params[XNN_MIN_ELEMENTS(1)],
  float multiplier,
  float output_min,
  float output_max,
  uint32_t width);

XNN_INTERNAL void xnn_init_f16_minmax_params(
  struct xnn_f16_minmax_params params[XNN_MIN_ELEMENTS(1)],
  uint16_t min,
  uint16_t max);

XNN_INTERNAL void xnn_init_f32_minmax_params(
  union xnn_f32_minmax_params params[XNN_MIN_ELEMENTS(1)],
  float output_min,
  float output_max);

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
XNN_INTERNAL void xnn_init_f32_minmax_sse_params(
  union xnn_f32_minmax_params params[XNN_MIN_ELEMENTS(1)],
  float output_min,
  float output_max);

XNN_INTERNAL void xnn_init_f32_minmax_avx_params(
  union xnn_f32_minmax_params params[XNN_MIN_ELEMENTS(1)],
  float output_min,
  float output_max);
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

XNN_INTERNAL void xnn_init_f32_minmax_scalar_params(
  union xnn_f32_minmax_params params[XNN_MIN_ELEMENTS(1)],
  float output_min,
  float output_max);

XNN_INTERNAL void xnn_init_f16_hswish_params(
  struct xnn_f16_hswish_params params[XNN_MIN_ELEMENTS(1)]);


#define DECLARE_INIT_F32_HSWISH_PARAMS_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                             \
    union xnn_f32_hswish_params params[XNN_MIN_ELEMENTS(1)]);

DECLARE_INIT_F32_HSWISH_PARAMS_FUNCTION(xnn_init_f32_hswish_scalar_params)

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  DECLARE_INIT_F32_HSWISH_PARAMS_FUNCTION(xnn_init_f32_hswish_sse_params)
  DECLARE_INIT_F32_HSWISH_PARAMS_FUNCTION(xnn_init_f32_hswish_avx_params)
  DECLARE_INIT_F32_HSWISH_PARAMS_FUNCTION(xnn_init_f32_hswish_avx512_params)
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  DECLARE_INIT_F32_HSWISH_PARAMS_FUNCTION(xnn_init_f32_hswish_wasmsimd_params)
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD

XNN_INTERNAL void xnn_init_f32_abs_params(
  union xnn_f32_abs_params params[XNN_MIN_ELEMENTS(1)]);

XNN_INTERNAL void xnn_init_scalar_f32_abs_params(
  union xnn_f32_abs_params params[XNN_MIN_ELEMENTS(1)]);

XNN_INTERNAL void xnn_init_f32_neg_params(
  union xnn_f32_neg_params params[XNN_MIN_ELEMENTS(1)]);

XNN_INTERNAL void xnn_init_scalar_f32_neg_params(
  union xnn_f32_neg_params params[XNN_MIN_ELEMENTS(1)]);

XNN_INTERNAL void xnn_init_f32_rnd_params(
  union xnn_f32_rnd_params params[XNN_MIN_ELEMENTS(1)]);

XNN_INTERNAL void xnn_init_scalar_f32_rnd_params(
  union xnn_f32_rnd_params params[XNN_MIN_ELEMENTS(1)]);

XNN_INTERNAL void xnn_init_f32_elu_params(
  union xnn_f32_elu_params params[XNN_MIN_ELEMENTS(1)],
  float prescale,
  float alpha,
  float beta);

XNN_INTERNAL void xnn_init_scalar_f32_elu_params(
  union xnn_f32_elu_params params[XNN_MIN_ELEMENTS(1)],
  float prescale,
  float alpha,
  float beta);

XNN_INTERNAL void xnn_init_f32_lrelu_params(
  union xnn_f32_lrelu_params params[XNN_MIN_ELEMENTS(1)],
  float slope);

XNN_INTERNAL void xnn_init_scalar_f32_lrelu_params(
  union xnn_f32_lrelu_params params[XNN_MIN_ELEMENTS(1)],
  float slope);

XNN_INTERNAL void xnn_init_f32_sqrt_params(
  union xnn_f32_sqrt_params params[XNN_MIN_ELEMENTS(1)]);

XNN_INTERNAL void xnn_init_scalar_f32_sqrt_params(
  union xnn_f32_sqrt_params params[XNN_MIN_ELEMENTS(1)]);

XNN_INTERNAL void xnn_init_f32_chw_params(
  union xnn_f32_chw_params params[XNN_MIN_ELEMENTS(1)],
  uint32_t width,
  float output_min,
  float output_max);

XNN_INTERNAL void xnn_update_f32_chw_params(
  union xnn_f32_chw_params* params,
  uint32_t width);

XNN_INTERNAL void xnn_init_scalar_f32_chw_params(
  union xnn_f32_chw_params params[XNN_MIN_ELEMENTS(1)],
  uint32_t width,
  float output_min,
  float output_max);


#define DECLARE_INIT_S8_MINMAX_PARAMS_FUNCTION(fn_name)     \
  XNN_INTERNAL void fn_name(                                \
    union xnn_s8_minmax_params params[XNN_MIN_ELEMENTS(1)], \
    int8_t output_min,                                      \
    int8_t output_max);

DECLARE_INIT_S8_MINMAX_PARAMS_FUNCTION(xnn_init_s8_minmax_scalar_params)

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  DECLARE_INIT_S8_MINMAX_PARAMS_FUNCTION(xnn_init_s8_minmax_neon_params)
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  DECLARE_INIT_S8_MINMAX_PARAMS_FUNCTION(xnn_init_s8_minmax_sse2_params)
  DECLARE_INIT_S8_MINMAX_PARAMS_FUNCTION(xnn_init_s8_minmax_sse4_params)
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  DECLARE_INIT_S8_MINMAX_PARAMS_FUNCTION(xnn_init_s8_minmax_wasmsimd_params)
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#define DECLARE_INIT_U8_MINMAX_PARAMS_FUNCTION(fn_name)      \
  XNN_INTERNAL void fn_name(                                 \
    union xnn_u8_minmax_params params[XNN_MIN_ELEMENTS(1)],  \
    uint8_t output_min,                                      \
    uint8_t output_max);

DECLARE_INIT_U8_MINMAX_PARAMS_FUNCTION(xnn_init_u8_minmax_params)
DECLARE_INIT_U8_MINMAX_PARAMS_FUNCTION(xnn_init_u8_minmax_scalar_params)

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  DECLARE_INIT_U8_MINMAX_PARAMS_FUNCTION(xnn_init_u8_minmax_neon_params)
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  DECLARE_INIT_U8_MINMAX_PARAMS_FUNCTION(xnn_init_u8_minmax_sse2_params)
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  DECLARE_INIT_U8_MINMAX_PARAMS_FUNCTION(xnn_init_u8_minmax_wasmsimd_params)
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#define DECLARE_INIT_QU8_ADD_MINMAX_PARAMS_FUNCTION(fn_name)        \
  XNN_INTERNAL void fn_name(                                        \
    union xnn_qu8_addsub_minmax_params params[XNN_MIN_ELEMENTS(1)], \
    uint8_t x_zero_point,                                           \
    uint8_t y_zero_point,                                           \
    uint8_t output_zero_point,                                      \
    float x_output_scale,                                           \
    float y_output_scale,                                           \
    uint8_t output_min,                                             \
    uint8_t output_max);

DECLARE_INIT_QU8_ADD_MINMAX_PARAMS_FUNCTION(xnn_init_qu8_add_minmax_scalar_params)

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  DECLARE_INIT_QU8_ADD_MINMAX_PARAMS_FUNCTION(xnn_init_qu8_add_minmax_neon_params)
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  DECLARE_INIT_QU8_ADD_MINMAX_PARAMS_FUNCTION(xnn_init_qu8_add_minmax_sse2_params)
  DECLARE_INIT_QU8_ADD_MINMAX_PARAMS_FUNCTION(xnn_init_qu8_add_minmax_sse4_params)
  DECLARE_INIT_QU8_ADD_MINMAX_PARAMS_FUNCTION(xnn_init_qu8_add_minmax_avx2_params)
  DECLARE_INIT_QU8_ADD_MINMAX_PARAMS_FUNCTION(xnn_init_qu8_add_minmax_avx512_params)
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  DECLARE_INIT_QU8_ADD_MINMAX_PARAMS_FUNCTION(xnn_init_qu8_add_minmax_wasmsimd_params)
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#define DECLARE_INIT_QS8_ADD_MINMAX_PARAMS_FUNCTION(fn_name)        \
  XNN_INTERNAL void fn_name(                                        \
    union xnn_qs8_addsub_minmax_params params[XNN_MIN_ELEMENTS(1)], \
    int8_t x_zero_point,                                            \
    int8_t y_zero_point,                                            \
    int8_t output_zero_point,                                       \
    float x_output_scale,                                           \
    float y_output_scale,                                           \
    int8_t output_min,                                              \
    int8_t output_max);

DECLARE_INIT_QS8_ADD_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_add_minmax_scalar_params)

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  DECLARE_INIT_QS8_ADD_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_add_minmax_neon_params)
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  DECLARE_INIT_QS8_ADD_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_add_minmax_sse2_params)
  DECLARE_INIT_QS8_ADD_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_add_minmax_sse4_mul16_params)
  DECLARE_INIT_QS8_ADD_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_add_minmax_sse4_mul32_params)
  DECLARE_INIT_QS8_ADD_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_add_minmax_avx2_params)
  DECLARE_INIT_QS8_ADD_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_add_minmax_avx512_params)
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  DECLARE_INIT_QS8_ADD_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_add_minmax_wasmsimd_params)
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#define DECLARE_INIT_QU8_MUL_MINMAX_PARAMS_FUNCTION(fn_name)     \
  XNN_INTERNAL void fn_name(                                     \
    union xnn_qu8_mul_minmax_params params[XNN_MIN_ELEMENTS(1)], \
    uint8_t a_zero_point,                                        \
    uint8_t b_zero_point,                                        \
    uint8_t output_zero_point,                                   \
    float product_output_scale,                                  \
    uint8_t output_min,                                          \
    uint8_t output_max);

DECLARE_INIT_QU8_MUL_MINMAX_PARAMS_FUNCTION(xnn_init_qu8_mul_minmax_fp32_scalar_params)

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  DECLARE_INIT_QU8_MUL_MINMAX_PARAMS_FUNCTION(xnn_init_qu8_mul_minmax_fp32_neon_params)
  DECLARE_INIT_QU8_MUL_MINMAX_PARAMS_FUNCTION(xnn_init_qu8_mul_minmax_fp32_neonv8_params)
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  DECLARE_INIT_QU8_MUL_MINMAX_PARAMS_FUNCTION(xnn_init_qu8_mul_minmax_fp32_sse2_params)
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  DECLARE_INIT_QU8_MUL_MINMAX_PARAMS_FUNCTION(xnn_init_qu8_mul_minmax_fp32_wasmsimd_params)
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#define DECLARE_INIT_QS8_MUL_MINMAX_PARAMS_FUNCTION(fn_name)     \
  XNN_INTERNAL void fn_name(                                     \
    union xnn_qs8_mul_minmax_params params[XNN_MIN_ELEMENTS(1)], \
    int8_t a_zero_point,                                         \
    int8_t b_zero_point,                                         \
    int8_t output_zero_point,                                    \
    float product_output_scale,                                  \
    int8_t output_min,                                           \
    int8_t output_max);

DECLARE_INIT_QS8_MUL_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_mul_minmax_fp32_scalar_params)

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  DECLARE_INIT_QS8_MUL_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_mul_minmax_fp32_neon_params)
  DECLARE_INIT_QS8_MUL_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_mul_minmax_fp32_neonv8_params)
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  DECLARE_INIT_QS8_MUL_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_mul_minmax_fp32_sse2_params)
  DECLARE_INIT_QS8_MUL_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_mul_minmax_fp32_sse4_params)
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  DECLARE_INIT_QS8_MUL_MINMAX_PARAMS_FUNCTION(xnn_init_qs8_mul_minmax_fp32_wasmsimd_params)
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#define DECLARE_INIT_F16_F32_CVT_PARAMS_FUNCTION(fn_name)      \
  XNN_INTERNAL void fn_name(                                   \
    union xnn_f16_f32_cvt_params params[XNN_MIN_ELEMENTS(1)]);

DECLARE_INIT_F16_F32_CVT_PARAMS_FUNCTION(xnn_init_f16_f32_cvt_scalar_params)

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  DECLARE_INIT_F16_F32_CVT_PARAMS_FUNCTION(xnn_init_f16_f32_cvt_neon_params)
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  DECLARE_INIT_F16_F32_CVT_PARAMS_FUNCTION(xnn_init_f16_f32_cvt_sse_int16_params)
  DECLARE_INIT_F16_F32_CVT_PARAMS_FUNCTION(xnn_init_f16_f32_cvt_sse_int32_params)
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  DECLARE_INIT_F16_F32_CVT_PARAMS_FUNCTION(xnn_init_f16_f32_cvt_wasmsimd_int16_params)
  DECLARE_INIT_F16_F32_CVT_PARAMS_FUNCTION(xnn_init_f16_f32_cvt_wasmsimd_int32_params)
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#define DECLARE_INIT_F32_QS8_CVT_PARAMS_FUNCTION(fn_name)     \
  XNN_INTERNAL void fn_name(                                  \
    union xnn_f32_qs8_cvt_params params[XNN_MIN_ELEMENTS(1)], \
    float scale,                                              \
    int8_t zero_point,                                        \
    int8_t output_min,                                        \
    int8_t output_max);

DECLARE_INIT_F32_QS8_CVT_PARAMS_FUNCTION(xnn_init_f32_qs8_cvt_scalar_magic_fminmax_params)
DECLARE_INIT_F32_QS8_CVT_PARAMS_FUNCTION(xnn_init_f32_qs8_cvt_scalar_magic_iminmax_params)

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  DECLARE_INIT_F32_QS8_CVT_PARAMS_FUNCTION(xnn_init_f32_qs8_cvt_neon_params)
  DECLARE_INIT_F32_QS8_CVT_PARAMS_FUNCTION(xnn_init_f32_qs8_cvt_neonv8_params)
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  DECLARE_INIT_F32_QS8_CVT_PARAMS_FUNCTION(xnn_init_f32_qs8_cvt_sse2_params)
  DECLARE_INIT_F32_QS8_CVT_PARAMS_FUNCTION(xnn_init_f32_qs8_cvt_sse4_params)
  DECLARE_INIT_F32_QS8_CVT_PARAMS_FUNCTION(xnn_init_f32_qs8_cvt_avx_params)
  DECLARE_INIT_F32_QS8_CVT_PARAMS_FUNCTION(xnn_init_f32_qs8_cvt_avx2_params)
  DECLARE_INIT_F32_QS8_CVT_PARAMS_FUNCTION(xnn_init_f32_qs8_cvt_avx512_params)
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  DECLARE_INIT_F32_QS8_CVT_PARAMS_FUNCTION(xnn_init_f32_qs8_cvt_wasmsimd_cvt_params)
  DECLARE_INIT_F32_QS8_CVT_PARAMS_FUNCTION(xnn_init_f32_qs8_cvt_wasmsimd_magic_params)
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#define DECLARE_INIT_F32_QU8_CVT_PARAMS_FUNCTION(fn_name)     \
  XNN_INTERNAL void fn_name(                                  \
    union xnn_f32_qu8_cvt_params params[XNN_MIN_ELEMENTS(1)], \
    float scale,                                              \
    uint8_t zero_point,                                       \
    uint8_t output_min,                                       \
    uint8_t output_max);

DECLARE_INIT_F32_QU8_CVT_PARAMS_FUNCTION(xnn_init_f32_qu8_cvt_scalar_magic_fminmax_params)
DECLARE_INIT_F32_QU8_CVT_PARAMS_FUNCTION(xnn_init_f32_qu8_cvt_scalar_magic_iminmax_params)

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  DECLARE_INIT_F32_QU8_CVT_PARAMS_FUNCTION(xnn_init_f32_qu8_cvt_neon_params)
  DECLARE_INIT_F32_QU8_CVT_PARAMS_FUNCTION(xnn_init_f32_qu8_cvt_neonv8_params)
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  DECLARE_INIT_F32_QU8_CVT_PARAMS_FUNCTION(xnn_init_f32_qu8_cvt_sse2_params)
  DECLARE_INIT_F32_QU8_CVT_PARAMS_FUNCTION(xnn_init_f32_qu8_cvt_avx_params)
  DECLARE_INIT_F32_QU8_CVT_PARAMS_FUNCTION(xnn_init_f32_qu8_cvt_avx2_params)
  DECLARE_INIT_F32_QU8_CVT_PARAMS_FUNCTION(xnn_init_f32_qu8_cvt_avx512_params)
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  DECLARE_INIT_F32_QU8_CVT_PARAMS_FUNCTION(xnn_init_f32_qu8_cvt_wasmsimd_cvt_params)
  DECLARE_INIT_F32_QU8_CVT_PARAMS_FUNCTION(xnn_init_f32_qu8_cvt_wasmsimd_magic_params)
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#define DECLARE_INIT_QS8_F32_CVT_PARAMS_FUNCTION(fn_name)     \
  XNN_INTERNAL void fn_name(                                  \
    union xnn_qs8_f32_cvt_params params[XNN_MIN_ELEMENTS(1)], \
    float scale,                                              \
    int8_t zero_point);

DECLARE_INIT_QS8_F32_CVT_PARAMS_FUNCTION(xnn_init_qs8_f32_cvt_scalar_params)

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  DECLARE_INIT_QS8_F32_CVT_PARAMS_FUNCTION(xnn_init_qs8_f32_cvt_neon_params)
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  DECLARE_INIT_QS8_F32_CVT_PARAMS_FUNCTION(xnn_init_qs8_f32_cvt_sse2_params)
  DECLARE_INIT_QS8_F32_CVT_PARAMS_FUNCTION(xnn_init_qs8_f32_cvt_sse4_params)
  DECLARE_INIT_QS8_F32_CVT_PARAMS_FUNCTION(xnn_init_qs8_f32_cvt_avx_params)
  DECLARE_INIT_QS8_F32_CVT_PARAMS_FUNCTION(xnn_init_qs8_f32_cvt_avx512_params)
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  DECLARE_INIT_QS8_F32_CVT_PARAMS_FUNCTION(xnn_init_qs8_f32_cvt_wasmsimd_params)
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD


#define DECLARE_INIT_QU8_F32_CVT_PARAMS_FUNCTION(fn_name)     \
  XNN_INTERNAL void fn_name(                                  \
    union xnn_qu8_f32_cvt_params params[XNN_MIN_ELEMENTS(1)], \
    float scale,                                              \
    uint8_t zero_point);

DECLARE_INIT_QU8_F32_CVT_PARAMS_FUNCTION(xnn_init_qu8_f32_cvt_scalar_params)

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  DECLARE_INIT_QU8_F32_CVT_PARAMS_FUNCTION(xnn_init_qu8_f32_cvt_neon_params)
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  DECLARE_INIT_QU8_F32_CVT_PARAMS_FUNCTION(xnn_init_qu8_f32_cvt_sse2_params)
  DECLARE_INIT_QU8_F32_CVT_PARAMS_FUNCTION(xnn_init_qu8_f32_cvt_sse4_params)
  DECLARE_INIT_QU8_F32_CVT_PARAMS_FUNCTION(xnn_init_qu8_f32_cvt_avx_params)
  DECLARE_INIT_QU8_F32_CVT_PARAMS_FUNCTION(xnn_init_qu8_f32_cvt_avx512_params)
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  DECLARE_INIT_QU8_F32_CVT_PARAMS_FUNCTION(xnn_init_qu8_f32_cvt_wasmsimd_params)
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD

#ifdef __cplusplus
}  // extern "C"
#endif
