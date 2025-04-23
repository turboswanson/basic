# Word Frequency Analyzer (Android Qt App)

**Word Frequency Analyzer** is an Android application built using **Qt 6.8.1/QML and C++** that allows users to read, analyze, and visualize the **15 most repeated words** from line-based, text-encoded files. It displays the results as a dynamic histogram and offers responsive UI controls for smooth interaction and real-time progress.

---

## 📂 Supported File Formats

This app works with **UTF-8 line-based files**, including:

- `.txt`, `.log`, `.csv`, `.tsv`
- `.md`, `.ini`, `.conf`
- `.json`, `.xml`, `.yaml`, `.yml`
- And other similar plain text formats

> ✅ Successfully tested with files up to **15,000 lines**.

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
  - Word inside the bar
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

### Model Reset (QML-triggered & C++-emitted)

```cpp
void WordCountModel::cleanModel() {
    beginResetModel();
    _wordCounts.clear();
    endResetModel();
    emit countChanged();
}

```

Called via:

```cpp
Signal from FileProcessor (processingHasCancelled)
```
Called via:


Signal from FileProcessor (processingHasCancelled)

Directly from QML's Open button

Cancellation Handling

```cpp
if (this->_cancelRequested) {
    emit processingHasCancelled();
    return;
}
```
File Processing Core

```cpp

QTextStream stream(&file);
stream.setEncoding(QStringConverter::Utf8);
while (!stream.atEnd()) {
    if (_cancelRequested) {
        emit processingHasCancelled();
        return;
    }

    QString line = stream.readLine();
    auto matches = _wordRegex.globalMatch(line);
    while (matches.hasNext()) {
        auto match = matches.next();
        QString word = match.captured().toLower().trimmed();
        if (!_stopWords.contains(word)) {
            _matchesCounting[word]++;
        }
    }

    emit progressChanged(static_cast<double>(currentLine + 1) / totalLines);
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



