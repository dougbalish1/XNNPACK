// Auto-generated file. Do not edit!
//   Template: src/f16-dwconv2d-chw/3x3p1-neonfp16arith.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <arm_neon.h>

#include <xnnpack/dwconv.h>
#include <xnnpack/math.h>

#ifdef XNN_ARCH_ARM
#include <xnnpack/intrinsics-polyfill.h>
#endif

void xnn_f16_dwconv2d_chw_ukernel_3x3p1__neonfp16arith_5x8(
    size_t input_height,
    size_t input_width,
    const void* input,
    const void* weights,
    const void* zero,
    void* output,
    uint32_t padding_top,
    const union xnn_f16_chw_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_OOB_READS
{
  assert(input_height != 0);
  assert(input_width != 0);
  assert(input_width % sizeof(__fp16) == 0);
  assert(padding_top == 1);

  const uint16x8_t vmask = vld1q_u16(params->neonfp16arith.mask);
  const float16x8_t vmax = vld1q_dup_f16(&params->neonfp16arith.max);
  const float16x8_t vmin = vld1q_dup_f16(&params->neonfp16arith.min);

  const __fp16* w0 = (const __fp16*)weights;
  const float16x8_t vw01234567 = vld1q_f16(w0);
  const float16x4_t vw89 = vreinterpret_f16_u32(vld1_dup_u32((const void*)(w0 + 8)));

  const size_t input_decrement = round_up_po2(input_width, 8 * sizeof(__fp16));

  const __fp16* i0 = zero;
  const __fp16* i1 = input;
  const __fp16* i2 = (const __fp16*) ((uintptr_t) i1 + input_width);
  const __fp16* i3 = (const __fp16*) ((uintptr_t) i2 + input_width);
  const __fp16* i4 = (const __fp16*) ((uintptr_t) i3 + input_width);
  const __fp16* i5 = (const __fp16*) ((uintptr_t) i4 + input_width);
  const __fp16* i6 = (const __fp16*) ((uintptr_t) i5 + input_width);

  __fp16* o0 = output;
  __fp16* o1 = (__fp16*) ((uintptr_t) o0 + input_width);
  __fp16* o2 = (__fp16*) ((uintptr_t) o1 + input_width);
  __fp16* o3 = (__fp16*) ((uintptr_t) o2 + input_width);
  __fp16* o4 = (__fp16*) ((uintptr_t) o3 + input_width);

  size_t output_height = input_height;
  do {
    if XNN_UNPREDICTABLE(output_height < 2) {
      i2 = zero;
      o1 = o0;
    }
    if XNN_UNPREDICTABLE(output_height < 3) {
      i3 = zero;
      o2 = o1;
    }
    if XNN_UNPREDICTABLE(output_height < 4) {
      i4 = zero;
      o3 = o2;
    }
    if XNN_UNPREDICTABLE(output_height < 5) {
      i5 = zero;
      o4 = o3;
    }
    if XNN_UNPREDICTABLE(output_height < 6) {
      i6 = zero;
    }

    float16x8_t vi0x01234567 = vmovq_n_f16(0);
    float16x8_t vi1x01234567 = vmovq_n_f16(0);
    float16x8_t vi2x01234567 = vmovq_n_f16(0);
    float16x8_t vi3x01234567 = vmovq_n_f16(0);
    float16x8_t vi4x01234567 = vmovq_n_f16(0);
    float16x8_t vi5x01234567 = vmovq_n_f16(0);
    float16x8_t vi6x01234567 = vmovq_n_f16(0);

    float16x8_t vi0x89ABCDEF = vld1q_f16(i0); i0 += 8;
    float16x8_t vi1x89ABCDEF = vld1q_f16(i1); i1 += 8;
    float16x8_t vi2x89ABCDEF = vld1q_f16(i2); i2 += 8;
    float16x8_t vi3x89ABCDEF = vld1q_f16(i3); i3 += 8;
    float16x8_t vi4x89ABCDEF = vld1q_f16(i4); i4 += 8;
    float16x8_t vi5x89ABCDEF = vld1q_f16(i5); i5 += 8;
    float16x8_t vi6x89ABCDEF = vld1q_f16(i6); i6 += 8;

    size_t w = input_width;
    for (; w > 8 * sizeof(__fp16); w -= 8 * sizeof(__fp16)) {
      float16x8_t vo0p0 = vdupq_lane_f16(vget_low_f16(vw01234567), 0);
      float16x8_t vo1p0 = vdupq_lane_f16(vget_low_f16(vw01234567), 0);
      float16x8_t vo2p0 = vdupq_lane_f16(vget_low_f16(vw01234567), 0);
      float16x8_t vo3p0 = vdupq_lane_f16(vget_low_f16(vw01234567), 0);
      float16x8_t vo4p0 = vdupq_lane_f16(vget_low_f16(vw01234567), 0);

      const float16x8_t vi0xGHIJKLMN = vld1q_f16(i0); i0 += 8;
      const float16x8_t vi1xGHIJKLMN = vld1q_f16(i1); i1 += 8;
      const float16x8_t vi2xGHIJKLMN = vld1q_f16(i2); i2 += 8;
      const float16x8_t vi3xGHIJKLMN = vld1q_f16(i3); i3 += 8;
      const float16x8_t vi4xGHIJKLMN = vld1q_f16(i4); i4 += 8;
      const float16x8_t vi5xGHIJKLMN = vld1q_f16(i5); i5 += 8;
      const float16x8_t vi6xGHIJKLMN = vld1q_f16(i6); i6 += 8;

      // Center column
      #if XNN_ARCH_ARM64
        vo0p0 = vfmaq_lane_f16(vo0p0, vi0x89ABCDEF, vget_low_f16(vw01234567), 2);
      #else
        vo0p0 = vmlaq_lane_f16(vo0p0, vi0x89ABCDEF, vget_low_f16(vw01234567), 2);
      #endif
      #if XNN_ARCH_ARM64
        vo1p0 = vfmaq_lane_f16(vo1p0, vi1x89ABCDEF, vget_low_f16(vw01234567), 2);
      #else
        vo1p0 = vmlaq_lane_f16(vo1p0, vi1x89ABCDEF, vget_low_f16(vw01234567), 2);
      #endif
      #if XNN_ARCH_ARM64
        vo2p0 = vfmaq_lane_f16(vo2p0, vi2x89ABCDEF, vget_low_f16(vw01234567), 2);
      #else
        vo2p0 = vmlaq_lane_f16(vo2p0, vi2x89ABCDEF, vget_low_f16(vw01234567), 2);
      #endif
      #if XNN_ARCH_ARM64
        vo3p0 = vfmaq_lane_f16(vo3p0, vi3x89ABCDEF, vget_low_f16(vw01234567), 2);
      #else
        vo3p0 = vmlaq_lane_f16(vo3p0, vi3x89ABCDEF, vget_low_f16(vw01234567), 2);
      #endif
      #if XNN_ARCH_ARM64
        vo4p0 = vfmaq_lane_f16(vo4p0, vi4x89ABCDEF, vget_low_f16(vw01234567), 2);
      #else
        vo4p0 = vmlaq_lane_f16(vo4p0, vi4x89ABCDEF, vget_low_f16(vw01234567), 2);
      #endif
      #if XNN_ARCH_ARM64
        vo0p0 = vfmaq_lane_f16(vo0p0, vi1x89ABCDEF, vget_high_f16(vw01234567), 1);
      #else
        vo0p0 = vmlaq_lane_f16(vo0p0, vi1x89ABCDEF, vget_high_f16(vw01234567), 1);
      #endif
      #if XNN_ARCH_ARM64
        vo1p0 = vfmaq_lane_f16(vo1p0, vi2x89ABCDEF, vget_high_f16(vw01234567), 1);
      #else
        vo1p0 = vmlaq_lane_f16(vo1p0, vi2x89ABCDEF, vget_high_f16(vw01234567), 1);
      #endif
      #if XNN_ARCH_ARM64
        vo2p0 = vfmaq_lane_f16(vo2p0, vi3x89ABCDEF, vget_high_f16(vw01234567), 1);
      #else
        vo2p0 = vmlaq_lane_f16(vo2p0, vi3x89ABCDEF, vget_high_f16(vw01234567), 1);
      #endif
      #if XNN_ARCH_ARM64
        vo3p0 = vfmaq_lane_f16(vo3p0, vi4x89ABCDEF, vget_high_f16(vw01234567), 1);
      #else
        vo3p0 = vmlaq_lane_f16(vo3p0, vi4x89ABCDEF, vget_high_f16(vw01234567), 1);
      #endif
      #if XNN_ARCH_ARM64
        vo4p0 = vfmaq_lane_f16(vo4p0, vi5x89ABCDEF, vget_high_f16(vw01234567), 1);
      #else
        vo4p0 = vmlaq_lane_f16(vo4p0, vi5x89ABCDEF, vget_high_f16(vw01234567), 1);
      #endif
      #if XNN_ARCH_ARM64
        vo0p0 = vfmaq_lane_f16(vo0p0, vi2x89ABCDEF, vw89, 0);
      #else
        vo0p0 = vmlaq_lane_f16(vo0p0, vi2x89ABCDEF, vw89, 0);
      #endif
      #if XNN_ARCH_ARM64
        vo1p0 = vfmaq_lane_f16(vo1p0, vi3x89ABCDEF, vw89, 0);
      #else
        vo1p0 = vmlaq_lane_f16(vo1p0, vi3x89ABCDEF, vw89, 0);
      #endif
      #if XNN_ARCH_ARM64
        vo2p0 = vfmaq_lane_f16(vo2p0, vi4x89ABCDEF, vw89, 0);
      #else
        vo2p0 = vmlaq_lane_f16(vo2p0, vi4x89ABCDEF, vw89, 0);
      #endif
      #if XNN_ARCH_ARM64
        vo3p0 = vfmaq_lane_f16(vo3p0, vi5x89ABCDEF, vw89, 0);
      #else
        vo3p0 = vmlaq_lane_f16(vo3p0, vi5x89ABCDEF, vw89, 0);
      #endif
      #if XNN_ARCH_ARM64
        vo4p0 = vfmaq_lane_f16(vo4p0, vi6x89ABCDEF, vw89, 0);
      #else
        vo4p0 = vmlaq_lane_f16(vo4p0, vi6x89ABCDEF, vw89, 0);
      #endif
      // Left column
      const float16x8_t vi0x789ABCDE = vextq_f16(vi0x01234567, vi0x89ABCDEF, 7);
      const float16x8_t vi1x789ABCDE = vextq_f16(vi1x01234567, vi1x89ABCDEF, 7);
      const float16x8_t vi2x789ABCDE = vextq_f16(vi2x01234567, vi2x89ABCDEF, 7);
      const float16x8_t vi3x789ABCDE = vextq_f16(vi3x01234567, vi3x89ABCDEF, 7);
      const float16x8_t vi4x789ABCDE = vextq_f16(vi4x01234567, vi4x89ABCDEF, 7);
      const float16x8_t vi5x789ABCDE = vextq_f16(vi5x01234567, vi5x89ABCDEF, 7);
      const float16x8_t vi6x789ABCDE = vextq_f16(vi6x01234567, vi6x89ABCDEF, 7);

      #if XNN_ARCH_ARM64
        vo0p0 = vfmaq_lane_f16(vo0p0, vi0x789ABCDE, vget_low_f16(vw01234567), 1);
      #else
        vo0p0 = vmlaq_lane_f16(vo0p0, vi0x789ABCDE, vget_low_f16(vw01234567), 1);
      #endif
      #if XNN_ARCH_ARM64
        vo1p0 = vfmaq_lane_f16(vo1p0, vi1x789ABCDE, vget_low_f16(vw01234567), 1);
      #else
        vo1p0 = vmlaq_lane_f16(vo1p0, vi1x789ABCDE, vget_low_f16(vw01234567), 1);
      #endif
      #if XNN_ARCH_ARM64
        vo2p0 = vfmaq_lane_f16(vo2p0, vi2x789ABCDE, vget_low_f16(vw01234567), 1);
      #else
        vo2p0 = vmlaq_lane_f16(vo2p0, vi2x789ABCDE, vget_low_f16(vw01234567), 1);
      #endif
      #if XNN_ARCH_ARM64
        vo3p0 = vfmaq_lane_f16(vo3p0, vi3x789ABCDE, vget_low_f16(vw01234567), 1);
      #else
        vo3p0 = vmlaq_lane_f16(vo3p0, vi3x789ABCDE, vget_low_f16(vw01234567), 1);
      #endif
      #if XNN_ARCH_ARM64
        vo4p0 = vfmaq_lane_f16(vo4p0, vi4x789ABCDE, vget_low_f16(vw01234567), 1);
      #else
        vo4p0 = vmlaq_lane_f16(vo4p0, vi4x789ABCDE, vget_low_f16(vw01234567), 1);
      #endif
      #if XNN_ARCH_ARM64
        vo0p0 = vfmaq_lane_f16(vo0p0, vi1x789ABCDE, vget_high_f16(vw01234567), 0);
      #else
        vo0p0 = vmlaq_lane_f16(vo0p0, vi1x789ABCDE, vget_high_f16(vw01234567), 0);
      #endif
      #if XNN_ARCH_ARM64
        vo1p0 = vfmaq_lane_f16(vo1p0, vi2x789ABCDE, vget_high_f16(vw01234567), 0);
      #else
        vo1p0 = vmlaq_lane_f16(vo1p0, vi2x789ABCDE, vget_high_f16(vw01234567), 0);
      #endif
      #if XNN_ARCH_ARM64
        vo2p0 = vfmaq_lane_f16(vo2p0, vi3x789ABCDE, vget_high_f16(vw01234567), 0);
      #else
        vo2p0 = vmlaq_lane_f16(vo2p0, vi3x789ABCDE, vget_high_f16(vw01234567), 0);
      #endif
      #if XNN_ARCH_ARM64
        vo3p0 = vfmaq_lane_f16(vo3p0, vi4x789ABCDE, vget_high_f16(vw01234567), 0);
      #else
        vo3p0 = vmlaq_lane_f16(vo3p0, vi4x789ABCDE, vget_high_f16(vw01234567), 0);
      #endif
      #if XNN_ARCH_ARM64
        vo4p0 = vfmaq_lane_f16(vo4p0, vi5x789ABCDE, vget_high_f16(vw01234567), 0);
      #else
        vo4p0 = vmlaq_lane_f16(vo4p0, vi5x789ABCDE, vget_high_f16(vw01234567), 0);
      #endif
      #if XNN_ARCH_ARM64
        vo0p0 = vfmaq_lane_f16(vo0p0, vi2x789ABCDE, vget_high_f16(vw01234567), 3);
      #else
        vo0p0 = vmlaq_lane_f16(vo0p0, vi2x789ABCDE, vget_high_f16(vw01234567), 3);
      #endif
      #if XNN_ARCH_ARM64
        vo1p0 = vfmaq_lane_f16(vo1p0, vi3x789ABCDE, vget_high_f16(vw01234567), 3);
      #else
        vo1p0 = vmlaq_lane_f16(vo1p0, vi3x789ABCDE, vget_high_f16(vw01234567), 3);
      #endif
      #if XNN_ARCH_ARM64
        vo2p0 = vfmaq_lane_f16(vo2p0, vi4x789ABCDE, vget_high_f16(vw01234567), 3);
      #else
        vo2p0 = vmlaq_lane_f16(vo2p0, vi4x789ABCDE, vget_high_f16(vw01234567), 3);
      #endif
      #if XNN_ARCH_ARM64
        vo3p0 = vfmaq_lane_f16(vo3p0, vi5x789ABCDE, vget_high_f16(vw01234567), 3);
      #else
        vo3p0 = vmlaq_lane_f16(vo3p0, vi5x789ABCDE, vget_high_f16(vw01234567), 3);
      #endif
      #if XNN_ARCH_ARM64
        vo4p0 = vfmaq_lane_f16(vo4p0, vi6x789ABCDE, vget_high_f16(vw01234567), 3);
      #else
        vo4p0 = vmlaq_lane_f16(vo4p0, vi6x789ABCDE, vget_high_f16(vw01234567), 3);
      #endif
      vi0x01234567 = vi0x89ABCDEF;
      vi1x01234567 = vi1x89ABCDEF;
      vi2x01234567 = vi2x89ABCDEF;
      vi3x01234567 = vi3x89ABCDEF;
      vi4x01234567 = vi4x89ABCDEF;
      vi5x01234567 = vi5x89ABCDEF;
      vi6x01234567 = vi6x89ABCDEF;

      // Right column
      const float16x8_t vi0x9ABCDEFG = vextq_f16(vi0x89ABCDEF, vi0xGHIJKLMN, 1);
      const float16x8_t vi1x9ABCDEFG = vextq_f16(vi1x89ABCDEF, vi1xGHIJKLMN, 1);
      const float16x8_t vi2x9ABCDEFG = vextq_f16(vi2x89ABCDEF, vi2xGHIJKLMN, 1);
      const float16x8_t vi3x9ABCDEFG = vextq_f16(vi3x89ABCDEF, vi3xGHIJKLMN, 1);
      const float16x8_t vi4x9ABCDEFG = vextq_f16(vi4x89ABCDEF, vi4xGHIJKLMN, 1);
      const float16x8_t vi5x9ABCDEFG = vextq_f16(vi5x89ABCDEF, vi5xGHIJKLMN, 1);
      const float16x8_t vi6x9ABCDEFG = vextq_f16(vi6x89ABCDEF, vi6xGHIJKLMN, 1);

      #if XNN_ARCH_ARM64
        vo0p0 = vfmaq_lane_f16(vo0p0, vi0x9ABCDEFG, vget_low_f16(vw01234567), 3);
      #else
        vo0p0 = vmlaq_lane_f16(vo0p0, vi0x9ABCDEFG, vget_low_f16(vw01234567), 3);
      #endif
      #if XNN_ARCH_ARM64
        vo1p0 = vfmaq_lane_f16(vo1p0, vi1x9ABCDEFG, vget_low_f16(vw01234567), 3);
      #else
        vo1p0 = vmlaq_lane_f16(vo1p0, vi1x9ABCDEFG, vget_low_f16(vw01234567), 3);
      #endif
      #if XNN_ARCH_ARM64
        vo2p0 = vfmaq_lane_f16(vo2p0, vi2x9ABCDEFG, vget_low_f16(vw01234567), 3);
      #else
        vo2p0 = vmlaq_lane_f16(vo2p0, vi2x9ABCDEFG, vget_low_f16(vw01234567), 3);
      #endif
      #if XNN_ARCH_ARM64
        vo3p0 = vfmaq_lane_f16(vo3p0, vi3x9ABCDEFG, vget_low_f16(vw01234567), 3);
      #else
        vo3p0 = vmlaq_lane_f16(vo3p0, vi3x9ABCDEFG, vget_low_f16(vw01234567), 3);
      #endif
      #if XNN_ARCH_ARM64
        vo4p0 = vfmaq_lane_f16(vo4p0, vi4x9ABCDEFG, vget_low_f16(vw01234567), 3);
      #else
        vo4p0 = vmlaq_lane_f16(vo4p0, vi4x9ABCDEFG, vget_low_f16(vw01234567), 3);
      #endif
      #if XNN_ARCH_ARM64
        vo0p0 = vfmaq_lane_f16(vo0p0, vi1x9ABCDEFG, vget_high_f16(vw01234567), 2);
      #else
        vo0p0 = vmlaq_lane_f16(vo0p0, vi1x9ABCDEFG, vget_high_f16(vw01234567), 2);
      #endif
      #if XNN_ARCH_ARM64
        vo1p0 = vfmaq_lane_f16(vo1p0, vi2x9ABCDEFG, vget_high_f16(vw01234567), 2);
      #else
        vo1p0 = vmlaq_lane_f16(vo1p0, vi2x9ABCDEFG, vget_high_f16(vw01234567), 2);
      #endif
      #if XNN_ARCH_ARM64
        vo2p0 = vfmaq_lane_f16(vo2p0, vi3x9ABCDEFG, vget_high_f16(vw01234567), 2);
      #else
        vo2p0 = vmlaq_lane_f16(vo2p0, vi3x9ABCDEFG, vget_high_f16(vw01234567), 2);
      #endif
      #if XNN_ARCH_ARM64
        vo3p0 = vfmaq_lane_f16(vo3p0, vi4x9ABCDEFG, vget_high_f16(vw01234567), 2);
      #else
        vo3p0 = vmlaq_lane_f16(vo3p0, vi4x9ABCDEFG, vget_high_f16(vw01234567), 2);
      #endif
      #if XNN_ARCH_ARM64
        vo4p0 = vfmaq_lane_f16(vo4p0, vi5x9ABCDEFG, vget_high_f16(vw01234567), 2);
      #else
        vo4p0 = vmlaq_lane_f16(vo4p0, vi5x9ABCDEFG, vget_high_f16(vw01234567), 2);
      #endif
      #if XNN_ARCH_ARM64
        vo0p0 = vfmaq_lane_f16(vo0p0, vi2x9ABCDEFG, vw89, 1);
      #else
        vo0p0 = vmlaq_lane_f16(vo0p0, vi2x9ABCDEFG, vw89, 1);
      #endif
      #if XNN_ARCH_ARM64
        vo1p0 = vfmaq_lane_f16(vo1p0, vi3x9ABCDEFG, vw89, 1);
      #else
        vo1p0 = vmlaq_lane_f16(vo1p0, vi3x9ABCDEFG, vw89, 1);
      #endif
      #if XNN_ARCH_ARM64
        vo2p0 = vfmaq_lane_f16(vo2p0, vi4x9ABCDEFG, vw89, 1);
      #else
        vo2p0 = vmlaq_lane_f16(vo2p0, vi4x9ABCDEFG, vw89, 1);
      #endif
      #if XNN_ARCH_ARM64
        vo3p0 = vfmaq_lane_f16(vo3p0, vi5x9ABCDEFG, vw89, 1);
      #else
        vo3p0 = vmlaq_lane_f16(vo3p0, vi5x9ABCDEFG, vw89, 1);
      #endif
      #if XNN_ARCH_ARM64
        vo4p0 = vfmaq_lane_f16(vo4p0, vi6x9ABCDEFG, vw89, 1);
      #else
        vo4p0 = vmlaq_lane_f16(vo4p0, vi6x9ABCDEFG, vw89, 1);
      #endif
      vi0x89ABCDEF = vi0xGHIJKLMN;
      vi1x89ABCDEF = vi1xGHIJKLMN;
      vi2x89ABCDEF = vi2xGHIJKLMN;
      vi3x89ABCDEF = vi3xGHIJKLMN;
      vi4x89ABCDEF = vi4xGHIJKLMN;
      vi5x89ABCDEF = vi5xGHIJKLMN;
      vi6x89ABCDEF = vi6xGHIJKLMN;


      float16x8_t vo0 = vmaxq_f16(vo0p0, vmin);
      float16x8_t vo1 = vmaxq_f16(vo1p0, vmin);
      float16x8_t vo2 = vmaxq_f16(vo2p0, vmin);
      float16x8_t vo3 = vmaxq_f16(vo3p0, vmin);
      float16x8_t vo4 = vmaxq_f16(vo4p0, vmin);

      vo0 = vminq_f16(vo0, vmax);
      vo1 = vminq_f16(vo1, vmax);
      vo2 = vminq_f16(vo2, vmax);
      vo3 = vminq_f16(vo3, vmax);
      vo4 = vminq_f16(vo4, vmax);

      vst1q_f16(o4, vo4); o4 += 8;
      vst1q_f16(o3, vo3); o3 += 8;
      vst1q_f16(o2, vo2); o2 += 8;
      vst1q_f16(o1, vo1); o1 += 8;
      vst1q_f16(o0, vo0); o0 += 8;
    }

    // Always process the last block of 1..8 pixels.
    assert(w >= 1 * sizeof(__fp16));
    assert(w <= 8 * sizeof(__fp16));
    {
      float16x8_t vo0p0 = vdupq_lane_f16(vget_low_f16(vw01234567), 0);
      float16x8_t vo1p0 = vdupq_lane_f16(vget_low_f16(vw01234567), 0);
      float16x8_t vo2p0 = vdupq_lane_f16(vget_low_f16(vw01234567), 0);
      float16x8_t vo3p0 = vdupq_lane_f16(vget_low_f16(vw01234567), 0);
      float16x8_t vo4p0 = vdupq_lane_f16(vget_low_f16(vw01234567), 0);

      vi0x89ABCDEF = vreinterpretq_f16_u16(vandq_u16(vmask, vreinterpretq_u16_f16(vi0x89ABCDEF)));
      vi1x89ABCDEF = vreinterpretq_f16_u16(vandq_u16(vmask, vreinterpretq_u16_f16(vi1x89ABCDEF)));
      vi2x89ABCDEF = vreinterpretq_f16_u16(vandq_u16(vmask, vreinterpretq_u16_f16(vi2x89ABCDEF)));
      vi3x89ABCDEF = vreinterpretq_f16_u16(vandq_u16(vmask, vreinterpretq_u16_f16(vi3x89ABCDEF)));
      vi4x89ABCDEF = vreinterpretq_f16_u16(vandq_u16(vmask, vreinterpretq_u16_f16(vi4x89ABCDEF)));
      vi5x89ABCDEF = vreinterpretq_f16_u16(vandq_u16(vmask, vreinterpretq_u16_f16(vi5x89ABCDEF)));
      vi6x89ABCDEF = vreinterpretq_f16_u16(vandq_u16(vmask, vreinterpretq_u16_f16(vi6x89ABCDEF)));

      // Center column
      #if XNN_ARCH_ARM64
        vo0p0 = vfmaq_lane_f16(vo0p0, vi0x89ABCDEF, vget_low_f16(vw01234567), 2);
      #else
        vo0p0 = vmlaq_lane_f16(vo0p0, vi0x89ABCDEF, vget_low_f16(vw01234567), 2);
      #endif
      #if XNN_ARCH_ARM64
        vo1p0 = vfmaq_lane_f16(vo1p0, vi1x89ABCDEF, vget_low_f16(vw01234567), 2);
      #else
        vo1p0 = vmlaq_lane_f16(vo1p0, vi1x89ABCDEF, vget_low_f16(vw01234567), 2);
      #endif
      #if XNN_ARCH_ARM64
        vo2p0 = vfmaq_lane_f16(vo2p0, vi2x89ABCDEF, vget_low_f16(vw01234567), 2);
      #else
        vo2p0 = vmlaq_lane_f16(vo2p0, vi2x89ABCDEF, vget_low_f16(vw01234567), 2);
      #endif
      #if XNN_ARCH_ARM64
        vo3p0 = vfmaq_lane_f16(vo3p0, vi3x89ABCDEF, vget_low_f16(vw01234567), 2);
      #else
        vo3p0 = vmlaq_lane_f16(vo3p0, vi3x89ABCDEF, vget_low_f16(vw01234567), 2);
      #endif
      #if XNN_ARCH_ARM64
        vo4p0 = vfmaq_lane_f16(vo4p0, vi4x89ABCDEF, vget_low_f16(vw01234567), 2);
      #else
        vo4p0 = vmlaq_lane_f16(vo4p0, vi4x89ABCDEF, vget_low_f16(vw01234567), 2);
      #endif
      #if XNN_ARCH_ARM64
        vo0p0 = vfmaq_lane_f16(vo0p0, vi1x89ABCDEF, vget_high_f16(vw01234567), 1);
      #else
        vo0p0 = vmlaq_lane_f16(vo0p0, vi1x89ABCDEF, vget_high_f16(vw01234567), 1);
      #endif
      #if XNN_ARCH_ARM64
        vo1p0 = vfmaq_lane_f16(vo1p0, vi2x89ABCDEF, vget_high_f16(vw01234567), 1);
      #else
        vo1p0 = vmlaq_lane_f16(vo1p0, vi2x89ABCDEF, vget_high_f16(vw01234567), 1);
      #endif
      #if XNN_ARCH_ARM64
        vo2p0 = vfmaq_lane_f16(vo2p0, vi3x89ABCDEF, vget_high_f16(vw01234567), 1);
      #else
        vo2p0 = vmlaq_lane_f16(vo2p0, vi3x89ABCDEF, vget_high_f16(vw01234567), 1);
      #endif
      #if XNN_ARCH_ARM64
        vo3p0 = vfmaq_lane_f16(vo3p0, vi4x89ABCDEF, vget_high_f16(vw01234567), 1);
      #else
        vo3p0 = vmlaq_lane_f16(vo3p0, vi4x89ABCDEF, vget_high_f16(vw01234567), 1);
      #endif
      #if XNN_ARCH_ARM64
        vo4p0 = vfmaq_lane_f16(vo4p0, vi5x89ABCDEF, vget_high_f16(vw01234567), 1);
      #else
        vo4p0 = vmlaq_lane_f16(vo4p0, vi5x89ABCDEF, vget_high_f16(vw01234567), 1);
      #endif
      #if XNN_ARCH_ARM64
        vo0p0 = vfmaq_lane_f16(vo0p0, vi2x89ABCDEF, vw89, 0);
      #else
        vo0p0 = vmlaq_lane_f16(vo0p0, vi2x89ABCDEF, vw89, 0);
      #endif
      #if XNN_ARCH_ARM64
        vo1p0 = vfmaq_lane_f16(vo1p0, vi3x89ABCDEF, vw89, 0);
      #else
        vo1p0 = vmlaq_lane_f16(vo1p0, vi3x89ABCDEF, vw89, 0);
      #endif
      #if XNN_ARCH_ARM64
        vo2p0 = vfmaq_lane_f16(vo2p0, vi4x89ABCDEF, vw89, 0);
      #else
        vo2p0 = vmlaq_lane_f16(vo2p0, vi4x89ABCDEF, vw89, 0);
      #endif
      #if XNN_ARCH_ARM64
        vo3p0 = vfmaq_lane_f16(vo3p0, vi5x89ABCDEF, vw89, 0);
      #else
        vo3p0 = vmlaq_lane_f16(vo3p0, vi5x89ABCDEF, vw89, 0);
      #endif
      #if XNN_ARCH_ARM64
        vo4p0 = vfmaq_lane_f16(vo4p0, vi6x89ABCDEF, vw89, 0);
      #else
        vo4p0 = vmlaq_lane_f16(vo4p0, vi6x89ABCDEF, vw89, 0);
      #endif
      // Left column
      const float16x8_t vi0x789ABCDE = vextq_f16(vi0x01234567, vi0x89ABCDEF, 7);
      const float16x8_t vi1x789ABCDE = vextq_f16(vi1x01234567, vi1x89ABCDEF, 7);
      const float16x8_t vi2x789ABCDE = vextq_f16(vi2x01234567, vi2x89ABCDEF, 7);
      const float16x8_t vi3x789ABCDE = vextq_f16(vi3x01234567, vi3x89ABCDEF, 7);
      const float16x8_t vi4x789ABCDE = vextq_f16(vi4x01234567, vi4x89ABCDEF, 7);
      const float16x8_t vi5x789ABCDE = vextq_f16(vi5x01234567, vi5x89ABCDEF, 7);
      const float16x8_t vi6x789ABCDE = vextq_f16(vi6x01234567, vi6x89ABCDEF, 7);

      #if XNN_ARCH_ARM64
        vo0p0 = vfmaq_lane_f16(vo0p0, vi0x789ABCDE, vget_low_f16(vw01234567), 1);
      #else
        vo0p0 = vmlaq_lane_f16(vo0p0, vi0x789ABCDE, vget_low_f16(vw01234567), 1);
      #endif
      #if XNN_ARCH_ARM64
        vo1p0 = vfmaq_lane_f16(vo1p0, vi1x789ABCDE, vget_low_f16(vw01234567), 1);
      #else
        vo1p0 = vmlaq_lane_f16(vo1p0, vi1x789ABCDE, vget_low_f16(vw01234567), 1);
      #endif
      #if XNN_ARCH_ARM64
        vo2p0 = vfmaq_lane_f16(vo2p0, vi2x789ABCDE, vget_low_f16(vw01234567), 1);
      #else
        vo2p0 = vmlaq_lane_f16(vo2p0, vi2x789ABCDE, vget_low_f16(vw01234567), 1);
      #endif
      #if XNN_ARCH_ARM64
        vo3p0 = vfmaq_lane_f16(vo3p0, vi3x789ABCDE, vget_low_f16(vw01234567), 1);
      #else
        vo3p0 = vmlaq_lane_f16(vo3p0, vi3x789ABCDE, vget_low_f16(vw01234567), 1);
      #endif
      #if XNN_ARCH_ARM64
        vo4p0 = vfmaq_lane_f16(vo4p0, vi4x789ABCDE, vget_low_f16(vw01234567), 1);
      #else
        vo4p0 = vmlaq_lane_f16(vo4p0, vi4x789ABCDE, vget_low_f16(vw01234567), 1);
      #endif
      #if XNN_ARCH_ARM64
        vo0p0 = vfmaq_lane_f16(vo0p0, vi1x789ABCDE, vget_high_f16(vw01234567), 0);
      #else
        vo0p0 = vmlaq_lane_f16(vo0p0, vi1x789ABCDE, vget_high_f16(vw01234567), 0);
      #endif
      #if XNN_ARCH_ARM64
        vo1p0 = vfmaq_lane_f16(vo1p0, vi2x789ABCDE, vget_high_f16(vw01234567), 0);
      #else
        vo1p0 = vmlaq_lane_f16(vo1p0, vi2x789ABCDE, vget_high_f16(vw01234567), 0);
      #endif
      #if XNN_ARCH_ARM64
        vo2p0 = vfmaq_lane_f16(vo2p0, vi3x789ABCDE, vget_high_f16(vw01234567), 0);
      #else
        vo2p0 = vmlaq_lane_f16(vo2p0, vi3x789ABCDE, vget_high_f16(vw01234567), 0);
      #endif
      #if XNN_ARCH_ARM64
        vo3p0 = vfmaq_lane_f16(vo3p0, vi4x789ABCDE, vget_high_f16(vw01234567), 0);
      #else
        vo3p0 = vmlaq_lane_f16(vo3p0, vi4x789ABCDE, vget_high_f16(vw01234567), 0);
      #endif
      #if XNN_ARCH_ARM64
        vo4p0 = vfmaq_lane_f16(vo4p0, vi5x789ABCDE, vget_high_f16(vw01234567), 0);
      #else
        vo4p0 = vmlaq_lane_f16(vo4p0, vi5x789ABCDE, vget_high_f16(vw01234567), 0);
      #endif
      #if XNN_ARCH_ARM64
        vo0p0 = vfmaq_lane_f16(vo0p0, vi2x789ABCDE, vget_high_f16(vw01234567), 3);
      #else
        vo0p0 = vmlaq_lane_f16(vo0p0, vi2x789ABCDE, vget_high_f16(vw01234567), 3);
      #endif
      #if XNN_ARCH_ARM64
        vo1p0 = vfmaq_lane_f16(vo1p0, vi3x789ABCDE, vget_high_f16(vw01234567), 3);
      #else
        vo1p0 = vmlaq_lane_f16(vo1p0, vi3x789ABCDE, vget_high_f16(vw01234567), 3);
      #endif
      #if XNN_ARCH_ARM64
        vo2p0 = vfmaq_lane_f16(vo2p0, vi4x789ABCDE, vget_high_f16(vw01234567), 3);
      #else
        vo2p0 = vmlaq_lane_f16(vo2p0, vi4x789ABCDE, vget_high_f16(vw01234567), 3);
      #endif
      #if XNN_ARCH_ARM64
        vo3p0 = vfmaq_lane_f16(vo3p0, vi5x789ABCDE, vget_high_f16(vw01234567), 3);
      #else
        vo3p0 = vmlaq_lane_f16(vo3p0, vi5x789ABCDE, vget_high_f16(vw01234567), 3);
      #endif
      #if XNN_ARCH_ARM64
        vo4p0 = vfmaq_lane_f16(vo4p0, vi6x789ABCDE, vget_high_f16(vw01234567), 3);
      #else
        vo4p0 = vmlaq_lane_f16(vo4p0, vi6x789ABCDE, vget_high_f16(vw01234567), 3);
      #endif
      // Right column
      const float16x8_t vzero = vmovq_n_f16(0);
      const float16x8_t vi0x9ABCDEFG = vextq_f16(vi0x89ABCDEF, vzero, 1);
      const float16x8_t vi1x9ABCDEFG = vextq_f16(vi1x89ABCDEF, vzero, 1);
      const float16x8_t vi2x9ABCDEFG = vextq_f16(vi2x89ABCDEF, vzero, 1);
      const float16x8_t vi3x9ABCDEFG = vextq_f16(vi3x89ABCDEF, vzero, 1);
      const float16x8_t vi4x9ABCDEFG = vextq_f16(vi4x89ABCDEF, vzero, 1);
      const float16x8_t vi5x9ABCDEFG = vextq_f16(vi5x89ABCDEF, vzero, 1);
      const float16x8_t vi6x9ABCDEFG = vextq_f16(vi6x89ABCDEF, vzero, 1);

      #if XNN_ARCH_ARM64
        vo0p0 = vfmaq_lane_f16(vo0p0, vi0x9ABCDEFG, vget_low_f16(vw01234567), 3);
      #else
        vo0p0 = vmlaq_lane_f16(vo0p0, vi0x9ABCDEFG, vget_low_f16(vw01234567), 3);
      #endif
      #if XNN_ARCH_ARM64
        vo1p0 = vfmaq_lane_f16(vo1p0, vi1x9ABCDEFG, vget_low_f16(vw01234567), 3);
      #else
        vo1p0 = vmlaq_lane_f16(vo1p0, vi1x9ABCDEFG, vget_low_f16(vw01234567), 3);
      #endif
      #if XNN_ARCH_ARM64
        vo2p0 = vfmaq_lane_f16(vo2p0, vi2x9ABCDEFG, vget_low_f16(vw01234567), 3);
      #else
        vo2p0 = vmlaq_lane_f16(vo2p0, vi2x9ABCDEFG, vget_low_f16(vw01234567), 3);
      #endif
      #if XNN_ARCH_ARM64
        vo3p0 = vfmaq_lane_f16(vo3p0, vi3x9ABCDEFG, vget_low_f16(vw01234567), 3);
      #else
        vo3p0 = vmlaq_lane_f16(vo3p0, vi3x9ABCDEFG, vget_low_f16(vw01234567), 3);
      #endif
      #if XNN_ARCH_ARM64
        vo4p0 = vfmaq_lane_f16(vo4p0, vi4x9ABCDEFG, vget_low_f16(vw01234567), 3);
      #else
        vo4p0 = vmlaq_lane_f16(vo4p0, vi4x9ABCDEFG, vget_low_f16(vw01234567), 3);
      #endif
      #if XNN_ARCH_ARM64
        vo0p0 = vfmaq_lane_f16(vo0p0, vi1x9ABCDEFG, vget_high_f16(vw01234567), 2);
      #else
        vo0p0 = vmlaq_lane_f16(vo0p0, vi1x9ABCDEFG, vget_high_f16(vw01234567), 2);
      #endif
      #if XNN_ARCH_ARM64
        vo1p0 = vfmaq_lane_f16(vo1p0, vi2x9ABCDEFG, vget_high_f16(vw01234567), 2);
      #else
        vo1p0 = vmlaq_lane_f16(vo1p0, vi2x9ABCDEFG, vget_high_f16(vw01234567), 2);
      #endif
      #if XNN_ARCH_ARM64
        vo2p0 = vfmaq_lane_f16(vo2p0, vi3x9ABCDEFG, vget_high_f16(vw01234567), 2);
      #else
        vo2p0 = vmlaq_lane_f16(vo2p0, vi3x9ABCDEFG, vget_high_f16(vw01234567), 2);
      #endif
      #if XNN_ARCH_ARM64
        vo3p0 = vfmaq_lane_f16(vo3p0, vi4x9ABCDEFG, vget_high_f16(vw01234567), 2);
      #else
        vo3p0 = vmlaq_lane_f16(vo3p0, vi4x9ABCDEFG, vget_high_f16(vw01234567), 2);
      #endif
      #if XNN_ARCH_ARM64
        vo4p0 = vfmaq_lane_f16(vo4p0, vi5x9ABCDEFG, vget_high_f16(vw01234567), 2);
      #else
        vo4p0 = vmlaq_lane_f16(vo4p0, vi5x9ABCDEFG, vget_high_f16(vw01234567), 2);
      #endif
      #if XNN_ARCH_ARM64
        vo0p0 = vfmaq_lane_f16(vo0p0, vi2x9ABCDEFG, vw89, 1);
      #else
        vo0p0 = vmlaq_lane_f16(vo0p0, vi2x9ABCDEFG, vw89, 1);
      #endif
      #if XNN_ARCH_ARM64
        vo1p0 = vfmaq_lane_f16(vo1p0, vi3x9ABCDEFG, vw89, 1);
      #else
        vo1p0 = vmlaq_lane_f16(vo1p0, vi3x9ABCDEFG, vw89, 1);
      #endif
      #if XNN_ARCH_ARM64
        vo2p0 = vfmaq_lane_f16(vo2p0, vi4x9ABCDEFG, vw89, 1);
      #else
        vo2p0 = vmlaq_lane_f16(vo2p0, vi4x9ABCDEFG, vw89, 1);
      #endif
      #if XNN_ARCH_ARM64
        vo3p0 = vfmaq_lane_f16(vo3p0, vi5x9ABCDEFG, vw89, 1);
      #else
        vo3p0 = vmlaq_lane_f16(vo3p0, vi5x9ABCDEFG, vw89, 1);
      #endif
      #if XNN_ARCH_ARM64
        vo4p0 = vfmaq_lane_f16(vo4p0, vi6x9ABCDEFG, vw89, 1);
      #else
        vo4p0 = vmlaq_lane_f16(vo4p0, vi6x9ABCDEFG, vw89, 1);
      #endif

      float16x8_t vo0 = vmaxq_f16(vo0p0, vmin);
      float16x8_t vo1 = vmaxq_f16(vo1p0, vmin);
      float16x8_t vo2 = vmaxq_f16(vo2p0, vmin);
      float16x8_t vo3 = vmaxq_f16(vo3p0, vmin);
      float16x8_t vo4 = vmaxq_f16(vo4p0, vmin);

      vo0 = vminq_f16(vo0, vmax);
      vo1 = vminq_f16(vo1, vmax);
      vo2 = vminq_f16(vo2, vmax);
      vo3 = vminq_f16(vo3, vmax);
      vo4 = vminq_f16(vo4, vmax);

      if XNN_LIKELY(w == 8 * sizeof(__fp16)) {
        vst1q_f16(o4, vo4); o4 += 8;
        vst1q_f16(o3, vo3); o3 += 8;
        vst1q_f16(o2, vo2); o2 += 8;
        vst1q_f16(o1, vo1); o1 += 8;
        vst1q_f16(o0, vo0); o0 += 8;
      } else {
        float16x4_t vo4_lo = vget_low_f16(vo4);
        float16x4_t vo3_lo = vget_low_f16(vo3);
        float16x4_t vo2_lo = vget_low_f16(vo2);
        float16x4_t vo1_lo = vget_low_f16(vo1);
        float16x4_t vo0_lo = vget_low_f16(vo0);

        if (w & (4 * sizeof(__fp16))) {
         vst1_f16(o4, vo4_lo); o4 += 4;
         vst1_f16(o3, vo3_lo); o3 += 4;
         vst1_f16(o2, vo2_lo); o2 += 4;
         vst1_f16(o1, vo1_lo); o1 += 4;
         vst1_f16(o0, vo0_lo); o0 += 4;

          vo4_lo = vget_high_f16(vo4);
          vo3_lo = vget_high_f16(vo3);
          vo2_lo = vget_high_f16(vo2);
          vo1_lo = vget_high_f16(vo1);
          vo0_lo = vget_high_f16(vo0);
        }
        if (w & (2 * sizeof(__fp16))) {
          vst1_lane_u32((void*) o4, vreinterpret_u32_f16(vo4_lo), 0); o4 += 2;
          vst1_lane_u32((void*) o3, vreinterpret_u32_f16(vo3_lo), 0); o3 += 2;
          vst1_lane_u32((void*) o2, vreinterpret_u32_f16(vo2_lo), 0); o2 += 2;
          vst1_lane_u32((void*) o1, vreinterpret_u32_f16(vo1_lo), 0); o1 += 2;
          vst1_lane_u32((void*) o0, vreinterpret_u32_f16(vo0_lo), 0); o0 += 2;

          vo0_lo = vext_f16(vo0_lo, vo0_lo, 2);
          vo1_lo = vext_f16(vo1_lo, vo1_lo, 2);
          vo2_lo = vext_f16(vo2_lo, vo2_lo, 2);
          vo3_lo = vext_f16(vo3_lo, vo3_lo, 2);
          vo4_lo = vext_f16(vo4_lo, vo4_lo, 2);
        }
        if (w & (1 * sizeof(__fp16))) {
          vst1_lane_f16(o4, vo4_lo, 0); o4 += 1;
          vst1_lane_f16(o3, vo3_lo, 0); o3 += 1;
          vst1_lane_f16(o2, vo2_lo, 0); o2 += 1;
          vst1_lane_f16(o1, vo1_lo, 0); o1 += 1;
          vst1_lane_f16(o0, vo0_lo, 0); o0 += 1;
        }
      }
    }

    i0 = (const __fp16*) ((uintptr_t) i5 - input_decrement);
    i1 = (const __fp16*) ((uintptr_t) i6 - input_decrement);
    i2 = (const __fp16*) ((uintptr_t) i1 + input_width);
    i3 = (const __fp16*) ((uintptr_t) i2 + input_width);
    i4 = (const __fp16*) ((uintptr_t) i3 + input_width);
    i5 = (const __fp16*) ((uintptr_t) i4 + input_width);
    i6 = (const __fp16*) ((uintptr_t) i5 + input_width);

    o0 = o4;
    o1 = (__fp16*) ((uintptr_t) o0 + input_width);
    o2 = (__fp16*) ((uintptr_t) o1 + input_width);
    o3 = (__fp16*) ((uintptr_t) o2 + input_width);
    o4 = (__fp16*) ((uintptr_t) o3 + input_width);

    output_height = doz(output_height, 5);
  } while (output_height != 0);
}
