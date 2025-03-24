#ifndef LLVM_LIB_TARGET_MyArch_MyArch_H
#define LLVM_LIB_TARGET_MyArch_MyArch_H

#include "MCTargetDesc/MyArchMCTargetDesc.h"
#include "llvm/Support/raw_ostream.h"

#define MYARCH_DUMP(Color)                                                     \
  {                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
  }
// #define MYARCH_DUMP(Color) {}

#define MYARCH_DUMP_RED MYARCH_DUMP(llvm::raw_ostream::RED)
#define MYARCH_DUMP_GREEN MYARCH_DUMP(llvm::raw_ostream::GREEN)
#define MYARCH_DUMP_YELLOW MYARCH_DUMP(llvm::raw_ostream::YELLOW)
#define MYARCH_DUMP_CYAN MYARCH_DUMP(llvm::raw_ostream::CYAN)
#define MYARCH_DUMP_MAGENTA MYARCH_DUMP(llvm::raw_ostream::MAGENTA)
#define MYARCH_DUMP_WHITE MYARCH_DUMP(llvm::raw_ostream::WHITE)

#endif // LLVM_LIB_TARGET_MyArch_MyArch_H
