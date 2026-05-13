add_library(sankore_podcast STATIC
    UBPodcastController.cpp
    UBPodcastController.h
    UBAbstractVideoEncoder.cpp
    UBAbstractVideoEncoder.h
    UBPodcastRecordingPalette.cpp
    UBPodcastRecordingPalette.h
    intranet/UBIntranetPodcastPublisher.cpp
    intranet/UBIntranetPodcastPublisher.h
    youtube/UBYouTubePublisher.cpp
    youtube/UBYouTubePublisher.h
)

if(APPLE)
    target_sources(sankore_podcast PRIVATE
        quicktime/UBAudioQueueRecorder.cpp
        quicktime/UBAudioQueueRecorder.h
        quicktime/UBQuickTimeFile.cpp
        quicktime/UBQuickTimeFile.h
        quicktime/UBQuickTimeVideoEncoder.cpp
        quicktime/UBQuickTimeVideoEncoder.h
    )
endif()

if(WIN32)
    target_sources(sankore_podcast PRIVATE
        windowsmedia/UBWaveRecorder.cpp
        windowsmedia/UBWaveRecorder.h
        windowsmedia/UBWindowsMediaFile.cpp
        windowsmedia/UBWindowsMediaFile.h
        windowsmedia/UBWindowsMediaVideoEncoder.cpp
        windowsmedia/UBWindowsMediaVideoEncoder.h
    )
endif()

target_include_directories(sankore_podcast PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(sankore_podcast PUBLIC
    sankore_core
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Multimedia
)
