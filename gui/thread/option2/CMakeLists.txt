qt5_wrap_cpp(MOC_FILES PollView.h)
qt5_wrap_ui(UI_FILES PollGUIWidget.ui)

add_executable(launch2 main.cpp PollModel.cpp PollView.cpp PollPresenter.cpp ${MOC_FILES} ${UI_FILES})
# For the auto generated ui_*.h file
target_include_directories(launch2 SYSTEM PUBLIC ${CMAKE_BINARY_DIR}/option2)

# Link with the Release version of the standard library. This is required because Conda does not provide packages with
# Debug symbols.
if(WIN32)
  set_property(TARGET launch2 PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")
endif()

target_link_libraries(launch2 Qt5::Core Qt5::Gui Qt5::Widgets)
