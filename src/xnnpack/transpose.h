// Copyright 2021 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <stddef.h>
#include <stdint.h>
#include <xnnpack/common.h>
#include <xnnpack/params.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DECLARE_X32_TRANSPOSE_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(const uint32_t* input,      \
                            uint32_t* output,           \
                            size_t input_stride,        \
                            size_t output_stride,       \
                            size_t block_width,         \
                            size_t block_height);

DECLARE_X32_TRANSPOSE_UKERNEL_FUNCTION(xnn_x32_transpose_ukernel__4x4_sse);
DECLARE_X32_TRANSPOSE_UKERNEL_FUNCTION(xnn_x32_transpose_ukernel__4x4_wasmsimd);

#define DECLARE_X16_TRANSPOSE_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(const uint16_t* input,      \
                            uint16_t* output,           \
                            size_t input_stride,        \
                            size_t output_stride,       \
                            size_t block_width,         \
                            size_t block_height);

DECLARE_X16_TRANSPOSE_UKERNEL_FUNCTION(xnn_x16_transpose_ukernel__4x8_sse2);

#ifdef __cplusplus
}  // extern "C"
#endif