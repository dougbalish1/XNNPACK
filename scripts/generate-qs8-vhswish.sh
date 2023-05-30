#!/bin/sh
# Copyright 2023 Google LLC
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.

################################## ARM NEON ###################################
tools/xngen src/qs8-vhswish/neon.c.in -D BATCH_TILE=8  -D DATATYPE=QS8 -o src/qs8-vhswish/gen/qs8-vhswish-neon-x8.c &
tools/xngen src/qs8-vhswish/neon.c.in -D BATCH_TILE=16 -D DATATYPE=QS8 -o src/qs8-vhswish/gen/qs8-vhswish-neon-x16.c &
tools/xngen src/qs8-vhswish/neon.c.in -D BATCH_TILE=32 -D DATATYPE=QS8 -o src/qs8-vhswish/gen/qs8-vhswish-neon-x32.c &

tools/xngen src/qs8-vhswish/neon.c.in -D BATCH_TILE=8  -D DATATYPE=QU8 -o src/qu8-vhswish/gen/qu8-vhswish-neon-x8.c &
tools/xngen src/qs8-vhswish/neon.c.in -D BATCH_TILE=16 -D DATATYPE=QU8 -o src/qu8-vhswish/gen/qu8-vhswish-neon-x16.c &
tools/xngen src/qs8-vhswish/neon.c.in -D BATCH_TILE=32 -D DATATYPE=QU8 -o src/qu8-vhswish/gen/qu8-vhswish-neon-x32.c &

################################### x86 SSE2 ##################################
tools/xngen src/qs8-vhswish/sse2.c.in -D BATCH_TILE=16 -D DATATYPE=QS8 -o src/qs8-vhswish/gen/qs8-vhswish-sse2-x16.c &
tools/xngen src/qs8-vhswish/sse2.c.in -D BATCH_TILE=32 -D DATATYPE=QS8 -o src/qs8-vhswish/gen/qs8-vhswish-sse2-x32.c &

tools/xngen src/qs8-vhswish/sse2.c.in -D BATCH_TILE=16 -D DATATYPE=QU8 -o src/qu8-vhswish/gen/qu8-vhswish-sse2-x16.c &
tools/xngen src/qs8-vhswish/sse2.c.in -D BATCH_TILE=32 -D DATATYPE=QU8 -o src/qu8-vhswish/gen/qu8-vhswish-sse2-x32.c &

################################## x86 SSSE3 ##################################
tools/xngen src/qs8-vhswish/ssse3.c.in -D BATCH_TILE=16 -D DATATYPE=QS8 -o src/qs8-vhswish/gen/qs8-vhswish-ssse3-x16.c &
tools/xngen src/qs8-vhswish/ssse3.c.in -D BATCH_TILE=32 -D DATATYPE=QS8 -o src/qs8-vhswish/gen/qs8-vhswish-ssse3-x32.c &

tools/xngen src/qs8-vhswish/ssse3.c.in -D BATCH_TILE=16 -D DATATYPE=QU8 -o src/qu8-vhswish/gen/qu8-vhswish-ssse3-x16.c &
tools/xngen src/qs8-vhswish/ssse3.c.in -D BATCH_TILE=32 -D DATATYPE=QU8 -o src/qu8-vhswish/gen/qu8-vhswish-ssse3-x32.c &

################################## x86 SSE4.1 #################################
tools/xngen src/qs8-vhswish/sse4.c.in -D BATCH_TILE=8  -D DATATYPE=QS8 -D AVX=0 -o src/qs8-vhswish/gen/qs8-vhswish-sse41-x8.c &
tools/xngen src/qs8-vhswish/sse4.c.in -D BATCH_TILE=16 -D DATATYPE=QS8 -D AVX=0 -o src/qs8-vhswish/gen/qs8-vhswish-sse41-x16.c &
tools/xngen src/qs8-vhswish/sse4.c.in -D BATCH_TILE=32 -D DATATYPE=QS8 -D AVX=0 -o src/qs8-vhswish/gen/qs8-vhswish-sse41-x32.c &

tools/xngen src/qs8-vhswish/sse4.c.in -D BATCH_TILE=8  -D DATATYPE=QU8 -D AVX=0 -o src/qu8-vhswish/gen/qu8-vhswish-sse41-x8.c &
tools/xngen src/qs8-vhswish/sse4.c.in -D BATCH_TILE=16 -D DATATYPE=QU8 -D AVX=0 -o src/qu8-vhswish/gen/qu8-vhswish-sse41-x16.c &
tools/xngen src/qs8-vhswish/sse4.c.in -D BATCH_TILE=32 -D DATATYPE=QU8 -D AVX=0 -o src/qu8-vhswish/gen/qu8-vhswish-sse41-x32.c &

#################################### Scalar ###################################
tools/xngen src/qs8-vhswish/scalar.c.in -D BATCH_TILE=1 -D DATATYPE=QS8 -o src/qs8-vhswish/gen/qs8-vhswish-scalar-x1.c &
tools/xngen src/qs8-vhswish/scalar.c.in -D BATCH_TILE=2 -D DATATYPE=QS8 -o src/qs8-vhswish/gen/qs8-vhswish-scalar-x2.c &
tools/xngen src/qs8-vhswish/scalar.c.in -D BATCH_TILE=4 -D DATATYPE=QS8 -o src/qs8-vhswish/gen/qs8-vhswish-scalar-x4.c &

tools/xngen src/qs8-vhswish/scalar.c.in -D BATCH_TILE=1 -D DATATYPE=QU8 -o src/qu8-vhswish/gen/qu8-vhswish-scalar-x1.c &
tools/xngen src/qs8-vhswish/scalar.c.in -D BATCH_TILE=2 -D DATATYPE=QU8 -o src/qu8-vhswish/gen/qu8-vhswish-scalar-x2.c &
tools/xngen src/qs8-vhswish/scalar.c.in -D BATCH_TILE=4 -D DATATYPE=QU8 -o src/qu8-vhswish/gen/qu8-vhswish-scalar-x4.c &

################################## Unit tests #################################
tools/generate-vhswish-test.py --spec test/qs8-vhswish.yaml --output test/qs8-vhswish.cc &
tools/generate-vhswish-test.py --spec test/qu8-vhswish.yaml --output test/qu8-vhswish.cc &

wait