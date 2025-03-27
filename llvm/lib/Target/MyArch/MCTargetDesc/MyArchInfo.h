#ifndef LLVM_LIB_TARGET_MYARCH_MCTARGETDESC_MYARCHINFO_H
#define LLVM_LIB_TARGET_MYARCH_MCTARGETDESC_MYARCHINFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace MyArchOp {
enum OperandType : unsigned {
  OPERAND_SIMM16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace MyArchOp

} // end namespace llvm

#endif
