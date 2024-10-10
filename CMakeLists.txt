# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(FREERTOS_KERNEL_PATH ${CMAKE_CURRENT_LIST_DIR}/lib/FreeRTOS-KERNEL/)

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
include(tools/cmake/FreeRTOS_Kernel_import.cmake)

project(Nishmah-MCU-Based-Controller C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1
add_executable(Nishmah-MCU-Based-Controller src/main.c )

target_compile_definitions(Nishmah-MCU-Based-Controller PRIVATE
    NO_SYS=0            # don't want NO_SYS (generally this would be in your lwipopts.h)
    LWIP_SOCKET=1       # we need the socket API (generally this would be in your lwipopts.h)
)

pico_set_program_name(Nishmah-MCU-Based-Controller "Nishmah-MCU-Based-Controller")
pico_set_program_version(Nishmah-MCU-Based-Controller "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_usb(Nishmah-MCU-Based-Controller 1)
pico_enable_stdio_uart(Nishmah-MCU-Based-Controller 0)

# Add the standard library to the build
target_link_libraries(Nishmah-MCU-Based-Controller
    pico_cyw43_arch_lwip_sys_freertos
    pico_lwip_http
    pico_lwip_mdns
    pico_stdlib
    FreeRTOS-Kernel-Heap4 # FreeRTOS kernel and dynamic heap
    pico_freertos_httpd_content
)

# Add the standard include files to the build
target_include_directories(Nishmah-MCU-Based-Controller PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/config
    ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
    ${PICO_LWIP_CONTRIB_PATH}/apps/httpd
)

pico_add_extra_outputs(Nishmah-MCU-Based-Controller)

pico_add_library(pico_freertos_httpd_content NOFLAG)
pico_set_lwip_httpd_content(pico_freertos_httpd_content INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/web/script.js
    ${CMAKE_CURRENT_LIST_DIR}/web/styles.css
    ${CMAKE_CURRENT_LIST_DIR}/web/index.shtml
)
