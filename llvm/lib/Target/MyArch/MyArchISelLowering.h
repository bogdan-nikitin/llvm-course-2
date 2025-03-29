#ifndef LLVM_LIB_TARGET_MYARCH_MYARCHISELLOWERING_H
#define LLVM_LIB_TARGET_MYARCH_MYARCHISELLOWERING_H

#include "MyArch.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class MyArchSubtarget;
class MyArchTargetMachine;

namespace MyArchISD {

enum NodeType : unsigned {
  // Start the numbering where the builtin ops and target ops leave off.
  FIRST_NUMBER = ISD::BUILTIN_OP_END,
  RET,
  CALL,
  BR_CC,
};

} // namespace MyArchISD

} // end namespace llvm

#endif // LLVM_LIB_TARGET_MYARCH_MYARCHISELLOWERING_H
