
# qhasm: int64 a

# qhasm: int64 b

# qhasm: int6464 control

# qhasm: input a

# qhasm: input b

# qhasm: input control

# qhasm: int6464 d0

# qhasm: int6464 a0

# qhasm: int6464 b0

# qhasm: int6464 d1

# qhasm: int6464 a1

# qhasm: int6464 b1

# qhasm: int6464 d2

# qhasm: int6464 a2

# qhasm: int6464 b2

# qhasm: int6464 d3

# qhasm: int6464 a3

# qhasm: int6464 b3

# qhasm: int64 i

# qhasm: enter _Z15conditionalswapR12fieldelementS0_3vec
.text
.p2align 5
.globl __Z15conditionalswapR12fieldelementS0_3vec
.globl _Z15conditionalswapR12fieldelementS0_3vec
__Z15conditionalswapR12fieldelementS0_3vec:
_Z15conditionalswapR12fieldelementS0_3vec:
mov %rsp,%r11
and $31,%r11
add $0,%r11
sub %r11,%rsp

# qhasm: i = 0
# asm 1: mov  $0,>i=int64#3
# asm 2: mov  $0,>i=%rdx
mov  $0,%rdx

# qhasm: mainloop:
._mainloop:

# qhasm: a0 = *(int128 *) (a + i)
# asm 1: movaps (<a=int64#1,<i=int64#3),>a0=int6464#2
# asm 2: movaps (<a=%rdi,<i=%rdx),>a0=%xmm1
movaps (%rdi,%rdx),%xmm1

# qhasm: a1 = *(int128 *) (a + i + 16)
# asm 1: movaps 16(<a=int64#1,<i=int64#3),>a1=int6464#3
# asm 2: movaps 16(<a=%rdi,<i=%rdx),>a1=%xmm2
movaps 16(%rdi,%rdx),%xmm2

# qhasm: a2 = *(int128 *) (a + i + 32)
# asm 1: movaps 32(<a=int64#1,<i=int64#3),>a2=int6464#4
# asm 2: movaps 32(<a=%rdi,<i=%rdx),>a2=%xmm3
movaps 32(%rdi,%rdx),%xmm3

# qhasm: a3 = *(int128 *) (a + i + 48)
# asm 1: movaps 48(<a=int64#1,<i=int64#3),>a3=int6464#5
# asm 2: movaps 48(<a=%rdi,<i=%rdx),>a3=%xmm4
movaps 48(%rdi,%rdx),%xmm4

# qhasm: b0 = *(int128 *) (b + i)
# asm 1: movaps (<b=int64#2,<i=int64#3),>b0=int6464#6
# asm 2: movaps (<b=%rsi,<i=%rdx),>b0=%xmm5
movaps (%rsi,%rdx),%xmm5

# qhasm: b1 = *(int128 *) (b + i + 16)
# asm 1: movaps 16(<b=int64#2,<i=int64#3),>b1=int6464#7
# asm 2: movaps 16(<b=%rsi,<i=%rdx),>b1=%xmm6
movaps 16(%rsi,%rdx),%xmm6

# qhasm: b2 = *(int128 *) (b + i + 32)
# asm 1: movaps 32(<b=int64#2,<i=int64#3),>b2=int6464#8
# asm 2: movaps 32(<b=%rsi,<i=%rdx),>b2=%xmm7
movaps 32(%rsi,%rdx),%xmm7

# qhasm: b3 = *(int128 *) (b + i + 48)
# asm 1: movaps 48(<b=int64#2,<i=int64#3),>b3=int6464#9
# asm 2: movaps 48(<b=%rsi,<i=%rdx),>b3=%xmm8
movaps 48(%rsi,%rdx),%xmm8

# qhasm: d0 = a0
# asm 1: movaps <a0=int6464#2,>d0=int6464#10
# asm 2: movaps <a0=%xmm1,>d0=%xmm9
movaps %xmm1,%xmm9

# qhasm: d1 = a1
# asm 1: movaps <a1=int6464#3,>d1=int6464#11
# asm 2: movaps <a1=%xmm2,>d1=%xmm10
movaps %xmm2,%xmm10

# qhasm: d2 = a2
# asm 1: movaps <a2=int6464#4,>d2=int6464#12
# asm 2: movaps <a2=%xmm3,>d2=%xmm11
movaps %xmm3,%xmm11

# qhasm: d3 = a3
# asm 1: movaps <a3=int6464#5,>d3=int6464#13
# asm 2: movaps <a3=%xmm4,>d3=%xmm12
movaps %xmm4,%xmm12

