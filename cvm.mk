##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ClawVM
ConfigurationName      :=Debug
WorkspacePath          :=/home/benedikt/Development/CodeLite
ProjectPath            :=/home/benedikt/Development/CodeLite/ClawVM
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Benedikt Müssig
Date                   :=08/05/16
CodeLitePath           :=/home/benedikt/.codelite
LinkerName             :=/usr/bin/avr-g++
SharedObjectLinkerName :=/usr/bin/avr-g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="ClawVM.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/avr-ar rcu
CXX      := /usr/bin/avr-g++
CC       := /usr/bin/avr-gcc
CXXFLAGS :=  -g -c -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -c -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/vars.c$(ObjectSuffix) $(IntermediateDirectory)/cpu.c$(ObjectSuffix) $(IntermediateDirectory)/stack.c$(ObjectSuffix) $(IntermediateDirectory)/maths.c$(ObjectSuffix) $(IntermediateDirectory)/logic.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/benedikt/Development/CodeLite/ClawVM/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM "main.c"

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) "main.c"

$(IntermediateDirectory)/vars.c$(ObjectSuffix): vars.c $(IntermediateDirectory)/vars.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/benedikt/Development/CodeLite/ClawVM/vars.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vars.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vars.c$(DependSuffix): vars.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vars.c$(ObjectSuffix) -MF$(IntermediateDirectory)/vars.c$(DependSuffix) -MM "vars.c"

$(IntermediateDirectory)/vars.c$(PreprocessSuffix): vars.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vars.c$(PreprocessSuffix) "vars.c"

$(IntermediateDirectory)/cpu.c$(ObjectSuffix): cpu.c $(IntermediateDirectory)/cpu.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/benedikt/Development/CodeLite/ClawVM/cpu.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cpu.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cpu.c$(DependSuffix): cpu.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cpu.c$(ObjectSuffix) -MF$(IntermediateDirectory)/cpu.c$(DependSuffix) -MM "cpu.c"

$(IntermediateDirectory)/cpu.c$(PreprocessSuffix): cpu.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cpu.c$(PreprocessSuffix) "cpu.c"

$(IntermediateDirectory)/stack.c$(ObjectSuffix): stack.c $(IntermediateDirectory)/stack.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/benedikt/Development/CodeLite/ClawVM/stack.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/stack.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/stack.c$(DependSuffix): stack.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/stack.c$(ObjectSuffix) -MF$(IntermediateDirectory)/stack.c$(DependSuffix) -MM "stack.c"

$(IntermediateDirectory)/stack.c$(PreprocessSuffix): stack.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/stack.c$(PreprocessSuffix) "stack.c"

$(IntermediateDirectory)/maths.c$(ObjectSuffix): maths.c $(IntermediateDirectory)/maths.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/benedikt/Development/CodeLite/ClawVM/maths.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/maths.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/maths.c$(DependSuffix): maths.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/maths.c$(ObjectSuffix) -MF$(IntermediateDirectory)/maths.c$(DependSuffix) -MM "maths.c"

$(IntermediateDirectory)/maths.c$(PreprocessSuffix): maths.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/maths.c$(PreprocessSuffix) "maths.c"

$(IntermediateDirectory)/logic.c$(ObjectSuffix): logic.c $(IntermediateDirectory)/logic.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/benedikt/Development/CodeLite/ClawVM/logic.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/logic.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/logic.c$(DependSuffix): logic.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/logic.c$(ObjectSuffix) -MF$(IntermediateDirectory)/logic.c$(DependSuffix) -MM "logic.c"

$(IntermediateDirectory)/logic.c$(PreprocessSuffix): logic.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/logic.c$(PreprocessSuffix) "logic.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


