### Array

<details>
  <summary>Общая информация</summary>
<br />

Array (массив) - это последовательный контейнер, инкапсулирующий в себе статический массив. В контейнер array нельзя добавить новый элементы, можно только модифицировать значение заданных изначально. В плане взаимодействия, контейнер array сочетает в себе очевидные свойства статического массива с основным достоинством контейнерных классов - более четкой организацией данных. Например, контейнер Array хранит размер массива и предоставляет итераторы. Так же как и vector, array занимает последовательную часть памяти и может быть передан в функцию как стандартный массив в Си. Вторым шаблонным аргументом класса array является его фактический размер.

</details>

<details>
  <summary>Спецификация</summary>
<br />

*Array Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

| Member type            | definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `value_type`             | `T` defines the type of an element (T is template parameter)                                  |
| `reference`              | `T &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const T &` defines the type of the constant reference                                         |
| `iterator`               | `T *` defines the type for iterating through the container                                                 |
| `const_iterator`         | `const T *` defines the constant type for iterating through the container                                           |
| `size_type`              | `size_t` defines the type of the container size (standard type is size_t) |

*Array Member functions*

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

| Functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `array()`  | default constructor, creates empty array                                 |
| `array(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates array initizialized using std::initializer_list<T>    |
| `array(const array &a)`  | copy constructor  |
| `array(array &&a)`  | move constructor  |
| `~array()`  | destructor  |
| `operator=(array &&a)`      | assignment operator overload for moving object                                |

*Array Element access*

В этой таблице перечислены публичные методы для доступа к элементам класса:

| Element access         | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `reference at(size_type pos)`                     | access specified element with bounds checking                                          |
| `reference operator[](size_type pos)`             | access specified element                                                               |
| `const_reference front()`          | access the first element                        |
| `const_reference back()`           | access the last element                         |
| `iterator data()`                   | direct access to the underlying array                                                  |

*Array Iterators*

В этой таблице перечислены публичные методы для итерирования по элементам класса (доступ к итераторам):

| Iterators      | Definition                                      |
|----------------|-------------------------------------------------|
| `iterator begin()`    | returns an iterator to the beginning            |
| `iterator end()`        | returns an iterator to the end                  |

*Array Capacity*

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:

| Capacity               | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |
| `size_type max_size()`       | returns the maximum possible number of elements |

*Array Modifiers*

В этой таблице перечислены публичные методы для изменения контейнера:

| Modifiers      | Definition                                      |
|----------------|-------------------------------------------------|
| `void swap(array& other)`                   | swaps the contents                                |
| `void fill(const_reference value);`         | assigns the given value value to all elements in the container. |

</details>

<details>
  <summary>Для тестирования</summary>
<br />
  Зайти в репозиторий

  Ввести в командную строку ''make''  
  Чтобы посмотреть покрытие через браузер, надо открыть файл array_coverage_report.html после использования ''make''
</details>

<details>
  <summary>Для использования</summary>
<br />
  Достаточно добавить #include "s21_array.h" в заголовок проекта, в котором собираетесь его использовать
</details>
