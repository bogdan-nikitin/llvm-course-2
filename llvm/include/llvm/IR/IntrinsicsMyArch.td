let TargetPrefix = "myarch" in {
  
  def int_myarch_putpixel:
    Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;
  
  def int_myarch_flush:
    Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;

  def int_myarch_rand:
    Intrinsic<[llvm_i32_ty], [], [IntrNoMem, IntrHasSideEffects]>;
  
  } // TargetPrefix = "myarch"