# qhasm: d0 ^= b0
# asm 1: xorps  <b0=int6464#6,<d0=int6464#10
# asm 2: xorps  <b0=%xmm5,<d0=%xmm9
xorps  %xmm5,%xmm9

# qhasm: d1 ^= b1
# asm 1: xorps  <b1=int6464#7,<d1=int6464#11
# asm 2: xorps  <b1=%xmm6,<d1=%xmm10
xorps  %xmm6,%xmm10

# qhasm: d2 ^= b2
# asm 1: xorps  <b2=int6464#8,<d2=int6464#12
# asm 2: xorps  <b2=%xmm7,<d2=%xmm11
xorps  %xmm7,%xmm11

# qhasm: d3 ^= b3
# asm 1: xorps  <b3=int6464#9,<d3=int6464#13
# asm 2: xorps  <b3=%xmm8,<d3=%xmm12
xorps  %xmm8,%xmm12

# qhasm: d0 &= control
# asm 1: andps  <control=int6464#1,<d0=int6464#10
# asm 2: andps  <control=%xmm0,<d0=%xmm9
andps  %xmm0,%xmm9

# qhasm: d1 &= control
# asm 1: andps  <control=int6464#1,<d1=int6464#11
# asm 2: andps  <control=%xmm0,<d1=%xmm10
andps  %xmm0,%xmm10

# qhasm: d2 &= control
# asm 1: andps  <control=int6464#1,<d2=int6464#12
# asm 2: andps  <control=%xmm0,<d2=%xmm11
andps  %xmm0,%xmm11

# qhasm: d3 &= control
# asm 1: andps  <control=int6464#1,<d3=int6464#13
# asm 2: andps  <control=%xmm0,<d3=%xmm12
andps  %xmm0,%xmm12

# qhasm: a0 ^= d0
# asm 1: xorps  <d0=int6464#10,<a0=int6464#2
# asm 2: xorps  <d0=%xmm9,<a0=%xmm1
xorps  %xmm9,%xmm1

# qhasm: a1 ^= d1
# asm 1: xorps  <d1=int6464#11,<a1=int6464#3
# asm 2: xorps  <d1=%xmm10,<a1=%xmm2
xorps  %xmm10,%xmm2

# qhasm: a2 ^= d2
# asm 1: xorps  <d2=int6464#12,<a2=int6464#4
# asm 2: xorps  <d2=%xmm11,<a2=%xmm3
xorps  %xmm11,%xmm3

# qhasm: a3 ^= d3
# asm 1: xorps  <d3=int6464#13,<a3=int6464#5
# asm 2: xorps  <d3=%xmm12,<a3=%xmm4
xorps  %xmm12,%xmm4

# qhasm: b0 ^= d0
# asm 1: xorps  <d0=int6464#10,<b0=int6464#6
# asm 2: xorps  <d0=%xmm9,<b0=%xmm5
xorps  %xmm9,%xmm5

# qhasm: b1 ^= d1
# asm 1: xorps  <d1=int6464#11,<b1=int6464#7
# asm 2: xorps  <d1=%xmm10,<b1=%xmm6
xorps  %xmm10,%xmm6

# qhasm: b2 ^= d2
# asm 1: xorps  <d2=int6464#12,<b2=int6464#8
# asm 2: xorps  <d2=%xmm11,<b2=%xmm7
xorps  %xmm11,%xmm7

# qhasm: b3 ^= d3
# asm 1: xorps  <d3=int6464#13,<b3=int6464#9
# asm 2: xorps  <d3=%xmm12,<b3=%xmm8
xorps  %xmm12,%xmm8

# qhasm: *(int128 *) (a + i) = a0
# asm 1: movaps <a0=int6464#2,(<a=int64#1,<i=int64#3)
# asm 2: movaps <a0=%xmm1,(<a=%rdi,<i=%rdx)
movaps %xmm1,(%rdi,%rdx)

# qhasm: *(int128 *) (a + i + 16) = a1
# asm 1: movaps <a1=int6464#3,16(<a=int64#1,<i=int64#3)
# asm 2: movaps <a1=%xmm2,16(<a=%rdi,<i=%rdx)
movaps %xmm2,16(%rdi,%rdx)

# qhasm: *(int128 *) (a + i + 32) = a2
# asm 1: movaps <a2=int6464#4,32(<a=int64#1,<i=int64#3)
# asm 2: movaps <a2=%xmm3,32(<a=%rdi,<i=%rdx)
movaps %xmm3,32(%rdi,%rdx)

