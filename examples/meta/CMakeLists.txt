# Check python dependency and return error
# Generate examples
# Check which interfaces are turned on
# Add CMakeLists file for each turned on interface

# Disabled (temporary) as non-portable solution. This is replaced by allowing any [a-zA-Z_][a-zA-Z0-9_]* as shogun keyword
# Generate type list
# execute_process(COMMAND sh ${CMAKE_CURRENT_SOURCE_DIR}/generator/types/get_type_list.sh > ${CMAKE_CURRENT_SOURCE_DIR}/generator/types/typelist)

# Run example generation script
add_custom_target(meta_examples
    COMMAND ${PYTHON_EXECUTABLE}
    ${CMAKE_CURRENT_SOURCE_DIR}/generator/generate.py
    -i ${CMAKE_CURRENT_SOURCE_DIR}/src
    -o ${CMAKE_CURRENT_BINARY_DIR}
    -t ${CMAKE_CURRENT_SOURCE_DIR}/generator/targets
    COMMENT "Generating examples from meta-language")

# Collect all meta example listings and store in variable
FILE(GLOB_RECURSE META_EXAMPLES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.sg)

# If testing is enabled we run the examples
IF(ENABLE_TESTING)
    # Python
    IF (PythonModular AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/python)
        add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/python)
    ENDIF()

    # java
    IF (JavaModular AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/java)
        add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/java)
    ENDIF()

    # octave
    IF (OctaveModular AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/octave)
        add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/octave)
    ENDIF()

    # r
    IF (RModular AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/r)
        add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/r)
    ENDIF()
ENDIF()