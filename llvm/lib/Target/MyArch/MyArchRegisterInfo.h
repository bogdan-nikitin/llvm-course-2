#ifndef LLVM_LIB_TARGET_MYARCH_MYARCHREGISTERINFO_H
#define LLVM_LIB_TARGET_MYARCH_MYARCHREGISTERINFO_H

#define GET_REGINFO_HEADER
#include "MyArchGenRegisterInfo.inc"

namespace llvm {

struct MyArchRegisterInfo : public MyArchGenRegisterInfo {
public:
  MyArchRegisterInfo();
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_MYARCH_MYARCHREGISTERINFO_H
