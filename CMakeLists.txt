# == DO NEVER EDIT THE NEXT LINES for Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.0.0)
set(toolchainVersion 13_2_Rel1)
set(picotoolVersion 2.0.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NEVER EDIT THE NEXT LINES for Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.0.0)
set(toolchainVersion 13_2_Rel1)
set(picotoolVersion 2.0.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(tools/cmake/pico_sdk_import.cmake)

# Pull in FreeRTOS Kernel (must be before project)
include(lib/FreeRTOS-Kernel/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)

project(Nishmah-MCU-Based-Controller C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Add executable. Default name is the project name, version 0.1
add_executable(Nishmah-MCU-Based-Controller src/main.c )

pico_set_program_name(Nishmah-MCU-Based-Controller "Nishmah-MCU-Based-Controller")
pico_set_program_version(Nishmah-MCU-Based-Controller "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(Nishmah-MCU-Based-Controller 0)
pico_enable_stdio_usb(Nishmah-MCU-Based-Controller 1)

# Add the standard library to the build
target_link_libraries(Nishmah-MCU-Based-Controller
    pico_stdlib
    FreeRTOS-Kernel-Heap4
)

# Add the standard include files to the build
target_include_directories(Nishmah-MCU-Based-Controller PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/config
    ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
)

# Add any user requested libraries
target_link_libraries(Nishmah-MCU-Based-Controller
    pico_cyw43_arch_lwip_threadsafe_background
)

pico_add_extra_outputs(Nishmah-MCU-Based-Controller)

