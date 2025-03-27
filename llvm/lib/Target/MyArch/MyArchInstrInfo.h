#ifndef LLVM_LIB_TARGET_MYARCH_MYARCHINSTRINFO_H
#define LLVM_LIB_TARGET_MYARCH_MYARCHINSTRINFO_H

#include "MCTargetDesc/MyArchInfo.h"
#include "MyArchRegisterInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "MyArchGenInstrInfo.inc"

namespace llvm {

class MyArchSubtarget;

class MyArchInstrInfo : public MyArchGenInstrInfo {
public:
  MyArchInstrInfo();
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_MYARCH_MYARCHINSTRINFO_H
