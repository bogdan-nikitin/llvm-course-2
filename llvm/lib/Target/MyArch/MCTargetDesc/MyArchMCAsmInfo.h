#ifndef LLVM_LIB_TARGET_MYARCH_MCTARGETDESC_MYARCHMCASMINFO_H
#define LLVM_LIB_TARGET_MYARCH_MCTARGETDESC_MYARCHMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class MyArchELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit MyArchELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_MYARCH_MCTARGETDESC_MYARCHMCASMINFO_H
