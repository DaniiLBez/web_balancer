Требуется разработать **сетевой балансировщик нагрузки**, работающий в системе **Linux**, который бы обладал следующими 
возможностями:

1. читать настройки из конфигурационного файла произвольного формата;
2. принимать UDP-датаграммы с определенного порта(задается файлом конфигурации);
3. перенаправлять датаграммы из п.2 на один из нескольких узлов(серверов) таким образом, чтобы нагрузка на узлы распределялась равномерно.(адреса узлов задаются файлом конфигурации);
4. ограничивать нагрузку на узлы, общее количество датаграмм проходящих через балансировщик не должно превышать N в секунду(задается файлом конфигурации), лишние датаграммы отклоняются.

Задание должно быть выполнено на языке С++ произвольного стандарта (**уместное применение ООП/STL приветствуется**), с 
использованием **POSIX API** для работы с сетью.
Применение библиотек и фреймвоков наподобие Qt или boost при выполнении задания **не допускается**
