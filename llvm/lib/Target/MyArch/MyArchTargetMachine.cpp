#include "MyArchTargetMachine.h"
#include "MyArch.h"
#include "TargetInfo/MyArchTargetInfo.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Transforms/Scalar.h"
#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeMyArchTarget() {
  // Register the target.
  MYARCH_DUMP_CYAN
  RegisterTargetMachine<MyArchTargetMachine> A(getTheMyArchTarget());
}

static std::string computeDataLayout(const Triple &TT, StringRef CPU,
                                     const TargetOptions &Options,
                                     bool IsLittle) {
  std::string Ret = "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32";
  return Ret;
}

static Reloc::Model getEffectiveRelocModel(bool JIT,
                                           std::optional<Reloc::Model> RM) {
  if (!RM || JIT)
    return Reloc::Static;
  return *RM;
}

MyArchTargetMachine::MyArchTargetMachine(const Target &T, const Triple &TT,
                                         StringRef CPU, StringRef FS,
                                         const TargetOptions &Options,
                                         std::optional<Reloc::Model> RM,
                                         std::optional<CodeModel::Model> CM,
                                         CodeGenOptLevel OL, bool JIT,
                                         bool IsLittle)
    : CodeGenTargetMachineImpl(T, computeDataLayout(TT, CPU, Options, IsLittle),
                               TT, CPU, FS, Options,
                               getEffectiveRelocModel(JIT, RM),
                               getEffectiveCodeModel(CM, CodeModel::Small), OL),
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()) {
  MYARCH_DUMP_CYAN
  initAsmInfo();
}

MyArchTargetMachine::MyArchTargetMachine(const Target &T, const Triple &TT,
                                         StringRef CPU, StringRef FS,
                                         const TargetOptions &Options,
                                         std::optional<Reloc::Model> RM,
                                         std::optional<CodeModel::Model> CM,
                                         CodeGenOptLevel OL, bool JIT)
    : MyArchTargetMachine(T, TT, CPU, FS, Options, RM, CM, OL, JIT, true) {}

namespace {

/// MyArch Code Generator Pass Configuration Options.
class MyArchPassConfig : public TargetPassConfig {
public:
  MyArchPassConfig(MyArchTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  MyArchTargetMachine &getMyArchTargetMachine() const {
    return getTM<MyArchTargetMachine>();
  }

  bool addInstSelector() override {
    MYARCH_DUMP_CYAN
    addPass(createMyArchISelDag(getMyArchTargetMachine(), getOptLevel()));
    return false;
  }
};

} // end anonymous namespace

TargetPassConfig *MyArchTargetMachine::createPassConfig(PassManagerBase &PM) {
  MYARCH_DUMP_CYAN
  return new MyArchPassConfig(*this, PM);
}
