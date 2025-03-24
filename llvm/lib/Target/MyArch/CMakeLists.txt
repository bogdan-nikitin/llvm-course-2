add_llvm_component_group(MyArch)

set(LLVM_TARGET_DEFINITIONS MyArch.td)

tablegen(LLVM MyArchGenRegisterInfo.inc -gen-register-info)

add_public_tablegen_target(MyArchCommonTableGen)

add_llvm_target(MyArchCodeGen
  MyArchTargetMachine.cpp
  MyArchRegisterInfo.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  MyArchInfo

  ADD_TO_COMPONENT
  MyArch
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
