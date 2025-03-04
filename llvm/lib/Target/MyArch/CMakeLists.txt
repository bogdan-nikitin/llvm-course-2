add_llvm_component_group(MyArch)

add_llvm_target(MyArchCodeGen
  MyArchTargetMachine.cpp

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
