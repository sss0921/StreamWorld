
!isEmpty(STREAMWORLD_PRI_INCLUDED):error("streamworld.pri already included")
STREAMWORLD_PRI_INCLUDED = 1

STREAMWORLD_SOURCE_TREE = $$PWD
STREAMWORLD_BUILD_TREE = $$shadowed($$PWD)

!isEqual(STREAMWORLD_SOURCE_TREE, $$STREAMWORLD_BUILD_TREE): copydata = 1

STREAMWORLD_BIN_PATH = $$STREAMWORLD_BUILD_TREE/bin
STREAMWORLD_LIB_PATH = $$STREAMWORLD_BUILD_TREE/lib