# qhasm: *(int128 *) (a + i + 48) = a3
# asm 1: movaps <a3=int6464#5,48(<a=int64#1,<i=int64#3)
# asm 2: movaps <a3=%xmm4,48(<a=%rdi,<i=%rdx)
movaps %xmm4,48(%rdi,%rdx)

# qhasm: *(int128 *) (b + i) = b0
# asm 1: movaps <b0=int6464#6,(<b=int64#2,<i=int64#3)
# asm 2: movaps <b0=%xmm5,(<b=%rsi,<i=%rdx)
movaps %xmm5,(%rsi,%rdx)

# qhasm: *(int128 *) (b + i + 16) = b1
# asm 1: movaps <b1=int6464#7,16(<b=int64#2,<i=int64#3)
# asm 2: movaps <b1=%xmm6,16(<b=%rsi,<i=%rdx)
movaps %xmm6,16(%rsi,%rdx)

# qhasm: *(int128 *) (b + i + 32) = b2
# asm 1: movaps <b2=int6464#8,32(<b=int64#2,<i=int64#3)
# asm 2: movaps <b2=%xmm7,32(<b=%rsi,<i=%rdx)
movaps %xmm7,32(%rsi,%rdx)

# qhasm: *(int128 *) (b + i + 48) = b3
# asm 1: movaps <b3=int6464#9,48(<b=int64#2,<i=int64#3)
# asm 2: movaps <b3=%xmm8,48(<b=%rsi,<i=%rdx)
movaps %xmm8,48(%rsi,%rdx)

# qhasm: i = i + 64
# asm 1: lea  64(<i=int64#3),>i=int64#3
# asm 2: lea  64(<i=%rdx),>i=%rdx
lea  64(%rdx),%rdx

# qhasm:                  signed<? i - 3968
# asm 1: cmp  $3968,<i=int64#3
# asm 2: cmp  $3968,<i=%rdx
cmp  $3968,%rdx
# comment:fp stack unchanged by jump

# qhasm: goto mainloop if signed<
jl ._mainloop

# qhasm: a0 = *(int128 *) (a + i)
# asm 1: movaps (<a=int64#1,<i=int64#3),>a0=int6464#2
# asm 2: movaps (<a=%rdi,<i=%rdx),>a0=%xmm1
movaps (%rdi,%rdx),%xmm1

# qhasm: a1 = *(int128 *) (a + i + 16)
# asm 1: movaps 16(<a=int64#1,<i=int64#3),>a1=int6464#3
# asm 2: movaps 16(<a=%rdi,<i=%rdx),>a1=%xmm2
movaps 16(%rdi,%rdx),%xmm2

# qhasm: a2 = *(int128 *) (a + i + 32)
# asm 1: movaps 32(<a=int64#1,<i=int64#3),>a2=int6464#4
# asm 2: movaps 32(<a=%rdi,<i=%rdx),>a2=%xmm3
movaps 32(%rdi,%rdx),%xmm3

# qhasm: b0 = *(int128 *) (b + i)
# asm 1: movaps (<b=int64#2,<i=int64#3),>b0=int6464#5
# asm 2: movaps (<b=%rsi,<i=%rdx),>b0=%xmm4
movaps (%rsi,%rdx),%xmm4

# qhasm: b1 = *(int128 *) (b + i + 16)
# asm 1: movaps 16(<b=int64#2,<i=int64#3),>b1=int6464#6
# asm 2: movaps 16(<b=%rsi,<i=%rdx),>b1=%xmm5
movaps 16(%rsi,%rdx),%xmm5

# qhasm: b2 = *(int128 *) (b + i + 32)
# asm 1: movaps 32(<b=int64#2,<i=int64#3),>b2=int6464#7
# asm 2: movaps 32(<b=%rsi,<i=%rdx),>b2=%xmm6
movaps 32(%rsi,%rdx),%xmm6

# qhasm: d0 = a0
# asm 1: movaps <a0=int6464#2,>d0=int6464#8
# asm 2: movaps <a0=%xmm1,>d0=%xmm7
movaps %xmm1,%xmm7

# qhasm: d1 = a1
# asm 1: movaps <a1=int6464#3,>d1=int6464#9
# asm 2: movaps <a1=%xmm2,>d1=%xmm8
movaps %xmm2,%xmm8

# qhasm: d2 = a2
# asm 1: movaps <a2=int6464#4,>d2=int6464#10
# asm 2: movaps <a2=%xmm3,>d2=%xmm9
movaps %xmm3,%xmm9

