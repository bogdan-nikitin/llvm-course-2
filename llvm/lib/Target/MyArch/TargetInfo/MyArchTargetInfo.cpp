#include "TargetInfo/MyArchTargetInfo.h"
#include "MyArch.h"
#include "llvm/MC/TargetRegistry.h"
using namespace llvm;

Target &llvm::getTheMyArchTarget() {
  MYARCH_DUMP_YELLOW
  static Target TheMyArchTarget;
  return TheMyArchTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeMyArchTargetInfo() {
  MYARCH_DUMP_YELLOW
  RegisterTarget<Triple::myarch> X(getTheMyArchTarget(), "myarch", "MyArch 32",
                                   "MYARCH");
}
