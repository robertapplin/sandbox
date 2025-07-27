qt5_wrap_cpp(MOC_FILES InvokeView.h)
qt5_wrap_ui(UI_FILES InvokeGUIWidget.ui)

add_executable(launch1 main.cpp InvokeModel.cpp InvokeView.cpp InvokePresenter.cpp ${MOC_FILES} ${UI_FILES})
# For the auto generated ui_*.h file
target_include_directories(launch1 SYSTEM PUBLIC ${CMAKE_BINARY_DIR}/option1)

# Link with the Release version of the standard library. This is required because Conda does not provide packages with
# Debug symbols.
if(WIN32)
  set_property(TARGET launch1 PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")
endif()

target_link_libraries(launch1 Qt5::Core Qt5::Gui Qt5::Widgets)
