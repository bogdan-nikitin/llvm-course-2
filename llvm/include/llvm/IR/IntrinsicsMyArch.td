let TargetPrefix = "myarch" in {
  
  def int_myarch_putpixel: ClangBuiltin<"simPutPixel">,
    Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;
  
  def int_myarch_flush: ClangBuiltin<"simFlush">,
    Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;

  def int_myarch_rand: ClangBuiltin<"simRand">,
    Intrinsic<[llvm_i32_ty], [], [IntrNoMem, IntrHasSideEffects]>;
  
  } // TargetPrefix = "myarch"
