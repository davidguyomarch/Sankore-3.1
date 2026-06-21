
CONFIG       += uitools

FORMS        += # src/web/browser/downloaditem.ui # excluded \
                # src/web/browser/downloads.ui # excluded \
                src/web/browser/passworddialog.ui \
                src/web/browser/proxy.ui

INCLUDEPATH  += src/web/browser

HEADERS      += src/web/UBWebController.h \
                # src/web/UBTrapFlashController.h # WebKit-specific \
                # src/web/UBWebKitUtils.h # WebKit-specific \
                src/web/UBWebPage.h \
                src/web/UBWebPluginWidget.h \
                src/web/UBOEmbedParser.h\
                src/web/browser/WBBrowserWindow.h \
                src/web/browser/WBChaseWidget.h \
                src/web/browser/WBDownloadManager.h \
                src/web/browser/WBModelMenu.h \
                # src/web/browser/WBEditTableView.h # WebKit-specific \
                src/web/browser/WBSearchLineEdit.h \
                src/web/browser/WBSqueezeLabel.h \
                src/web/browser/WBTabWidget.h \
                src/web/browser/WBToolBarSearch.h \
                src/web/browser/WBUrlLineEdit.h \
                src/web/browser/WBWebView.h \
                src/web/browser/WBHistory.h \
                # src/web/browser/WBWebTrapWebView.h # WebKit-specific \
                # src/web/browser/WBTrapWebPageContent.h # WebKit-specific


SOURCES      += src/web/UBWebController.cpp \
                # src/web/UBTrapFlashController.cpp # WebKit-specific \
                # src/web/UBWebKitUtils.cpp # WebKit-specific \
                src/web/UBWebPage.cpp \
                src/web/UBWebPluginWidget.cpp \
                src/web/UBOEmbedParser.cpp\
                src/web/browser/WBBrowserWindow.cpp \
                src/web/browser/WBChaseWidget.cpp \
                src/web/browser/WBDownloadManager.cpp \
                src/web/browser/WBModelMenu.cpp \
                # src/web/browser/WBEditTableView.cpp # WebKit-specific \
                src/web/browser/WBSearchLineEdit.cpp \
                src/web/browser/WBSqueezeLabel.cpp \
                src/web/browser/WBTabWidget.cpp \
                src/web/browser/WBToolBarSearch.cpp \
                src/web/browser/WBUrlLineEdit.cpp \
                src/web/browser/WBWebView.cpp \
                src/web/browser/WBHistory.cpp \
                # src/web/browser/WBWebTrapWebView.cpp # WebKit-specific \
                # src/web/browser/WBTrapWebPageContent.cpp # WebKit-specific

    
    


