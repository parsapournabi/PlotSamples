import QtQuick 2.12
import QtCharts 2.13

Item {
    id: root
    ChartView {
        anchors.fill: parent
        antialiasing: true
        ScatterSeries {
            name: "leaf"
            markerSize: 10
            color: "green"


            XYPoint { x: 100; y: 120 }
            XYPoint { x: 110; y: 120 }
            XYPoint { x: 110; y: 130 }
            XYPoint { x: 120; y: 140 }
        }
    }


}
