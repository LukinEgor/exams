<?php
// Получает содержимое файла в виде массива. В данном примере мы используем
// обращение по протоколу HTTP для получения HTML-кода с удаленного сервера.
$lines = file('http://www.example.com/');

// Осуществим проход массива и выведем содержимое в виде HTML-кода вместе с номерами строк.
foreach ($lines as $line_num => $line) {
    echo "Строка #<b>{$line_num}</b> : " . htmlspecialchars($line) . "<br />\n";
}

// Второй пример. Получим содержание web-страницы в виде одной строки.
// См.также описание функции file_get_contents().
$html = implode('', file('http://www.example.com/'));

// Используем необязательный параметр flags (начиная с PHP 5)
$trimmed = file('somefile.txt', FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);
?>
