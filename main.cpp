#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>


void print(const std::vector<int>& array)
{
    std::cout << "array :" << std::endl;

    for(const auto& it : array)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

// Для первых двух вариантов сортировки взял в основу сортировку вставками и добавил логигу удаления нужных элементов
std::vector<int> firstSort(std::vector<int> array)
{
    for (size_t i = 1; i < array.size();) {
        if(array[i-1] % 2 == 0)
        {
            array.erase(array.begin() + i - 1);
            continue;
        }

        if(array[i] % 2 == 0)
        {
            array.erase(array.begin() + i);
            continue;
        }

        int x = array[i];
        size_t j = i;
        while (j > 0 && array[j - 1] > x) {
            array[j] = array[j - 1];
            --j;
        }
        array[j] = x;

        ++i;
    }
    // Крайний случай когда в конце массива содержался четный элемент, а все элементы до него были нечетными
    if(array.size() == 1 && array[0] % 2 == 0)
    {
        array.erase(array.begin());
    }
    return array;
}

std::vector<int> secondSort(std::vector<int> array)
{
    for (size_t i = 1; i < array.size();) {
        if(array[i - 1] % 2 != 0)
        {
            array.erase(array.begin() + i - 1);
            continue;
        }
        if(array[i] % 2 != 0)
        {
            array.erase(array.begin() + i);
            continue;
        }

        int x = array[i];
        size_t j = i;
        while (j > 0 && array[j - 1] < x) {
            array[j] = array[j - 1];
            --j;
        }
        array[j] = x;

        ++i;
    }

    // Крайний случай когда в конце массива содержался нечетный элемент, а все элементы до него были четными
    if(array.size() == 1 && array[0] % 2 != 0)
    {
        array.erase(array.begin());
    }

    return array;
}

std::vector<int> thirdSort(std::vector<int> array)
{
    auto comporator = [](int l, int r)
    {
        if (l%2 < r%2) return true;
        if (l%2 > r%2) return false;
        if (l%2 == 0 && r%2 == 0) return l < r;
        if (l%2 == 1 && r%2 == 1) return l > r;
        return false;
    };

    sort(array.begin(), array.end(), comporator);

    return array;
}


int main()
{
    std::srand((int) std::time(0));

    int size;
    std::cout << "Введите размер массива N = ";
    std::cin >> size;

    std::vector<int> array(size);

    //Generate random vector
    for(int i = 0; i < size; ++i)
    {
        array[i] = std::rand() % 100;
    }

    std::cout << "Исходный массив ";
    print(array);

    std::cout << " Первый вариинт алгоритма ";
    print(firstSort(array));

    std::cout << " Второй вариант алгоритма ";
    print(secondSort(array));

    std::cout << " Третий вариант алгоритма ";
    print(thirdSort(array));

    return 0;
}