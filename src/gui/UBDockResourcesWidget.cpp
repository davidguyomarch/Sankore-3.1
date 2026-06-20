#include "UBDockResourcesWidget.h"
#include "globals/UBGlobals.h"

UBDockResourcesWidget::UBDockResourcesWidget(QWidget *parent):
    UBDockPaletteWidget(parent, "UBDockResourcesWidget")
{
    setVisibleState(true);

    SET_STYLE_SHEET();

    QVBoxLayout *layout = new QVBoxLayout(this);
    setLayout(layout);
    mTeacherResourceWidget = new UBTeacherResources(this);
    layout->addWidget(mTeacherResourceWidget);


    mLeftPalette = nullptr;
}

bool UBDockResourcesWidget::hasUserDataInTeacherGuide()
{
    return mTeacherResourceWidget->hasUserDataInTeacherGuide();
}

bool UBDockResourcesWidget::isModified()
{
    return mTeacherResourceWidget->isModified();
}
