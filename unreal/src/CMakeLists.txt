# Copyright 2017 Valve Corporation. All rights reserved. Subject to the following license:
# https://valvesoftware.github.io/steam-audio/license.html

#
# VERSION STAMPING
#

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/SteamAudioUnreal/Plugins/SteamAudio/SteamAudio.uplugin.in ${CMAKE_CURRENT_SOURCE_DIR}/SteamAudioUnreal/Plugins/SteamAudio/SteamAudio.uplugin)

#
# UNREAL PLUGIN
#

set(UBT_ARGS "-iwyu -noubtmakefiles -nohotreload")

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/HostProject.uproject "{ \"FileVersion\": 3, \"Plugins\": [ { \"Name\": \"SteamAudio\", \"Enabled\": true } ] }")

add_custom_target(phonon_unreal_setup
    COMMAND     cmake -E rm -rf ${CMAKE_CURRENT_BINARY_DIR}/HostProject
    COMMAND     cmake -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/HostProject
    COMMAND     cmake -E copy ${CMAKE_CURRENT_BINARY_DIR}/HostProject.uproject ${CMAKE_CURRENT_BINARY_DIR}/HostProject/HostProject.uproject
    COMMAND     cmake -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins/SteamAudio
    COMMAND     cmake -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/SteamAudioUnreal/Plugins/SteamAudio ${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins/SteamAudio
    COMMAND     cmake -E rm -rf ${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins/SteamAudio/Intermediate
    VERBATIM
)

add_custom_target(phonon_unreal_win32
    COMMAND     ${Unreal_EXECUTABLE} UnrealGame Win32 Development -project=${CMAKE_CURRENT_BINARY_DIR}/HostProject/HostProject.uproject -plugin=${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins/SteamAudio/SteamAudio.uplugin -manifest=${CMAKE_CURRENT_BINARY_DIR}/Manifest-SteamAudio-UnrealGame-Win32-Development.xml ${UBT_ARGS}
    COMMAND     ${Unreal_EXECUTABLE} UnrealGame Win32 Shipping -project=${CMAKE_CURRENT_BINARY_DIR}/HostProject/HostProject.uproject -plugin=${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins/SteamAudio/SteamAudio.uplugin -manifest=${CMAKE_CURRENT_BINARY_DIR}/Manifest-SteamAudio-UnrealGame-Win32-Shipping.xml ${UBT_ARGS}
    VERBATIM
)

add_custom_target(phonon_unreal_win64
    COMMAND     ${Unreal_EXECUTABLE} UnrealEditor Win64 Development -project=${CMAKE_CURRENT_BINARY_DIR}/HostProject/HostProject.uproject -plugin=${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins/SteamAudio/SteamAudio.uplugin -manifest=${CMAKE_CURRENT_BINARY_DIR}/Manifest-SteamAudio-UnrealEditor-Win64-Development.xml ${UBT_ARGS}
    COMMAND     ${Unreal_EXECUTABLE} UnrealGame Win64 Development -project=${CMAKE_CURRENT_BINARY_DIR}/HostProject/HostProject.uproject -plugin=${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins/SteamAudio/SteamAudio.uplugin -manifest=${CMAKE_CURRENT_BINARY_DIR}/Manifest-SteamAudio-UnrealGame-Win64-Development.xml ${UBT_ARGS}
    COMMAND     ${Unreal_EXECUTABLE} UnrealGame Win64 Shipping -project=${CMAKE_CURRENT_BINARY_DIR}/HostProject/HostProject.uproject -plugin=${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins/SteamAudio/SteamAudio.uplugin -manifest=${CMAKE_CURRENT_BINARY_DIR}/Manifest-SteamAudio-UnrealGame-Win64-Shipping.xml ${UBT_ARGS}
    VERBATIM
)

add_custom_target(phonon_unreal_linux
    COMMAND     ${Unreal_EXECUTABLE} UnrealGame Linux Development -project=${CMAKE_CURRENT_BINARY_DIR}/HostProject/HostProject.uproject -plugin=${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins/SteamAudio/SteamAudio.uplugin -manifest=${CMAKE_CURRENT_BINARY_DIR}/Manifest-SteamAudio-UnrealGame-Linux-Development.xml ${UBT_ARGS}
    COMMAND     ${Unreal_EXECUTABLE} UnrealGame Linux Shipping -project=${CMAKE_CURRENT_BINARY_DIR}/HostProject/HostProject.uproject -plugin=${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins/SteamAudio/SteamAudio.uplugin -manifest=${CMAKE_CURRENT_BINARY_DIR}/Manifest-SteamAudio-UnrealGame-Linux-Shipping.xml ${UBT_ARGS}
    VERBATIM
)

add_custom_target(phonon_unreal_mac
    COMMAND     ${Unreal_EXECUTABLE} UnrealEditor Mac Development -project=${CMAKE_CURRENT_BINARY_DIR}/HostProject/HostProject.uproject -plugin=${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins/SteamAudio/SteamAudio.uplugin -manifest=${CMAKE_CURRENT_BINARY_DIR}/Manifest-SteamAudio-UnrealEditor-Mac-Development.xml ${UBT_ARGS}
    COMMAND     ${Unreal_EXECUTABLE} UnrealGame Mac Development -project=${CMAKE_CURRENT_BINARY_DIR}/HostProject/HostProject.uproject -plugin=${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins/SteamAudio/SteamAudio.uplugin -manifest=${CMAKE_CURRENT_BINARY_DIR}/Manifest-SteamAudio-UnrealGame-Mac-Development.xml ${UBT_ARGS}
    COMMAND     ${Unreal_EXECUTABLE} UnrealGame Mac Shipping -project=${CMAKE_CURRENT_BINARY_DIR}/HostProject/HostProject.uproject -plugin=${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins/SteamAudio/SteamAudio.uplugin -manifest=${CMAKE_CURRENT_BINARY_DIR}/Manifest-SteamAudio-UnrealGame-Mac-Shipping.xml ${UBT_ARGS}
    VERBATIM
)

add_custom_target(phonon_unreal_android
    COMMAND     ${Unreal_EXECUTABLE} UnrealGame Android Development -project=${CMAKE_CURRENT_BINARY_DIR}/HostProject/HostProject.uproject -plugin=${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins/SteamAudio/SteamAudio.uplugin -manifest=${CMAKE_CURRENT_BINARY_DIR}/Manifest-SteamAudio-UnrealGame-Android-Development.xml ${UBT_ARGS} -architectures=armv7+arm64
    COMMAND     ${Unreal_EXECUTABLE} UnrealGame Android Shipping -project=${CMAKE_CURRENT_BINARY_DIR}/HostProject/HostProject.uproject -plugin=${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins/SteamAudio/SteamAudio.uplugin -manifest=${CMAKE_CURRENT_BINARY_DIR}/Manifest-SteamAudio-UnrealGame-Android-Shipping.xml ${UBT_ARGS} -architectures=armv7+arm64
    VERBATIM
)

add_custom_target(phonon_unreal ALL
    COMMAND     cmake -E echo Built plugin SteamAudio.
    VERBATIM
)

add_dependencies(phonon_unreal_win32 phonon_unreal_setup)
add_dependencies(phonon_unreal_win64 phonon_unreal_setup)
add_dependencies(phonon_unreal_linux phonon_unreal_setup)
add_dependencies(phonon_unreal_mac phonon_unreal_setup)
add_dependencies(phonon_unreal_android phonon_unreal_setup)

if (IPL_OS_WINDOWS AND IPL_CPU_X64)
    add_dependencies(phonon_unreal phonon_unreal_win64)
    if (STEAMAUDIOUNREAL_CROSSCOMPILE_WIN32)
        add_dependencies(phonon_unreal phonon_unreal_win32)
    endif()
    if (STEAMAUDIOUNREAL_CROSSCOMPILE_LINUX)
        add_dependencies(phonon_unreal phonon_unreal_linux)
    endif()
    if (STEAMAUDIOUNREAL_CROSSCOMPILE_ANDROID)
        add_dependencies(phonon_unreal phonon_unreal_android)
    endif()
elseif (IPL_OS_MACOS)
    add_dependencies(phonon_unreal phonon_unreal_mac)
endif()

#
# INSTALL
#

if (IPL_OS_WINDOWS AND IPL_CPU_X64)
    install(CODE "execute_process(COMMAND cmake -E rm -r ${CMAKE_HOME_DIRECTORY}/bin/unreal/SteamAudio COMMAND_ECHO STDOUT)")
    install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/SteamAudioUnreal/Plugins/SteamAudio/SteamAudio.uplugin DESTINATION unreal/SteamAudio)
    install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/SteamAudioUnreal/Plugins/SteamAudio/Source DESTINATION unreal/SteamAudio)
    install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/SteamAudioUnreal/Plugins/SteamAudio/Content DESTINATION unreal/SteamAudio)
    install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/SteamAudioUnreal/Plugins/SteamAudio/Resources DESTINATION unreal/SteamAudio)
    install(CODE "execute_process(COMMAND python copy_files_from_manifest.py -s ${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins -d ${CMAKE_HOME_DIRECTORY}/bin/unreal -m ${CMAKE_CURRENT_BINARY_DIR}/Manifest-SteamAudio-UnrealEditor-Win64-Development.xml WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build)")
    install(CODE "execute_process(COMMAND python copy_files_from_manifest.py -s ${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins -d ${CMAKE_HOME_DIRECTORY}/bin/unreal -m ${CMAKE_CURRENT_BINARY_DIR}/Manifest-SteamAudio-UnrealGame-Win64-Development.xml WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build)")
    install(CODE "execute_process(COMMAND python copy_files_from_manifest.py -s ${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins -d ${CMAKE_HOME_DIRECTORY}/bin/unreal -m ${CMAKE_CURRENT_BINARY_DIR}/Manifest-SteamAudio-UnrealGame-Win64-Shipping.xml WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build)")
    if (STEAMAUDIOUNREAL_CROSSCOMPILE_WIN32)
        install(CODE "execute_process(COMMAND python copy_files_from_manifest.py -s ${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins -d ${CMAKE_HOME_DIRECTORY}/bin/unreal -m ${CMAKE_CURRENT_BINARY_DIR}/Manifest-SteamAudio-UnrealGame-Win32-Development.xml WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build)")
        install(CODE "execute_process(COMMAND python copy_files_from_manifest.py -s ${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins -d ${CMAKE_HOME_DIRECTORY}/bin/unreal -m ${CMAKE_CURRENT_BINARY_DIR}/Manifest-SteamAudio-UnrealGame-Win32-Shipping.xml WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build)")
    endif()
    if (STEAMAUDIOUNREAL_CROSSCOMPILE_LINUX)
        install(CODE "execute_process(COMMAND python copy_files_from_manifest.py -s ${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins -d ${CMAKE_HOME_DIRECTORY}/bin/unreal -m ${CMAKE_CURRENT_BINARY_DIR}/Manifest-SteamAudio-UnrealGame-Linux-Development.xml WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build)")
        install(CODE "execute_process(COMMAND python copy_files_from_manifest.py -s ${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins -d ${CMAKE_HOME_DIRECTORY}/bin/unreal -m ${CMAKE_CURRENT_BINARY_DIR}/Manifest-SteamAudio-UnrealGame-Linux-Shipping.xml WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build)")
    endif()
    if (STEAMAUDIOUNREAL_CROSSCOMPILE_ANDROID)
        install(CODE "execute_process(COMMAND python copy_files_from_manifest.py -s ${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins -d ${CMAKE_HOME_DIRECTORY}/bin/unreal -m ${CMAKE_CURRENT_BINARY_DIR}/Manifest-SteamAudio-UnrealGame-Android-Development.xml WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build)")
        install(CODE "execute_process(COMMAND python copy_files_from_manifest.py -s ${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins -d ${CMAKE_HOME_DIRECTORY}/bin/unreal -m ${CMAKE_CURRENT_BINARY_DIR}/Manifest-SteamAudio-UnrealGame-Android-Shipping.xml WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build)")
    endif()
elseif (IPL_OS_MACOS)
    install(CODE "execute_process(COMMAND cmake -E rm -rf ${CMAKE_HOME_DIRECTORY}/bin/unreal/SteamAudio)")
    install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/SteamAudioUnreal/Plugins/SteamAudio/SteamAudio.uplugin DESTINATION unreal/SteamAudio)
    install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/SteamAudioUnreal/Plugins/SteamAudio/Source DESTINATION unreal/SteamAudio)
    install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/SteamAudioUnreal/Plugins/SteamAudio/Content DESTINATION unreal/SteamAudio)
    install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/SteamAudioUnreal/Plugins/SteamAudio/Resources DESTINATION unreal/SteamAudio)
    install(CODE "execute_process(COMMAND python copy_files_from_manifest.py -s ${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins -d ${CMAKE_HOME_DIRECTORY}/bin/unreal -m ${CMAKE_CURRENT_BINARY_DIR}/Manifest-SteamAudio-UnrealEditor-Mac-Development.xml WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build)")
    install(CODE "execute_process(COMMAND python copy_files_from_manifest.py -s ${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins -d ${CMAKE_HOME_DIRECTORY}/bin/unreal -m ${CMAKE_CURRENT_BINARY_DIR}/Manifest-SteamAudio-UnrealGame-Mac-Development.xml WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build)")
    install(CODE "execute_process(COMMAND python copy_files_from_manifest.py -s ${CMAKE_CURRENT_BINARY_DIR}/HostProject/Plugins -d ${CMAKE_HOME_DIRECTORY}/bin/unreal -m ${CMAKE_CURRENT_BINARY_DIR}/Manifest-SteamAudio-UnrealGame-Mac-Shipping.xml WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build)")
endif()
