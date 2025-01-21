# Tools

## DAaaS SFTP data download and upload

https://www.youtube.com/watch?v=39al0Fjlzz4

## Dependency Walker

https://github.com/lucasg/Dependencies

## Process Monitor & Explorer

Very useful tools for investigating why programs external to our project (such as qt or git) have stopped running. For example I used Process Monitor to discover why I was getting a "This application failed to start because no qt platform plugin could be initialized" error. Turns out I had set the ``QT_QPA_PLATFORM_PLUGIN_PATH`` as a system variable which was causing problems.

- [Process Monitor](https://docs.microsoft.com/en-gb/sysinternals/downloads/procmon)
- [Process Explorer](https://docs.microsoft.com/en-us/sysinternals/downloads/process-explorer)

## Windows subsystem for Linux (WSL2)

https://developer.mantidproject.org/WindowsSubsystemForLinux.html
