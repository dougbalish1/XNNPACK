#!/bin/sh
# Copyright 2023 Google LLC
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.

################################# ARM NEONFP16 ################################
tools/xngen src/f16-f32acc-rsum/neonfp16.c.in -D BATCH_TILE=4  -D ACCUMULATORS=1 -o src/f16-f32acc-rsum/gen/f16-f32acc-rsum-neonfp16-x4.c &
tools/xngen src/f16-f32acc-rsum/neonfp16.c.in -D BATCH_TILE=8  -D ACCUMULATORS=1 -o src/f16-f32acc-rsum/gen/f16-f32acc-rsum-neonfp16-x8.c &
tools/xngen src/f16-f32acc-rsum/neonfp16.c.in -D BATCH_TILE=16 -D ACCUMULATORS=2 -o src/f16-f32acc-rsum/gen/f16-f32acc-rsum-neonfp16-x16-acc2.c &
tools/xngen src/f16-f32acc-rsum/neonfp16.c.in -D BATCH_TILE=24 -D ACCUMULATORS=3 -o src/f16-f32acc-rsum/gen/f16-f32acc-rsum-neonfp16-x24-acc3.c &
tools/xngen src/f16-f32acc-rsum/neonfp16.c.in -D BATCH_TILE=32 -D ACCUMULATORS=2 -o src/f16-f32acc-rsum/gen/f16-f32acc-rsum-neonfp16-x32-acc2.c &
tools/xngen src/f16-f32acc-rsum/neonfp16.c.in -D BATCH_TILE=32 -D ACCUMULATORS=4 -o src/f16-f32acc-rsum/gen/f16-f32acc-rsum-neonfp16-x32-acc4.c &

################################### x86 F16C ##################################
tools/xngen src/f16-f32acc-rsum/f16c.c.in -D BATCH_TILE=8  -D ACCUMULATORS=1 -o src/f16-f32acc-rsum/gen/f16-f32acc-rsum-f16c-x8.c &
tools/xngen src/f16-f32acc-rsum/f16c.c.in -D BATCH_TILE=16 -D ACCUMULATORS=2 -o src/f16-f32acc-rsum/gen/f16-f32acc-rsum-f16c-x16-acc2.c &
tools/xngen src/f16-f32acc-rsum/f16c.c.in -D BATCH_TILE=24 -D ACCUMULATORS=3 -o src/f16-f32acc-rsum/gen/f16-f32acc-rsum-f16c-x24-acc3.c &
tools/xngen src/f16-f32acc-rsum/f16c.c.in -D BATCH_TILE=32 -D ACCUMULATORS=2 -o src/f16-f32acc-rsum/gen/f16-f32acc-rsum-f16c-x32-acc2.c &
tools/xngen src/f16-f32acc-rsum/f16c.c.in -D BATCH_TILE=32 -D ACCUMULATORS=4 -o src/f16-f32acc-rsum/gen/f16-f32acc-rsum-f16c-x32-acc4.c &

################################## Unit tests #################################
tools/generate-reduce-test.py --tester RSumMicrokernelTester --spec test/f16-f32acc-rsum.yaml --output test/f16-f32acc-rsum.cc &

wait
