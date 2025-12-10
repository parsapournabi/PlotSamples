import QtQuick 2.12
import QtCharts 2.13

import Adapters 1.0 as Adapters

Item {
    id: root
    ChartView {
        id: chartView
        anchors.fill: parent
        antialiasing: true
        ValueAxis {
            id: axisY2
            min: -260
            max: 150
        }

        ValueAxis {
            id: axisX
            min: -160
            max: 180
        }
        ScatterSeries {
            id: leafSerie
            name: "leaf"
            markerSize: 4
            color: "green"

            axisX: axisX
            axisY: axisY2


            // XYPoint { x: 100; y: 120 }
            // XYPoint { x: 110; y: 120 }
            // XYPoint { x: 110; y: 130 }
            // XYPoint { x: 120; y: 140 }
        }
    }
    Adapters.ScatterLeafAdapter {
        id: adapter

    }
    Timer {
        running: true
        repeat: true
        interval: 16
        onTriggered: {
            adapter.updateSeries(leafSerie)
        }
    }


}
