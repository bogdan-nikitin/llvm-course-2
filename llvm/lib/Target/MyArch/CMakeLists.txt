add_llvm_component_group(MyArch)

set(LLVM_TARGET_DEFINITIONS MyArch.td)

tablegen(LLVM MyArchGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM MyArchGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM MyArchGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM MyArchGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM MyArchGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM MyArchGenCallingConv.inc -gen-callingconv)
tablegen(LLVM MyArchGenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM MyArchGenMCCodeEmitter.inc -gen-emitter)

add_public_tablegen_target(MyArchCommonTableGen)

add_llvm_target(MyArchCodeGen
  MyArchTargetMachine.cpp
  MyArchRegisterInfo.cpp
  MyArchInstrInfo.cpp
  MyArchSubtarget.cpp
  MyArchAsmPrinter.cpp
  MyArchISelDagToDag.cpp
  MyArchISelLowering.cpp
  MyArchMCInstLower.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  MyArchInfo
  AsmPrinter
  SelectionDAG

  ADD_TO_COMPONENT
  MyArch
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
