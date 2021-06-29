#include "flowlayout.h"

#include <QtWidgets/QWidget>

/*!
  \param parent Parent widget
  \param margin Left, right, top and bottom margins
  \param hSpacing Horizontal spacing between widgets
  \param vSpacing Vertical spacing between widgets
*/
FlowLayout::FlowLayout(QWidget *parent, int margin, int hSpacing, int vSpacing) : QLayout(parent), m_hSpace(hSpacing), m_vSpace(vSpacing) {
    setContentsMargins(margin, margin, margin, margin);
}


/*!
  \param margin Left, right, top and bottom margins
  \param hSpacing Horizontal spacing between widgets
  \param vSpacing Vertical spacing between widgets
*/
FlowLayout::FlowLayout(int margin, int hSpacing, int vSpacing) : m_hSpace(hSpacing), m_vSpace(vSpacing) {
    setContentsMargins(margin, margin, margin, margin);
}


/*! \brief Delete all items
*/
FlowLayout::~FlowLayout() {
    QLayoutItem *item;
    while ((item = takeAt(0)))
        delete item;
}


/*! \brief Append an item to the layout
  \param item Item to append
*/
void FlowLayout::addItem(QLayoutItem *item) {
    itemList.append(item);
}


/*! \brief Return the horizontal spacing between widgets
  \return Horizontal spacing between widgets
*/
int FlowLayout::horizontalSpacing() const {
    if (m_hSpace >= 0)
        return m_hSpace;
    else
        return smartSpacing(QStyle::PM_LayoutHorizontalSpacing);
}


/*! \brief Return the vertical spacing between widgets
  \return Vertical spacing between widgets
*/
int FlowLayout::verticalSpacing() const {
    if (m_vSpace >= 0)
        return m_vSpace;
    else
        return smartSpacing(QStyle::PM_LayoutVerticalSpacing);
}


/*! \brief Return the number of items in the layout
  \return Number of items
*/
int FlowLayout::count() const {
    return itemList.size();
}


/*! \brief Return the item at a given position

  \param index Position of item searched
  \return Item at position index
*/
QLayoutItem *FlowLayout::itemAt(int index) const {
    return itemList.value(index);
}


/*! \brief Return the item at a given position and remove it

  \param index Position of item searched
  \return Item at position index
*/
QLayoutItem *FlowLayout::takeAt(int index) {
    if (index >= 0 && index < itemList.size())
        return itemList.takeAt(index);
    else
        return 0;
}


/*! \brief Not used for FlowLayout

  \return 0
*/
Qt::Orientations FlowLayout::expandingDirections() const {
    return 0;
}


/*! \brief Not used for FlowLayout

  \return True
*/
bool FlowLayout::hasHeightForWidth() const {
    return true;
}


/*! \brief Returns the height which would be used for a given width

  \param width Width to test
  \return New height
*/
int FlowLayout::heightForWidth(int width) const {
    int height = doLayout(QRect(0, 0, width, 0), true);
    return height;
}


/*! \brief Sets the layout geometry

  \param rect New geometry
*/
void FlowLayout::setGeometry(const QRect &rect) {
    QLayout::setGeometry(rect);
    doLayout(rect, false);
}


/*! \brief Returns the recommanded size

  \return Size
*/
QSize FlowLayout::sizeHint() const {
    return minimumSize();
}


/*! \brief Returns the minimum size of the layout

  \return Size
*/
QSize FlowLayout::minimumSize() const {
    QSize size;
    QLayoutItem *item;
    foreach (item, itemList)
        size = size.expandedTo(item->minimumSize());

    size += QSize(2 * margin(), 2 * margin());
    return size;
}


/*! \brief Calculate items positions for a given geometry

  \param rect Geometry to use
  \param testOnly If true, returns only the new height, but don't apply the new geometry
  \return New height
*/
int FlowLayout::doLayout(const QRect &rect, bool testOnly) const {
    int left, top, right, bottom;
    getContentsMargins(&left, &top, &right, &bottom);
    QRect effectiveRect = rect.adjusted(+left, +top, -right, -bottom);
    int x = effectiveRect.x();
    int y = effectiveRect.y();
    int lineHeight = 0;
    QLayoutItem *item;
    foreach (item, itemList) {
        QWidget *wid = item->widget();
        int spaceX = horizontalSpacing();
        if (spaceX == -1)
            spaceX = wid->style()->layoutSpacing(
                    QSizePolicy::PushButton, QSizePolicy::PushButton, Qt::Horizontal);
        int spaceY = verticalSpacing();
        if (spaceY == -1)
            spaceY = wid->style()->layoutSpacing(
                    QSizePolicy::PushButton, QSizePolicy::PushButton, Qt::Vertical);
        int nextX = x + item->sizeHint().width() + spaceX;
        if (nextX - spaceX > effectiveRect.right() && lineHeight > 0) {
            x = effectiveRect.x();
            y = y + lineHeight + spaceY;
            nextX = x + item->sizeHint().width() + spaceX;
            lineHeight = 0;
        }

        if (!testOnly)
            item->setGeometry(QRect(QPoint(x, y), item->sizeHint()));

        x = nextX;
        lineHeight = qMax(lineHeight, item->sizeHint().height());
    }
    return y + lineHeight - rect.y() + bottom;
}


/*! \brief Returns the recommanded spacing

  \param pm PixelMetric of the style
  \return Recommanded spacing
*/
int FlowLayout::smartSpacing(QStyle::PixelMetric pm) const {
    QObject *parent = this->parent();
    if (!parent) {
        return -1;
    } else if (parent->isWidgetType()) {
        QWidget *pw = static_cast<QWidget*>(parent);
        return pw->style()->pixelMetric(pm, 0, pw);
    } else {
        return static_cast<QLayout *>(parent)->spacing();
    }
}