# qhasm: d0 ^= b0
# asm 1: xorps  <b0=int6464#5,<d0=int6464#8
# asm 2: xorps  <b0=%xmm4,<d0=%xmm7
xorps  %xmm4,%xmm7

# qhasm: d1 ^= b1
# asm 1: xorps  <b1=int6464#6,<d1=int6464#9
# asm 2: xorps  <b1=%xmm5,<d1=%xmm8
xorps  %xmm5,%xmm8

# qhasm: d2 ^= b2
# asm 1: xorps  <b2=int6464#7,<d2=int6464#10
# asm 2: xorps  <b2=%xmm6,<d2=%xmm9
xorps  %xmm6,%xmm9

# qhasm: d0 &= control
# asm 1: andps  <control=int6464#1,<d0=int6464#8
# asm 2: andps  <control=%xmm0,<d0=%xmm7
andps  %xmm0,%xmm7

# qhasm: d1 &= control
# asm 1: andps  <control=int6464#1,<d1=int6464#9
# asm 2: andps  <control=%xmm0,<d1=%xmm8
andps  %xmm0,%xmm8

# qhasm: d2 &= control
# asm 1: andps  <control=int6464#1,<d2=int6464#10
# asm 2: andps  <control=%xmm0,<d2=%xmm9
andps  %xmm0,%xmm9

# qhasm: a0 ^= d0
# asm 1: xorps  <d0=int6464#8,<a0=int6464#2
# asm 2: xorps  <d0=%xmm7,<a0=%xmm1
xorps  %xmm7,%xmm1

# qhasm: a1 ^= d1
# asm 1: xorps  <d1=int6464#9,<a1=int6464#3
# asm 2: xorps  <d1=%xmm8,<a1=%xmm2
xorps  %xmm8,%xmm2

# qhasm: a2 ^= d2
# asm 1: xorps  <d2=int6464#10,<a2=int6464#4
# asm 2: xorps  <d2=%xmm9,<a2=%xmm3
xorps  %xmm9,%xmm3

# qhasm: b0 ^= d0
# asm 1: xorps  <d0=int6464#8,<b0=int6464#5
# asm 2: xorps  <d0=%xmm7,<b0=%xmm4
xorps  %xmm7,%xmm4

# qhasm: b1 ^= d1
# asm 1: xorps  <d1=int6464#9,<b1=int6464#6
# asm 2: xorps  <d1=%xmm8,<b1=%xmm5
xorps  %xmm8,%xmm5

# qhasm: b2 ^= d2
# asm 1: xorps  <d2=int6464#10,<b2=int6464#7
# asm 2: xorps  <d2=%xmm9,<b2=%xmm6
xorps  %xmm9,%xmm6

# qhasm: *(int128 *) (a + i) = a0
# asm 1: movaps <a0=int6464#2,(<a=int64#1,<i=int64#3)
# asm 2: movaps <a0=%xmm1,(<a=%rdi,<i=%rdx)
movaps %xmm1,(%rdi,%rdx)

# qhasm: *(int128 *) (a + i + 16) = a1
# asm 1: movaps <a1=int6464#3,16(<a=int64#1,<i=int64#3)
# asm 2: movaps <a1=%xmm2,16(<a=%rdi,<i=%rdx)
movaps %xmm2,16(%rdi,%rdx)

# qhasm: *(int128 *) (a + i + 32) = a2
# asm 1: movaps <a2=int6464#4,32(<a=int64#1,<i=int64#3)
# asm 2: movaps <a2=%xmm3,32(<a=%rdi,<i=%rdx)
movaps %xmm3,32(%rdi,%rdx)

# qhasm: *(int128 *) (b + i) = b0
# asm 1: movaps <b0=int6464#5,(<b=int64#2,<i=int64#3)
# asm 2: movaps <b0=%xmm4,(<b=%rsi,<i=%rdx)
movaps %xmm4,(%rsi,%rdx)

# qhasm: *(int128 *) (b + i + 16) = b1
# asm 1: movaps <b1=int6464#6,16(<b=int64#2,<i=int64#3)
# asm 2: movaps <b1=%xmm5,16(<b=%rsi,<i=%rdx)
movaps %xmm5,16(%rsi,%rdx)

# qhasm: *(int128 *) (b + i + 32) = b2
# asm 1: movaps <b2=int6464#7,32(<b=int64#2,<i=int64#3)
# asm 2: movaps <b2=%xmm6,32(<b=%rsi,<i=%rdx)
movaps %xmm6,32(%rsi,%rdx)

# qhasm: leave
add %r11,%rsp
xor %rax,%rax
xor %rdx,%rdx
ret
