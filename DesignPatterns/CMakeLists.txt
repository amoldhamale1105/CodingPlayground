project(DesignPatterns)

# Set parent directory for downstream projects
get_filename_component(PARENT_DIR ${PROJECT_SOURCE_DIR} NAME_WE)

add_subdirectory(BehaviouralPatterns)
add_subdirectory(CreationalPatterns)
add_subdirectory(StructuralPatterns)