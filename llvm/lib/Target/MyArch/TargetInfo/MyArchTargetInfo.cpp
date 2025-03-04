#include "TargetInfo/MyArchTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
using namespace llvm;

Target &llvm::getTheMyArchTarget() {
  static Target TheMyArchTarget;
  return TheMyArchTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeMyArchTargetInfo() {
  RegisterTarget<Triple::myarch> X(getTheMyArchTarget(), "myarch", "MyArch 32",
                                   "MYARCH");
}
