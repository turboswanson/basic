# Анализатор Частоты Слов (Android-приложение на Qt)

**Анализатор Частоты Слов** — это Android-приложение, созданное с использованием **Qt 6.8.1/QML and C++**, которое позволяет пользователям читать, анализировать и визуализировать **15** наиболее часто встречающихся слов из текстовых файлов, основанных на строках. Результаты отображаются в виде динамической **гистограммы**, а также предлагается отзывчивый пользовательский интерфейс с плавным взаимодействием и отображением прогресса в реальном времени.

---

## 📂 Поддерживаемые форматы файлов
Приложение работает с текстовыми файлами в кодировке **UTF-8**, основанными на строках, включая:

- `.txt`, `.log`, `.csv`, `.tsv`
- `.md`, `.ini`, `.conf`
- `.json`, `.xml`, `.yaml`, `.yml`
- другие подобные форматы простого текста

> ✅ Успешно протестировано с файлами до 20 000 строк.

---

## 🎯 Возможности

- Выбор файла через проводник Android
- Определение и подсчет слов с использованием регулярных выражений
- Автоматическое игнорирование распространенных служебных слов
- Отображение **15** наиболее часто встречающихся слов в виде гистограммы
- Индикатор выполнения в реальном времени
- Возможность отмены анализа в любой момент
- Чистый и отзывчивый пользовательский интерфейс с четкими статусами

## 🖥️ Обзор интерфейса

### Поведение UI:

Интерфейс приложения адаптивен и учитывает размеры текущего окна.

**Open file**: Открывает проводник. Пользователь выбирает файл.

**Start**: Активируется после выбора файла. Начинается анализ.

**Cancel**:

    - Во время обработки: Останавливает анализ.

    - После обработки: Скрывает гистограмму и возвращает в начальное состояние.

---    

### 📊 Визуализация гистограммы

- Отображает **15** горизонтальных полос, представляющих частоту слов. Каждая полоса содержит:

- Найденное слово внутри полосы

- Число вхождений справа

- Полосы отсортированы по убыванию количества

### 🔄 Прогресс и статус

**Индикатор выполнения**: Заполняется по мере выполнения анализа

**Строка статуса**: Отображает одно из состояний:

- "Готово к выбору файла"
- "Обработка ..."
- "Успешно. Нажмите Отмена, чтобы начать заново"

## Основные моменты кода

Архитектура приложения основана на MVC (Model-View-Controller) методе c использованием QAbstractListModel и состоит из:
- **Model**: `WordModelCount` (организация логики хранения данных)
- **View**: `AppView` (организация пользовательского интерфейса)
- **Controller**: `FileProcessor` (организация взаимодействия между Model and View)

### Обработка файла

```cpp

void FileProcessor::fileProcessing(QFile &file) {
  int totalLines = 0;
  {
    // Создание потока для подсчета общего количества строк в файле
    QTextStream counterStream(&file);
    counterStream.setEncoding(QStringConverter::Utf8);

    while (!counterStream.atEnd()) {
      counterStream.readLine(); // Чтение строки
      ++totalLines;             // Увеличение счётчика строк
    }
  }

  file.seek(0); // Возвращение к началу файла для основного анализа

  // Основной поток чтения
  QTextStream stream(&file);
  stream.setEncoding(QStringConverter::Utf8);

  int currentLine = 0; // Счетчик текущей строки
  while (!stream.atEnd()) {

    // Проверка: если запрошена отмена — прекращаем обработку
    if (this->_cancelRequested) {
      emit processingHasCancelled(); // Сигнал отмены
      this->_isProcessing = false;   // Сброс флага обработки
      return;
    }

    QString line = stream.readLine(); // Чтение строки из файла

    // Поиск соответствий по регулярному выражению в строке
    auto matches = this->_wordRegex.globalMatch(line);

    while (matches.hasNext()) {
      auto match = matches.next();
      QString word = match.captured().toLower().trimmed(); // Приведение к нижнему регистру и удаление пробелов

      // Пропуск стоп-слов
      if (!this->_stopWords.contains(word)) {
        this->_matchesCounting[word]++; // Увеличение счетчика(значения) для найденного слова (ключа)
      }
    }

    // Обновление прогресс бара
    if (currentLine % updateInterval == 0 || currentLine == totalLines - 1) {
      emit progressChanged(static_cast<double>(currentLine + 1) / totalLines); // Сигнал обновления прогресса
    }

    ++currentLine; // Переход к следующей строке
  }
}

```
#### Исключения при обработке файла

```
  "a", "an", "and", "are", "as", "at", "be", "been", "but",
        "by", "for", "from", "has", "have", "if", "in", "is", "it",
        "of", "on", "or", "that", "the", "to", "was", "were", "with",

        "в", "во", "на", "по", "при", "у", "к", "из", "из-за", "от", "до", "за",
        "и", "но", "а", "не", "что", "как", "же", "ли", "т.д"
```

### Обновление модели 

- Вызывается сигналом :

``` cpp
    void fileProcessed(QVector<QPair<QString,int>> wordCounts);
```

```cpp
  void WordCountModel::setWordCount(const QVector<QPair<QString, int>> &data) {
  beginResetModel();
  this->_wordCounts = data;
  endResetModel();

  emit countChanged(); // уведомление View об изменениях
}
```
### Сброс модели

- Вызывается из View при нажатии кнопки **Open**

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
и сигналом

```cpp
    &FileProcessor::processingHasCancelled
```   
```cpp
    void WordCountModel::cleanModel() {
        beginResetModel();
        this->_wordCounts.clear();
        endResetModel();

        emit countChanged(); // Уведомление View
}
```

## 📱 Платформа

Сборка: Qt 6.8.1, QML, C++

Устройство: Android (APK via Qt for Android)

Тестирование
✅ Проверена работа с:

.txt, .log, .csv, .json, .xml

Файлы до 50000 строк


## Лицензия
  Разработка для личного использования







