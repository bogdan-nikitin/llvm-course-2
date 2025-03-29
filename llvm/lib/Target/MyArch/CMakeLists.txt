add_llvm_component_group(MyArch)

set(LLVM_TARGET_DEFINITIONS MyArch.td)

tablegen(LLVM MyArchGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM MyArchGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM MyArchGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM MyArchGenMCPseudoLowering.inc -gen-pseudo-lowering)

add_public_tablegen_target(MyArchCommonTableGen)

add_llvm_target(MyArchCodeGen
  MyArchTargetMachine.cpp
  MyArchRegisterInfo.cpp
  MyArchInstrInfo.cpp
  MyArchSubtarget.cpp
  MyArchAsmPrinter.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  MyArchInfo
  AsmPrinter

  ADD_TO_COMPONENT
  MyArch
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
