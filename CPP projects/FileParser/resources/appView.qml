import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs

ApplicationWindow {
    width: Screen.width
    height: Screen.height
    visible: true
    title: "Top 15 Words"

    property real progressIndex: 0
    property bool isProcessing: false
    property bool hasOpened: false
    property string status: "Ready to open file"
    property string filePath: ""

    readonly property real borderWidth: Screen.width * 0.015
    readonly property real statusFontSize: Screen.height * 0.015
    readonly property real buttonFontSize: Screen.height * 0.02
    readonly property real barFontSize: Screen.height * 0.015

    readonly property real animationDuration: 200

    Rectangle {
        id: mainWrapper
        height: parent.height
        width: parent.width
        anchors.top: parent.top
        color: "#f8fafc"
        border.color: "#94a3b8"
        border.width: borderWidth

        Rectangle {
            id: navigationWrapper
            anchors {
                top: parent.top
                left: parent.left
                right: parent.right
            }
            anchors.margins: mainWrapper.border.width
            height: 0.2 * (mainWrapper.height - 2 * mainWrapper.border.width)
            width: parent.width - (2 * navigationWrapper.border.width)
            border.color: "#cbd5e1"
            border.width: borderWidth
            color: "#e2e8f0"

            FileDialog {
                id: fileDialog
                title: "Choose Text File"

                onAccepted: {
                    if (selectedFiles && selectedFiles.length > 0) {
                        filePath = selectedFiles[0]
                        fileProcessor.setFilePath(filePath)
                        status = "Let's get started with\n" + filePath
                        progressIndex = 0
                        hasOpened = true
                    } else {
                        console.warn("No file selected")
                    }
                }
                onRejected: {
                    console.warn("File selection was canceled")
                }
            }

            Row {
                id: mainRow
                anchors.fill: parent
                anchors.margins: parent.border.width
                spacing: 2

                readonly property int itemsAmount: 3

                Rectangle {
                    id: fileDialogWrapper
                    width: (parent.width - 2 * mainRow.spacing) / mainRow.itemsAmount
                    height: parent.height
                    color: "#facc15"

                    Button {
                        id: openButton
                        anchors.centerIn: parent
                        text: "Open File"
                        font.pixelSize: buttonFontSize
                        enabled: !isProcessing

                        onClicked: {
                            wordModel.cleanModel()
                            fileDialog.open()
                        }
                    }
                }

                Rectangle {
                    id: startButtonWrapper
                    width: (parent.width - 2 * mainRow.spacing) / mainRow.itemsAmount
                    height: parent.height
                    color: "#22c55e"

                    Button {
                        id: startButton
                        anchors.centerIn: parent
                        text: "Start"
                        font.pixelSize: buttonFontSize
                        enabled: !isProcessing && hasOpened

                        onClicked: {
                            fileProcessor.startFileProcessing()
                            isProcessing = true
                            status = "Processing ..."
                        }
                    }
                }

                Rectangle {
                    id: cancelButtonWrapper
                    width: (parent.width - 2 * mainRow.spacing) / mainRow.itemsAmount
                    height: parent.height
                    color: "#ef4444"

                    Button {
                        id: cancelButton
                        anchors.centerIn: parent
                        text: "Cancel"
                        font.pixelSize: buttonFontSize

                        onClicked: {
                            fileProcessor.cancelFileProcessing()
                            isProcessing = false
                            hasOpened = false
                            status = "Ready to open the file"
                        }
                    }
                }
            }
        }

        Rectangle {
            id: histogramWrapper
            anchors {
                top: navigationWrapper.bottom
                left: parent.left
                right: parent.right
            }
            height: 0.65 * (mainWrapper.height - 2 * navigationWrapper.border.width)
            width: parent.width - (2 * histogramWrapper.border.width)
            anchors.margins: parent.border.width
            border.color: "#cbd5e1"
            border.width: borderWidth
            color: "#f1f5f9"

            Rectangle {
                id: histogram
                anchors {
                    top: parent.top
                    left: parent.left
                    right: parent.right
                }
                anchors.margins: parent.border.width
                height: parent.height - (2 * parent.border.width)
                color: "#e5e7eb"
                border.color: "#94a3b8"
                border.width: borderWidth

                readonly property real padding: 20
                readonly property real availableHeight: histogram.height - 2 * padding
                readonly property real availableWidth: histogram.width - 2 * padding

                Column {
                    id: barColumn
                    spacing: 3
                    anchors.centerIn: parent

                    Repeater {
                        id: modelRepeater
                        model: wordModel

                        Row {
                            id: barRow
                            spacing: 6
                            height: (histogramWrapper.height / wordModel.rowCount) * 0.7
                            width: histogram.availableWidth

                            Rectangle {
                                id: bar
                                width: (count / wordModel.maxCount)
                                       * (parent.width - 4 * histogram.border.width)
                                height: parent.height
                                color: "#3b82f6"
                                radius: 3

                                Text {
                                    id: wordText
                                    text: word
                                    font.pixelSize: barFontSize
                                    color: "white"
                                    anchors.centerIn: parent
                                }
                            }

                            Text {
                                text: count
                                font.pixelSize: barFontSize
                                anchors.verticalCenter: parent.verticalCenter
                                color: "#0f172a"
                            }
                        }
                    }
                }
            }
        }

        Rectangle {
            id: progressBarWrapper
            anchors {
                top: histogramWrapper.bottom
                left: parent.left
                right: parent.right
            }
            height: 0.015 * (mainWrapper.height - 2 * histogramWrapper.border.width)
            width: parent.width - (2 * progressBarWrapper.border.width)
            anchors.margins: parent.border.width
            border.color: "#10b981"
            border.width: borderWidth
            color: "#d1fae5"

            visible: isProcessing

            Rectangle {
                id: progressBar
                height: parent.height
                width: parent.width * progressIndex

                color: "#059669"

                Behavior on width {

                    NumberAnimation {
                        duration: animationDuration
                    }
                }
            }
        }

        Rectangle {
            id: statusBarWrapper
            anchors {
                top: progressBarWrapper.bottom
                left: parent.left
                right: parent.right
            }
            height: 0.1 * (mainWrapper.height - 2 * progressBarWrapper.border.width)
            width: parent.width - (2 * statusBarWrapper.border.width)
            anchors.margins: parent.border.width
            border.color: "#7c3aed"
            border.width: borderWidth
            color: "#ede9fe"

            Text {
                id: statusText
                wrapMode: Text.Wrap
                color: "#1e293b"
                text: status
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
                anchors.margins: parent.border.width
                font.pixelSize: statusFontSize
            }
        }
    }

    function updateProgress(value) {
        progressIndex = value

        if (progressIndex === 1) {
            status = "Successful. Press Cancel to start with a new file"
            statusText.text = status
        }
    }
}
