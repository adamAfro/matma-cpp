# Matematyczne Obiekty w C++

## Wektory

Wektory to ciągi liczbowe o danej długości, które mogą być dodane, albo pomnożone skalarnie

```cpp
Vector v1(3, new double [] { 1,  2, 3 });
Vector v2(3, new double [] { 1, -2, 0 });

Vector vplus = v1 + v2;
Vector vprod = v1 * v2;
```

Do elementu wektora można odnieść się po jego indeksie

```cpp
double el = v1[1]; // 2
```

Wektor można wypisać w strumieniu, albo zebrać informacje na jego temat - `read()` różni się od strumienia tym, że ma też typ obiektu (tj. *wektor*) z długością

```cpp
cout << v1;
std::string info = v1.read();
```
