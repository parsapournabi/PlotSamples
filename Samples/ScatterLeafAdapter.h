#ifndef SCATTERLEAFADAPTER_H
#define SCATTERLEAFADAPTER_H

#include <QObject>
#include <QAbstractSeries>
#include <QXYSeries>
#include <QRandomGenerator>

#include <QQuickItem>

QT_FORWARD_DECLARE_CLASS(QAbstractSeries)
QT_FORWARD_DECLARE_CLASS(QQuickView)

class ScatterLeafAdapter : public QObject
{
        Q_OBJECT
    public:
        explicit ScatterLeafAdapter(QObject* parent = nullptr)
            : QObject{parent}
        {
            generatePoints();
        }

        Q_INVOKABLE void updateSeries(QAbstractSeries* serie)
        {
            if (m_points.empty())
            {
                qCritical() << "points are empty!";
                return;
            }
            if (!serie)
            {
                qCritical() << "Serie is NULL";
                return;
            }
            auto xySerie = static_cast<QXYSeries*>(serie);
            if (!xySerie)
            {
                qCritical() << "Casting serie -> xySerie wasn't successfull!";
                return;
            }

            xySerie->replace(m_points);

        }

        void generatePoints()
        {

            // sinData(m_points);
            leafData(m_points);

        }
    protected:
        void leafData(QList<QPointF>& points)
        {
            constexpr int iterations = 20000;
            constexpr int width = 800;
            constexpr int height = 1000;


            qreal x = 0.0;
            qreal y = 0.0;

            points.resize(iterations);
            auto ptr = points.data();
            for (int i = 0; i < iterations; i++)
            {
                double px = 65.0 * x;
                double py = 37.0 * y - 252.0;

                ptr[i] = QPointF(px, py);

                double r = QRandomGenerator::global()->bounded(100.0);

                double xn = x;
                double yn = y;

                if (r < 1.0)
                {
                    x = 0;
                    y = 0.16 * yn;
                }
                else if (r < 86.0)
                {
                    x = 0.85 * xn + 0.04 * yn;
                    y = -0.04 * xn + 0.85 * yn + 1.6;
                }
                else if (r < 93.0)
                {
                    x = 0.20 * xn - 0.26 * yn;
                    y = 0.23 * xn + 0.22 * yn + 1.6;
                }
                else
                {
                    x = -0.15 * xn + 0.28 * yn;
                    y = 0.26 * xn + 0.24 * yn + 0.44;
                }
            }

        }
        void sinData(QList<QPointF>& points)
        {
            points.resize(1024);
            auto ptr = points.data();
            for (int i(0); i < m_points.size(); ++i)
            {
                qreal x(0);
                qreal y(0);
                y = qSin(M_PI / 50 * i) + 0.5 + QRandomGenerator::global()->generateDouble();
                x = i;
                ptr[i] = QPointF(x, y);
            }

        }


    private:
        QList<QPointF> m_points;


};

static void registerAdapter()
{
    qmlRegisterType<ScatterLeafAdapter>("Adapters", 1, 0, "ScatterLeafAdapter");
}
Q_COREAPP_STARTUP_FUNCTION(registerAdapter)

#endif // SCATTERLEAFADAPTER_H
