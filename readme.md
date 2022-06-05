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

## Macierze

Macierze to w sumie wektory, ale elementy mają oprócz pozycji *poziomej* też *pionową*, czyli można do nich dojść po dwóch zmiennych

```cpp
class Matrix : public Vector {...}

Matrix m1(3,3, new double [] {
  1, 2, 3,
  4, 5, 6,
  7, 8, 9
});
```

Kwestie dobierania się do elementów i strumieniowania są analogiczne do wektora

```cpp
std::string info = m1.read();
cout << m1;
cout << m1[1]; // zwraca rząd jako wektor (j.w.)
cout << m1[1][1]; // element środkowy
```

Też, dodawanie jest analogiczne - każdy element jest sumowany z innym

```
Matrix mplus = m1 + m2;
```
