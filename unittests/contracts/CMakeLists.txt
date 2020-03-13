# will be implictly used for any compilation unit if not overrided by SYSTEM_INCLUDE_FOLDERS parameter
# these directories go as -isystem <dir> to avoid warnings from code of third-party libraries

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/arisen.bios/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/arisen.bios/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/arisen.msig/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/arisen.msig/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/arisen.system/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/arisen.system/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/arisen.token/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/arisen.token/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/arisen.wrap/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/arisen.wrap/)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/old_versions/v1.6.0-rc3/arisen.bios/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/old_versions/v1.6.0-rc3/arisen.bios/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/old_versions/v1.7.0-develop-preactivate_feature/arisen.bios/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/old_versions/v1.7.0-develop-preactivate_feature/arisen.bios/)
