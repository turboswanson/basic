# Word Frequency Analyzer (Android Qt App)

**Word Frequency Analyzer** is an Android application built using **Qt 6.8.1/QML and C++** that allows users to read, analyze, and visualize the **15 most repeated words** from line-based, text-encoded files. It displays the results as a dynamic **histogram** and offers responsive UI controls for smooth interaction and real-time progress.

---

## 📂 Supported File Formats

This app works with **UTF-8 line-based files**, including:

- `.txt`, `.log`, `.csv`, `.tsv`
- `.md`, `.ini`, `.conf`
- `.json`, `.xml`, `.yaml`, `.yml`
- And other similar plain text formats

> ✅ Successfully tested with files up to **20,000 lines**.

---

## 🎯 Features

- File selection through Android's file explorer
- Regex-based word detection and frequency counting
- Ignore common stop words automatically
- Displays top 15 words as a **histogram**
- Real-time **progress bar**
- Cancel analysis any time
- Clean, responsive UI with clear statuses

---

## 🖥️ UI Overview


### UI Behavior

- **Open File**: Opens file explorer. Prompts user to pick a file.
- **Start**: Becomes active once a file is selected. Begins analysis.
- **Cancel**: 
  - During processing: Stops analysis.
  - After processing: Hides histogram and resets to initial state.

---

## 📊 Histogram Visualization

- Shows **15 horizontal bars** representing word frequency
- Each bar includes:
  - Found word inside the bar
  - Frequency count on the right
- Bars sorted by descending word count

---

## 🔄 Progress & Status

- **Progress Bar**: Fills based on analysis progress.
- **Status Bar**: Displays one of the following states:
  - `"Ready to open file"`
  - `"Processing ..."`
  - `"Successful. Press Cancel to start with a new file"`

---

## ⚙️ Code Highlights

The application architecture is based on the MVC (Model-View-Controller) pattern and
QAbstractListModel , consisting of:
- **Model**: `WordModelCount` (handles data logic)
- **View**: `AppView` (handles UI presentation)
- **Controller**: `FileProcessor` (manages interactions between Model and View)

### File Processing Core

```cpp

void FileProcessor::fileProcessing(QFile &file) {
  int totalLines = 0;
  {
    // Create a stream to count the total number of lines in the file
    QTextStream counterStream(&file);
    counterStream.setEncoding(QStringConverter::Utf8);

    while (!counterStream.atEnd()) {
      counterStream.readLine(); // Read a line
      ++totalLines;             // Increment line counter
    }
  }

  file.seek(0); // Return to the beginning of the file for main processing

  // Main reading stream
  QTextStream stream(&file);
  stream.setEncoding(QStringConverter::Utf8);

  int currentLine = 0; // Current line counter
  while (!stream.atEnd()) {

    // Check: if cancellation was requested - stop processing
    if (this->_cancelRequested) {
      emit processingHasCancelled(); // Cancellation signal
      this->_isProcessing = false;   // Reset processing flag
      return;
    }

    QString line = stream.readLine(); // Read a line from the file

    // Find matches by regular expression in the line
    auto matches = this->_wordRegex.globalMatch(line);

    while (matches.hasNext()) {
      auto match = matches.next();
      QString word = match.captured().toLower().trimmed(); // Convert to lowercase and remove spaces

      // Skip stop words
      if (!this->_stopWords.contains(word)) {
        this->_matchesCounting[word]++; // Increment counter (value) for the found word (key)
      }
    }

    // Update progress bar
    if (currentLine % updateInterval == 0 || currentLine == totalLines - 1) {
      emit progressChanged(static_cast<double>(currentLine + 1) / totalLines); // Progress update signal
    }

    ++currentLine; // Move to the next line
  }
}
```

### File processing cancelation

- Called by View with button **Cancel** pressing

```qml
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
```
```cpp
  void FileProcessor::cancelFileProcessing() {
    {
      this->_cancelRequested = true;
      this->_isProcessing = false;
      emit processingHasCancelled();
    }
  }
```                    
#### File processing exceptions words

```
  "a", "an", "and", "are", "as", "at", "be", "been", "but",
        "by", "for", "from", "has", "have", "if", "in", "is", "it",
        "of", "on", "or", "that", "the", "to", "was", "were", "with",

        "в", "во", "на", "по", "при", "у", "к", "из", "из-за", "от", "до", "за",
        "и", "но", "а", "не", "что", "как", "же", "ли", "т.д"
```


### Model Updating

- Called by:

``` cpp
    void fileProcessed(QVector<QPair<QString,int>> wordCounts);
```

and signal

```cpp
    &FileProcessor::processingHasCancelled
```

```cpp
  void WordCountModel::setWordCount(const QVector<QPair<QString, int>> &data) {
  beginResetModel();
  this->_wordCounts = data;
  endResetModel();

  emit countChanged(); // notifying View about changes
}
```

### Model Reset

- Called by View with button **Open** pressing

``` qml

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
```

```cpp
    void WordCountModel::cleanModel() {
        beginResetModel();
        this->_wordCounts.clear();
        endResetModel();

        emit countChanged(); // notifying View
}
```




📱 Platform
Built With: Qt 6.8.1, QML, C++

Target: Android (APK via Qt for Android)

Architecture: MVC-like pattern using QAbstractListModel for histogram data

Testing
✅ Verified with:

.txt, .log, .csv, .json, .xml

Files up to 15,000 lines

Cancelling midway and restarting successfully

License
This project is open-source under the MIT License.



