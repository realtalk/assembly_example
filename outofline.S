.globl call_outofline_asm_add
.globl call_outofline_asm_rdtsc

call_outofline_asm_add:
  pushq %rbp
  movq  %rsp, %rbp

  addq %rsi, %rdi
  movq %rdi, %rax

  leaveq
  retq

call_outofline_asm_rdtsc:
  pushq %rbp
  movq  %rsp, %rbp

  movq  $0, %rax
  movq  $0, %rdx

  rdtsc

  shlq $32, %rdx
  orq  %rdx, %rax

  leaveq
  retq
