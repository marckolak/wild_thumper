#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QPen>
#include <QBrush>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);


    void zoomIn(void);

    void zoomOut(void);

protected:
    /**
     * @brief paintEvent called when the widget needs repainting e.g. resize or new localization computed
     * @param event paint event
     */
    void paintEvent(QPaintEvent *event) override;

    /**
     * @brief resizeEvent called when the window is resized
     * @param resizedEvent
     */
    void resizeEvent(QResizeEvent* resizedEvent) override;


private:

    /** */
    double lim;

    /** */
    int rHeight;

    /** */
    int rWidth;

    /** */
    double rAspect;

    /** */
    double limX;

    /** */
    double limY;

    /** */
    double rCenterX;

    /** */
    double rCenterY;

    double cX = 0;
    double cY = 0;


    std::vector<int> xTicks;
    std::vector<int> yTicks;

    void plotAxes(QPainter* p);

    double rX(double x);
    double rY(double y);

    double mX(double xr);
    double mY(double yr);

    std::vector<int> getTicksX();
    std::vector<int> getTicksY();


    void calcRenderParams();

signals:

};

#endif // RENDERAREA_H